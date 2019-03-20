package hep.aida.jni;

import hep.aida.*;

public class CIFunctionFactory extends CProxy implements IFunctionFactory {

    public CIFunctionFactory(long crefID) {
        super(crefID);
    }

    public native IFunction createFunctionByName(String path, String model) throws IllegalArgumentException;
    public native IFunction createFunctionFromScript(String name, int dim, String valexpr, String parameters, String description) throws IllegalArgumentException;
    public native IFunction createFunctionFromScript(String name, int dim, String valexpr, String parameters, String description, String gradexpr) throws IllegalArgumentException;
    public native IFunction cloneFunction(String path, IFunction f) throws IllegalArgumentException;
    public native IFunctionCatalog catalog();
} 
