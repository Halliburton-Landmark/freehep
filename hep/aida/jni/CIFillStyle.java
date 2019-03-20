package hep.aida.jni;

import hep.aida.*;

public class CIFillStyle extends CIBrushStyle implements IFillStyle {

    public CIFillStyle(long crefID) {
        super(crefID);
    }

    public native String[] availablePatterns();

    public native String pattern();

    public native boolean setPattern(String pattern);
} 

