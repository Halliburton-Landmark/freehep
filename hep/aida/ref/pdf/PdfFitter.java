package hep.aida.ref.pdf;

import hep.aida.*;
import hep.aida.dev.*;
import hep.aida.ext.*;
import hep.aida.ref.fitter.fitData.FitDataCreator;
import java.util.*;
import org.freehep.util.*;
import org.openide.util.Lookup;

/**
 * Another implementation of IFitter.
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
public class PdfFitter {

    // The IOptimizer.
    private String engineType;
    private IOptimizer optimizer = null;
    
    // The IFitMethod.
    private String fitMethodType;
    private IFitMethod fitMethod = null;

    // Internal configuration
    private boolean useGradient = true;

    public PdfFitter(String fitMethodType, String engineType) throws IllegalArgumentException {
        setFitMethod(fitMethodType);
        setEngine(engineType);
    }
    
    public void setEngine(String engineType) throws IllegalArgumentException {
        if (engineType == null || engineType.length() == 0) engineType = "uncmin";
        String enType = engineType.toLowerCase();
        
        IOptimizerFactory tmpOptimizerFactory = null;
        Lookup.Template template = new Lookup.Template(IOptimizerFactory.class);
        Lookup.Result result = FreeHEPLookup.instance().lookup(template);
        Collection c = result.allInstances();
        for (Iterator i = c.iterator(); i.hasNext(); ) {
            IOptimizerFactory of = (IOptimizerFactory)i.next();
            String[] names = of.optimizerFactoryNames();
            if ( names == null || names.length == 0 )
                throw new IllegalArgumentException("IOptimizerFactory with illegal names!");
            for ( int j = 0; j < names.length; j++ ) {
                if ( enType.equals( names[j].toLowerCase() ) ) {
                    tmpOptimizerFactory = of;
                    break;
                }
            }
        }
        if (tmpOptimizerFactory == null) throw new IllegalArgumentException("Cannot create IOptimizer of type: "+engineType);
        this.engineType = engineType;
        this.optimizer = tmpOptimizerFactory.create(engineType);
    }
    public String engineName() {
        return engineType;
    }
    
    public void setFitMethod(String fitMethodType) throws IllegalArgumentException {
        if (fitMethodType == null || fitMethodType.length() == 0) fitMethodType = "chi2";
        // Check the lookup table to look for the fitMethod of the given type.
        String fitMet = fitMethodType.toLowerCase();
        
        IFitMethod tmpFitMethod = null;
        Lookup.Template template = new Lookup.Template(IFitMethod.class);
        Lookup.Result result = FreeHEPLookup.instance().lookup(template);
        Collection c = result.allInstances();
        for (Iterator i = c.iterator(); i.hasNext(); ) {
            IFitMethod fm = (IFitMethod)i.next();
            String[] names = fm.fitMethodNames();
            if ( names == null || names.length == 0 )
                throw new IllegalArgumentException("IFitMethod with illegal names!");
            for ( int j = 0; j < names.length; j++ ) {
                if ( fitMet.equals( names[j].toLowerCase() ) ) {
                    tmpFitMethod = fm;
                    break;
                }
            }
        }
        if (tmpFitMethod == null) throw new IllegalArgumentException("Unknown IFitMethod type: "+fitMethodType);
        this.fitMethodType = fitMethodType;
        this.fitMethod = tmpFitMethod;
    }
    
    public String fitMethodName() {
        return fitMethodType;
    }
    
    public void fit(Object[] objs, Function[] functions) {
        IFitData[] data = new IFitData[objs.length];
        for ( int i = 0; i < data.length; i++ )
            data[i] = FitDataCreator.create(objs[i]); 
        fit( data, functions);
    }
    
    public void fit(IFitData[] data, Function[] functions) {
        int nData = data.length;        
        if ( nData != functions.length )
            throw new IllegalArgumentException("Inconsistent number of data sets ("+nData+") and functions ("+functions.length+").");
        
        int fitType = fitMethod.fitType();
        for ( int i = 0; i < nData; i++ ) {
            if ( fitType != ( (IDevFitData) data[i] ).fitType() ) throw new IllegalArgumentException("This FitData is incompatible with the selected fit method");
            if ( data[i].dimension() != functions[i].numberOfDependents() ) throw new IllegalArgumentException("Dimension mismatch!! Function's dimension "+functions[i].numberOfDependents()+" FitData's dimension "+data[i].dimension());
        }

        // For simultaneous fits the normalization parameter of the functions have to have different names.
        // The name is changed before the fit and changed back after the fit.
        if ( nData > 1 )
            for ( int i = 0; i < nData; i++ )
                functions[i].getNormalizationParameter().setName("norm_"+i);
        
        
        
        fitMethod.clear();
        optimizer.reset();
        
        setErrorDefinition();
        
        boolean normalizeFunction = fitType == IFitMethod.UNBINNED_FIT; 
        for ( int i = 0; i < nData; i++ ) 
            functions[i].normalize(normalizeFunction);
        
        InternalObjectiveFunction objectiveFunction = new InternalObjectiveFunction(data, functions);
        
        for( int i = 0; i < objectiveFunction.dimension(); i++ ) {
            Parameter p = objectiveFunction.getVariable(i);
            IVariableSettings varSet = optimizer.variableSettings(p.name());
            varSet.setValue( p.value() );
            varSet.setFixed( p.isFixed() );
                        
            double stepSize = p.stepSize();
            if ( Double.isNaN( stepSize ) ) {
                stepSize = 0.1*Math.abs(p.value());
                if ( stepSize < 1 ) stepSize = 1;
            }
            varSet.setStepSize( stepSize );
            if ( p.useBounds() )
                varSet.setBounds( p.lowerBound(), p.upperBound() );
        }
        
        optimizer.setFunction(objectiveFunction);
        
        optimizer.configuration().setUseFunctionGradient(objectiveFunction.providesGradient() && useFunctionGradient());
        
        optimizer.configuration().setMaxIterations(500);
        //        optimizer.configuration().setPrintLevel(-2);

        optimizer.optimize();
        
        // Change back the name of the normalization parameter.
        if ( nData > 1 )
            for ( int i = 0; i < nData; i++ )
                functions[i].getNormalizationParameter().setName("norm");
        
    }
    
    public void fit(Object obj, Function function) {
        IFitData data = FitDataCreator.create(obj); 
        fit( data, function);
    }
    
    public void fit(IFitData data, Function function) {
        
        fit( new IFitData[] {data}, new Function[] { function } );

        /*
        int status = optimizer.result().optimizationStatus();
        int dataEntries = ((FitFunction) fitFunction).dataEntries();
        int freePars = ((FitFunction) fitFunction).nFreePars();
        int nDoF = dataEntries - freePars;
        double funcVal = fitFunction.value(f.parameters());
        
        IDevFitResult result = new FitResult(fitFunction.dimension(), fitSeconds);
        result.setConstraints( constraints() );
        result.setDataDescription( d.dataDescription() );
        result.setEngineName( engineName() );
        result.setFitMethodName( fitMethodName() );
        result.setFitStatus( status );
        result.setFittedFunction( f ); // FIX ME! Replace with clone.
        result.setIsValid( true ); ////??????
        result.setNdf( nDoF );
        
        if ( fitMethod.fitType() == IFitMethod.UNBINNED_FIT )
            result.setQuality( funcVal/nDoF/Math.sqrt(2.) );
        else
            result.setQuality( funcVal/nDoF );
         */
    }


    public boolean useFunctionGradient() {
        return useGradient;
    }
    public void setUseFunctionGradient(boolean useGradient) {
        this.useGradient = useGradient;
    }
    
    private void setErrorDefinition() {
        if ( fitMethod.fitType() == IFitMethod.BINNED_FIT )
            optimizer.configuration().setErrorDefinition(IOptimizerConfiguration.CHI2_FIT_ERROR);
        else
            optimizer.configuration().setErrorDefinition(IOptimizerConfiguration.LOGL_FIT_ERROR);
    }

    private class InternalObjectiveFunction implements IFunction {
        
        private ArrayList vars = new ArrayList();
        private Function[] functions;
        private IDevFitDataIterator[] iters;
        
        InternalObjectiveFunction(IFitData[] data, Function[] functions) {
            this.functions = functions;
            this.iters = new IDevFitDataIterator[data.length];
            
            for ( int i = 0; i < functions.length; i++ ) {

                iters[i] = ( (IDevFitData) data[i] ).dataIterator();
                Function f = functions[i];
                for ( int j = 0; j < f.numberOfParameters(); j++ ) {
                    Parameter p = f.getParameter(j);
                    if ( ! vars.contains(p) )
                        vars.add(p);
                }
            }
        }
        
        public String normalizationParameter() {
            throw new UnsupportedOperationException();
        }
        
        public Parameter getVariable(int index) {
            return (Parameter) vars.get(index);
        }
        
        public double value(double[] values) {
            double value = 0;
            
            for ( int i = 0; i < vars.size(); i++ )
                ( (Parameter) vars.get(i) ).setValue(values[i]);
            
            for ( int i = 0; i < functions.length; i++ ) {
                Function f = functions[i];
                value += fitMethod.evaluate(iters[i],f);
            }
            return value;
        }
        
        public boolean providesGradient() {
            for ( int i = 0; i < functions.length; i++ ) {
                Function f = functions[i];
                for ( int j = 0; j < f.numberOfParameters(); j++ ) {
                    if ( ! f.providesGradientWithRespectToVariable(f.getParameter(i) ) )
                        return false;
                }
            }
            return true;
        }
        
        public int dimension() {
            return vars.size();
        }
        
        public double[] gradient(double[] values) {
            double[] grad = new double[vars.size()];
            for ( int i = 0; i < vars.size(); i++ )
                ( (Parameter) vars.get(i) ).setValue(values[i]);

            for ( int i = 0; i < functions.length; i++ ) {
                Function f = functions[i];
                int fPars = f.numberOfParameters();
                double[] g =  fitMethod.evaluateGradient(fPars, iters[i], f);
                for ( int j = 0; j < fPars; j++ ) {
                    Parameter p = f.getParameter(j);
                    grad[ vars.indexOf(p) ] += g[j];
                }
            }
            return grad;
        }
        
        public int numberOfParameters() {
            return 0;
        }
        
        public String variableName(int index) {
            return ( (Parameter) vars.get(index) ).name();
        }
        
        public String[] variableNames() {
            String[] names = new String[vars.size()];
            for ( int i = 0; i < names.length; i++ )
                names[i] = ( (Parameter) vars.get(i) ).name();
            return names;
        }
                
        public hep.aida.IAnnotation annotation() {
            throw new UnsupportedOperationException();
        }
        
        public String codeletString() {
            throw new UnsupportedOperationException();
        }

        public int indexOfParameter(String str) {
            throw new UnsupportedOperationException();
        }
        
        public boolean isEqual(hep.aida.IFunction iFunction) {
            throw new UnsupportedOperationException();
        }
        
        public double parameter(String str) {
            throw new UnsupportedOperationException();
        }
        
        public String[] parameterNames() {
            throw new UnsupportedOperationException();
        }
        
        public double[] parameters() {
            throw new UnsupportedOperationException();
        }
        
        public void setParameter(String str, double param) throws java.lang.IllegalArgumentException {
            throw new UnsupportedOperationException();
        }
        
        public void setParameters(double[] values) throws java.lang.IllegalArgumentException {
            throw new UnsupportedOperationException();
        }
        
        public void setTitle(String str) throws java.lang.IllegalArgumentException {
            throw new UnsupportedOperationException();
        }
        
        public String title() {
            throw new UnsupportedOperationException();
        }
        
    }            
}
    