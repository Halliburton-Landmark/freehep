package hep.aida.ref.plotter;

import hep.aida.IBrushStyle;
import hep.aida.ref.plotter.BaseStyle;
import hep.aida.ref.plotter.Style;

/**
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
abstract class BrushStyle extends BaseStyle implements IBrushStyle {
    
    protected void initializeBaseStyle() {        
        addParameter( new ColorStyleParameter( Style.BRUSH_COLOR) );
        addParameter( new DoubleStyleParameter( Style.BRUSH_OPACITY, 1, 0, 1) );
    }
    
    public String[] availableColors() {
        return availableParameterOptions( Style.BRUSH_COLOR );
    }   
    
    public String color() {
        return ( (ColorStyleParameter) deepestSetParameter( Style.BRUSH_COLOR ) ).stringValue();
    }
    
    /**
     * returns -1 if it not set
     */
    public double opacity() {
        return ( (DoubleStyleParameter) deepestSetParameter( Style.BRUSH_OPACITY ) ).value();
    }
    
    public boolean setColor(String color) {
        return ( (ColorStyleParameter) parameter( Style.BRUSH_COLOR ) ).setStringValue(color);
    }
    
    public boolean setOpacity(double opacity) {
        return ( (DoubleStyleParameter) parameter( Style.BRUSH_OPACITY ) ).setValue(opacity);
    }    
}
