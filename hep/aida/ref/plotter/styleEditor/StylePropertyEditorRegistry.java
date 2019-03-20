/*
 * StylePropertyEditorRegistry.java
 *
 * Created on June 14, 2005, 7:50 PM
 */

package hep.aida.ref.plotter.styleEditor;

import java.beans.PropertyEditor;
import java.util.logging.*;
import com.l2fprod.common.propertysheet.*;
import com.l2fprod.common.beans.editor.*;

/**
 *
 * @author  serbo
 */
public class StylePropertyEditorRegistry extends PropertyEditorRegistry {
    private Logger styleLogger;
    
    /** Creates a new instance of StylePropertyEditorRegistry */
    public StylePropertyEditorRegistry() {
        super();
        styleLogger = Logger.getLogger("hep.aida.ref.plotter.styleEditor");
    }
    
    public synchronized PropertyEditor getEditor(Property property) {
        styleLogger.finest("StylePropertyEditorRegistry.getEditor for property: "+property.getName());
        PropertyEditor editor = null;
        if (property instanceof StyleProperty) {
            String[] options = ((StyleProperty) property).getAvailableValues();
            Class type = property.getType();
            if (options != null && options.length > 0 && type == String.class) {
                editor = new ComboBoxPropertyEditor();
                ((ComboBoxPropertyEditor) editor).setAvailableValues(options);
            }
        }
        
        if (editor == null) editor = super.getEditor(property);
        return editor;
    }
}
