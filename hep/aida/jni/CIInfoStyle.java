package hep.aida.jni;

import hep.aida.*;

public class CIInfoStyle extends CIBaseStyle implements IInfoStyle {

    public CIInfoStyle(long crefID) {
        super(crefID);
    }

    public native ITextStyle textStyle();

    public native boolean setTextStyle(ITextStyle textStyle);
} 
