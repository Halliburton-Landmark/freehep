package hep.aida.jni;

import hep.aida.*;

public class CIPlotterFactory extends CProxy implements IPlotterFactory {

    public CIPlotterFactory(long crefID) {
        super(crefID);
    }

    public native IPlotter create();

    public native IPlotter create(String name);

    public native IMarkerStyle createMarkerStyle();

    public native ITextStyle createTextStyle();

    public native ILineStyle createLineStyle();

    public native IFillStyle createFillStyle();

    public native IDataStyle createDataStyle();

    public native IAxisStyle createAxisStyle();

    public native ITitleStyle createTitleStyle();

    public native IPlotterStyle createPlotterStyle();
} 
