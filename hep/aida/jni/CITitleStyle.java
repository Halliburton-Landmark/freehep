package hep.aida.jni;

import hep.aida.*;

public class CITitleStyle extends CIBaseStyle implements ITitleStyle {

    public CITitleStyle(long crefID) {
        super(crefID);
    }

    public native ITextStyle textStyle();

    public native boolean setTextStyle(ITextStyle textStyle);
} 

