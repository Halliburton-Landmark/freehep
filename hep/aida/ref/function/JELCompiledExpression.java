/*
 * JELCompiledExpression.java
 *
 * Created on September 4, 2002, 6:15 AM
 */

package hep.aida.ref.function;
import java.util.*;
import gnu.jel.*;


/**
 *
 * @author  serbo
 */

// Convenience wrapper around the JEL's CompiledExpression
public  class JELCompiledExpression  {

    private String expression;
    private String parsedExpression;
    private int dim;
    private int nPar;
    private String[] parNames;

    private CompiledExpression compExpression;
    private Library lib;
    private ValueProvider pro;
    private Object[] context;
    private Resolver res;

    public JELCompiledExpression(int dim, int nPar, String expr, String[] pNames) {
	//System.out.println("JELCompiledExpression::  expr = "+expr+",  nVar = "+dim+",  nPar = "+nPar + ", pNames = "+pNames[0]+" "+pNames[1]+" "+pNames[2]);

	this.dim = dim;
	this.nPar = nPar;
	expression = expr;

	// Set parameter names
	setParameterNames(pNames);

	// Create a compiled expression
	parse();
	compile();
    }

    public void setParameterNames(String[] pNames) {
	if (pNames == null) {
	    throw new IllegalArgumentException("Can not set parameter names to a null");
	} else if (nPar != pNames.length) {
	    throw new IllegalArgumentException("Number of parameters ("+nPar+
					       ") is different from number of supplied parameter names ("+pNames.length+")");
	}
	    parNames = new String[pNames.length];
	    for (int i=0; i<pNames.length; i++) parNames[i] = pNames[i];
    }

    public void parse() {
	parsedExpression = "";
	StringTokenizer st = new StringTokenizer(expression, "[]");
	while (st.hasMoreTokens()) {
	    String token = st.nextToken();
	    //System.out.println(token);
	    if (token.toLowerCase().endsWith("x")) {
		parsedExpression += token.substring(0,token.length()-1) + "x" + st.nextToken();
		//parsedExpression += token.substring(0,token.length()-1) + "___x" + st.nextToken() + "___";
		//} else if (token.endsWith("p")) {
		//parsedExpression += token.substring(0,token.length()-1) + "___p" + st.nextToken() + "___";
	    } else parsedExpression += token;
	}
	//System.out.println("NEW:::"+parsedExpression);
    }

    private void compile() {
	Class[] staticLib  = new Class[1];
	
	Class[] dynamicLib = new Class[1];
	context = new Object[1];
	Class[] dotLib     =  { Object.class, String.class, java.util.Date.class };
	try {
	    staticLib[0]  = java.lang.Class.forName("java.lang.Math");

	    pro = new ValueProvider(dim, nPar);
	    dynamicLib[0] = pro.getClass(); 
	    context[0] = pro;

	    res = new Resolver();

	} catch(ClassNotFoundException e) {
	    throw new RuntimeException("Can not find class for JEL!", e);
	}

	try {
	    lib = new Library(staticLib, dynamicLib, dotLib, res, null);
	    lib.markStateDependent("random", null);
	} catch (gnu.jel.CompilationException ec1) {
	    throw new RuntimeException("Can not compile JEL Library!", ec1);
	}

	try {
	    compExpression = Evaluator.compile(parsedExpression, lib, Double.TYPE);
	} catch (gnu.jel.CompilationException ec2) { 
	    throw new RuntimeException("Can not compile JEL Expression: "+expression, ec2);
	}
    }
    
    public double evaluate(double[] var, double[] par) {
	pro.setVar(var);
	pro.setPar(par);

	double num = 0;
	try {
	    num =  compExpression.evaluate_double(context);
	} catch (Throwable t) { 
	    throw new RuntimeException("Runtime JEL Evaluation Problems!", t);
	}

	return num;
    }


    public class Resolver extends DVMap {
	
	public Resolver() {}
	public String getTypeName(String name) { 
	    //System.out.println("Resolver.getTypeName:: name = "+name);

	    // Loop over all possible variables first
	    for (int i=0; i<dim; i++) {
		if (name.equals("x"+i)) return "Double";
	    }

	    // Then over all parameters
	    for (int i=0; i<nPar; i++) {
		if (name.equals(parNames[i])) return "Double";
	    }

	    return null; 
	}
	
	public Object translate(String name) {
	    //System.out.println("Resolver.translate:: name = "+name);
	    int n = -1;
	    int offset = 0;

	    // Loop over all possible variables first
	    for (int i=0; i<dim; i++) {
		if (name.equals("x"+i)) return new Integer(i);
	    }
	    
	    // Then over all parameters
	    for (int i=0; i<nPar; i++) {
		if (name.equals(parNames[i])) return new Integer(i+dim);
	    }

	    return new Integer(n);
	}
    }
    
    public class ValueProvider {
	private double[] var;
	private double[] par;
	
	public ValueProvider(int dim, int nPar) {
	    var = new double[dim]; 
	    par = new double[nPar]; 
	}
	
	public void setVar(double[] v) { var = v; }
	public void setPar(double[] p) { par = p; }
	
	public double getDoubleProperty(int i) { 
	    //System.out.println("ValueProvider.getDoubleProperty(int):: i = "+i);
	    if (i < dim) {
		return var[i]; 
	    } else if (i >= dim) {
		return par[i-dim];
	    } else if (i < 0 || i > dim+par.length) {
		throw new IllegalArgumentException("Wrong argument number: "+i+", dimension = "+dim+
						   ", N parameters = "+par.length);
	    }
	    return 0;
	}
    }

    public int parseInt(String name) { return Integer.parseInt(name.substring(4, name.length()-3)); }

    public static void main(String[] args) {
	
	int nV = Integer.parseInt(args[1]);
	int nP = Integer.parseInt(args[2]);

	JELCompiledExpression expr = new JELCompiledExpression(nV, nP, args[0], null);

	System.out.println("Arguments: "+args.length+", expr = "+args[0]+",  nVar = "+nV+",  nPar = "+nP);

	double[] var = new double[ nV ];
	double[] par = new double[ nP ];

	for (int i=0; i<nP; i++) { par[i] = Double.parseDouble(args[i+3]); }

	for (int i=0; i<10; i++) {
	    var[0] = i/10.;
	    
	    double d = expr.evaluate(var, par);
	    System.out.println(i/10. +"\t" + d);
	}
    }

}
