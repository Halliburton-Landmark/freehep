package hep.aida.jni;

import hep.aida.*;

public class CIProfile1D extends CIProfile implements IProfile1D {

    public CIProfile1D(long crefID) {
        super(crefID);
    }

    public native void fill(double x, double y);

    public native void fill(double x, double y, double weight);

    public native double binMean(int index);

    public native int binEntries(int index);

    public native double binHeight(int index);

    public native double binError(int index);

    public native double binRms(int index);

    public native double mean();

    public native double rms();

    public native IAxis axis();

    public native int coordToIndex(double coord);

    public native void add(IProfile1D p);
}
