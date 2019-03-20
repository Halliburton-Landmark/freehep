package hep.aida.jni;

import hep.aida.*;

public class CITextStyle extends CIBrushStyle implements ITextStyle {

    public CITextStyle(long crefID) {
        super(crefID);
    }

    public native String[] availableFonts();

    public native double fontSize();

    public native boolean setFontSize(double size);

    public native String font();

    public native boolean setFont(String font);

    public native boolean isBold();

    public native boolean isItalic();

    public native boolean isUnderlined();

    public native boolean setBold();
    public native boolean setBold(boolean bold);

    public native boolean setItalic();
    public native boolean setItalic(boolean italic);

    public native boolean setUnderlined();
    public native boolean setUnderlined(boolean underlined);
} 

