/*
 * PolynomialModelFunction.java
 *
 * Created on September 3, 2002, 4:07 AM
 */

package hep.aida.ref.function;
import java.util.*;
import hep.aida.*;
import hep.aida.ref.*;
import hep.aida.ref.fitter.*;
import hep.aida.dev.*;

//import jas.aida.*;
//import jas.aida.gui.*;

/**
 *
 * @author  serbo
 */
public class PolynomialModelFunction extends AbstractDevModelFunction {

    public PolynomialModelFunction(String str) {
	super();

	if(!str.toLowerCase().startsWith("p"))
	    throw new IllegalArgumentException("PolynomialModelFunction Function Qualifier must start with \"P\"");
	int dim = Integer.parseInt(str.substring(1));
	setDimension(1);
	setNumberOfParameters(dim+1);

	setCodeletString("PolynomialModelFunction of power " + dim);
	setTitle(str);
    }

    public int dimension() { return dimension; }

    public int numberOfParameters() { return p.length; }

    public double functionValue(double[] var) {
	double val = 0;
	for (int i=1; i<numberOfParameters(); i++) { val += p[i]*Math.pow(var[0], i); }
	return val+p[0];
    }



    public static void main(String[] args) throws java.io.IOException {
//        IAnalysisFactory af = new JASGUIAnalysisFactory();
        IAnalysisFactory af = IAnalysisFactory.create();
        ITree tree = af.createTreeFactory().create();
        IHistogramFactory hf = af.createHistogramFactory( tree );
        IFunctionFactory  ff = af.createFunctionFactory( tree );
        IPlotterFactory   pf = af.createPlotterFactory( );
	IPlotter plotter = pf.create("JAS Plotter");
	plotter.createRegions(2, 2);

        hep.aida.IHistogram1D hist1 = hf.createHistogram1D("hist1","hist1",100,-5,5);
        hep.aida.IHistogram1D hist2 = hf.createHistogram1D("hist2","hist2",100,-5,5);
        java.util.Random r = new java.util.Random();

        for ( int i = 0; i < 40000; i++ ) {
	    double x = 10.*(r.nextDouble() - 0.5);
	    double poly  = x*x - 4*x + 5.5;
	    double y = r.nextDouble()*50.5;

	    if (poly >= y) { hist1.fill(x); hist2.fill(x); }
	}

	IModelFunction f1 = (IModelFunction) ff.createFunctionByName("f1","p2");
	IModelFunction f2 = (IModelFunction) ff.createFunctionByName("f2","p2");
	IModelFunction f3 = (IModelFunction) ff.createFunctionByName("f3","p2");
	IModelFunction f4 = (IModelFunction) ff.createFunctionByName("f4","p2");

	double[] chi2Pars = new double[] {380, 0.1, -20.0};

	f1.setParameters(chi2Pars);
	f2.setParameters(chi2Pars);

	for (int i=-5; i<10; i++) {
	    System.out.println("x =\t" + i + "  \tf = " + f1.value(new double[] { i*1. }) +
			       "  \tgrad = " + (f1.gradient(new double[] { i*1. }))[0] +
			       "  \tparGrad = " + (f1.parameterGradient(new double[] { i*1. }))[0] +
			       "   " + (f1.parameterGradient(new double[] { i*1. }))[1] +
			       "   " + (f1.parameterGradient(new double[] { i*1. }))[2] );
	}

	// Do Chi-2 fit
	plotter.currentRegion().plot(hist1);
	plotter.currentRegion().plot(f1);


        Fitter fitter = new Fitter("chi2","minuit",null);
        fitter.fitParameterSettings("p0").setStepSize(10.);
        fitter.fitParameterSettings("p1").setStepSize(1.);
        fitter.fitParameterSettings("p2").setStepSize(5.);

        fitter.fit(hist1,f2);


	plotter.next();
	plotter.currentRegion().plot(hist1);
	plotter.currentRegion().plot(f2);


// Do ML fit
	f3.normalize(true);
	f4.normalize(true);

	double[] MLPars = new double[] {0.1, -20.0};
	f3.setParameters(MLPars);
	f4.setParameters(MLPars);

	for (int i=-5; i<10; i++) {
	    System.out.println("x =\t" + i + "  \tf = " + f3.value(new double[] { i*1. }) +
			       "  \tgrad = " + (f3.gradient(new double[] { i*1. }))[0] +
			       "  \tparGrad = " + (f3.parameterGradient(new double[] { i*1. }))[0] +
			       "   " + (f3.parameterGradient(new double[] { i*1. }))[1] +
			       "   " + (f3.parameterGradient(new double[] { i*1. }))[2] );
	}
	plotter.next();
	plotter.currentRegion().plot(hist2);
	plotter.currentRegion().plot(f3);

	plotter.next();
	plotter.currentRegion().plot(hist2);
	plotter.currentRegion().plot(f4);

	plotter.show();

    }
}
