package hep.aida.jni;

import hep.aida.*;

public class CIFitParameterSettings extends CProxy implements IFitParameterSettings {

    public CIFitParameterSettings(long crefID) {
        super(crefID);
    }
    
    public native String name();

    public native double stepSize();

    public native double upperBound();

    public native double lowerBound();

    public native boolean isBound();

    public native boolean isFixed();

    public native void setStepSize(double step);

    public native void setBounds(double lo, double up);

    public native void removeBounds();

    public native void setFixed(boolean isFixed);

    public native void setLowerBound(double lowerBound);

    public native void setUpperBound(double upperBound);

    public native void reset();
} 
