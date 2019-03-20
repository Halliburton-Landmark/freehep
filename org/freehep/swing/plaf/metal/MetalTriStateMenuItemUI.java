// Copyright 2000, CERN, Geneva, Switzerland.
package org.freehep.swing.plaf.metal;

import java.awt.*;
import java.awt.event.*;
import java.io.Serializable;

import javax.swing.*;
import javax.swing.plaf.ComponentUI;
import javax.swing.plaf.basic.BasicCheckBoxMenuItemUI;




/**
 *
 * @author Mark Donszelmann
 * @version $Id: MetalTriStateMenuItemUI.java,v 1.1 2000/05/23 07:57:40 duns Exp $
 */
public class MetalTriStateMenuItemUI extends BasicCheckBoxMenuItemUI {
    
    public static ComponentUI createUI(JComponent b) {
        return new MetalTriStateMenuItemUI();
    }

    public String getPropertyPrefix() {
	    return "CheckBoxMenuItem";
    }

    public void installDefaults() {
       	super.installDefaults();
     	checkIcon = new CheckBoxMenuItemIcon();
    }
}
