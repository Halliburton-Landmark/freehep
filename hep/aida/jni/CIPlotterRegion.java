package hep.aida.jni;

import hep.aida.*;



public class CIPlotterRegion extends CProxy implements IPlotterRegion {

    public CIPlotterRegion(long crefID) {
        super(crefID);
    }

    public native void plot(IBaseHistogram histogram) throws IllegalArgumentException;
    public native void plot(IBaseHistogram histogram, String options) throws IllegalArgumentException;

    public native void plot(IBaseHistogram histogram, IPlotterStyle style) throws IllegalArgumentException;
    public native void plot(IBaseHistogram histogram, IPlotterStyle style, String options) throws IllegalArgumentException;

    public native void plot(IFunction function) throws IllegalArgumentException;
    public native void plot(IFunction function, String options) throws IllegalArgumentException;

    public native void plot(IFunction function, IPlotterStyle style) throws IllegalArgumentException;
    public native void plot(IFunction function, IPlotterStyle style, String options) throws IllegalArgumentException;

    public native void plot(IDataPointSet dataPointSet) throws IllegalArgumentException;
    public native void plot(IDataPointSet dataPointSet, String options) throws IllegalArgumentException;

    public native void plot(IDataPointSet dataPointSet, IPlotterStyle style) throws IllegalArgumentException;
    public native void plot(IDataPointSet dataPointSet, IPlotterStyle style, String options) throws IllegalArgumentException;

    public native void remove(IBaseHistogram histogram) throws IllegalArgumentException;

    public native void remove(IFunction function) throws IllegalArgumentException;

    public native void remove(IDataPointSet dataPointSet) throws IllegalArgumentException;

    public native void clear();

    public native void setParameter(String parameter) throws IllegalArgumentException;
    public native void setParameter(String parameter, String options) throws IllegalArgumentException;

    public native String parameterValue(String parameter);

    public native String[] availableParameterOptions(String parameter);

    public native String[] availableParameters();

    public native IPlotterStyle style();

    public native void setStyle(IPlotterStyle style) throws IllegalArgumentException;

    public native void applyStyle(IPlotterStyle style) throws IllegalArgumentException;

    public native void setTitle(String title);

    public native void setXLimits() throws IllegalArgumentException;
    public native void setXLimits(double min) throws IllegalArgumentException;
    public native void setXLimits(double min, double max) throws IllegalArgumentException;

    public native void setYLimits() throws IllegalArgumentException;
    public native void setYLimits(double min) throws IllegalArgumentException;
    public native void setYLimits(double min, double max) throws IllegalArgumentException;

    public native void setZLimits() throws IllegalArgumentException;
    public native void setZLimits(double min) throws IllegalArgumentException;
    public native void setZLimits(double min, double max) throws IllegalArgumentException;

    public native IPlotterLayout layout();

    public native void setLayout(IPlotterLayout layout) throws IllegalArgumentException;

    public native IInfo info();
} 
