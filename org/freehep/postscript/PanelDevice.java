// Copyright 2001-2004, FreeHEP.
package org.freehep.postscript;

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.awt.image.*;
import java.util.*;
import javax.swing.*;

import org.freehep.graphics2d.BufferedPanel;

/**
 * @author Mark Donszelmann
 * @version $Id: PanelDevice.java,v 1.1 2004/01/12 20:19:16 duns Exp $
 */
public class PanelDevice extends PSDevice {
    
    private final JPanel panel;
    private Graphics2D imageGraphics = null;

    public PanelDevice(JPanel panel) {
        this.panel = panel;
        
        // forward the resize
        panel.addComponentListener(new ComponentAdapter() {
            public void componentResized(ComponentEvent event) {
                fireComponentResizedEvent(event);
            }
        });
    }
    
    public double getWidth() {
        return panel.getWidth();
    }
    
    public double getHeight() {
        return panel.getHeight();
    }
      
    public AffineTransform getDeviceTransform() {
        return panel.getGraphicsConfiguration().getDefaultTransform();  
    }
        
    public Graphics getDeviceGraphics() {
        return panel.getGraphics();
    }

    public Graphics2D getGraphics() {
        if (imageGraphics != null) return imageGraphics;
        return super.getGraphics();
    }

    public void refresh() {
        panel.repaint();
    }
    
    public BufferedImage convertToImage(int width, int height) {
        BufferedImage image = (BufferedImage)panel.createImage(width, height);
        imageGraphics = (Graphics2D)image.getGraphics();
        return image;
    }
}
