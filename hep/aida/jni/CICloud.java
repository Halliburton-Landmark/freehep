package hep.aida.jni;

import hep.aida.*;

public class CICloud extends CIBaseHistogram implements ICloud {

    public CICloud(long crefID) {
        super(crefID);
    }

    public native double sumOfWeights();

    public native void convertToHistogram();

    public native boolean isConverted();

    public native int maxEntries();

    public native void scale(double scaleFactor);
}
