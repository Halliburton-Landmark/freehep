package hep.aida.jni;

import hep.aida.*;

public class CIDataPointSetFactory extends CProxy implements IDataPointSetFactory {

    public CIDataPointSetFactory(long crefID) {
        super(crefID);
    }

    public native IDataPointSet create(String path, String title, int dimOfPoints) throws IllegalArgumentException;
    public native IDataPointSet create(String pathAndTitle, int dimOfPoints) throws IllegalArgumentException;
    public native IDataPointSet createY(String path, String title, double[] y, double[] ey) throws IllegalArgumentException;
    public native IDataPointSet createY(String path, String title, double[] y, double[] eyp, double[] eym) throws IllegalArgumentException;
    public native IDataPointSet createY(String pathAndTitle, double[] y, double[] ey) throws IllegalArgumentException;
    public native IDataPointSet createY(String pathAndTitle, double[] y, double[] eyp, double[] eym) throws IllegalArgumentException;
    public native IDataPointSet createX(String path, String title, double[] x, double[] ex) throws IllegalArgumentException;
    public native IDataPointSet createX(String path, String title, double[] x, double[] exp, double[] exm) throws IllegalArgumentException;
    public native IDataPointSet createX(String pathAndTitle, double[] x, double[] ex) throws IllegalArgumentException;
    public native IDataPointSet createX(String pathAndTitle, double[] x, double[] exp, double[] exm) throws IllegalArgumentException;
    public native IDataPointSet createXY(String path, String title, double[] x, double[] y, double[] exp, double[] eyp, double[] exm, double[] eym) throws IllegalArgumentException;
    public native IDataPointSet createXY(String path, String title, double[] x, double[] y, double[] ex, double[] ey) throws IllegalArgumentException;
    public native IDataPointSet createXY(String pathAndTitle, double[] x, double[] y, double[] exp, double[] eyp, double[] exm, double[] eym) throws IllegalArgumentException;
    public native IDataPointSet createXY(String pathAndTitle, double[] x, double[] y, double[] ex, double[] ey) throws IllegalArgumentException;
    public native IDataPointSet createXYZ(String path, String title, double[] x, double[] y, double[] z, double[] exp, double[] eyp, double[] ezp, double[] exm, double[] eym, double[] ezm) throws IllegalArgumentException;
    public native IDataPointSet createXYZ(String path, String title, double[] x, double[] y, double[] z, double[] ex, double[] ey, double[] ez) throws IllegalArgumentException;
    public native IDataPointSet createXYZ(String pathAndTitle, double[] x, double[] y, double[] z, double[] exp, double[] eyp, double[] ezp, double[] exm, double[] eym, double[] ezm) throws IllegalArgumentException;
    public native IDataPointSet createXYZ(String pathAndTitle, double[] x, double[] y, double[] z, double[] ex, double[] ey, double[] ez) throws IllegalArgumentException;
    public native IDataPointSet createCopy(String path, IDataPointSet dataPointSet) throws IllegalArgumentException;
    public native void destroy(IDataPointSet dataPointSet) throws IllegalArgumentException;
    public native IDataPointSet create(String path, IHistogram1D hist) throws IllegalArgumentException;
    public native IDataPointSet create(String path, IHistogram1D hist, String options) throws IllegalArgumentException;
    public native IDataPointSet create(String path, IHistogram2D hist) throws IllegalArgumentException;
    public native IDataPointSet create(String path, IHistogram2D hist, String options) throws IllegalArgumentException;
    public native IDataPointSet create(String path, IHistogram3D hist) throws IllegalArgumentException;
    public native IDataPointSet create(String path, IHistogram3D hist, String options) throws IllegalArgumentException;
    public native IDataPointSet create(String path, ICloud1D cloud) throws IllegalArgumentException;
    public native IDataPointSet create(String path, ICloud1D cloud, String options) throws IllegalArgumentException;
    public native IDataPointSet create(String path, ICloud2D cloud) throws IllegalArgumentException;
    public native IDataPointSet create(String path, ICloud2D cloud, String options) throws IllegalArgumentException;
    public native IDataPointSet create(String path, ICloud3D cloud) throws IllegalArgumentException;
    public native IDataPointSet create(String path, ICloud3D cloud, String options) throws IllegalArgumentException;
    public native IDataPointSet create(String path, IProfile1D profile) throws IllegalArgumentException;
    public native IDataPointSet create(String path, IProfile1D profile, String options) throws IllegalArgumentException;
    public native IDataPointSet create(String path, IProfile2D profile) throws IllegalArgumentException;
    public native IDataPointSet create(String path, IProfile2D profile, String options) throws IllegalArgumentException;
    public native IDataPointSet add(String path, IDataPointSet dataPointSet1, IDataPointSet dataPointSet2) throws IllegalArgumentException;
    public native IDataPointSet subtract(String path, IDataPointSet dataPointSet1, IDataPointSet dataPointSet2) throws IllegalArgumentException;
    public native IDataPointSet multiply(String path, IDataPointSet dataPointSet1, IDataPointSet dataPointSet2) throws IllegalArgumentException;
    public native IDataPointSet divide(String path, IDataPointSet dataPointSet1, IDataPointSet dataPointSet2) throws IllegalArgumentException;
    public native IDataPointSet weightedMean(String path, IDataPointSet dataPointSet1, IDataPointSet dataPointSet2) throws IllegalArgumentException;
} 
