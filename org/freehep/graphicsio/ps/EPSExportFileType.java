// Copyright 2000, CERN, Geneva, Switzerland and University of Santa Cruz, California, U.S.A.
package org.freehep.graphicsio.ps;

import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.util.Properties;

import javax.swing.*;
import javax.swing.border.*;
import javax.swing.filechooser.FileFilter;

import org.freehep.graphics2d.VectorGraphics;
import org.freehep.graphicsio.PageConstants;
import org.freehep.graphicsio.exportchooser.OptionPanel;
import org.freehep.swing.ExtensionFileFilter;
import org.freehep.swing.layout.TableLayout;
import org.freehep.util.UserProperties;

/**
 *
 * @author Charles Loomis
 * @version $Id: EPSExportFileType.java,v 1.7 2004/01/15 19:16:56 duns Exp $
 */
public class EPSExportFileType
    extends AbstractPSExportFileType {

    public String getDescription() {
        return "Encapsulated PostScript";
    }

    public String[] getExtensions() {
        return new String[] {"eps","EPS","epi","EPI","epsi","EPSI","epsf","EPSF"};
    }

    public JPanel createOptionPanel(Properties user) {
        UserProperties options = new UserProperties(user, PSGraphics2D.getDefaultProperties());
        JPanel panel = super.createOptionPanel(options);
        preview.setVisible(true);
        return panel;
    }

    public VectorGraphics getGraphics(OutputStream os, Component target)
        throws IOException {

        return new PSGraphics2D(os, target);
    }
}
