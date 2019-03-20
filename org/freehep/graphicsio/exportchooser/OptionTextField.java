// Copyright 2003, FreeHEP.
package org.freehep.graphicsio.exportchooser;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import java.util.*;

import org.freehep.swing.layout.TableLayout;

/**
 *
 * @author Mark Donszelmann
 * @version $Id: OptionTextField.java,v 1.3 2003/04/30 19:02:03 duns Exp $
 */
public class OptionTextField extends JTextField implements Options {
    protected String initialText;
    protected String key;

    public OptionTextField(Properties options, String key, int columns) {
        super(options.getProperty(key, ""), columns);
        this.key = key;
        initialText = getText();
    }

    public boolean applyChangedOptions(Properties options) {
        if (!getText().equals(initialText)) {
            options.setProperty(key, getText());
            return true;
        }
        return false;
    }
}

