package hep.aida.jni;

import hep.aida.*;

public class CIBaseHistogram extends CProxy implements IBaseHistogram {

    public CIBaseHistogram(long crefID) {
        super(crefID);
    }

    public native String title();

    public native void setTitle(String title);

    public native IAnnotation annotation();

    public native int dimension();

    public native void reset();

    public native int entries();

}
