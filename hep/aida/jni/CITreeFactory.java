package hep.aida.jni;

import java.io.*;

import hep.aida.*;

public class CITreeFactory extends CProxy implements ITreeFactory {

    public CITreeFactory(long crefID) {
        super(crefID);
    }

    public native ITree create();

    public native ITree create(String storeName) throws IllegalArgumentException, IOException;
    public native ITree create(String storeName, String storeType) throws IllegalArgumentException, IOException;
    public native ITree create(String storeName, String storeType, boolean readOnly) throws IllegalArgumentException, IOException;
    public native ITree create(String storeName, String storeType, boolean readOnly, boolean createNew) throws IllegalArgumentException, IOException;
    public native ITree create(String storeName, String storeType, boolean readOnly, boolean createNew, String options) throws IllegalArgumentException, IOException;
} 
