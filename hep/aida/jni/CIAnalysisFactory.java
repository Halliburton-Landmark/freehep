package hep.aida.jni;

import hep.aida.*;

public class CIAnalysisFactory extends IAnalysisFactory {

    protected CIAnalysisFactory() {
    }

    public native static IAnalysisFactory create();
    
    public native ITreeFactory createTreeFactory();
    public native IHistogramFactory createHistogramFactory(ITree tree) throws IllegalArgumentException;
    public native IDataPointSetFactory createDataPointSetFactory(ITree tree) throws IllegalArgumentException;
    public native ITupleFactory createTupleFactory(ITree tree) throws IllegalArgumentException;
    public native IFunctionFactory createFunctionFactory(ITree tree) throws IllegalArgumentException;
    public native IPlotterFactory createPlotterFactory();
    public native IFitFactory createFitFactory();
} 
