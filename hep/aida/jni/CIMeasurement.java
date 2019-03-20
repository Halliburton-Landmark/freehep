package hep.aida.jni;

import hep.aida.*;
 
public class CIMeasurement extends CProxy implements  IMeasurement {

    public CIMeasurement(long crefID) {
        super(crefID);
    }

    public native double value();

    public native double errorPlus();

    public native double errorMinus();

    public native void setValue(double value) throws IllegalArgumentException;

    public native void setErrorPlus(double errorPlus) throws IllegalArgumentException;

    public native void setErrorMinus(double errorMinus) throws IllegalArgumentException;
} 
