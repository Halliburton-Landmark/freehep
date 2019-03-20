package org.freehep.graphicsio.swf;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;
import javax.swing.*;

import org.freehep.graphics2d.VectorGraphics;
import org.freehep.graphicsio.ImageConstants;
import org.freehep.graphicsio.exportchooser.AbstractExportFileType;
import org.freehep.graphicsio.exportchooser.BackgroundPanel;
import org.freehep.graphicsio.exportchooser.OptionPanel;
import org.freehep.graphicsio.exportchooser.ImageTypePanel;
import org.freehep.swing.layout.TableLayout;
import org.freehep.util.UserProperties;

/**
 * // FIXME, check all options
 * @author Mark Donszelmann
 * @version $Id: SWFExportFileType.java,v 1.11 2005/01/10 21:54:55 duns Exp $
 */
public class SWFExportFileType extends AbstractExportFileType {

    public String getDescription() {
        return "MacroMedia Flash File Format";
    }

    public String[] getExtensions() {
        return new String[] { "swf", "SWF"};
    }

    public String[] getMIMETypes() {
        return new String[] {"application/x-shockwave-flash"};
    }

    public boolean hasOptionPanel() {
        return true;
    }

    public JPanel createOptionPanel(Properties user) {
        UserProperties options = new UserProperties(user, SWFGraphics2D.getDefaultProperties());

        String rootKey = SWFGraphics2D.class.getName();

        // Make the full panel.
        OptionPanel optionsPanel = new OptionPanel();
        optionsPanel.add("0 0 [5 5 5 5] wt", new BackgroundPanel(options, rootKey, true));
        optionsPanel.add("0 1 [5 5 5 5] wt", new ImageTypePanel(options, rootKey,
            new String[] {ImageConstants.SMALLEST, ImageConstants.ZLIB, ImageConstants.JPG}));
        optionsPanel.add(TableLayout.COLUMN_FILL, new JLabel());

        return optionsPanel;
    }

    public VectorGraphics getGraphics(OutputStream os, Component target)
            throws IOException {

        return new SWFGraphics2D(os, target);
    }

}
