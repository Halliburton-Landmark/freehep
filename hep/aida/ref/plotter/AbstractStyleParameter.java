package hep.aida.ref.plotter;

/**
 *
 * @author The FreeHEP team @ SLAC
 */
public abstract class AbstractStyleParameter {
    
    private String name;
    private String defaultValue;
    private String currentValue = null;
    private String[] noOptions = new String[0];
    private String[] possibleValues = null;
        
    AbstractStyleParameter(String name, String defaultValue) {
        this(name, defaultValue, null);
    }
    
    AbstractStyleParameter(String name, String defaultValue, String[] possibleValues) {
        this.name = name;
        setDefaultValue(defaultValue);
        this.possibleValues = possibleValues;
    }
    
    protected String name() {
        return name;
    }
    
    protected void setDefaultValue(String defaultValue) {
        this.defaultValue = defaultValue;
    }
    
    protected boolean hasAllowedValues() {
        return possibleValues != null;
    }

    protected String[] allowedValues() {
        if ( hasAllowedValues() )
            return possibleValues;
        return noOptions;
    }

    protected boolean isParameterValueSet() {
        return currentValue != null;
    }
    
    protected String parameterValue() {
        String parValue;

        if ( isParameterValueSet() )
            parValue = currentValue;
        else
            parValue = defaultValue();
        
        if ( ! hasAllowedValues() || parValue == null )
            return parValue;

        try {
            int index = Integer.parseInt(parValue);
            if ( index >= allowedValues().length )
                return parValue;
            return allowedValues()[index];
        } catch (NumberFormatException nfe) {
            return parValue;
        }
    }
    
    protected String defaultValue() {
        return defaultValue;
    }
    
    protected void reset() {
        currentValue = null;
    }

    protected boolean setParameter() {
        reset();
        return true;
    }
    
    protected boolean setParameter(String parValue) {
        currentValue = parValue;
        return isValueAllowed(parValue);
    }
    
    protected boolean isCurrentValueAllowed() {
        return checkValue(parameterValue());
    }
    
    protected boolean isValueAllowed(String val) {
        return checkValue(val);        
    }
    
    private boolean checkValue(String val) {
        if ( val == null )
            return ! hasAllowedValues();
        if ( ! hasAllowedValues() )
            return true;
        String[] allowedValues = allowedValues();
        for ( int i = 0; i < allowedValues.length; i++ )
            if ( val.equals(allowedValues[i]) )
                return true;
        try {
            int index = Integer.parseInt(val);
            if ( index < 0 || index >= allowedValues.length )
                return false;
            return true;
        } catch (NumberFormatException nfe) {
            return false;
        }
    }
    
    public abstract Class type();
    
}
