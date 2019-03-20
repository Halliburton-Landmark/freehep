package hep.aida.jni;

import hep.aida.*;

public class CIMarkerStyle extends CIBrushStyle implements IMarkerStyle {

    public CIMarkerStyle(long crefID) {
        super(crefID);
    }

    public native String[] availableShapes();

    public native String shape();

    public native boolean setShape(String shape);
} 

