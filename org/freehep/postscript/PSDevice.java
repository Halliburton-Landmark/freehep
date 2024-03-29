// Copyright 2004, FreeHEP.
package org.freehep.postscript;

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.awt.image.*;
import java.util.*;

/*
 * @author Mark Donszelmann
 * @version $Id: PSDevice.java,v 1.1 2004/01/12 20:19:15 duns Exp $
 */
public abstract class PSDevice implements DSCEventListener {

    private boolean valid = false;
    private AffineTransform mirror = null;
    private AffineTransform boundingBox = new AffineTransform();
    private AffineTransform pageBoundingBox = null;
    private AffineTransform transform = new AffineTransform();
    private Graphics2D graphics;

    private Collection/*<ComponentListener>*/ listeners = new ArrayList();

    public void addComponentListener(ComponentListener l) {
        listeners.add(l);
    }
    
    public void removeComponentListener(ComponentListener l) {
        listeners.remove(l);
    }

    protected void fireComponentResizedEvent(ComponentEvent e) {
        valid = false;
        mirror = new AffineTransform(1, 0, 0, -1, 0, getHeight());
        for (Iterator i=listeners.iterator(); i.hasNext(); ) {
            ((ComponentListener)i.next()).componentResized(e);
        }
    }        

    public void dscCommentFound(DSCEvent event) {
        if (event.getComment().equals("BoundingBox:")) {
            Rectangle bb = (Rectangle)event.getArgs();
            double s = Math.min(getWidth()/(double)bb.width, 
                                getHeight()/(double)bb.height);       
            boundingBox = new AffineTransform(s, 0, 0, s, -bb.x*s, -bb.y*s);
            pageBoundingBox = null;
            valid = false;
        }
        
        if (event.getComment().equals("PageBoundingBox:")) {
            Rectangle bb = (Rectangle)event.getArgs();
            double s = Math.min(getWidth()/(double)bb.width, 
                                getHeight()/(double)bb.height);       
            pageBoundingBox = new AffineTransform(s, 0, 0, s, -bb.x*s, -bb.y*s);
            valid = false;
        }
        
        if (event.getComment().equals("Page:")) {
            pageBoundingBox = null;
            valid = false;
        }
    }

    
    public void setTransform(AffineTransform transform) {
        this.transform = (transform != null) ? transform : new AffineTransform();
        valid = false;
    }
    
    public AffineTransform getTransform() {
        return transform;
    }
    
    public AffineTransform getMirrorTransform() {
        if (mirror == null) mirror = new AffineTransform(1, 0, 0, -1, 0, getHeight());
        return mirror;
    }

    public AffineTransform getBoundingBoxTransform() {
        return (pageBoundingBox != null) ? pageBoundingBox : boundingBox;
    }

// FIXME this method and the next seem clumsy. There must be a way 
// for deviceGraphics to remain untouched, and to just add new transforms
// to graphics, BUT getDeviceGraphics().create() does not seem to work, 
// presumably because BufferedPanel probably copies a different buffer...
    public Graphics2D getGraphics() {
        if (!valid) {
            graphics = (Graphics2D)getDeviceGraphics();
            graphics.setTransform(getDeviceTransform());
            graphics.transform(getTransform());
            graphics.transform(getMirrorTransform());
            graphics.transform(getBoundingBoxTransform());
            valid = true;
        }
        return graphics;
    }

    public void erasePage() {
        graphics = (Graphics2D)getDeviceGraphics();
        graphics.setTransform(getDeviceTransform());
        graphics.fillRect(0, 0, (int)getWidth(), (int)getHeight());
        valid = false;
    }

    public abstract AffineTransform getDeviceTransform();
    public abstract Graphics getDeviceGraphics();
    public abstract double getWidth();
    public abstract double getHeight();
    public abstract BufferedImage convertToImage(int width, int height);
    public abstract void refresh();

}
