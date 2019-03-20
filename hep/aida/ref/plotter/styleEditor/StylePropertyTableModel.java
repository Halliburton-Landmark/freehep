/*
 * StylePropertyTableModel.java
 *
 * Created on June 13, 2005, 8:00 PM
 */

package hep.aida.ref.plotter.styleEditor;

import hep.aida.*;
import hep.aida.ref.plotter.*;
import com.l2fprod.common.propertysheet.*;

/**
 *
 * @author  The FreeHEP team @ SLAC
 */
public class StylePropertyTableModel extends PropertySheetTableModel {
    
    private IBaseStyle style;
    
    public StylePropertyTableModel(IBaseStyle style) {
        super();
        this.style = style;
        setProperties();
    }
    
    public IBaseStyle getStyle() { return style; }
    
    private void setProperties() {
        String[] pars = style.availableParameters();
        if (pars == null) return;
        
        Property[] props = new Property[pars.length];
        for (int i=0; i<pars.length; i++) {
            props[i] = new StyleProperty(style, pars[i]);
        }
        
        setProperties(props);
    }
 
}
