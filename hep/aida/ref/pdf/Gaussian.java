package hep.aida.ref.pdf;

import cern.colt.function.DoubleFunction;
import cern.jet.math.Functions;

/**
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
public class Gaussian extends Function{
    
    private Dependent x;
    private Parameter m;
    private Parameter s;
    
    private final double r2 = Math.sqrt(2);
    private final double rootPiOverTwo = Math.sqrt( Math.PI/2 );
    
    private double twoSigmaSquared;
    private double mean;
    private double sigma;
    private double xVal;
    
    private static DoubleFunction erf = Functions.erf;
    
    public Gaussian(String name) {
        this(name, null, null, null);
    }

    public Gaussian(String name, Dependent x) {
        this(name, x, null, null);
    }

    public Gaussian(String name, Dependent x, Parameter mean, Parameter sigma) {
        super(name);
        this.x = x;
        this.m = mean;
        this.s = sigma;
        initializeVariables();
    }
    
    
    private void initializeVariables() {
        if ( x == null )
            x = new Dependent("x", -10, 10);
        if ( m == null )
            m = new Parameter("mean");
        if ( s == null )
            s = new Parameter("sigma");
        VariableList list = new VariableList();
        list.add(x);
        list.add(m);
        list.add(s);
        addVariables(list);
    }
    
    public void variableChanged(Variable var) {
        if ( var == m )
            mean = m.value();
        else if ( var == s ) {
            sigma = s.value();
            twoSigmaSquared = 2*Math.pow( sigma, 2 );
        }
        else if ( var == x )
            xVal = x.value();
    }
    
    public double functionMaxValue() {
        return 1;
    }

    public double functionValue() {
        return Math.exp( -Math.pow( xVal - mean, 2 )/twoSigmaSquared );
    }

    public double evaluateAnalyticalVariableGradient(Variable var) {
        double y = functionValue();
        if ( var == x )
            return y*(-2.)*(xVal - mean)/twoSigmaSquared;
        else if ( var == m )
            return y*2.*(xVal - mean)/(twoSigmaSquared);
        else if( var == s )
            return y*2.*Math.pow(xVal - mean,2)/(twoSigmaSquared*sigma);
        return 0;
    }

    public boolean hasAnalyticalVariableGradient(Variable var) {
        return true;
    }

    public boolean hasAnalyticalNormalization(Dependent dep) {
        if ( dep == x )
            return true;
        return false;
    }
    
    public double evaluateAnalyticalNormalization(Dependent dep) {
        double[] xMax = x.range().upperBounds();
        double[] xMin = x.range().lowerBounds();
        if ( xMax.length != 1 || xMin.length != 1 )
            throw new IllegalArgumentException("Normalization over multiple ranges is not supported for Function Gaussian.");
        double den = r2*sigma;
        double ue = erf.apply((xMax[0]-mean)/den);
        double le = erf.apply((xMin[0]-mean)/den);
        return rootPiOverTwo*sigma*(ue-le);
    }
}
