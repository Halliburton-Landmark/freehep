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
 * @version $Id: InfoPanel.java,v 1.1 2003/04/25 23:12:47 duns Exp $
 */
public class InfoPanel extends OptionPanel {
    public InfoPanel(Properties options, String rootKey, String[] keys) {
        super("Info");

        for (int i=0; i<keys.length; i++) {
            add(TableLayout.LEFT,  new JLabel(keys[i]));
            add(TableLayout.RIGHT, new OptionTextField(options,
                                            rootKey+"."+keys[i], 40));
        }
    }
}
