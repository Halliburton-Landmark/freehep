package hep.aida.jni;

import hep.aida.*;

 
public class CIFitResult extends CProxy implements IFitResult {

    public CIFitResult(long crefID) {
        super(crefID);
    }

    public native boolean isValid();

    public native int fitStatus();

    public native IFunction fittedFunction();

    public native double quality();

    public native int ndf();

    public native double covMatrixElement(int i, int j);

    public native String fitMethodName();

    public native String engineName();

    public native String dataDescription();

    public native String[] constraints();

    public native IFitParameterSettings fitParameterSettings(String name);

    public native double[] fittedParameters();

    public native String[] fittedParameterNames();

    public native double fittedParameter(String name);

    public native double[] errors();

    public native double[] errorsPlus();

    public native double[] errorsMinus();

} 

