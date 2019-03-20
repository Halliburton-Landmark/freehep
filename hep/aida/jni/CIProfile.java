package hep.aida.jni;

import hep.aida.*;

public class CIProfile extends CIBaseHistogram implements IProfile {

    public CIProfile(long crefID) {
        super(crefID);
    }

    public native int allEntries();

    public native int extraEntries();

    public native double sumBinHeights();

    public native double sumAllBinHeights();

    public native double sumExtraBinHeights();

    public native double minBinHeight();

    public native double maxBinHeight();
}
