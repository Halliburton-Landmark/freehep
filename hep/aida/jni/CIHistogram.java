package hep.aida.jni;

import hep.aida.*;

public class CIHistogram extends CIBaseHistogram implements IHistogram {

    public CIHistogram(long crefID) {
        super(crefID);
    }

    public native int allEntries();

    public native int extraEntries();

    public native double equivalentBinEntries();

    public native double sumBinHeights();

    public native double sumAllBinHeights();

    public native double sumExtraBinHeights();

    public native double minBinHeight();

    public native double maxBinHeight();

    public native void scale(double scaleFactor);
}
