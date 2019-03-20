/*
 * FunctionCore.java
 *
 * Created on September 4, 2002, 6:15 AM
 */

package hep.aida.ref.function;
import java.util.*;
import hep.aida.*;
import hep.aida.ref.*;
import gnu.jel.*;


/**
 *
 * @author  serbo
 */

// Creates FunctionCore from a String expression
public  class JELFunctionCore extends FunctionCore {

    private String expression;
    private String gradient;
    private boolean providesGradient;

    private JELCompiledExpression compExpression;
    private JELCompiledExpression[] compGradient;

    public JELFunctionCore(int dim, int nPar, String expr, String[] pNames, String[] gradient) {
	super(dim, nPar);

	if (expr != null && !expr.equals("")) expression = expr;
	else
	    throw new IllegalArgumentException("Can not create function from an empty script!");

	// Check parameter names
	if (pNames!= null && nPar != pNames.length)
	    throw new IllegalArgumentException("Number of parameters ("+nPar+
					       ") is different from number of parameter names ("+pNames.length+")");
	// Create JEL compiled expression
	compExpression = new JELCompiledExpression(dimension, numberOfParameters, expression, pNames);

	// Setup and compile gradients
	compGradient = null;
	if (gradient != null && gradient.length > 0) { 
	    providesGradient = true; 
	    compGradient = new JELCompiledExpression[dim];
	    for (int i=0; i<dim; i++)  { compGradient[i] = new JELCompiledExpression(dimension, numberOfParameters, gradient[i], pNames); }
	} else {
	    providesGradient = false;
	    this.gradient = null;
	}

	// Set parameter names
	if (pNames != null) setParameterNames(pNames);
    }

    // Value of the function WITHOUT Normalization factor (as if N=1)
    public double functionValue(double[] var) { return compExpression.evaluate(var, parameters()); }

    public boolean setParameterNames(String[] params) { 
	super.setParameterNames(params);
	compExpression.setParameterNames(params);
	if (compGradient != null) {
	    for (int i=0; i<dimension; i++) { compGradient[i].setParameterNames(params); }
	}
	return true;
    }

    // Each concrete FunctionCore has to implement those methods that deal with Gradients and Normalization
    public boolean providesGradient() { return providesGradient; }
    
    public double[] gradient(double[] x) { 
	
	if (compGradient == null || !providesGradient)
	throw new UnsupportedOperationException("This function does not provide gradient");

	double[] grad = new double[numberOfParameters];
	for (int i=0; i<numberOfParameters; i++)  { grad[i] = compGradient[i].evaluate(x, parameters()); }

	return grad;
    }

    public boolean providesParameterGradient() { return false; }

    public double[] parameterGradient(double[] x) {
	throw new UnsupportedOperationException("JELFunctionCore does not provide parameter gradient");
    }

    public boolean providesNormalization() { return false; }

    public double normalizationAmplitude(double[] xMin, double[] xMax)  {
	throw new UnsupportedOperationException("JELFunctionCore does not provide normalization");
    }


    // Check fitting with this function
    public static void main(String[] args) throws java.io.IOException {

        IAnalysisFactory af = IAnalysisFactory.create();     //jas.aida.gui.JASGUIAnalysisFactory.create(); 
        ITree tree = af.createTreeFactory().create();
        IHistogramFactory hf = af.createHistogramFactory( tree );
        ITupleFactory tf = af.createTupleFactory( tree );
        IFunctionFactory ff = af.createFunctionFactory( tree );
        IPlotterFactory pf = af.createPlotterFactory(  );

	IPlotter plotter = pf.create("JAS Plotter");
	plotter.createRegions(2, 1);
        
	IModelFunction f1 = (IModelFunction) ff.createFunctionFromScript("Script Function 1", 1, "a*(1+c*sin(x[0]-d))", "a,c,d", "f1");
	IModelFunction f2 = (IModelFunction) ff.createFunctionFromScript("Script Function 2", 1, "a*(1+c*sin(x[0]-d))", "a,c,d", "f2");

        hep.aida.IHistogram1D hist1 = hf.createHistogram1D("hist1","hist1",100,-5,5);
        hep.aida.IHistogram1D hist2 = hf.createHistogram1D("hist2","hist1",100,-5,5);
        hep.aida.IHistogram2D hist2d = hf.createHistogram2D("hist2d","hist2d",100,-5,5,10,-10,0);
        java.util.Random r = new java.util.Random();
        
        ITuple tup = tf.create("tup","tup","double x0, double y");
        
        for ( int i = 0; i < 50000; i++ ) {
            double x = 10.*(r.nextDouble()-0.5);
            double y = r.nextDouble()*2;
	    double d = 1+0.3*Math.sin(x-0.8);
	    if (y < d) {
		hist1.fill(x);
		hist2.fill(x);
		hist2d.fill(x,y);
		tup.fill(0,x);
		tup.fill(1,y);
		tup.addRow();
	    }
        }

	// Do Chi-2 Fitting
	double[] chi2 = new double[] { 300, 0.5, 1 };
	f1.setParameters(chi2);
	f2.setParameters(chi2);


	//System.out.println(" parameters: "+f1.parameter("a")+"  "+f1.parameter("b")+"  "+f1.parameter("c")+"  "+f1.parameter("d"));
	//System.out.println(" parameters: "+f1.parameter("a")+"  "+f1.parameter("c")+"  "+f1.parameter("d"));

	double[] var = new double[1];
	for (int i=-5; i<5; i++) {
	    var[0] = i*1.;
	    
	    double d = f1.value(var);
	    //System.out.println(i +"\t" + d);
	}

	plotter.currentRegion().plot(hist1);
	plotter.currentRegion().plot(f1);
	plotter.currentRegion().plot(f1);

        hep.aida.ref.fitter.Fitter fitter = new hep.aida.ref.fitter.Fitter("Chi2","minuit",null);
        fitter.fit(hist1,f2);

	plotter.next();
	plotter.currentRegion().plot(hist1);
	//plotter.currentRegion().plot(f1);
	plotter.currentRegion().plot(f2);

	plotter.show();

    }   
}
