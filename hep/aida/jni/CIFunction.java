package hep.aida.jni;

import hep.aida.*;

 
public class CIFunction extends CProxy implements IFunction {

    public CIFunction(long crefID) {
        super(crefID);
    }

    public native String title();

    public native void setTitle(String title) throws IllegalArgumentException;

    public native double value(double[] x);

    public native int dimension();

    public native boolean isEqual(IFunction f);

    public native double[] gradient(double[] x);

    public native boolean providesGradient();

    public native String variableName(int i);

    public native String[] variableNames();

    public native void setParameters(double[] params) throws IllegalArgumentException;

    public native double[] parameters();

    public native int numberOfParameters();

    public native String[] parameterNames();

    public native void setParameter(String name, double x) throws IllegalArgumentException;

    public native double parameter(String name);

    public native int indexOfParameter(String name);

    public native IAnnotation annotation();

    public native String codeletString();

}
