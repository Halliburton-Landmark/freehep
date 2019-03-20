package hep.aida.jni;

import hep.aida.*;

public class CIBaseStyle extends CProxy implements IBaseStyle {

    public CIBaseStyle(long crefID) {
        super(crefID);
    }

    public native void reset();

    public native boolean setParameter(String paramName);
    public native boolean setParameter(String paramName, String options);

    public native String parameterValue(String parameter);

    public native String[] availableParameters();

    public native String[] availableParameterOptions(String paramName);
} 

