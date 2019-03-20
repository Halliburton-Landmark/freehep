// Copyright 2000-2003 FreeHEP
package org.freehep.graphicsio.java;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;
import javax.swing.*;

import org.freehep.graphics2d.VectorGraphics;
import org.freehep.graphicsio.exportchooser.AbstractExportFileType;
import org.freehep.util.UserProperties;

/**
 * // FIXME, check all options
 * @author Mark Donszelmann
 * @version $Id: JAVAExportFileType.java,v 1.6 2004/01/15 19:16:55 duns Exp $
 */
public class JAVAExportFileType extends AbstractExportFileType {

    public String getDescription() {
        return "Java Source File (for Testing)";
    }

    public String[] getExtensions() {
        return new String[] { "java", "JAVA" };
    }

    public String[] getMIMETypes() {
       return new String[] { "application/java" };
    }

    public boolean hasOptionPanel() {
        return false;
    }

    public VectorGraphics getGraphics(File file, Component target)
            throws IOException {

        return new JAVAGraphics2D(file, target);
    }

    public VectorGraphics getGraphics(OutputStream os, Component target)
            throws IOException {

        return new JAVAGraphics2D(os, target);
    }

}
