package hep.aida.jni;

import hep.aida.*;

 
public class CIEvaluator extends CProxy implements IEvaluator {

    public CIEvaluator(long crefID) {
        super(crefID);
    }

    public native void initialize(ITuple ituple) throws IllegalArgumentException;

    public native double evaluateDouble() throws RuntimeException;

    public native String expression();
} 

