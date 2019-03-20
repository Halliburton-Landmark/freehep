/*
 * MinuitCommands.java
 *
 * Created on May 23, 2002, 1:48 PM
 */

package hep.aida.ref.optimizer.minuit;

import hep.aida.ref.*;
import hep.aida.*;
import hep.aida.ext.*;
import java.util.ArrayList;

/**
 *
 *  Minuit commands.
 *
 * @author Tony Johnson, Victor Serbo, Max Turri
 *
 */
public class MinuitCommands {
    
    private static IFunction function = null;
    private String[] variableNames;
    
    private MinuitOptimizer theOptimizer;
    
    private int[] parInfo = new int[2];
    private double[] minInfo = new double[3];
    private double[] arglist = new double[100];
    private ArrayList varList = new ArrayList();
    
    /**
     * The possible status of the covariance matrix
     *
     */
    protected static final int MATRIX_NOT_CALCULATED  = 0;
    protected static final int MATRIX_DIAGONAL_APPROX = 1;
    protected static final int MATRIX_FULL_FORCED_POS = 2;
    protected static final int MATRIX_FULL_ACCURATE   = 3;
    
    /**
     * The printout levels for the minimizer output are the following:
     *
     */
    protected static final int NO_OUTPUT       = -1;
    protected static final int MINIMAL_OUTPUT  = 0;
    protected static final int NORMAL_OUTPUT   = 1;
    protected static final int DETAILED_OUTPUT = 2;
    protected static final int MAXIMAL_OUTPUT  = 3;
    
    /**
     * The different types of minimization.
     *
     */
    protected static final int SIMPLEX_MIN  = 0;
    protected static final int MIGRAD_MIN   = 1;
    protected static final int MINIMIZE_MIN = 2;
    
    private static boolean isLibLoaded = false;
    private boolean isInitialized = false;
    
    /**
     * Initialize minuit.
     * @param inputUnit  Unit number for input to Minuit (default 5)
     * @param outputUnit Unit number for output from Minuit (default 6)
     * @param saveUnit   Unit number to be used for SAVE command (default 7)
     *
     */
    protected static native void jmninit(int inputUnit, int outputUnit, int saveUnit);
    
    /**
     * Set the title of the minimization session.
     * The title maximum length is 50 characters.
     * @param title The title.
     *
     */
    protected static native void jmnseti(String title);
    
    /**
     * Define a new fit parameter.
     * @param parNum   The parameter number (+1) as referenced by the IFunction to be
     *                 minimized.
     * @param parName  The parameter's name. (maximum 10 characters).
     * @param parValue The parameter's starting value.
     * @param stepSize Starting step size or approximate error.
     * @param minValue The parameter's lower limit.
     * @param maxValue The parameter's upper limit. If the upper and the lower limits are set to 0,
     *                 the parameter is considered unbounded.
     * @return Error code. 0 if no error, > 0 if request failed.
     *
     */
    protected static native int  jmnparm(int parNum, String parName, double parValue, double stepSize, double minValue, double maxValue);
    
    /**
     * Execute a Minuit command, the command is executed on the current function.
     * @param command The Minuit command to be executed.
     * @param argList Array containing the numeric arguments to the command.
     * @param nArg    The number of arguments specified.
     * @return Error code. 0 if no error, > 0 otherwise.
     *
     */
    protected static native int  jmnexcm(String command, double[] argList, int nArg);
    
    /**
     * Get the current value of a parameter.
     * @param parNum  The parameter's number (+1) as referenced in the function to be minimized.
     * @param parName The parameter's name (it is a one dimensional array);
     * @param parVals The parameter's values. This array contains four entries: the
     *                current value of the parameter, the current error on the parameter,
     *                the parameter's lower and upper bound (both 0 if parameter is unbounded).
     * @return Internal parameter's number (as used by the fit); 0 if parameter is a constant,
     *         a negative number if parameter is not defined.
     *
     */
    protected static native int  jmnpout(int parNum, String[] parName, double[] parVals);
    
    /**
     * Get the current status of minimization.
     * @param vals The values of the minimization. This array contains the following three
     *             entries: the current best value of the function, the estimated vertical distance
     *             to the minimum, the value of UP defining the errors.
     * @param pars The parameters information. This array contains the following two entries:
     *             the number of variables in the fit, the highest parameter number (as seen
     *             by the function to be minimized).
     * @return The status of the fit telling at what stage the covariance matrix is:
     *         0 not calculated, 1 diagonal approximation, 2 full matrix but forced positive-definite,
     *         3 full accurate matrix.
     *
     */
    protected static native int  jmnstat(double[] vals, int[] pars);
    
    /**
     * Get the covariance matrix.
     * @param errorMatrix The error matrix. It is an array of length nDim*nDim
     * @param nDim        The dimension of the error matrix (at least the number of free variables).
     *
     */
    protected static native void jmnemat(double[] errorMatrix, int nDim);
    
    /**
     * Get the current parameter's errors.
     * @param parNum The parameter's number; if positive it is the number as referenced
     *               by the function to be minimized, if negative it is the negative of the
     *               parameter number as used within Minuit (the internal representation)
     * @param errors The parameter's errors. This array has four entries: the positive MINOS
     *               error, the negative MINOS error, the parabolic error from the error matrix
     *               and the global correlation coerricient.
     *
     */
    protected static native void jmnerrs(int parNum, double[] errors);
    
    /**
     * Get the two dimensional contour for the current configuration.
     * @param parNum1 The external number of the first parameter.
     * @param parNum2 The external number of the second parameter.
     * @param nPoints The number of points that are to be calculated on the contour (>4).
     * @param xPoints The array of the x-coordinate of the found points.
     * @param yPoints The array of the y-coordinate of the found points.
     * @param nFound  The number of points that have been found. This is a 1-dimensional array.
     *
     */
    protected static native void jmncont(int parNum1, int parNum2, int nPoints, double[] xPoints, double[] yPoints, int[] nFound);
        
    private void loadAndInitialize() {
        isInitialized = true;
        if ( ! isLibLoaded ) {
            String libName = "minuitAdapter";
            try {
                System.loadLibrary(libName);
            } catch ( UnsatisfiedLinkError ule ){
                throw new RuntimeException("Problem loading the library "+libName,ule);
            }
            isLibLoaded = true;
        }
        jmninit( 5, 6, 7);
        ((MinuitOptimizerConfiguration)theOptimizer.configuration()).setDefaults();
    }
    
    /**
     * Default constructor.
     *
     */
    protected MinuitCommands(MinuitOptimizer theOptimizer) {
        this.theOptimizer = theOptimizer;
    }
    
    
    public void setPrintLevel(int printLevel) throws java.lang.IllegalArgumentException {
        if ( !isInitialized )
            loadAndInitialize();
        arglist[0] = printLevel;
        jmnexcm("SET PRINT",arglist,1);
    }
    
    /**
     * Reset Minuit.
     *
     */
    protected void resetMinuit() {
        if ( !isInitialized )
            loadAndInitialize();
        function = null;
        variableNames = null;
        varList.clear();
        jmnexcm( "CLEAR", arglist, 0 );
    }
    
    
    /**
     * Evaluate the function.
     * @param vars The values of the parameters where the function has to be evaluated.
     * @return     The value of the function.
     *
     */
    public static double evaluateFunction( double[] vars ) {
        return function.value( vars );
    }
    
    /**
     * Evaluate the function's derivatives.
     * @param vars The values of the parameters where the function's derivatives have to be evaluated.
     * @return     The array containing the function's derivatives.
     *
     */
    public static double[] evaluateDerivatives( double[] vars ) {
        return function.gradient( vars );
    }
    
    /**
     * Initialize the function.
     *
     */
    public static void initializeFunction() {
    }
    
    /**
     * Finalize the function after the fit is over.
     *
     */
    public static void finalizeFunction() {
    }
    
    /**
     * Set the function to be minimized.
     * When setting a new function the minimizer is cleared of previous information.
     * @param function The function to be minimized.
     *
     */
    protected void setFunction( IFunction function, MinuitOptimizer optimizer ) {
        this.function = function;
        this.variableNames = function.variableNames();
        if ( variableNames == null || variableNames.length == 0 ) throw new IllegalArgumentException("Cannot optimize!! There are no variables in this function!");
        for ( int i = 0; i<variableNames.length; i++ ) {
            String varName = variableNames[i];
            IVariableSettings varSet = optimizer.variableSettings(varName);
            double value = varSet.value();
            if ( Double.isNaN(value) ) throw new IllegalArgumentException("No initial value set for variable "+varName);
            
            if ( varSet.isBound() )
                addVariable( varName, value, varSet.stepSize(), varSet.lowerBound(), varSet.upperBound() );
            else
                addVariable( varName, value, varSet.stepSize(), 0, 0 );
            if ( varSet.isFixed() ) fixVariable(varName);
        }
        
        if ( getNVariables() == 0 ) throw new IllegalArgumentException("Cannot optimize!! There are no free variable registered in Minuit!");
    }

    protected void updateFunction( MinuitOptimizer optimizer ) {
        if ( !isInitialized )
            loadAndInitialize();
        for ( int i = 0; i<variableNames.length; i++ ) {
            String varName = variableNames[i];
            IVariableSettings varSet = optimizer.variableSettings(varName);
            if ( ! varSet.isFixed() ) {
                String[] name = new String[1];
                double[] vals = new double[4];
                jmnpout(i+1,name,vals);
                //            if ( ! name[0].equals(variableNames[i]) ) throw new RuntimeException("Something went wrong!! Variables name mismatch!! "+name[0]+" "+variableNames[i]);
                varSet.setValue(vals[0]);
                varSet.setStepSize(vals[1]);
            }
        }
    }
    
    protected void fixVariable( String varName ) {
        if ( !isInitialized )
            loadAndInitialize();
        arglist[0] = varList.indexOf(varName)+1;
        if ( jmnexcm("FIX", arglist, 1) != 0 ) throw new RuntimeException();
    }
    
    /**
     * Add a variable to the fit.
     * @param parNum   The variable number as referenced by the Function.
     * @param var      The Variable.
     * @param stepSize The initial step size.
     * @return <code>true</code> if the variable was added successfully.
     *         <code>false</code> otherwise.
     *
     */
    private void addVariable( String varName, double value, double step, double lowerBound, double upperBound ) {
        if ( !isInitialized )
            loadAndInitialize();
        if ( jmnparm( varList.size()+1,varName,value,step,lowerBound,upperBound) != 0 ) throw new RuntimeException();
        varList.add( varName );
    }
    
    
    /**
     * Get the status of the fit.
     * @return The status of the fit based on the current status
     *         of the covariance matrix.
     *
     */
    protected int getStatus() {
        if ( !isInitialized )
            loadAndInitialize();
        return jmnstat(minInfo, parInfo);
    }
    
    /**
     * Get the number of (released) variables in the minimization.
     * @return The number of variables in the minimization.
     *
     */
    protected int getNVariables() {
        if ( !isInitialized )
            loadAndInitialize();
        jmnstat(minInfo, parInfo);
        return parInfo[0];
    }
    
    /**
     * Get the value of UP, the errorDefinition.
     * @return The number of UP.
     *
     */
    protected double getErrorDef() {
        if ( !isInitialized )
            loadAndInitialize();
        jmnstat(minInfo, parInfo);
        return minInfo[2];
    }
    
    /**
     * Set the Error Definition, the Minuit UP value.
     * Minuit defines variable's errors as the change in the variable's value
     * required to change the function value by the Error Definition (UP).
     * For chiSquared fits UP=1, for negative log likelihood UP=0.5.
     * @param errDef The new value for the Error Definition
     *
     */
    protected void setErrorDef( int errDef ) {
        if ( !isInitialized )
            loadAndInitialize();
        if ( errDef == MinuitOptimizerConfiguration.DEFAULT_ERROR  || errDef == MinuitOptimizerConfiguration.CHI2_FIT_ERROR ) arglist[0] = 1.;
        else if ( errDef == MinuitOptimizerConfiguration.LOGL_FIT_ERROR ) arglist[0] = 0.5;
        if ( jmnexcm("SET ERR",arglist,1) != 0 ) throw new RuntimeException();
    }
    
    protected void setErrorDefinition( double errDef ) {
        if ( !isInitialized )
            loadAndInitialize();
        arglist[0] = errDef;
        if ( jmnexcm("SET ERR",arglist,1) != 0 ) throw new RuntimeException();
    }
    /**
     * Tell Minuit if the derivatives provided by the function are to be used.
     *
     */
    protected void setUseFunctionGradient( boolean useFunctionGradient ) {
        if ( !isInitialized )
            loadAndInitialize();
        if ( useFunctionGradient ) {
            // This forces Minuit to use the function's derivatives.
            // without arglist[0] = 1, Minuit will calculate its own derivatives
            // and compare it with the ones provided by the funciton.
            arglist[0] = 1;
            if ( jmnexcm("SET GRADIENT",arglist,1) != 0 ) throw new RuntimeException();
        }
        else {
            if ( jmnexcm("SET NOGRADIENT",arglist,0) != 0 ) throw new RuntimeException();
        }
    }
    
    
    /**
     * Set the strategy to be used in calculating the first and second derivative and
     * in certain optimization methods. It determines the reliability of the calculation
     * as it changes the number of allowed function calls.
     *
     */
    protected void setStrategy( int strategy ) {
        if ( !isInitialized )
            loadAndInitialize();
        arglist[0] = strategy;
        if ( jmnexcm("SET STRATEGY",arglist,1) != 0 ) throw new RuntimeException();
    }
    
    /**
     * Informs Minuit on the machin precision.
     *
     */
    protected void setPrecision( double precision ) {
        if ( !isInitialized )
            loadAndInitialize();
        arglist[0] = precision;
        if ( jmnexcm("SET EPSMACHINE",arglist,1) != 0 ) throw new RuntimeException();
    }
    
    /**
     * Minimize the function.
     * @param method The optimization method. It can be:
     *                - SIMPLEX performs a minimixation using the simplex method of
     *                  Nedler and Mead. The minimization will stop after maxIter call have
     *                  been performed or when the EDM is less than the tolerance (default
     *                  is 0.1*UP)
     *                - MIGRAD The default minimization using the Migrad method. maxIter is the (optional)
     *                  maximum amount of iterations; when this is reached the minimization will
     *                  stopped even if it did not converge. The minimization converges when
     *                  the EDM is less than 0.001*tolerance*UP.
     *                - MINIMIZE It starts by using the MIGRAD minimization; it this
     *                  does not converge it switches to the SIMPLEX method.
     *                - IMPROVE If a previous minimization has converged and the function is in
     *                  and optimal solution, it searches for additional global optimal points.
     *                  The calculation will be stopped after maxIterations calls.
     *                - SEEK Causes a Monte Carlo minimization of the function, by choosing uniformely random values
     *                  of the variables in an hypercube centered in the current variable values. The size of the
     *                  hypercube is specified by the value of tolerance.
     * @param maxIterations   The maximum amount of allowed iterations.
     * @param tolerance The tolerance for the minimization.
     * @return <code>true</code> if the command was successfull; <code>false</code> otherwise.
     *         Check the status of the minimization to know what went wrong.
     *
     */
    protected void optimize( String method, int maxIterations, double tolerance ) {
        if ( !isInitialized )
            loadAndInitialize();
        arglist[0] = 1;
        if ( jmnexcm("CALL FCN",arglist,1) != 0 ) throw new RuntimeException();
        int nArg = 2;
        arglist[0] = maxIterations;
        arglist[1] = tolerance;
        if ( method.startsWith("IMP") ) nArg = 1;
        jmnexcm(method, arglist, nArg);
  //        if ( jmnexcm(method, arglist, nArg) != 0 ) throw new RuntimeException();
    }
    
    /**
     * Perform the Minos error analysis on the specified variables.
     * param maxIter The maximum number of iterations allowed.
     * param vars    The list of variables whose errors are to be recalculated.
     * return <code>true</code> if the command was successfull; <code>false</code> otherwise.
     *         Check the status of the minimization to know what went wrong.
     *
     */
    /*
    protected boolean minos( int maxIter, ArrayList vars ) {
        int nArg = 0;
        arglist[nArg++] = maxIter;
        Iterator iter = vars.iterator();
        while( iter.hasNext() )
            arglist[nArg++] = varList.indexOf( iter.next() ) + 1;
        return internMinos( nArg );
    }
     */
    protected void minos() {
        internMinos(0);
    }
    
    private void internMinos( int nArg ) {
        if ( !isInitialized )
            loadAndInitialize();
        if ( function == null ) throw new RuntimeException("A function has to be provided before minimizing!!!");
        if ( jmnexcm("MINOS",arglist,nArg) != 0 ) throw new RuntimeException();
    }
    
    /**
     * Calculate the Error Matrix in the current configuration.
     * @return <code>true</code> if the error matrix was calculated successfully.
     *         <code>false</code> otherwise.
     *
     */
    /*
    protected boolean calculateErrorMatrix() {
        if ( function == null ) {
            System.out.println("A function has to be provided before minimizing!!!");
            return false;
        }
        if ( jmnexcm("HESSE",arglist,0) == 0 ) return true;
        return false;
    }
     */
    protected double[][] calculateContour( String parName1, String parName2 ) {
        return calculateContour( parName1, parName2, 20);
    }
    protected double[][] calculateContour( String parName1, String parName2, int nPoints ) {
        return calculateContour( parName1, parName2, nPoints, 1 );
    }
    protected double[][] calculateContour( String parName1, String parName2, int nPoints, double nSigmas ) {
        if ( !isInitialized )
            loadAndInitialize();
        double errDef = getErrorDef();
        if( nSigmas < 1 ) throw new IllegalArgumentException("The number of sigmas has to at least 1");
        setErrorDefinition( nSigmas*nSigmas*errDef );
        
        int parIndex1 = varList.indexOf(parName1)+1;
        int parIndex2 = varList.indexOf(parName2)+1;

        double[] xPoints = new double[nPoints];
        double[] yPoints = new double[nPoints];
        int[] nFound = new int[1];
        
        jmncont( parIndex1, parIndex2, nPoints, xPoints, yPoints, nFound );
        
        int pointFound = nFound[0];
        double[][] contour = new double[2][pointFound];
        for ( int i = 0; i < pointFound; i++ ) {
            contour[0][i] = xPoints[i];
            contour[1][i] = yPoints[i];
        }
        
        setErrorDefinition( errDef );
        
        return contour;
    }
    
    
    protected double[][] getCovarianceMatrix() {
        if ( !isInitialized )
            loadAndInitialize();
        int nDim = getNVariables();
        double[][] covMatrix = new double[nDim][nDim];
        double[] matrix = new double[nDim*nDim];
        jmnemat(matrix, nDim);
        for ( int i = 0; i< nDim; i++ ) 
            for ( int j = 0; j< nDim; j++ ) 
                covMatrix[i][j] = matrix[i*nDim+j];
        return covMatrix;
    }        
 
}
