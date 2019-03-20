package hep.aida.ref.plotter;

import hep.aida.ILineStyle;
import hep.aida.ref.plotter.BrushStyle;
import hep.aida.ref.plotter.Style;

/**
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
public class LineStyle extends BrushStyle implements ILineStyle {
    
    protected void initializeBaseStyle() {
        super.initializeBaseStyle();
        String[] lineTypes = { "solid", "dotted", "dashed", "dotdash" };
        addParameter( new StringStyleParameter( Style.LINE_TYPE, lineTypes[0], lineTypes) );
        addParameter( new IntegerStyleParameter( Style.LINE_THICKNESS, 2) );        
    }
    
    public String[] availableLineTypes() {
        return availableParameterOptions( Style.LINE_TYPE );
    }
    
    public String lineType() {
        return ( (StringStyleParameter) deepestSetParameter( Style.LINE_TYPE ) ).value();
    }
    
    public boolean setLineType(String lineType) {
        return ( (StringStyleParameter) parameter( Style.LINE_TYPE ) ).setValue( lineType );
    }
    
    public boolean setThickness(int lineThickness) {
        return ( (IntegerStyleParameter) parameter( Style.LINE_THICKNESS ) ).setValue( lineThickness );
    }
    
    public int thickness() {
        return ( (IntegerStyleParameter) deepestSetParameter( Style.LINE_THICKNESS ) ).value();
    }
}
