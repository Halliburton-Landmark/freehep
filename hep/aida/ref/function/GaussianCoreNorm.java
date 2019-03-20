/*
 *ExponentialCoreNorm .java
 *
 * Created on October 5, 2002, 1:41 PM
 */

package hep.aida.ref.function;
import java.util.*;
import hep.aida.*;
import hep.aida.ref.*;
import hep.aida.ref.fitter.*;
import hep.aida.ref.fitter.fitData.*;


/**
 *
 * @author  serbo
 */

/**
 * Not normalised Gaussian (G) distribution in the form:
 *    f = (1/N)*exp(-(x-mean)^2/(2*sigma^2))  has 2 parameters
 * Normalization Amplitude is calculated by the "normalizationAmplitude" method
 */
public class GaussianCoreNorm extends FunctionCore {

    protected boolean providesNormalization;
    protected final double r2 = Math.sqrt(2);

    public GaussianCoreNorm(String str) {
	super(1, 2, new double[] {0., 1.});
	setTitle("GaussianCoreNorm::"+str);
	providesNormalization = true;

	String[] names = new String[] { "mean", "sigma" };
	setParameterNames(names);
    }

    public GaussianCoreNorm(String str, double[] pVal) {
	super(1, 2, pVal);
	setTitle("GaussianCoreNorm::"+str);
	providesNormalization = true;

	String[] names = new String[] { "mean", "sigma" };
	setParameterNames(names);
    }

    // Value of the function WITHOUT Normalization factor (as if N=1)
    public double functionValue(double[] var) {
	return Math.exp( -Math.pow( var[0] - p[0], 2 )/(2*Math.pow( p[1], 2 )) );
    }

    // Each concrete FunctionCore has to implement those methods that deal with Gradients and Normalization
    public boolean providesGradient() { return true; }

    public double[] gradient(double[] var)  {
	return new double[] { functionValue(var)*(-2.)*(var[0] - p[0])/(2*Math.pow( p[1], 2 )) };
    }

    public boolean providesParameterGradient() { return true; }

    public double[] parameterGradient(double[] var) {
	double y = functionValue(var);
	return new double[] {  y*2.*(var[0] - p[0])/(2*Math.pow( p[1], 2 )),
			       y*2.*Math.pow(var[0] - p[0],2)/(2*Math.pow( Math.abs(p[1]), 3 )) };
    }

    public boolean providesNormalization() { return providesNormalization; }

    public double normalizationAmplitude(double[] xMin, double[] xMax) {
	return Math.sqrt( Math.PI/2 )*p[1]*(erf( (xMax[0]-p[0])/(r2*p[1]) ) - erf( (xMin[0]-p[0])/(r2*p[1]) ) );
    }

    /* For Gaussian normalization calculations */
    private double erf(double d) {
        double d1 = (0.0D / 0.0D);
        double d2 = Math.abs(d);
        if(d2 <= 1.0D) {
            if(d2 <= erf_sqeps)
                d1 = (2D * d) / 1.7724538509055161D;
            else
                d1 = d * (1.0D + csevl(2D * d * d - 1.0D, erfc_coef));
        } else
            if(d2 <= erf_xbig)
                d1 = sign(1.0D - erfc(d2), d);
            else
                d1 = sign(1.0D, d);
        return d1;
    }


    private double erfc(double d) {
        double d1 = (0.0D / 0.0D);
        if(d <= erfc_xsml)
            d1 = 2D;
        else
            if(d <= erfc_xmax) {
                double d2 = Math.abs(d);
                if(d2 <= 1.0D) {
                    if(d2 < erf_sqeps)
                        d1 = 1.0D - (2D * d) / 1.7724538509055161D;
                    else
                        d1 = 1.0D - d * (1.0D + csevl(2D * d * d - 1.0D, erfc_coef));
                } else {
                    d2 *= d2;
                    if(d2 <= 4D)
                        d1 = (Math.exp(-d2) / Math.abs(d)) * (0.5D + csevl((8D / d2 - 5D) / 3D, erfc2_coef));
                    else
                        d1 = (Math.exp(-d2) / Math.abs(d)) * (0.5D + csevl(8D / d2 - 1.0D, erfcc_coef));
                    if(d < 0.0D)
                        d1 = 2D - d1;
                }
            } else {
                d1 = 0.0D;
            }
        return d1;
    }

    private double csevl(double d, double ad[]) {
        int i = ad.length;
        double d2 = 0.0D;
        double d1 = 0.0D;
        double d3 = 0.0D;
        double d4 = 2D * d;
        for(int j = i - 1; j >= 0; j--) {
            d3 = d2;
            d2 = d1;
            d1 = (d4 * d2 - d3) + ad[j];
        }

        return 0.5D * (d1 - d3);
    }
    public static double sign(double d, double d1) {
        double d2 = d >= 0.0D ? d : -d;
        return d1 >= 0.0D ? d2 : -d2;
    }

    private final double erfc_coef[] = {
        -0.049046121234691806D, -0.14226120510371365D, 0.010035582187599796D, -0.00057687646997674853D,
	2.741993125219606E-005D, -1.1043175507344507E-006D, 3.8488755420345036E-008D, -1.1808582533875466E-009D,
	3.2334215826050907E-011D, -7.9910159470045487E-013D,
        1.7990725113961456E-014D, -3.7186354878186928E-016D, 7.1035990037142532E-018D
    };
    private final double erfc2_coef[] = {
        -0.069601346602309502D, -0.041101339362620892D, 0.0039144958666896268D, 
	-0.00049063956505489791D, 7.1574790013770361E-005D, -1.1530716341312328E-005D, 
	1.9946705902019974E-006D, -3.6426664715992229E-007D, 6.9443726100050124E-008D, 
	-1.3712209021043659E-008D, 2.7883896610071373E-009D, -5.8141647243311614E-010D, 
	1.2389204917527532E-010D, -2.6906391453067435E-011D, 5.9426143508479114E-012D,
	-1.3323867357581197E-012D, 3.0280468061771323E-013D, -6.9666488149410327E-014D, 
	1.620854541053923E-014D, -3.8099344652504917E-015D, 9.0404878159788311E-016D, 
	-2.1640061950896072E-016D, 5.2221022339958551E-017D, -1.2697296023645554E-017D, 
	3.1091455042761977E-018D
    };
    private final double erfcc_coef[] = {
        0.071517931020292483D, -0.026532434337606717D, 0.0017111539779208558D, 
	-0.00016375166345851787D, 1.9871293500552038E-005D, -2.8437124127665552E-006D, 
	4.6061613089631305E-007D, -8.227753025879209E-008D, 1.5921418727709012E-008D, 
	-3.2950713622528431E-009D, 7.2234397604005558E-010D, -1.6648558133987297E-010D, 
	4.0103925882376649E-011D, -1.0048162144257311E-011D, 2.6082759133003339E-012D,
	-6.9911105604040245E-013D, 1.9294923332617072E-013D, -5.4701311887543309E-014D, 
	1.5896633097626975E-014D, -4.7268939801975551E-015D, 1.4358733767849847E-015D,
	-4.4495105618173579E-016D, 1.4048108847682335E-016D, -4.5138183877642106E-017D,
	1.4745215410451331E-017D, -4.8926214069457765E-018D, 1.6476121414106467E-018D, 
	-5.6268171763294081E-019D, 1.9474433822320786E-019D
    };
    private final double erf_xbig = Math.sqrt(-Math.log(1.9678190753608168E-016D));
    private final double erf_sqeps = Math.sqrt(2.2204460492503E-016D);
    private final double erfc_xsml = -Math.sqrt(-Math.log(1.9678190753608168E-016D));
    private double erfc_xmax;



    // Check fitting with this function
    public static void main(String[] args) throws java.io.IOException {

        IAnalysisFactory af = IAnalysisFactory.create();     //jas.aida.gui.JASGUIAnalysisFactory.create(); 
        ITree tree = af.createTreeFactory().create();
        IHistogramFactory hf = af.createHistogramFactory( tree );
        ITupleFactory tf = af.createTupleFactory( tree );
        IFunctionFactory ff = af.createFunctionFactory( tree );
        IPlotterFactory pf = af.createPlotterFactory(  );

	IPlotter plotter = pf.create("JAS Plotter");
	plotter.createRegions(1, 2);
        
	IModelFunction f1 = (IModelFunction) ff.createFunctionByName("f1","g");
	IModelFunction f2 = (IModelFunction) ff.createFunctionByName("f2","G");
	IModelFunction f3 = (IModelFunction) ff.createFunctionByName("f3","g");
	IModelFunction f4 = (IModelFunction) ff.createFunctionByName("f4","G");

        hep.aida.IHistogram1D hist1 = hf.createHistogram1D("hist1","hist1",100,-5,5);
        hep.aida.IHistogram1D hist2 = hf.createHistogram1D("hist2","hist2",100,-5,5);
        hep.aida.IHistogram2D hist2d = hf.createHistogram2D("hist2d","hist2d",100,-5,5,10,-10,0);
        java.util.Random r = new java.util.Random();
        
        ITuple tup = tf.create("tup","tup","double x0, double y");
        
	
        for ( int i = 0; i < 50000; i++ ) {
            double x = 10.*(r.nextDouble()-0.5);
            double y = r.nextDouble();
	    double d = Math.exp(-(x+0.7)*(x+0.7)/8.);
	    if (y < d) {
		hist1.fill(x);
		//hist2.fill(x);
		hist2d.fill(x,y);
		tup.fill(0,x);
		tup.fill(1,y);
		tup.addRow();
	    }
        }
	//hist2.scale(1./hist2.sumBinHeights());    
	

	// Do Chi-2 Fitting
	//f1.normalize(false);
	//f2.normalize(false);
	double[] chi2 = new double[] { 500., 0.5, 0.5 };
	f1.setParameters(chi2);
	f2.setParameters(chi2);

        Fitter fitter = new Fitter("Chi2","minuit",null);
        IFitResult fr = fitter.fit(hist1,f2);
        //fitter.fit(hist1,"G");

	plotter.currentRegion().plot(hist1);
	plotter.currentRegion().plot(f1);
	plotter.currentRegion().plot(fr.fittedFunction());

	// Do ML fitting
	//for (int i=0; i<1; i++) hist2.fill(0.1);
	f3.normalize(true);
	f4.normalize(true);

	double[] ml = new double[] { -1., 3 };
	f3.setParameters(ml);
	f4.setParameters(ml);

	//for (int i=-5; i<6; i++) System.out.println(i+"\t "+f3.value(new double[] { i*1. }) );
	System.out.println("Variable names: "+f4.variableName(0) );

        IEvaluator[] ev = null;
        FitData fd = new FitData();

        Fitter fitter2 = new Fitter("uml","minuit",null);
        //fitter.setFitMethod("uml");
        //fitter2.fitParameterSettings("mean").setStepSize(0.1);
        //fitter2.fitParameterSettings("sigma").setStepSize(0.1);
        String[] colNames = {"x0"};
        fd.createConnection(tup,colNames);

	fd.range(0).excludeAll();
	fd.range(0).include(-5., 5.);

        IFitResult ml_fr = fitter2.fit(fd,f3);

	plotter.next();
	plotter.currentRegion().plot(hist2);
	plotter.currentRegion().plot(f3);
	plotter.currentRegion().plot(ml_fr.fittedFunction());

	plotter.show();

    }
}
