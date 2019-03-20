package hep.aida.jni;

import hep.aida.*;

public class CITuple extends CProxy implements ITuple {

    public CITuple(long crefID) {
        super(crefID);
    }

    public native  String title();

    public native  void setTitle(String title) throws IllegalArgumentException;

    public native  IAnnotation annotation();

    public native  void fill(int column, double value) throws IllegalArgumentException;

    public native  void fill(int column, float value) throws IllegalArgumentException;

    public native  void fill(int column, int value) throws IllegalArgumentException;

    public native  void fill(int column, short value) throws IllegalArgumentException;

    public native  void fill(int column, long value) throws IllegalArgumentException;

    public native  void fill(int column, char value) throws IllegalArgumentException;

    public native  void fill(int column, byte value) throws IllegalArgumentException;

    public native  void fill(int column, boolean value) throws IllegalArgumentException;

    public native  void fill(int column, String value) throws IllegalArgumentException;

    public native  void fill(int column, Object value) throws IllegalArgumentException;

    public native  void fill(double[] values) throws IllegalArgumentException;

    public native  void fill(float[] values) throws IllegalArgumentException;

    public native  void addRow() throws OutOfStorageException;

    public native  void resetRow();

    public native  void reset();

    public native  int rows();

    public native  void start();

    public native  void skip(int rows) throws IllegalArgumentException;

    public native  boolean next();

    public native  void setRow(int rowIndex) throws IllegalArgumentException;

    public native  int findColumn(String name) throws IllegalArgumentException;

    public native  double getDouble(int column) throws ClassCastException;

    public native  float getFloat(int column) throws ClassCastException;

    public native  int getInt(int column) throws ClassCastException;

    public native  short getShort(int column) throws ClassCastException;

    public native  long getLong(int column) throws ClassCastException;

    public native  char getChar(int column) throws ClassCastException;

    public native  byte getByte(int column) throws ClassCastException;
 
    public native  boolean getBoolean(int column) throws ClassCastException;

    public native  String getString(int column) throws ClassCastException;

    public native  Object getObject(int column) throws ClassCastException;

    public native  ITuple getTuple(int column);

    public native  int columns();

    public native  String columnName(int column) throws IllegalArgumentException;

    public native  String[] columnNames();

    public native  Class columnType(int column) throws IllegalArgumentException;

    public native  Class[] columnTypes();

    public native  double columnMin(int column) throws IllegalArgumentException;

    public native  double columnMax(int column) throws IllegalArgumentException;

    public native  double columnMean(int column) throws IllegalArgumentException;

    public native  double columnRms(int column) throws IllegalArgumentException;

    public native  void project(IHistogram1D histogram, IEvaluator evaluatorX) throws IllegalArgumentException;

    public native  void project(IHistogram1D histogram, IEvaluator evaluatorX, IFilter filter) throws IllegalArgumentException;

    public native  void project(IHistogram1D histogram, IEvaluator evaluatorX, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(IHistogram1D histogram, IEvaluator evaluatorX, IFilter filter, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(IHistogram2D histogram, IEvaluator evaluatorX, IEvaluator evaluatorY) throws IllegalArgumentException;

    public native  void project(IHistogram2D histogram, IEvaluator evaluatorX, IEvaluator evaluatorY, IFilter filter) throws IllegalArgumentException;

    public native  void project(IHistogram2D histogram, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(IHistogram2D histogram, IEvaluator evaluatorX, IEvaluator evaluatorY, IFilter filter, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(IHistogram3D histogram, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator evaluatorZ) throws IllegalArgumentException;

    public native  void project(IHistogram3D histogram, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator evaluatorZ, IFilter filter) throws IllegalArgumentException;

    public native  void project(IHistogram3D histogram, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator evaluatorZ, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(IHistogram3D histogram, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator evaluatorZ, IFilter filter, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(ICloud1D cloud, IEvaluator evaluatorX) throws IllegalArgumentException;

    public native  void project(ICloud1D cloud, IEvaluator evaluatorX, IFilter filter) throws IllegalArgumentException;

    public native  void project(ICloud1D cloud, IEvaluator evaluatorX, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(ICloud1D cloud, IEvaluator evaluatorX, IFilter filter, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(ICloud2D cloud, IEvaluator evaluatorX, IEvaluator evaluatorY) throws IllegalArgumentException;

    public native  void project(ICloud2D cloud, IEvaluator evaluatorX, IEvaluator evaluatorY, IFilter filter) throws IllegalArgumentException;

    public native  void project(ICloud2D cloud, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(ICloud2D cloud, IEvaluator evaluatorX, IEvaluator evaluatorY, IFilter filter, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(ICloud3D cloud, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator evaluatorZ) throws IllegalArgumentException;

    public native  void project(ICloud3D cloud, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator evaluatorZ, IFilter filter) throws IllegalArgumentException;

    public native  void project(ICloud3D cloud, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator evaluatorZ, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(ICloud3D cloud, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator evaluatorZ, IFilter filter, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(IProfile1D profile, IEvaluator evaluatorX, IEvaluator evaluatorY) throws IllegalArgumentException;

    public native  void project(IProfile1D profile, IEvaluator evaluatorX, IEvaluator evaluatorY, IFilter filter) throws IllegalArgumentException;

    public native  void project(IProfile1D profile, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(IProfile1D profile, IEvaluator evaluatorX, IEvaluator evaluatorY, IFilter filter, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(IProfile2D profile, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator evaluatorZ) throws IllegalArgumentException;

    public native  void project(IProfile2D profile, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator evaluatorZ, IFilter filter) throws IllegalArgumentException;

    public native  void project(IProfile2D profile, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator evaluatorZ, IEvaluator weight) throws IllegalArgumentException;

    public native  void project(IProfile2D profile, IEvaluator evaluatorX, IEvaluator evaluatorY, IEvaluator evaluatorZ, IFilter filter, IEvaluator weight) throws IllegalArgumentException;
}

