package hep.aida.jni;

import hep.aida.*;


public class CIFilter extends CProxy implements IFilter {

    public CIFilter(long crefID) {
        super(crefID);
    }

    public native void initialize(ITuple ituple) throws IllegalArgumentException;

    public native boolean accept() throws RuntimeException;

    public native String expression();
} 
