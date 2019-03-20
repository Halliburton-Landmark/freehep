package hep.aida.jni;

import hep.aida.*;

public class CIPlotterStyle extends CIBaseStyle implements  IPlotterStyle {

    public CIPlotterStyle(long crefID) {
        super(crefID);
    }

    public native IDataStyle dataStyle();

    public native IAxisStyle xAxisStyle();

    public native IAxisStyle yAxisStyle();

    public native IAxisStyle zAxisStyle();

    public native ITitleStyle titleStyle();

    public native IInfoStyle infoStyle();

    public native boolean setDataStyle(IDataStyle dataStyle);

    public native boolean setAxisStyleX(IAxisStyle xAxisStyle);

    public native boolean setAxisStyleY(IAxisStyle yAxisStyle);

    public native boolean setAxisStyleZ(IAxisStyle zAxisStyle);

    public native boolean setTitleStyle(ITitleStyle textStyle);

    public native boolean setInfoStyle(IInfoStyle infoStyle);
} 
