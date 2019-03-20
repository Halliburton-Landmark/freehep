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
 * @version $Id: OptionPanel.java,v 1.3 2003/04/30 19:02:03 duns Exp $
 */
public class OptionPanel extends JPanel implements Options {
    public OptionPanel() {
        this(null);
    }

    public OptionPanel(String title) {
        super(new TableLayout());
        if (title != null) setBorder(BorderFactory.createTitledBorder(
                                     BorderFactory.createEtchedBorder(),
                                     title));
    }

    public void setEnabled(boolean enable) {
        for (int i=0; i<getComponentCount(); i++) {
            Component c = getComponent(i);
            c.setEnabled(enable);
        }
    }

    public boolean applyChangedOptions(Properties options) {
        boolean changed = false;
        for (int i=0; i<getComponentCount(); i++) {
            Component c = getComponent(i);
            if (c instanceof Options) {
                boolean changedThis = ((Options)c).applyChangedOptions(options);
                changed = changed || changedThis;
            }
        }
        return changed;
    }
}
