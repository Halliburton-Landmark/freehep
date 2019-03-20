package hep.aida.jni;

import hep.aida.*;

public class CICloud2D extends CICloud implements ICloud2D {

    public CICloud2D(long crefID) {
        super(crefID);
    }

    public native void fill(double x, double y);

    public native void fill(double x, double y, double weight);

    public native double lowerEdgeX();
    public native double lowerEdgeY();
    
    public native double upperEdgeX();
    public native double upperEdgeY();
    
    public native double valueX(int index) throws AlreadyConvertedException;
    public native double valueY(int index) throws AlreadyConvertedException;
    
    public native double weight(int index) throws AlreadyConvertedException;

    public native double meanX();
    public native double meanY();

    public native double rmsX();
    public native double rmsY();

    public native void convert(int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY) throws AlreadyConvertedException;
    
    public native void convert(double[] binEdgesX, double[] binEdgesY) throws AlreadyConvertedException;
    
    public native IHistogram2D histogram();
    
    public native void fillHistogram(IHistogram2D h);
}
