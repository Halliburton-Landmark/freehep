/*
 *ExponentialCoreNorm .java
 *
 * Created on September 6, 2002, 3:28 PM
 */

package hep.aida.ref.function;
import java.util.*;
import hep.aida.*;
import hep.aida.ref.*;
import hep.aida.ref.fitter.*;
import hep.aida.ref.fitter.fitData.*;


/**
 *
 * @author serbo
 */

/**
 * Normalised Exponential (E) distribution in the form:
 *    f = (1/N)*exp((x-origin)/exponent)) has 2 parameters, 
 * Normalization Amplitude N is calculated by the "normalizationAmplitude" method
 */
public class ExponentialCoreNorm extends FunctionCore {

    protected boolean providesNormalization;

    public ExponentialCoreNorm(String str) {
	super(1, 1, new double[] {1.} );
	setTitle("ExponentialCoreNorm::"+str);
	providesNormalization = true;

	String[] names = new String[] { "exponent" };
	setParameterNames(names);
    }

    public ExponentialCoreNorm(String str, double[] pVal) {
	super(1, 1, pVal);
	setTitle("ExponentialCoreNorm::"+str);
	providesNormalization = true;

	String[] names = new String[] { "exponent" };
	setParameterNames(names);
    }

    // Value of the function WITHOUT Normalization factor (as if N=1)
    public double functionValue(double[] var) {
	double val =  Math.exp(var[0]*p[0]);
	return val;
    }

    // Each concrete FunctionCore has to implement those methods that deal with Gradients and Normalization
    public boolean providesGradient() { return true; }

    public double[] gradient(double[] var)  {
	return new double[] { functionValue(var)*p[0] };
    }

    public boolean providesParameterGradient() { return true; }

    public double[] parameterGradient(double[] var) { 
	return new double[] { functionValue(var)*var[0] };
    }

    public boolean providesNormalization() { return providesNormalization; }

    public double normalizationAmplitude(double[] xMin, double[] xMax) {
	double val = 0;
	val = (functionValue(new double[] {xMax[0]}) - functionValue(new double[] {xMin[0]}))/p[0];
	//System.out.println("\t  val="+val+"\t xMin="+xMin[0]+"\t xMax="+xMax[0]+"\t par="+p[0]);
	
	return val;
    } 


    // Check fitting with this function
    public static void main(String[] args) throws java.io.IOException {
        System.out.println("Start ExponentialCoreNorm");
        IAnalysisFactory af = IAnalysisFactory.create();     //jas.aida.gui.JASGUIAnalysisFactory.create(); 
        System.out.println("af="+af);
        ITree tree = af.createTreeFactory().create();
        IHistogramFactory hf = af.createHistogramFactory( tree );
        ITupleFactory tf = af.createTupleFactory( tree );
        IFunctionFactory ff = af.createFunctionFactory( tree );
        IPlotterFactory pf = af.createPlotterFactory(  );

	IPlotter plotter = pf.create("JAS Plotter");
	plotter.createRegions(2, 2);
        
	IModelFunction f1 = (IModelFunction) ff.createFunctionByName("f1","e");
	IModelFunction f2 = (IModelFunction) ff.createFunctionByName("f2","e");
	IModelFunction f3 = (IModelFunction) ff.createFunctionByName("f3","e");
	IModelFunction f4 = (IModelFunction) ff.createFunctionByName("f4","e");

        hep.aida.IHistogram1D hist1 = hf.createHistogram1D("hist1","hist1",100,-5,5);
        hep.aida.IHistogram1D hist2 = hf.createHistogram1D("hist2","hist2",100,-5,5);
        hep.aida.IHistogram2D hist2d = hf.createHistogram2D("hist2d","hist2d",100,-5,5,10,-10,0);
        java.util.Random r = new java.util.Random();
        
        ITuple tup = tf.create("tup","tup","double x0, double y");

        System.out.println("Filling tuple");
        for ( int i = 0; i < 50000; i++ ) {
            double x = 10.*(r.nextDouble()-0.5);
            double y = r.nextDouble()*2.;
	    double d = Math.exp((x-2.)/5.);
	    if (y < d) {
		hist1.fill(x);
		//hist2.fill(x);
		hist2d.fill(x,y);
		tup.fill(0,x);
		tup.fill(1,y);
		tup.addRow();
	    }
        }
        System.out.println("Filled Histograms and Tuple");
	//hist2.scale(1./hist2.sumBinHeights());    
        System.out.println("Filling tuple done");

	// Do Chi-2 Fitting
	double[] chi2 = new double[] { 10, 1.5 };
	f1.setParameters(chi2);
	f2.setParameters(chi2);
	f2.normalize(false);

        Fitter fitter = new Fitter("Chi2","uncmin",null);
        //fitter.fit(hist1,f2);
        System.out.println("about to fit");
        fitter.fit(hist1,"e");
        System.out.println("Fit done!");

	plotter.currentRegion().plot(hist1);
	plotter.currentRegion().plot(f1);

	plotter.next();
	plotter.currentRegion().plot(hist1);
	plotter.currentRegion().plot(f1);
	plotter.currentRegion().plot(f2);

        System.out.println("show");
	plotter.show();

	// Do ML fitting
	for (int i=0; i<1; i++) hist2.fill(0.1);
	f3.normalize(true);
	f4.normalize(true);

        System.out.println("Set Normalization for f3 and f4");
	f3.excludeNormalizationAll();
	f3.normalizationRange(0).include(-5., 5.);
	f4.excludeNormalizationAll();
	f4.normalizationRange(0).include(-5., 5.);
        System.out.println("Set Normalization range for f3 and f4");

	double[] ml = new double[] { -0.5 };
	f3.setParameters(ml);
	f4.setParameters(ml);

	//for (int i=-5; i<6; i++) System.out.println(i+"\t "+f3.value(new double[] { i*1. }) );
	System.out.println("Variable names: "+f4.variableName(0) );

        IEvaluator[] ev = null;
        FitData fd = new FitData();

        //Fitter fitter2 = new Fitter("uml","minuit");
        //fitter.setFitMethod("uml");
        //fitter2.fitParameterSettings("exponent").setStepSize(0.1);
        //String[] colNames = {"x0"};
        //fd.createConnection(tup,colNames);
	//fd.pipe(0).excludeAll();
	//fd.pipe(0).includeRange(-5., 5.);
        //fitter2.fit(fd,f4);

	plotter.next();
	plotter.currentRegion().plot(hist2);
	plotter.currentRegion().plot(f3);

	plotter.next();
	plotter.currentRegion().plot(hist2);
	plotter.currentRegion().plot(f4);
	plotter.show();
	System.out.println("Done");
    }
}
