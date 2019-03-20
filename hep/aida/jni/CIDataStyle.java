package hep.aida.jni;

import hep.aida.*;

public class CIDataStyle extends CIBaseStyle implements IDataStyle {

    public CIDataStyle(long crefID) {
        super(crefID);
    }

    public native ILineStyle lineStyle();

    public native IMarkerStyle markerStyle();

    public native IFillStyle fillStyle();

    public native boolean setLineStyle(ILineStyle lineStyle);

    public native boolean setMarkerStyle(IMarkerStyle markerStyle);

    public native boolean setFillStyle(IFillStyle fillStyle);
} 
