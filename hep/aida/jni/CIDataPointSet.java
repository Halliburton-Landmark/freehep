package hep.aida.jni;

import hep.aida.*;

public class CIDataPointSet extends CProxy implements IDataPointSet {

    public CIDataPointSet(long crefID) {
        super(crefID);
    }

    public native IAnnotation annotation();

    public native String title();

    public native void setTitle(String title) throws IllegalArgumentException;

    public native int dimension();

    public native void clear();

    public native int size();

    public native IDataPoint point(int index);

    public native void setCoordinate(int coord, double[] val, double[] err) throws IllegalArgumentException;

    public native void setCoordinate(int coord, double[] val, double[] errp, double[] errm) throws IllegalArgumentException;

    public native IDataPoint addPoint() throws RuntimeException;

    public native void addPoint(IDataPoint point) throws IllegalArgumentException;

    public native void removePoint(int index) throws IllegalArgumentException;
      
    public native double lowerExtent(int coord) throws IllegalArgumentException;

    public native double upperExtent(int coord) throws IllegalArgumentException;

    public native void scale(double scaleFactor) throws IllegalArgumentException;

    public native void scaleValues(double scaleFactor) throws IllegalArgumentException;

    public native void scaleErrors(double scaleFactor) throws IllegalArgumentException;
} 
