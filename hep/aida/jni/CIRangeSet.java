package hep.aida.jni;

import hep.aida.*;


public class CIRangeSet extends CProxy implements IRangeSet {

    public CIRangeSet(long crefID) {
        super(crefID);
    }

    public native double[] lowerBounds();

    public native double[] upperBounds();

    public native void include(double xMin, double xMax);

    public native void exclude(double xMin, double xMax);

    public native void includeAll();

    public native void excludeAll();

    public native boolean isInRange(double point);

    public native int size();

    public native double PLUS_INF();

    public native double MINUS_INF();
} 
