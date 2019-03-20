package hep.aida.jni;

import hep.aida.*;

public class CIHistogram1D extends CIHistogram implements IHistogram1D {

    public CIHistogram1D(long crefID) {
        super(crefID);
    }

    public native void fill(double x);

    public native void fill(double x, double weight);

    public native double binMean(int index);

    public native int binEntries(int index);

    public native double binHeight(int index);

    public native double binError(int index);

    public native double mean();

    public native double rms();

    public native IAxis axis();

    public native int coordToIndex(double coord);

    public native void add(IHistogram1D hist);
}
