// Copyright 2001-2004, FreeHEP.
package org.freehep.postscript;

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.awt.image.*;
import java.util.*;

import org.freehep.graphics2d.BufferedPanel;

/**
 * PostScript Panel for PostScript Processor,
 *
 * @author Mark Donszelmann
 * @version $Id: PSPanel.java,v 1.6 2004/01/12 20:19:16 duns Exp $
 */
public class PSPanel extends BufferedPanel {
    
    private Graphics2D mirroredGraphics;

    public PSPanel() {
        super(false);
    }
    
    public Graphics getGraphics() {        
        return mirroredGraphics;
    }
        
    public void setBounds(int x, int y, int w, int h) {
        super.setBounds(x, y, w, h);
        if (mirroredGraphics != null) mirroredGraphics.dispose();
        mirroredGraphics = (Graphics2D)super.getGraphics().create();
    }
    
}
