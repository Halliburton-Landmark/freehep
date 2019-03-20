package hep.aida.ref;

import org.freehep.util.Factory;

import hep.aida.*;
import hep.aida.ref.histogram.*;
import hep.aida.ref.tuple.*;
import hep.aida.ref.plotter.*;
import hep.aida.ref.tree.*;
import hep.aida.ref.function.*;
import hep.aida.ref.fitter.*;
import org.freehep.util.FreeHEPLookup;


/**
 * @author Mark Donszelmann
 * @version $Id: BatchAnalysisFactory.java,v 1.5 2005/06/04 00:37:59 turri Exp $
 */
public class BatchAnalysisFactory extends IAnalysisFactory {
    
    public BatchAnalysisFactory() {        
    }

    public ITreeFactory createTreeFactory(String options) {
        return new TreeFactory(this);
    }

    public IHistogramFactory createHistogramFactory(ITree tree, String options) {
        return new HistogramFactory(tree);
    }
   
    public ITupleFactory createTupleFactory(ITree tree, String options) {
        return new TupleFactory(tree);
    }

    public IFunctionFactory createFunctionFactory (ITree tree, String options) {
        return new FunctionFactory(tree); 
    }  

    public IPlotterFactory createPlotterFactory(String options) {
        return new DummyPlotterFactory();
    }  

    public IDataPointSetFactory createDataPointSetFactory(ITree iTree, String options) {
        return new DataPointSetFactory(iTree);
    }
    
    public IFitFactory createFitFactory(String options) {
        return new FitFactory(); 
    }  

    public IGenericFactory createGenericFactory(String factoryType, String options) {
        throw new UnsupportedOperationException("CreateGenericFactory is currently not supported");
    }
}
