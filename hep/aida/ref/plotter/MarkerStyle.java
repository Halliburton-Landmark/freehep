package hep.aida.ref.plotter;

import hep.aida.IMarkerStyle;
import hep.aida.ref.plotter.BrushStyle;
import hep.aida.ref.plotter.Style;

/**
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
public class MarkerStyle extends BrushStyle implements IMarkerStyle {
    
    protected void initializeBaseStyle() {
        super.initializeBaseStyle();
        String[] availShapes = {"dot", "box", "triangle", "diamond", "star", "verticalLine", "horizontalLine", "cross", "circle", "square"};
        addParameter( new StringStyleParameter( Style.MARKER_SHAPE, null, availShapes) );
        addParameter( new IntegerStyleParameter(Style.MARKER_SIZE, 6) );
    }
    
    public String[] availableShapes() {
        return availableParameterOptions(Style.MARKER_SHAPE);
    }
    
    public boolean setShape(String markerShape) {
        return ( (StringStyleParameter) parameter(Style.MARKER_SHAPE) ).setValue(markerShape);
    }
    
    public String shape() {
        return ( (StringStyleParameter) deepestSetParameter(Style.MARKER_SHAPE) ).value();
    }    

    /**
     * Set the marker's size.
     * @param size The marker's size.
     * @return false if the implementation cannot perform the requested change
     *               in the marker's size.
     *
     */
    public boolean setSize(int size) {
        return ( (IntegerStyleParameter) parameter(Style.MARKER_SIZE) ).setValue(size);
    }

    /**
     * Get the marker's size.
     * @return The marker's size.
     *
     */
    public int size() {
        return ( (IntegerStyleParameter) deepestSetParameter(Style.MARKER_SIZE) ).value();
    }
    
}
