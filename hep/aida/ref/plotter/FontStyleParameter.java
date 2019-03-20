package hep.aida.ref.plotter;

import java.awt.*;
import java.awt.GraphicsEnvironment;

/**
 *
 * @author The FreeHEP team @ SLAC
 */
public class FontStyleParameter extends StringStyleParameter {
    
    private static String[] defaultValues = GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();
    
    FontStyleParameter(String name, String defaultValue) {
        super(name, defaultValue, defaultValues);
    }
    
    public Class type() {
        return Font.class;
    }
}
