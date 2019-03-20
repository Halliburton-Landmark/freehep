package hep.aida.jni;

import hep.aida.*;

public class CIAxis extends CProxy implements IAxis {

    public CIAxis(long crefID) {
        super(crefID);
    }

    public native boolean isFixedBinning();

    public native double lowerEdge();

    public native double upperEdge();

    public native int bins();

    public native double binLowerEdge(int index);

    public native double binUpperEdge(int index);

    public native double binWidth(int index);

    public native int coordToIndex(double coord);
}
