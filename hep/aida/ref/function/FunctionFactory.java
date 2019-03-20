/*
 * FunctionFactory.java
 *
 * Created on February 6, 2002, 1:08 PM
 */

package hep.aida.ref.function;

import java.util.*;
import hep.aida.*;
import hep.aida.ref.tree.*;
import hep.aida.ref.*;

/**
 * @author serbo
 * @version $Id: 
 */
public class FunctionFactory implements IFunctionFactory
{
    private Tree tree;
    private FunctionCatalog catalog;
   
    private final static char separatorChar = '/';
    
    private String nameInPath( String path ) {
        int index = path.lastIndexOf( separatorChar );
        if ( index == -1 )
            return path;
        return path.substring( index+1 );
    }
    
    private String parentPath( String path ) {
        int index = path.lastIndexOf( separatorChar );
        if ( index == -1 )
            return null;
        return path.substring(0,index);
    }

    /** 
    * Create a new FunctionFactory.
    * This constructor is used by AnalysisFactory, the Master Factory.
    * @param tree the ITree where the histogram is added.
    */
   public FunctionFactory(ITree tree)
   {
      this((Tree)tree);
   }
    
   /** 
    * Create a new FunctionFactory.
    * This constructor is used by AnalysisFactory, the Master Factory.
    * @param tree the Tree where the histogram is added.
    */
   protected FunctionFactory(Tree tree)
   {
      this.tree = tree;
      catalog = FunctionCatalog.getFunctionCatalog();
   }

   
   
    /**
     * Create function from a name registered in the catalog.
     * This is the easiest way to create simple model functions for fitting.
     * Every AIDA compliant implementation should predefine "G", "E", "Pn"
     * (n is an integer, e.e "P0","P5"). Simple operations are permitted,
     * e.g. "G+P2".
     */
    public IFunction createFunctionByName(String path, String model) {
	IFunction result = catalog.create(nameInPath(path), model);

	if ((tree != null) && (path != null) && (result instanceof IManagedObject))
	    tree.addFromFactory(parentPath(path),(IManagedObject) result);

        return result; 
    }

    /**
     * Create function from script. Script conventions:
     * example:  createFunctionFromScript(2, "a*x[0]*x[0] + b*x[1]", "a,b", 
                                          "this is my function", "2*a*x[0],b")
     */
    public IFunction createFunctionFromScript(String path, int dim, String valexpr, String parameters, String description) {
	String gradexpr = null;

	return createFunctionFromScript(path, dim, valexpr, parameters, description, gradexpr);
    }

    /**
     * Create function from script. Script conventions:
     * example:  createFunctionFromScript(2, "a*x[0]*x[0] + b*x[1]", "a,b", 
                                          "this is my function", "2*a*x[0],b")
     */
    public IFunction createFunctionFromScript(String path, int dim, String valexpr, String parameters, String description, String gradexpr) {
	if (valexpr == null || valexpr.equals("")) { 
	    throw new IllegalArgumentException("Can not create function from an empty string");
	}

	String codeletString = new String("codelet:"+description+":verbatim:jel : " +
					  dim + " : " + valexpr + " : " + parameters + " : " + gradexpr);

	IFunction result = catalog.getFunctionCreator().createFromCodelet(nameInPath(path), codeletString);
	if (tree != null && path != null) tree.addFromFactory(parentPath(path),(IManagedObject) result);

	return result;
    }


    public IFunction cloneFunction(String path, IFunction f) {
	IFunction clone = catalog.clone(nameInPath(path), f);

	if (tree != null && path != null) tree.addFromFactory(parentPath(path),(IManagedObject) clone);

	return clone;
    }

    /**
     * get access to the function catalog
     */
    public IFunctionCatalog catalog() {
        return catalog;
    }

   
    /*
    public hep.aida.IFunction create(String name, String label, String type) {
        Function result = new Function(name, label, type, null, null);
        if (tree != null) tree.add(result);
        return (IFunction) result;
    }

    public IFunction create(String name, String label, String type, double[] parameterValues)
    {
	return create(name, label, type, parameterValues, null);
    }

    public IFunction create(String name, String label, String type, double[] parameterValues, String parameterNames)
    {

	Function result = new Function(name, label, type, parameterValues, parameterNames);
	if (tree != null) tree.add(result);
	return (IFunction) result;
    }
 
    public IFunction createFit(String name, String label, String type, String options)
    {
	// First get options and values from "options" string
	Map hash = hep.aida.ref.AidaUtils.parseOptions(options);

	Function result = new Function(name, label, type, hash);
	if (tree != null) tree.add(result);
	return (IFunction)result;
    }

    public IFunction createScripted(String name, String label, String script)
    {
	throw new UnsupportedOperationException();
    }
    */

}
