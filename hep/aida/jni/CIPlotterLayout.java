package hep.aida.jni;

import hep.aida.*;


public class CIPlotterLayout extends CProxy implements IPlotterLayout {

    public CIPlotterLayout(long crefID) {
        super(crefID);
    }

    public native void reset();

    public native boolean setParameter(String paramName, double paramValue);

    public native double parameterValue(String paramName);

    public native String[] availableParameters();
}
