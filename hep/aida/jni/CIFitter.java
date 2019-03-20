package hep.aida.jni;

import hep.aida.*;



public class CIFitter extends CProxy implements IFitter {

    public CIFitter(long crefID) {
        super(crefID);
    }

    public native IFitResult fit(IFitData fitData, IFunction func);

    public native IFitResult fit(IBaseHistogram hist, IFunction func);

    public native IFitResult fit(IBaseHistogram hist, String model);

    public native IFitResult fit(IBaseHistogram hist, String model, double[] initialParameters);

    public native IFitResult fit(IDataPointSet dataPointSet, IFunction f);

    public native IFitResult fit(IDataPointSet dataPointSet, String model);

    public native IFitResult fit(IDataPointSet dataPointSet, String model, double[] initialParameters);

    public native IFitResult fit(IFitData d, String model);

    public native IFitResult fit(IFitData d, String model, double[] initialParameters);

    public native void setEngine(String name) throws IllegalArgumentException;

    public native String engineName();

    public native IFitParameterSettings fitParameterSettings(String name);

    public native String[] listParameterSettings();

    public native void resetParameterSettings();

    public native void setConstraint(String expr) throws IllegalArgumentException;

    public native String[] constraints();

    public native void resetConstraints();

    public native void setFitMethod(String name) throws IllegalArgumentException;

    public native String fitMethodName();

    public native IDataPointSet createScan1D(IFitData d, IFunction f, String par, int npts, double pmin, double pmax);

    public native IDataPointSet createContour(IFitData d, IFitResult r, String par1, String par2, int npts, double up);

    public native void setUseFunctionGradient(boolean useGrad);

    public native boolean useFunctionGradient();

}

