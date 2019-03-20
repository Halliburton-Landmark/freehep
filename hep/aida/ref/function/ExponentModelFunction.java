/*
 * ExponentModelFunction.java
 *
 * Created on September 3, 2002, 4:07 AM
 */

package hep.aida.ref.function;
import java.util.*;
//import hep.aida.*;
import hep.aida.ref.*;
import hep.aida.dev.*;
//import hep.aida.ext.*;

/**
 *
 * @author  serbo
 */
public class ExponentModelFunction extends AbstractDevModelFunction {

    public ExponentModelFunction(String str) {
	super();

	if(!str.toLowerCase().startsWith("e"))
	    throw new IllegalArgumentException("Exponent Function Qualifier must start with \"e\"");
	int dim = Integer.parseInt(str.substring(1));
	setDimension(dim);
	setNumberOfParameters(dim+1);

	setCodeletString("ExponentModelFunction");
	setNormalization(true, false);
    }

    public int dimension() { return dimension; }

    public int numberOfParameters() { return p.length; }

    public double functionValue(double[] var) {
	double val = 1;
	for (int i=0; i<dimension; i++) { val = val*Math.exp(p[i]*var[i]); }
	return val*p[numberOfParameters()-1];
    }


    public static void main(String[] args) {
	System.out.println("ExponentModelFunction.main: creating Exponential Function:: " + args[0]);

	ExponentModelFunction exp = new ExponentModelFunction(args[0]);

	double[] pars = new double[] {1, 2};

	exp.setParameters(pars);

	for (int i=0; i<10; i++) {
	    System.out.println("x = " + i +", f = " + exp.value(new double[] {i*1.}));
	}
    }
}
