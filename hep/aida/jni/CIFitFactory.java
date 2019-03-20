package hep.aida.jni;

import hep.aida.*;

public class CIFitFactory extends CProxy implements IFitFactory {

    public CIFitFactory(long crefID) {
        super(crefID);
    }

    public native IFitData createFitData();
    public native IFitter createFitter() throws IllegalArgumentException;
    public native IFitter createFitter(String fitterType) throws IllegalArgumentException;
    public native IFitter createFitter(String fitterType, String engineType) throws IllegalArgumentException;
    public native IFitter createFitter(String fitterType, String engineType, String options) throws IllegalArgumentException;
}

