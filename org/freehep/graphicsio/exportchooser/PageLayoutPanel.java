// Copyright 2003, FreeHEP.
package org.freehep.graphicsio.exportchooser;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import java.util.*;

import org.freehep.graphicsio.PageConstants;
import org.freehep.swing.layout.TableLayout;

/**
 *
 * @author Mark Donszelmann
 * @version $Id: PageLayoutPanel.java,v 1.2 2003/05/27 22:35:43 duns Exp $
 */
public class PageLayoutPanel extends OptionPanel {
    public PageLayoutPanel(Properties options, String rootKey) {
        super("Page Layout");

        add(TableLayout.LEFT , new JLabel("Size:"));
        add(TableLayout.RIGHT, new OptionComboBox(options,
                                            rootKey+"."+PageConstants.PAGE_SIZE,
                                            PageConstants.getSizeList()));

// FIXME: re-add FREEHEP-277, Margins are now Insets
//        add(TableLayout.LEFT , new JLabel("Margins:"));
//        add(TableLayout.RIGHT, new OptionComboBox(options,
//                                            rootKey+"."+PageConstants.PAGE_MARGINS,
//                                            PageConstants.getMarginsList()));

        add(TableLayout.LEFT , new JLabel("Orientation:"));
        add(TableLayout.RIGHT, new OptionComboBox(options,
                                            rootKey+"."+PageConstants.ORIENTATION,
                                            PageConstants.getOrientationList()));

        add(TableLayout.FULL,  new OptionCheckBox(options,
                                            rootKey+"."+PageConstants.FIT_TO_PAGE,
                                            "Fit to Page"));
    }
}
