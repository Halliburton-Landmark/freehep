// Copyright 2003, FreeHEP.
package org.freehep.graphicsio.exportchooser;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import java.text.*;
import java.util.*;

import org.freehep.swing.layout.TableLayout;

/**
 *
 * @author Mark Donszelmann
 * @version $Id: OptionFormattedTextField.java,v 1.3 2003/04/30 19:02:03 duns Exp $
 */
public class OptionFormattedTextField extends JFormattedTextField implements Options {
    protected String initialText;
    protected String key;

    public OptionFormattedTextField(Properties options, String key, String text, int columns,
                                      Format format) {
        super(format);
        setText(options.getProperty(key, text));
        setColumns(columns);
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

