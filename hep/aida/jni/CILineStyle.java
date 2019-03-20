package hep.aida.jni;

import hep.aida.*;

public class CILineStyle extends CIBrushStyle implements ILineStyle {

    public CILineStyle(long crefID) {
        super(crefID);
    }

    public native String[] availableLineTypes();

    public native String lineType();

    public native int thickness();

    public native boolean setLineType(String newLineType);

    public native boolean setThickness(int newThickness);
}

