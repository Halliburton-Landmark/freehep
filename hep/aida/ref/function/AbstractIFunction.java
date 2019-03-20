/*
 * AbstractIFunction.java
 *
 * Created on February 18, 2004, 12:02 PM
 */
package hep.aida.ref.function;

import hep.aida.*;
import hep.aida.ref.Annotation;
import hep.aida.ref.function.FunctionDispatcher;
import hep.aida.ref.function.FunctionListener;
import java.util.ArrayList;


/**
 * AbstractIFunction is implementation of the IFunction.
 * User has to implement "value" method.  
 * @author  serbo
 */
public abstract class AbstractIFunction  implements IModelFunction, FunctionDispatcher {
    

    protected String[] variableNames;
    protected String[] parameterNames;
    protected String codeletString; 
    
    private Annotation annotation;
    private int dimension;
    private int numberOfParameters;
    private ArrayList listeners = new ArrayList();
    
    private RangeSet[] rangeSet;

    protected double[] p;
    protected double[] gradient;
    
    /** Creates a new instance of AbstractIFunction 
     *  with default variable names (x0, x1, ...) 
     *  and default parameter names (p0, p1, ...)
     */
    public AbstractIFunction(String title, int dimension, int numberOfParameters) {   
        variableNames = new String[dimension];
        for (int i=0; i<dimension; i++) { variableNames[i] = "x"+i; }
        
        parameterNames = new String[numberOfParameters];
        for (int i=0; i<numberOfParameters; i++) { parameterNames[i] = "p"+i; }

        init(title);
    }
    
    /** Creates a new instance of AbstractIFunction 
     *  with specified variable and parameter names
     */
    public AbstractIFunction(String title, String[] variableNames, String[] parameterNames) {   
        this.variableNames = variableNames;
        this.parameterNames = parameterNames;

        init(title);        
    }
    
    
    // Service methods
    
    protected void init(String title) {
        dimension = variableNames.length;
        numberOfParameters = parameterNames.length;
        p = new double[numberOfParameters];
        gradient = new double[dimension];
        
        rangeSet = new RangeSet[dimension()];
        for (int i=0; i<dimension(); i++)
            rangeSet[i] = new RangeSet();

        codeletString = "codelet:hep.aida.ref.function.AbstractIFunction:file:";
        
        if (title == null) title = "";
        annotation = new Annotation();
        annotation.addItem(Annotation.titleKey, title);
        annotation.setFillable(true);
     }
    
    public void setCodeletString(String str) { codeletString = str; }
    
    // IFunction methods
    
    /** Provide value for your function here. Something like:
     *  return p[0]*v[0]*v[0]+p[1]*v[0]+p[3]; 
     */
    public abstract double value(double[] v);
    
    
    public boolean providesGradient() {
        return false;
    }
    
    public double[] gradient(double[] values) {
        return gradient;
    }
    
    public String codeletString() {
        return codeletString;
    }
    
    public hep.aida.IAnnotation annotation() {
        return annotation;
    }
    
    public int dimension() {
        return dimension;
    }
    
    public int indexOfParameter(String str) {
        int index = -1;
        for (int i=0; i<numberOfParameters; i++) {
            if (str.equals(parameterNames[i])) {
                index = i;
                break;
            }
        }        
        return index;
    }
    
    public int numberOfParameters() {
        return numberOfParameters;
    }
    
    public double parameter(String str) {
        int index = indexOfParameter(str);
        if (index == -1) throw new IllegalArgumentException("Parameter \""+str+"\" does not exist");
        return p[index];
    }
    
    public String[] parameterNames() {
        return parameterNames;
    }
    
    public double[] parameters() {
        return p;
    }
    
    public void setParameter(String str, double param) throws java.lang.IllegalArgumentException {
        int index = indexOfParameter(str);
        if (index == -1) throw new IllegalArgumentException("Parameter \""+str+"\" does not exist");
        p[index] = param;
        notifyFunctionChanged(new FunctionChangedEvent( FunctionChangedEvent.PARAMETER_VALUE_CHANGED ) );
    }
    
    public void setParameters(double[] pars) throws java.lang.IllegalArgumentException {        
        if (pars.length != numberOfParameters) 
            throw new IllegalArgumentException("Wrong number of input parameters:"+pars.length+", must be "+numberOfParameters);
        for (int i=0; i<numberOfParameters; i++) p[i] = pars[i];
        notifyFunctionChanged(new FunctionChangedEvent( FunctionChangedEvent.PARAMETER_VALUE_CHANGED ) );
    }
    
    public void setTitle(String title) throws java.lang.IllegalArgumentException {
        annotation.setValue(Annotation.titleKey, title);
        notifyFunctionChanged(new FunctionChangedEvent( FunctionChangedEvent.TITLE_CHANGED ) );
    }
    
    public String title() {
        return annotation.value(Annotation.titleKey);
    }
    
    public String variableName(int index) {
        return variableNames[index];
    }
    
    public String[] variableNames() {
         return variableNames;
    }
    
    public void excludeNormalizationAll() {
        for (int i=0; i<dimension(); i++) rangeSet[i].excludeAll();
        notifyFunctionChanged(new FunctionChangedEvent( FunctionChangedEvent.RANGE_CHANGED ) );
    }
    
    public void includeNormalizationAll() {
        for (int i=0; i<dimension(); i++) rangeSet[i].includeAll();
        notifyFunctionChanged(new FunctionChangedEvent( FunctionChangedEvent.RANGE_CHANGED ) );
    }
    
    public boolean isNormalized() {
        return false;
    }
    
    public IRangeSet normalizationRange(int iAxis) { 
        return rangeSet[iAxis]; 
    }
    
    public void normalize(boolean param) {
    }
    
    public double[] parameterGradient(double[] values) {
        return null;
    }
    
    public boolean providesNormalization() {
        return false;
    }
    
    public boolean providesParameterGradient() {
        return false;
    }
    
    public String normalizationParameter() {
        throw new UnsupportedOperationException("This method needs to be overwritten to perform unbinned fits");        
    }
    
    
    public boolean isEqual(hep.aida.IFunction iFunction) {
	throw new UnsupportedOperationException("Not implemented");
    }
    

    
    // Example: simple way of using AbstractIFunction
    // Users can also extend 
    // IFunction class for more complex cases
    public static void main(String[] args) {
      IAnalysisFactory af = IAnalysisFactory.create();
      ITree tree = af.createTreeFactory().create();
      IHistogramFactory hf = af.createHistogramFactory(tree);
      IFitFactory fitFactory = af.createFitFactory();
      
      tree.mkdir("/Histograms");
      tree.cd("/Histograms");

      // Create and fill histogram
      IHistogram1D h1 = hf.createHistogram1D("Histogram-1",50,-3,3);
      java.util.Random r = new java.util.Random();
      for (int i = 0; i < 1000; i++ ) {
          double x = r.nextGaussian()*2. + 1.;
          h1.fill(x);
      }
      
      // Creaete function
      AbstractIFunction f1 = new AbstractIFunction("Parabola", 1, 3) {
            public double value(double[] v) { return p[0]*v[0]*v[0]+p[1]*v[0]+p[2]; }
      };
      f1.setParameters(new double[] {-3., -2., 30. } );
      
      
      // Do fit
      //IFitter fitter = fitFactory.createFitter("Chi2","minuit", "noClone=\"false\"");
      IFitter fitter = fitFactory.createFitter("Chi2","uncmin", "noClone=\"true\"");

      IFitResult fitResult = fitter.fit(h1, f1);

      // Create histogram and fill it with random numbers according to the f2 distribution
      IHistogram1D h2 = hf.createHistogram1D("Histogram-2",50,-3,3);
      AbstractIFunction f2 = new AbstractIFunction("Parabola", 1, 3) {
            public double value(double[] v) { return p[0]*v[0]*v[0]+p[1]*v[0]+p[2]; }
      };
      f2.setParameters(new double[] {1., -4., 4. } );
      FunctionUtils.fill(h2, f2, 10000, 20.);
      
      
      // Plotting results
      IPlotter plotter = af.createPlotterFactory().create("Test Fit plot");

      plotter.show();
      plotter.createRegions(1,2);

      plotter.region(0).plot(h1);
      plotter.region(0).plot(fitResult.fittedFunction());
      plotter.region(1).plot(h2);
      System.out.println("Chi2="+fitResult.quality());     

    }
    
    public void addFunctionListener( FunctionListener listener ) {
        listeners.add(listener);
    }
    
    public void removeFunctionListener( FunctionListener listener ) {
        listeners.remove(listener);
    }

    void notifyFunctionChanged(FunctionChangedEvent event) {
        for ( int i = 0; i < listeners.size(); i++ )
            ( (FunctionListener) listeners.get(i) ).functionChanged(event);
    }    
    
}
