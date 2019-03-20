// Copyright 2003, FreeHEP.
package org.freehep.graphicsio.ps;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;

import javax.swing.*;
import javax.swing.border.*;
import javax.swing.filechooser.FileFilter;

import org.freehep.graphics2d.VectorGraphics;
import org.freehep.graphicsio.InfoConstants;
import org.freehep.graphicsio.ImageConstants;
import org.freehep.graphicsio.exportchooser.AbstractExportFileType;
import org.freehep.graphicsio.exportchooser.BackgroundPanel;
import org.freehep.graphicsio.exportchooser.FontPanel;
import org.freehep.graphicsio.exportchooser.PageLayoutPanel;
import org.freehep.graphicsio.exportchooser.PageMarginPanel;
import org.freehep.graphicsio.exportchooser.InfoPanel;
import org.freehep.graphicsio.exportchooser.ImageTypePanel;
import org.freehep.graphicsio.exportchooser.OptionPanel;
import org.freehep.graphicsio.exportchooser.OptionCheckBox;
import org.freehep.graphicsio.exportchooser.OptionComboBox;
import org.freehep.swing.layout.TableLayout;
import org.freehep.util.UserProperties;

/**
 *
 * @author Charles Loomis, Simon Fischer
 * @version $Id: AbstractPSExportFileType.java,v 1.10 2003/06/05 17:58:07 duns Exp $
 */
public abstract class AbstractPSExportFileType
    extends AbstractExportFileType {

    protected static final String bitsList[] = {"1","2","4","8"};
    protected OptionPanel preview;
    protected OptionCheckBox previewCheckBox;

    public boolean hasOptionPanel() {
        return true;
    }

    public String[] getMIMETypes() {
        return new String[]{ "application/postscript" };
    }

    public JPanel createOptionPanel(Properties user) {
        UserProperties options = new UserProperties(user, PSGraphics2D.getDefaultProperties());
        preview = new OptionPanel("Preview Image");
        previewCheckBox = new OptionCheckBox(options,
                                                PSGraphics2D.PREVIEW,
                                                "Include preview");

        preview.add(TableLayout.FULL, previewCheckBox);

        final JLabel previewLabel = new JLabel("Bits per sample");
        preview.add(TableLayout.LEFT,  previewLabel);
        previewCheckBox.enables(previewLabel);

        final OptionComboBox previewComboBox = new OptionComboBox(options,
                                                PSGraphics2D.PREVIEW_BITS,
                                                bitsList);
        preview.add(TableLayout.RIGHT, previewComboBox);
        previewCheckBox.enables(previewComboBox);
        preview.setVisible(false);

        String rootKey = PSGraphics2D.class.getName();

        JPanel infoPanel = new InfoPanel(options, rootKey, new String[] {
            InfoConstants.FOR,
            InfoConstants.TITLE
        });

        // TableLayout.LEFT Panel
        JPanel leftPanel = new OptionPanel();
        leftPanel.add(TableLayout.COLUMN, new PageLayoutPanel(options, rootKey));
        leftPanel.add(TableLayout.COLUMN, new PageMarginPanel(options, rootKey));
        leftPanel.add(TableLayout.COLUMN_FILL, new JLabel());

        // TableLayout.RIGHT Panel
        JPanel rightPanel = new OptionPanel();
        rightPanel.add(TableLayout.COLUMN, new BackgroundPanel(options, rootKey, false));
        rightPanel.add(TableLayout.COLUMN, preview);
        rightPanel.add(TableLayout.COLUMN, new ImageTypePanel(options, rootKey,
            new String[] {ImageConstants.SMALLEST, ImageConstants.ZLIB, ImageConstants.JPG}));
        rightPanel.add(TableLayout.COLUMN, new FontPanel(options, rootKey));
        rightPanel.add(TableLayout.COLUMN_FILL, new JLabel());

        // Make the full panel.
        OptionPanel optionsPanel = new OptionPanel();
        optionsPanel.add("0 0 [5 5 5 5] wt", leftPanel);
        optionsPanel.add("1 0 [5 5 5 5] wt", rightPanel);
        optionsPanel.add("0 1 2 1 [5 5 5 5] wt", infoPanel);
        optionsPanel.add(TableLayout.COLUMN_FILL, new JLabel());

        return optionsPanel;
    }

    public VectorGraphics getGraphics(OutputStream os, Component target)
        throws IOException {

        return new PSGraphics2D(os, target.getSize());
    }
}
