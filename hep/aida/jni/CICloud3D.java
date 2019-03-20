package hep.aida.jni;

import hep.aida.*;

public class CICloud3D extends CICloud implements ICloud3D {

    public CICloud3D(long crefID) {
        super(crefID);
    }

    public native void fill(double x, double y, double z);

    public native void fill(double x, double y, double z, double weight);

    public native double lowerEdgeX();
    public native double lowerEdgeY();
    public native double lowerEdgeZ();
    
    public native double upperEdgeX();
    public native double upperEdgeY();
    public native double upperEdgeZ();
    
    public native double valueX(int index) throws AlreadyConvertedException;
    public native double valueY(int index) throws AlreadyConvertedException;
    public native double valueZ(int index) throws AlreadyConvertedException;
    
    public native double weight(int index) throws AlreadyConvertedException;

    public native double meanX();
    public native double meanY();
    public native double meanZ();

    public native double rmsX();
    public native double rmsY();
    public native double rmsZ();

    public native void convert(int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, int nBinsZ, double lowerEdgeZ, double upperEdgeZ) throws AlreadyConvertedException;
    
    public native void convert(double[] binEdgesX, double[] binEdgesY, double[] binEdgesZ) throws AlreadyConvertedException;
    
    public native IHistogram3D histogram();
    
    public native void fillHistogram(IHistogram3D h);
}
