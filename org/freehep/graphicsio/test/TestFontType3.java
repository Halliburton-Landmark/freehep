// Copyright 2003, FreeHEP.
package org.freehep.graphicsio.test;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import javax.swing.border.*;

import java.io.FileOutputStream;
import java.io.OutputStream;

import org.freehep.graphics2d.*;
import org.freehep.graphicsio.*;
import org.freehep.graphicsio.exportchooser.*;
import org.freehep.graphicsio.pdf.*;
import org.freehep.graphicsio.ps.*;
import org.freehep.util.*;

/**
 *
 * @author Mark Donszelmann
 * @version $Id: TestFontType3.java,v 1.2 2003/05/03 15:58:15 duns Exp $
 */
public class TestFontType3
    extends TestTaggedString {

    public TestFontType3(String[] args) throws Exception {
        super(args);
        setName("Test Font Type3");
    }

    public static void main(String[] args) throws Exception {
        UserProperties p = new UserProperties();
        p.setProperty(PDFGraphics2D.EMBED_FONTS, true);
        p.setProperty(PDFGraphics2D.EMBED_FONTS_AS, FontConstants.EMBED_FONTS_TYPE3);
        p.setProperty(PSGraphics2D.EMBED_FONTS, true);
        p.setProperty(PSGraphics2D.EMBED_FONTS_AS, FontConstants.EMBED_FONTS_TYPE3);

        new TestFontType3(args).runTest(p);
    }
}
