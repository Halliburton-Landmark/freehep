package hep.aida.jni;

import hep.aida.*;

public class CIHistogram3D extends CIHistogram implements IHistogram3D {

    public CIHistogram3D(long crefID) {
        super(crefID);
    }

    public native void fill(double x, double y, double z);

    public native void fill(double x, double y, double z, double weight);

    public native double binMeanX(int xIndex, int yIndex, int zIndex);
    public native double binMeanY(int xIndex, int yIndex, int zIndex);
    public native double binMeanZ(int xIndex, int yIndex, int zIndex);

    public native int binEntries(int xIndex, int yIndex, int zIndex);

    public native int binEntriesX(int index);
    public native int binEntriesY(int index);
    public native int binEntriesZ(int index);

    public native double binHeight(int xIndex, int yIndex, int zIndex);
    
    public native double binHeightX(int index);
    public native double binHeightY(int index);
    public native double binHeightZ(int index);

    public native double binError(int xIndex, int yIndex, int zIndex);

    public native double meanX();
    public native double meanY();
    public native double meanZ();

    public native double rmsX();
    public native double rmsY();
    public native double rmsZ();

    public native IAxis xAxis();
    public native IAxis yAxis();
    public native IAxis zAxis();

    public native int coordToIndexX(double coord);
    public native int coordToIndexY(double coord);
    public native int coordToIndexZ(double coord);

    public native void add(IHistogram3D hist);
}
