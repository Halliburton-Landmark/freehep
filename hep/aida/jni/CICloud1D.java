package hep.aida.jni;

import hep.aida.*;

public class CICloud1D extends CICloud implements ICloud1D {

    public CICloud1D(long crefID) {
        super(crefID);
    }

    public native void fill(double x);

    public native void fill(double x, double weight);

    public native double lowerEdge();
    
    public native double upperEdge();
    
    public native double value(int index) throws AlreadyConvertedException;
    
    public native double weight(int index) throws AlreadyConvertedException;

    public native double mean();

    public native double rms();

    public native void convert(int nBins, double lowerEdge, double upperEdge) throws AlreadyConvertedException;
    
    public native void convert(double[] binEdges) throws AlreadyConvertedException;
    
    public native IHistogram1D histogram();
    
    public native void fillHistogram(IHistogram1D h);
}
