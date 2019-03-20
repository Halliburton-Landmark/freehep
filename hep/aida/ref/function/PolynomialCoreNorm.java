/*
 * PolynomialCoreNorm.java
 *
 * Created on September 5, 2002, 1:40 PM
 */

package hep.aida.ref.function;
import java.util.*;
import hep.aida.*;
import hep.aida.ref.*;
import hep.aida.ref.fitter.*;
import hep.aida.ref.fitter.fitData.*;
import hep.aida.ref.fitter.fitMethod.*;



/**
 *
 * @author  serbo
 */

/**
 * Normalised Polynomial (Pn) distribution in the form:
 *    f = (1 + p1*x + p2*x*x + ... )/N  , has n-1 paremeters
 *    Normalization N is calculated by the "normalizationAmplitude" method
 */
public class PolynomialCoreNorm extends PolynomialCoreNotNorm {

    public PolynomialCoreNorm(String str) {
	super(1, getDimension(str)-1);
	setTitle("PolynomialCoreNorm::"+str);
	providesNormalization = true;
	String[] pNames = new String[numberOfParameters];
	for (int i=0; i<numberOfParameters; i++) { pNames[i] = "p" + (i+1); }
	setParameterNames(pNames);
    }

    public PolynomialCoreNorm(String str, double[] pVal) {
	super(1, getDimension(str)-1, pVal);
	setTitle("PolynomialCoreNorm::"+str);
	providesNormalization = true;
	String[] pNames = new String[numberOfParameters];
	for (int i=0; i<numberOfParameters; i++) { pNames[i] = "p" + (i+1); }
	setParameterNames(pNames);
    }

    // Value of the function WITHOUT Normalization factor (as if N=1)
    public double functionValue(double[] var) {
	double val = 0;
	for (int i=0; i<numberOfParameters; i++) { val += p[i]*Math.pow(var[0], i+1); }
	val +=1.;
	return val;
    }

    public double[] gradient(double[] var)  {
	double[] tmp = new double[] {0.};
	if (numberOfParameters == 0) return tmp;
	double val = p[0];
	for (int i=1; i<numberOfParameters; i++) { val += i*p[i]*Math.pow(var[0], i); }
	tmp[0] = val;
	return tmp;
    }

    public double[] parameterGradient(double[] var) { 
	double[] tmp = new double[numberOfParameters];
        tmp[0] = 1;
	for (int i=1; i<numberOfParameters; i++) {tmp[i] = Math.pow(var[0], i); } 
	return tmp;
    }


    public double normalizationAmplitude(double[] xMin, double[] xMax) {
	double val = 0;
	val += (xMax[0]-xMin[0]);
	for (int i=0; i<numberOfParameters; i++) {
	    val += (p[i]/(i+2))*(Math.pow(xMax[0], i+2) - Math.pow(xMin[0], i+2));
//	    System.out.println("   i="+i+" \t  val="+val+"\t xMin="+xMin[0]+"\t xMax="+xMax[0]+"\t par="+p[i]);
	}
	return val;
    }


    // Check fitting with this function
    public static void main(String[] args) throws java.io.IOException {

        IAnalysisFactory af = IAnalysisFactory.create();        //jas.aida.gui.JASGUIAnalysisFactory.create();       
        ITree tree = af.createTreeFactory().create();
        IHistogramFactory hf = af.createHistogramFactory( tree );
        ITupleFactory tf = af.createTupleFactory( tree );
        IFunctionFactory ff = af.createFunctionFactory( tree );
        IPlotterFactory pf = af.createPlotterFactory(  );

	IPlotter plotter = pf.create("JAS Plotter");
	plotter.createRegions(2, 2);
        
	IModelFunction f1 = (IModelFunction) ff.createFunctionByName("f1","p2");
	IModelFunction f2 = (IModelFunction) ff.createFunctionByName("f2","p2");
	IModelFunction f3 = (IModelFunction) ff.createFunctionByName("f3","p2");
	IModelFunction f4 = (IModelFunction) ff.createFunctionByName("f4","p2");

        hep.aida.IHistogram1D hist1 = hf.createHistogram1D("hist1","hist1",100,-5,5);
        hep.aida.IHistogram1D hist2 = hf.createHistogram1D("hist2","hist2",100,-5,5);
        hep.aida.IHistogram2D hist2d = hf.createHistogram2D("hist2d","hist2d",100,-5,5,10,-10,0);
        java.util.Random r = new java.util.Random();
        
        ITuple tup = tf.create("tup","tup","double x0, double y");
        
        for ( int i = 0; i < 20000; i++ ) {
            double x = 10.*(r.nextDouble()-0.5);
            double y = r.nextDouble()*60;
	    double d = x*x - 4.0*x + 25;
	    if (y < d) {
		hist1.fill(x);
		hist2d.fill(x,y);
		tup.fill(0,x);
		tup.fill(1,y);
		tup.addRow();
	    }
        }
                

	// Do Chi-2 Fitting
	double[] chi2 = new double[] { 180, 0.1, -20 };
	f1.setParameters(chi2);
	f2.setParameters(chi2);
	f2.normalize(false);

        Fitter fitter = new Fitter("Chi2","minuit",null);
        //fitter.fit(hist1,f2);
        fitter.fit(hist1,"p2");

	plotter.currentRegion().plot(hist1);
	plotter.currentRegion().plot(f1);

	plotter.next();
	plotter.currentRegion().plot(hist1);
	plotter.currentRegion().plot(f2);
	

	// Do ML fitting
	for (int i=0; i<1; i++) hist2.fill(0.1);
	f3.normalize(true);
	f4.normalize(true);

	f3.excludeNormalizationAll();
	f3.normalizationRange(0).include(-5., 5.);
	f4.excludeNormalizationAll();
	f4.normalizationRange(0).include(-5., 5.);

	double[] ml = new double[] { 0.1, 2 };
	f3.setParameters(ml);
	f4.setParameters(ml);

	//for (int i=-5; i<6; i++) System.out.println(i+"\t "+f3.value(new double[] { i*1. }) );
	System.out.println("Variable names: "+f4.variableName(0) );

        IEvaluator[] ev = null;
        FitData fd = new FitData();

        Fitter fitter2 = new Fitter("uml","minuit",null);
        //fitter.setFitMethod("uml");
        fitter2.fitParameterSettings("p0").setStepSize(0.1);
        fitter2.fitParameterSettings("p1").setStepSize(0.1);
        fitter2.fitParameterSettings("p2").setStepSize(0.1);
//        String[] colNames = {"x0","y"};
        String[] colNames = {"x0"};
        fd.createConnection(tup,colNames);
        fitter2.fit(fd,f4);

	plotter.next();
	plotter.currentRegion().plot(hist2);
	plotter.currentRegion().plot(f3);

	plotter.next();
	plotter.currentRegion().plot(hist2);
	plotter.currentRegion().plot(f4);

	plotter.show();
    }

}
