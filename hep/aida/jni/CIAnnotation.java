package hep.aida.jni;

import hep.aida.*;

public class CIAnnotation extends CProxy implements IAnnotation {

    public CIAnnotation(long crefID) {
        super(crefID);
    }

    public native void addItem(String key, String value);
    public native void addItem(String key, String value, boolean sticky);
    public native void removeItem(String key);
    public native String value(String key);
    public native void setValue(String key, String value);
    public native void setSticky(String key, boolean sticky);
    public native int size();
    public native String key(int index);
    public native String value(int index);
    public native void reset();
}
