// Copyright 2003, FreeHEP.
package org.freehep.graphicsio.exportchooser;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.text.*;
import java.util.*;
import javax.swing.*;

import org.freehep.graphics2d.VectorGraphics;
import org.freehep.graphics2d.ScreenConstants;
import org.freehep.graphicsio.ImageConstants;
import org.freehep.swing.layout.TableLayout;
import org.freehep.util.UserProperties;

/**
 *
 * @author Mark Donszelmann
 * @version $Id: ImageTypePanel.java,v 1.1 2003/06/02 17:24:36 duns Exp $
 */
public class ImageTypePanel extends OptionPanel {

    private String key;
    private String initialType;
    private JComboBox imageSizeCombo;

    public ImageTypePanel(Properties user, String rootKey, String[] types) {
        super("Image Type");
        key = rootKey+"."+ImageConstants.WRITE_IMAGES_AS;

        UserProperties options = new UserProperties(user);
        initialType = options.getProperty(key);

        OptionComboBox imageTypeCombo = new OptionComboBox(options, key, types);
        add(TableLayout.LEFT,  new JLabel("Include Images as "));
        add(TableLayout.RIGHT, imageTypeCombo);
    }
}