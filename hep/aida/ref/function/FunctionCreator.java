/*
 * FunctionCreator.java
 *
 * Created on September 26, 2002, 11:57 AM
 */

package hep.aida.ref.function;
import java.util.*;
import java.net.*;
import java.io.*;
import hep.aida.*;
import hep.aida.ext.*;
import hep.aida.ref.*;
import hep.aida.dev.*;

/**
 * Singleton class that is used by FunctionFactory and FunctionCatalog
 * to create functions from codelet strings. Use static method 
 * getFunctionCreator() to get an instance of this class.
 *
 * @author  serbo
 */
public class FunctionCreator {

    private String nameInTree;

    public FunctionCreator() {
	nameInTree = null;
    }
    

    public IFunction createFromCodelet(String codeletString) {
	return createFromCodelet(null, codeletString);
    }

    
    public IFunction createFromCodelet(String nameInTree, String codeletString) {
	IFunction f = null;
	if (!codeletString.toLowerCase().startsWith(FunctionCatalog.prefix))
	    throw new IllegalArgumentException("\""+ codeletString + "\" is not a codelet string (must start with \""+FunctionCatalog.prefix+"\")");
	
	String name = CodeletUtils.modelFromCodelet(codeletString);
	String location = CodeletUtils.locationFromCodelet(codeletString);
	//System.out.println("Catalog:  index="+index+",  name="+name+",  location="+location);


	// Catalog entries for Build-in functions
	if (CodeletUtils.isCodeletFromCatalog(codeletString)) {
	    if (name.toLowerCase().equals("e")) { 
		f = new BaseModelFunction(name, name, new ExponentialCoreNotNorm(name), new ExponentialCoreNorm(name));
	    } else if (name.toLowerCase().startsWith("p")) {
		f = new BaseModelFunction(name, name, new PolynomialCoreNotNorm(name), new PolynomialCoreNorm(name));
	    } else if (name.toLowerCase().startsWith("g2")) {
		f = new BaseModelFunction(name, name, new GaussianCore2DNotNorm(name), new GaussianCore2DNorm(name));
	    } else if (name.toLowerCase().startsWith("g")) {
		f = new BaseModelFunction(name, name, new GaussianCoreNotNorm(name), new GaussianCoreNorm(name));
	    } else {
		throw new UnsupportedOperationException("Can not create function: "+name);
	    }
	    ((BaseModelFunction) f).setCodeletString(codeletString);	 
            if ( nameInTree == null ) nameInTree = name;
	    ((ManagedObject) f).setName(nameInTree);
	}

	// Create JEL-based scripted function. The codeletString explession after
	// "codelet:verbatim:jel:" MUST contain a full description of scripted function.
	// Currently use ":" as deliminators. Example:
	// codelet:Script_Function:verbatim:jel :1 : a*(1+c*sin(x[0]-d)) : a,c,d : a*c*cos(x[0]-d) 
        else if (CodeletUtils.isCodeletFromScript(codeletString)) {
	    String scriptDef = location.substring(14);
	    int index = scriptDef.indexOf(":");
	    //System.out.println("scriptDef="+scriptDef+",   index="+index);
	    int dim = Integer.parseInt(scriptDef.substring(0, index).trim());
	    int index2 = scriptDef.indexOf(":", index+1);
	    String valexpr = scriptDef.substring(index+1, index2);
	    index = scriptDef.indexOf(":", index2+1);
	    String parameters = scriptDef.substring(index2+1, index);
	    index2 = scriptDef.lastIndexOf(":");
	    String gradexpr = scriptDef.substring(index2+1);
	    if (gradexpr.trim().toLowerCase().equals("null") || gradexpr.trim().equals("") ) gradexpr = null;

	    //System.out.println("dim="+dim+",  valexpr="+valexpr+",  parameters="+parameters+",  gradexpr="+gradexpr);

	    f = new JELBaseModelFunction(name, dim, valexpr, parameters, name, gradexpr);
	    ((JELBaseModelFunction) f).setCodeletString(codeletString);
	    ((ManagedObject) f).setName(nameInTree);
	}

	// Load function from file. "name" MUST be just FULL name of the class
	// (e.g. "fitProject.functions.MyFunction"
        else if (CodeletUtils.isCodeletFromFile(codeletString)) {
	    try {
		String urlString = location.substring(5).trim();
		if (urlString == null || urlString.equals("")) {
		    Class cl = Class.forName(name);
		    f = (IFunction) cl.newInstance();
		} else {
		    URL[] urlList = new URL[] { new File(urlString.substring(1)).toURL() };
		    URLClassLoader loader = new URLClassLoader(urlList);
		    
		    System.out.println("Name: "+name+"\nFile Name: "+urlString);
		    System.out.println("URL: "+urlList[0].getFile());
		    Class cl = loader.loadClass(name);
		    f = (IFunction) cl.newInstance();

		}
		if (f instanceof ManagedObject) ((ManagedObject) f).setName(nameInTree);
		if (f instanceof IManagedFunction) ((IManagedFunction) f).setName(nameInTree);
	    } catch (Exception ec) { 
		throw new RuntimeException("Can not create user function:"+name, ec);
	    }
	}

	return f;
    }

    public static String toString(IFunction f) {
	
	String out = "Codelet: "+f.codeletString()+"\n";
	if (f instanceof IManagedObject) out += "   name: "+((IManagedObject) f).name()+"\n";
	out += "\tDimensions: "+f.dimension()+"\n";
	for (int i =0; i<f.dimension(); i++) out += "\t\t Variable "+i+"\t Name: "+f.variableName(i)+"\n";
	out += "\tParameters: "+f.numberOfParameters()+"\n";
	String[] par = f.parameterNames();
	for (int i =0; i<f.numberOfParameters(); i++) out += "\t\t Parameter "+i+"\t Name: "+par[i]+"\n";

	out += "Provides gradiant: "+f.providesGradient();

	return out;
    }

    public static void main(String[] args) {

	FunctionCreator fc = new FunctionCreator();

	IFunction f = fc.createFromCodelet(args[0]);
	System.out.println(fc.toString(f));
    }


}
