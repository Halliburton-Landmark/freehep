package hep.aida.jni;

import java.io.*;

import hep.aida.*;


 
public class CIFunctionCatalog extends CProxy implements IFunctionCatalog {

    public CIFunctionCatalog(long crefID) {
        super(crefID);
    }

    public native boolean add(String nameId, IFunction f);

    public native boolean add(String nameId, String codelet);

    public native String[] list();

    public native void remove(String nameId);

    public native void storeAll(String nameOnDisk) throws IOException;

    public native void loadAll(String nameOnDisk) throws IOException;
} 

