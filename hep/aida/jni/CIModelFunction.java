package hep.aida.jni;

import hep.aida.*;


public class CIModelFunction extends CIFunction implements IModelFunction {

    public CIModelFunction(long crefID) {
        super(crefID);
    }

    public native boolean providesNormalization();

    public native void normalize(boolean on);

    public native boolean isNormalized();

    public native double[] parameterGradient(double[] x);

    public native boolean providesParameterGradient();

    public native IRangeSet normalizationRange(int iAxis);

    public native void includeNormalizationAll();

    public native void excludeNormalizationAll();
}
