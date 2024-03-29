// Copyright 2003, FreeHEP
package org.freehep.graphicsio.raw;

import java.awt.*;
import java.io.*;
import java.util.*;
import javax.imageio.*;
import javax.imageio.metadata.*;
import javax.imageio.spi.*;

import org.freehep.graphicsio.ImageParamConverter;
import org.freehep.util.UserProperties;

/**
 *
 * @version $Id: RawImageWriteParam.java,v 1.2 2003/12/06 00:12:29 duns Exp $
 */
public class RawImageWriteParam extends ImageWriteParam implements ImageParamConverter {

    private final static String rootKey = RawImageWriteParam.class.getName();
    public final static String BACKGROUND   = rootKey+".Background";
    public final static String CODE         = rootKey+".Code";
    public final static String PAD          = rootKey+".Pad";

    private Color bkg;
    private String code;
    private int pad;

    public RawImageWriteParam(Locale locale) {
        super(locale);
        bkg = null;
        code = "ARGB";
        pad = 1;
    }

    public ImageWriteParam getWriteParam(Properties properties) {
        UserProperties p = new UserProperties(properties);
        setBackground(p.getPropertyColor(BACKGROUND, bkg));
        setCode(p.getProperty(CODE, code));
        setPad(p.getPropertyInt(PAD, pad));
        return this;
    }

    public Color getBackground() {
        return bkg;
    }

    public void setBackground(Color bkg) {
        this.bkg = bkg;
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public int getPad() {
        return pad;
    }

    public void setPad(int pad) {
        this.pad = pad;
    }
}
                    