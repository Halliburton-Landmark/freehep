package hep.aida.jni;

import hep.aida.*;

public class CIInfo extends CProxy implements IInfo {

    public CIInfo(long crefID) {
        super(crefID);
    }

    public native void clear();

    public native void addText(String text);

    public native void addLegend(IMarkerStyle style, String description);

    public native void addLegend(ILineStyle style, String description);

    public native void addLegend(IFillStyle style, String description);
} 

