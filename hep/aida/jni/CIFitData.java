package hep.aida.jni;

import hep.aida.*;


public class CIFitData extends CProxy implements IFitData {

    public CIFitData(long crefID) {
        super(crefID);
    }

    public native  void create1DConnection(IHistogram1D h) throws IllegalArgumentException;

    public native  void create1DConnection(ICloud1D c) throws IllegalArgumentException;

    public native  void create1DConnection(IProfile1D p) throws IllegalArgumentException;

    public native  void create1DConnection(IDataPointSet dp, int xIndex, int valIndex) throws IllegalArgumentException;

//    public native  void create1DConnection(double[] x, double[] y, double[][] corrMatrix) throws IllegalArgumentException;

    public native  void create2DConnection(IHistogram2D h) throws IllegalArgumentException;

    public native  void create2DConnection(IHistogram2D h, int xIndex, int yIndex) throws IllegalArgumentException;

    public native  void create2DConnection(ICloud2D c) throws IllegalArgumentException;

    public native  void create2DConnection(ICloud2D c, int xIndex, int yIndex) throws IllegalArgumentException;

    public native  void create2DConnection(IProfile2D p) throws IllegalArgumentException;

    public native void create2DConnection(IProfile2D p, int xIndex, int yIndex) throws IllegalArgumentException;

    public native void create2DConnection(IDataPointSet dp, int xIndex, int yIndex, int valIndex) throws IllegalArgumentException;

    public native void create3DConnection(IHistogram3D h) throws IllegalArgumentException;

    public native void create3DConnection(IHistogram3D h, int xIndex, int yIndex, int zIndex) throws IllegalArgumentException;

    public native void create3DConnection(ICloud3D c) throws IllegalArgumentException;

    public native void create3DConnection(ICloud3D c, int xIndex, int yIndex, int zIndex) throws IllegalArgumentException;

    public native void create3DConnection(IDataPointSet dp, int xIndex, int yIndex, int zIndex, int valIndex) throws IllegalArgumentException;

    public native void createConnection(ITuple t, String[] colNames) throws IllegalArgumentException;

    public native void createConnection(ITuple t, IEvaluator[] evals) throws IllegalArgumentException;

    public native void createConnection(IDataPointSet dp, int[] indices, int valIndex) throws IllegalArgumentException;

    public native void reset();

    public native int dimension();

    public native String dataDescription();

    public native IRangeSet range(int index) throws IllegalArgumentException;

} 

