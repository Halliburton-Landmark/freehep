package hep.aida.ref.tuple;
import gnu.jel.*;
import hep.aida.ITuple;

/**
 *
 * @author The FreeHEP team @ SLAC
 */
class JELExpression {

    private String expression;
    private Object[] context;
    private Library lib;
    private CompiledExpression compExpression;
    
    /** 
     * Default contructor.
     * @param expression The expression to evaluate.
     *
     */   
    protected JELExpression(String expression) {
        this.expression = expression;
    }

    protected String expression() {
        return expression;
    }

    protected double evaluateDouble() {
        try {
            return compExpression.evaluate_double(context);
	} catch (Throwable t) {
	    throw new RuntimeException("Runtime JEL Evaluation Problems!", t);
	}
    }
            
    protected boolean evaluateBoolean() {
        try {
            return compExpression.evaluate_boolean(context);
	} catch (Throwable t) {
	    throw new RuntimeException("Runtime JEL Evaluation Problems!", t);
	}
    }
    
    protected void compile(Class type, ITuple tuple) {
	lib = null;
	compExpression = null;

	Class[] staticLib  = new Class[1];
	Class[] dynamicLib = new Class[1];
	context = new Object[1];
	Class[] dotLib     =  { Object.class, String.class, java.util.Date.class };
	JELTupleProvider tupleProvider = new JELTupleProvider(tuple);
	try {
	    staticLib[0]  = java.lang.Class.forName("java.lang.Math");

	    context[0] = tupleProvider;
	    dynamicLib[0] = tupleProvider.getClass(); 

	} catch(ClassNotFoundException e) {
	    throw new RuntimeException("Can not find class for JEL!", e);
	}
	
	try {
	    lib = new Library(staticLib, dynamicLib, dotLib, tupleProvider, null);
	    lib.markStateDependent("random", null);
	} catch (gnu.jel.CompilationException ec1) {
	    throw new RuntimeException("Can not compile JEL Library!", ec1);
	}

	try {
	    compExpression = gnu.jel.Evaluator.compile(expression, lib, type);
	} catch (gnu.jel.CompilationException ec2) { 
	    throw new RuntimeException("Can not compile JEL Expression: "+expression, ec2);
	}

    }
}
