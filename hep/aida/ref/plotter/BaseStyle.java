package hep.aida.ref.plotter;

import hep.aida.IBaseStyle;
import hep.aida.ref.plotter.StyleListener;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.Set;

/**
 *
 * @author The AIDA team @ SLAC.
 *
 * When plotting an AIDA object there are several styles that contribute to the
 * resulting style of the plot: the default (root) style, the style of the plotter,
 * the style of the region and the style provided by the user. These styles have
 * a parent-child relationship with the default (root) style being the parent of the plotter
 * style, the plotter style the parent of the region style etc.
 * All the styles in an inheritance chain have the same set of parameters. A prameter is
 * defined by the following attributes:
 *   - options, i.e. possible values. This is meant to be an hint of what the possible
 *                                    values are.
 *   - current value. The current value is, by default null.
 * When plotting, the top level style is considered first and all the other in
 * sequence when a given parameter is not specified (still null) by the top level style.
 *
 * Please notice that parameters, options and values are CASE INSENSITIVE.
 *
 */
public abstract class BaseStyle implements IBaseStyle, StyleListener {
    
    
    private Hashtable internalParameterHash = new Hashtable();
    private Hashtable parameterHash = new Hashtable();
        
    private Hashtable baseStyles = new Hashtable();
    
    private BaseStyle parent = null;

    private String name = "plotter";
    
    private ArrayList listeners = new ArrayList();
    
    /**
     * Create a BaseStyle without a parent.
     * The parent, if ever available, can be set via the setParent method.
     *
     */
    protected BaseStyle() {
        initializeBaseStyle();
        setParent( null );
        addParameter( new BooleanStyleParameter(Style.IS_VISIBLE, true) );
    }
    
    /**
     * Create a clone of a BaseStyle.
     * @param style The BaseStyle to be cloned.
     *
     */
    protected BaseStyle( BaseStyle style ) {
        this();
        copyStyle( this, style );
    }
    
    private void copyStyle( BaseStyle newStyle, BaseStyle oldStyle ) {
        Collection pars = oldStyle.parameters();
        Iterator iter = pars.iterator();
        while( iter.hasNext() ) {
            AbstractStyleParameter oldPar = (AbstractStyleParameter) iter.next();
            if ( ! oldPar.isParameterValueSet() ) 
                newStyle.setParameter(oldPar.name());
            else 
                newStyle.setParameter( oldPar.name(), oldPar.parameterValue() );
        }
        String[] names = newStyle.baseStyleNames();
        for ( int i = 0; i < names.length; i++ )
            copyStyle( newStyle.baseStyle( names[i] ), oldStyle.baseStyle( names[i] ) );
    }

    /**
     * Initialize the BaseStyle.
     * This method has to be overwritten by all Style that has to add parameters or
     * internal BaseStyles.
     *
     */
    protected abstract void initializeBaseStyle();
    
    
    /**
     * Set the name of this BaseStyle.
     * @param name The name.
     *
     */
    protected void setName( String name )  {
        this.name = name;
    }
    
    /**
     * Get the name of this BaseStyle.
     * @return The name of the BaseStyle.
     *
     */
    public String name() {
        return name;
    }
    
    /**
     * @return The type of the style.
     */
    public Class type() {
        return this.getClass().getInterfaces()[0];
    }
        
    /**
     * @return A sub style, knowing its name.
     */
    public IBaseStyle child(String name) {
        return (IBaseStyle) baseStyles.get( name );
    }
    
    /**
     * @return The array of sub styles.
     */
    public IBaseStyle[] children() {
        IBaseStyle[] children = new IBaseStyle[baseStyles.size()];
        Set keys = baseStyles.keySet();
        Iterator i = keys.iterator();
        int count = 0;
        while( i.hasNext() )
            children[count++] = (IBaseStyle) baseStyles.get(i.next());
        return children;
    }
    
    /**
     * Set isVisible of the data.
     */
    public boolean setVisible(boolean visible) {
        return setParameter(Style.IS_VISIBLE, String.valueOf(visible) );
    }
    
    /**
     * Get isVisible of the data.
     * return The isVisible of the data.
     */
    public boolean isVisible() {
        String isVisible = parameterValue(Style.IS_VISIBLE);
        return Boolean.valueOf(isVisible).booleanValue();
    }
    
    /**
     * Set the parent for this BaseStyle.
     * The parent can be set only once; if this is done a second time a RuntimeException is
     * thrown.
     * @param p The parent for this BaseStyle.
     *
     */
    public void setParent( IBaseStyle p ) {
        BaseStyle parent = (BaseStyle)p;
        this.parent = parent;
        if ( parent != null ) {
            //            if ( ! parent.hasListener( this ) )
            //                parent.addStyleListener(this);
            Enumeration keys = baseStyles.keys();
            while ( keys.hasMoreElements() ) {
                String name = (String) keys.nextElement();
                baseStyle(name).setParent( parent.baseStyle(name) );
            }
        }
    }
    
    /**
     * Get the parent for this BaseStyle.
     * @return The parent.
     *
     */
    public BaseStyle parent() {
        return parent;
    }
    
    /**
     * Add a BaseStyle to this BaseStyle.
     * This method is to be invoked when a BaseStyle contains other BaseStyles in order
     * for the reset and the setParent methods to work properly.
     *
     */
    protected boolean addBaseStyle( IBaseStyle baseStyle, String name ) {
        BaseStyle bs = (BaseStyle) baseStyle;
        bs.setName(name);
        if ( baseStyles.get( bs.name() ) != null )
            ( (BaseStyle) baseStyles.get(bs.name()) ).removeStyleListener(this);
        baseStyles.put( bs.name(), baseStyle );
        bs.addStyleListener(this);
        if ( parent != null )
            bs.setParent( parent.baseStyle( bs.name() ) );
        notifyStyleChanged();
        return true;
    }
    
    /**
     * Get a BaseStyle contained in this BaseStyle.
     * The indexing is the internal one.
     *
     */
    private BaseStyle baseStyle( String name ) {
        return (BaseStyle) child(name);
    }
    
    /**
     * Get the available BaseStyle names attached to this BaseStyle.
     *
     */
    private String[] baseStyleNames() {
        String[] names = new String[ baseStyles.size() ];
        Enumeration e = baseStyles.keys();
        int count = 0;
        while( e.hasMoreElements() )
            names[ count++ ] = (String) e.nextElement();
        return names;
    }
        
    /**
     * Add a new parameter to this BaseStyle.
     * @param styleParameter The style parameter.
     *
     */
    protected void addParameter( AbstractStyleParameter styleParameter ) {
        addParameter(styleParameter, true);
    }

    private void addParameter( AbstractStyleParameter styleParameter, boolean isInternal) {
        String name = styleParameter.name();
        if ( isRegisteredParameter(name) )
            throw new IllegalArgumentException("Parameter "+styleParameter.name()+" already belongs to this style.");
        if ( isInternal )
            internalParameterHash.put(name, styleParameter);
        parameterHash.put(name, styleParameter);
    }
    
    private boolean isInternalParameter( String parameterName ) {
        return internalParameterHash.containsKey(parameterName);
    }
    
    private boolean isExternalParameter( String parameterName ) {
        return ( ! internalParameterHash.containsKey(parameterName) ) && parameterHash.containsKey(parameterName);
    }
    
    private boolean isRegisteredParameter( String parameterName ) {
        return parameterHash.containsKey(parameterName);
        
    }
    
    public AbstractStyleParameter parameter(String parName) {
        if ( ! isRegisteredParameter(parName) )
            throw new IllegalArgumentException("Parameter with name "+parName+" does not belong to this style.");
        return (AbstractStyleParameter) parameterHash.get(parName);
    }
    
    protected AbstractStyleParameter deepestSetParameter(String parName) {
        if ( parameter(parName).isParameterValueSet() || parent() == null )
            return parameter(parName);
        else
            return parent().deepestSetParameter(parName);        
    }
    
    
    
    protected int numberOfParameters() {
        return parameterHash.size();
    }
    
    protected Collection parameters() {
        return parameterHash.values();
    }

    public boolean isParameterSet(String parameterName) {
        if ( parameter(parameterName).isParameterValueSet() || parent() == null )
            return parameter(parameterName).isParameterValueSet();
        else
            return parent().isParameterSet(parameterName);        
    }
    
    /**
     * Below are the AIDA methods.
     *
     */
    public String[] availableParameterOptions(String parameterName) {
        AbstractStyleParameter par = parameter(parameterName);
        return par.allowedValues();
    }
    
    public String[] availableParameters() {
        int size = numberOfParameters();
        String[] pars = new String[ size ];
        Collection parameters = parameters();
        Iterator iter = parameters.iterator();
        int count = 0;
        while( iter.hasNext() )
            pars[count++] = ( (AbstractStyleParameter) iter.next() ).name();
        return pars;
    }
    
    public String parameterValue(String parameterName) {
        AbstractStyleParameter par = deepestSetParameter(parameterName);
        return par.parameterValue();
    }
    
    public void reset() {
        reset(true);
    }
    
    private void reset( boolean sendNotification ) {
        Enumeration parKeys = parameterHash.keys();
        while( parKeys.hasMoreElements() )
            parameter( (String) parKeys.nextElement() ).reset();

        Enumeration keys = baseStyles.keys();
        while( keys.hasMoreElements() )
            baseStyle( (String) keys.nextElement() ).reset(false);

        if ( sendNotification )
            notifyStyleChanged();
    }
    
        
    public boolean setParameter(String parameterName) {
        boolean result = false;
        if ( isRegisteredParameter(parameterName) ) {
            result = parameter(parameterName).setParameter();
            if ( ! isInternalParameter(parameterName) )
                result = false;
        }
        else {
            StringStyleParameter styleParameter = new StringStyleParameter(parameterName, null);
            addParameter(styleParameter, false);
        }
        notifyStyleChanged();
        return result;
    }
    
    public boolean setParameter(String parameterName, String parValue) {
        boolean result = false;
        if ( isRegisteredParameter(parameterName) ) {
            result = parameter(parameterName).setParameter(parValue);
            if ( ! isInternalParameter(parameterName) )
                result = false;
        }
        else {
            StringStyleParameter styleParameter = new StringStyleParameter(parameterName, null);
            addParameter(styleParameter, false);
            styleParameter.setValue(parValue);
        }
        notifyStyleChanged();
        return result;
    }
    
    // Use this method to give styles a different default than the "standard one"
    protected void setParameterDefault(String parameterName, String parDefaultValue) {
        if ( ! isRegisteredParameter(parameterName) )
            throw new IllegalArgumentException("Parameter "+parameterName+" does not exist ");
        parameter(parameterName).setDefaultValue(parDefaultValue);
        notifyStyleChanged();
    }

    /**
     * Add a StyleListener.
     *
     */
    void addStyleListener( StyleListener listener ) {
        listeners.add(listener);
    }
    
    /**
     * Remove a StyleListener.
     *
     */
    void removeStyleListener( StyleListener listener ) {
        if ( listeners.contains( listener ) )
            listeners.remove(listener);
    }
    
    /**
     * Notify the listeners that the style has changed.
     *
     */
    void notifyStyleChanged() {
        for ( int i = 0; i < listeners.size(); i++ ) {
            StyleListener listener = (StyleListener) listeners.get(i);
            listener.styleChanged(this);
        }
    }
    
    boolean hasListener( StyleListener listener ) {
        for ( int i = 0; i < listeners.size(); i++ )
            if ( listener == listeners.get(i) )
                return true;
        return false;
    }
    
    public void styleChanged(BaseStyle style) {
        notifyStyleChanged();
    }
        
}
