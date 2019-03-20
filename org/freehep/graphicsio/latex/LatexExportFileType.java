// Copyright 2004, FreeHEP.
package org.freehep.graphicsio.latex;

import java.awt.*;
import java.io.*;
import java.util.*;
import javax.swing.*;
import javax.swing.filechooser.FileFilter;

import org.freehep.graphics2d.VectorGraphics;
import org.freehep.graphicsio.exportchooser.AbstractExportFileType;
import org.freehep.swing.ExtensionFileFilter;
import org.freehep.util.UserProperties;

/**
 *
 * @author Andre Bach
 * @version $Id: LatexExportFileType.java,v 1.2 2004/08/20 18:14:06 duns Exp $
 */
public class LatexExportFileType extends AbstractExportFileType {

    public String getDescription() {
        return "LaTeX";
    }

    public String[] getExtensions() {
        return new String[] { "tex" };
    }
    
    public String[] getMIMETypes() {
        return new String[] { "image/tex" };
    }
    
    public VectorGraphics getGraphics(OutputStream os, Component target)
            throws IOException {
        // Not sure what the value of the boolean should be. Or add another constructor?
        return new LatexGraphics2D(os, target, false);
    }
}
