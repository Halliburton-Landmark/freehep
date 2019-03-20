package hep.aida.jni;

import hep.aida.*;

public class CIAxisStyle extends CIBaseStyle implements IAxisStyle {

    public CIAxisStyle(long crefID) {
        super(crefID);
    }

    public native ILineStyle lineStyle();

    public native ITextStyle tickLabelStyle();

    public native ITextStyle labelStyle();

    public native boolean setlineStyle(ILineStyle lineStyle);

    public native boolean setTickLabelStyle(ITextStyle tickLabelStyle);

    public native boolean setLabelStyle(ITextStyle labelStyle);

    public native void setLabel(String label);
} 
