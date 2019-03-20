/*
 * StylePropertyTableModel.java
 *
 * Created on June 13, 2005, 8:00 PM
 */

package hep.aida.ref.plotter.styleEditor;

import java.util.logging.*;

import java.awt.Color;
import java.awt.Font;
import java.beans.BeanInfo;

import hep.aida.*;
import hep.aida.ref.plotter.*;
import org.freehep.swing.ColorConverter;
import com.l2fprod.common.propertysheet.*;
import com.l2fprod.common.beans.BaseBeanInfo;

/**
 *
 * @author  The FreeHEP team @ SLAC
 */
public class StyleProperty extends DefaultProperty {
    
    private BaseStyle style;
    private Logger styleLogger;
    
    StyleProperty(IBaseStyle style, String parameterName) {
        super();
        this.style = (BaseStyle) style;
        styleLogger = Logger.getLogger("hep.aida.ref.plotter.styleEditor");
        init(parameterName);
    }
    
    
    // Service methods
    
    void init(String parameterName) {
        setName(parameterName);
        setEditable(true);
        readFromObject(style);
    }
    
    public String[] getAvailableValues() {
        return style.availableParameterOptions(getName());
    }
    
    // Overwrite Property methods
    public void readFromObject(Object object) {
        String parameterName = getName();
        setDisplayName(parameterName);
        
        Class t = style.parameter(parameterName).type();
        
        String value = style.parameterValue(parameterName);
        String[] options = style.availableParameterOptions(parameterName);
        if (options != null && options.length > 0) {
            setCategory("preset");
        }
            
        Object objValue = null;
        styleLogger.fine("StyleProperty.readFromObject: Style="+style.name()+", parameter="+parameterName+", value="+value+", type="+t);
        
        setType(t);
        if (t == Boolean.TYPE) {
            objValue = Boolean.valueOf(value);
            setCategory("boolean");
        } else if (t == Color.class) {
            setCategory("color");
            try { 
                if (value != null && value.length() > 0) objValue = ColorConverter.get(value); 
                setCategory("color");
            } catch (Exception e) { e.printStackTrace(); }
        } else if (t == Double.TYPE) {
            if (options != null && options.length > 0) { 
                setType(String.class); 
                objValue = value; 
            } else {
                if (value != null && value.length() > 0) objValue = Double.valueOf(value);
                setCategory("double");
            }
        } else if (t == Font.class) {
            if (options != null && options.length > 0) { 
                setType(String.class); 
                setCategory("preset");
                objValue = value; 
            } else {
                if (value != null && value.length() > 0) objValue = Font.getFont(value);
                setCategory("font");
            }
        } else if (t == Integer.TYPE) { 
            if (options != null && options.length > 0) { 
                setType(String.class); 
                objValue = value; 
            } else {
                if (value != null && value.length() > 0) objValue = Integer.valueOf(value);
                setCategory("integer");
            }
        } else if (t == String.class)  {
            objValue = value;
            if (options == null || options.length == 0) setCategory("string");            
        } else throw new RuntimeException("**** Unknown type of parameter: name="+parameterName+", type="+t);
        
        setValue(objValue);
    }
    
    public void writeToObject(Object object) {
        String parameterName = getName();
        Class t = getType();
        
        Object objValue = getValue();
        String objString = (objValue == null) ? "null" : objValue.getClass().getName();
        String value = null;
        
        if (objValue == null) value = null;
        else if (objValue instanceof Boolean) value = objValue.toString();
        else if (objValue instanceof Color) value = ColorConverter.get((Color) objValue);
        else if (objValue instanceof Double) value = objValue.toString();
        else if (objValue instanceof Integer) value = objValue.toString();
        else if (objValue instanceof String)  value = (String) objValue;
        else throw new RuntimeException("Unknown return type of parameter: name="+parameterName+", type="+objValue);
        
        String oldValue = style.parameterValue(parameterName);
        styleLogger.fine("StyleProperty.writeToObject: Style="+style.name()+", parameter="+parameterName+", newValue="+value+", oldValue="+oldValue);

        style.setParameter(parameterName, value);
        
    }        
 
}