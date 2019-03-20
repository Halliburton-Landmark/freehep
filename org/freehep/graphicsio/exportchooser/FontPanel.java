// Copyright 2003, FreeHEP.
package org.freehep.graphicsio.exportchooser;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import java.util.*;

import org.freehep.graphicsio.FontConstants;
import org.freehep.swing.layout.TableLayout;

/**
 *
 * @author Mark Donszelmann
 * @version $Id: FontPanel.java,v 1.1 2003/04/25 23:12:47 duns Exp $
 */
public class FontPanel extends OptionPanel {
    public FontPanel(Properties options, String rootKey) {
        super("Fonts");

        final OptionCheckBox checkBox = new OptionCheckBox(options,
                                            rootKey+"."+FontConstants.EMBED_FONTS,
                                            "Embed Fonts as");
        add(TableLayout.LEFT,  checkBox);
        final OptionComboBox comboBox = new OptionComboBox(options,
                                            rootKey+"."+FontConstants.EMBED_FONTS_AS,
                                            FontConstants.getEmbedFontsAsList());
        add(TableLayout.RIGHT, comboBox);
        checkBox.enables(comboBox);
    }
}
