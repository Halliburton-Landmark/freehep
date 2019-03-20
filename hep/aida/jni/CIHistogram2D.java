package hep.aida.jni;

import hep.aida.*;

public class CIHistogram2D extends CIHistogram implements IHistogram2D {

    public CIHistogram2D(long crefID) {
        super(crefID);
    }

    public native void fill(double x, double y);

    public native void fill(double x, double y, double weight);

    public native double binMeanX(int xIndex, int yIndex);
    public native double binMeanY(int xIndex, int yIndex);

    public native int binEntries(int xIndex, int yIndex);

    public native int binEntriesX(int index);
    public native int binEntriesY(int index);

    public native double binHeight(int xIndex, int yIndex);
    
    public native double binHeightX(int index);
    public native double binHeightY(int index);

    public native double binError(int xIndex, int yIndex);

    public native double meanX();
    public native double meanY();

    public native double rmsX();
    public native double rmsY();

    public native IAxis xAxis();
    public native IAxis yAxis();

    public native int coordToIndexX(double coord);
    public native int coordToIndexY(double coord);

    public native void add(IHistogram2D hist);
}
