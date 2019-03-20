package hep.aida.jni;

import hep.aida.*;

public class CIBrushStyle extends CIBaseStyle implements IBrushStyle {

    public CIBrushStyle(long crefID) {
        super(crefID);
    }

    public native String[] availableColors();

    public native String color();

    public native double opacity();

    public native boolean setColor(String newColor);

    public native boolean setOpacity(double newOpacity);
} 
