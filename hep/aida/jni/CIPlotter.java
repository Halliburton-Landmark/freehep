package hep.aida.jni;

import java.io.*;

import hep.aida.*;


 
public class CIPlotter extends CProxy implements IPlotter {

    public CIPlotter(long crefID) {
        super(crefID);
    }

    public native IPlotterRegion createRegion();
    public native IPlotterRegion createRegion(double x);
    public native IPlotterRegion createRegion(double x, double y);
    public native IPlotterRegion createRegion(double x, double y, double w);
    public native IPlotterRegion createRegion(double x, double y, double w, double h);
    public native void createRegions() throws IllegalArgumentException;
    public native void createRegions(int columns) throws IllegalArgumentException;
    public native void createRegions(int columns, int rows) throws IllegalArgumentException;
    public native void createRegions(int columns, int rows, int index) throws IllegalArgumentException;
    public native IPlotterRegion currentRegion();
    public native int currentRegionNumber();
    public native int numberOfRegions();
    public native void setCurrentRegionNumber(int index) throws IllegalArgumentException;
    public native IPlotterRegion next();
    public native IPlotterRegion region(int index);
    public native void destroyRegions();
    public native void clearRegions();
    public native void setParameter(String parameter) throws IllegalArgumentException;
    public native void setParameter(String parameter, String options) throws IllegalArgumentException;
    public native String parameterValue(String parameter);
    public native String[] availableParameterOptions(String parameter);
    public native String[] availableParameters();

    public native void show() throws RuntimeException;
    public native void refresh() throws RuntimeException;
    public native void hide() throws RuntimeException;
    public native void interact() throws RuntimeException;

    public native void writeToFile(String filename) throws IOException;
    public native void writeToFile(String filename, String type) throws IOException;
    public native void setTitle(String title);
    public native ITitleStyle titleStyle();

    public native void setTitleStyle(ITitleStyle style);
} 
