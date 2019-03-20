package hep.aida.jni;

import hep.aida.*;

public class CIDataPoint extends CProxy implements  IDataPoint {

    public CIDataPoint(long crefID) {
        super(crefID);
    }

    public native int dimension();

    public native IMeasurement coordinate(int coord);
} 

