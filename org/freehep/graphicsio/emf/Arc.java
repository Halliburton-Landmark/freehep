// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Point;
import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * Arc TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: Arc.java,v 1.2 2003/09/29 22:05:53 duns Exp $
 */
public class Arc
    extends EMFTag {

    private Rectangle bounds;
    private Point start, end;

    Arc() {
        super(45, 1);
    }

    public Arc(Rectangle bounds, Point start, Point end) {
        this();
        this.bounds = bounds;
        this.start = start;
        this.end = end;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        Arc tag = new Arc(emf.readRECTL(), emf.readPOINTL(), emf.readPOINTL());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeRECTL(bounds);
        emf.writePOINTL(start);
        emf.writePOINTL(end);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  bounds: "+bounds+"\n"+
            "  start: "+start+"\n"+
            "  end: "+end;
    }   
    public Rectangle getBounds() { 
        return bounds;
    }
    public Point getStart() {
            return start;
    }
    public Point getEnd() {
        return end;
    }
}
