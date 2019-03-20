// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * IntersectClipRect TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: IntersectClipRect.java,v 1.1 2002/02/27 22:05:04 duns Exp $
 */
public class IntersectClipRect
    extends EMFTag {

    private Rectangle bounds;

    IntersectClipRect() {
        super(30, 1);
    }

    public IntersectClipRect(Rectangle bounds) {
        this();
        this.bounds = bounds;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        IntersectClipRect tag = new IntersectClipRect(emf.readRECTL());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeRECTL(bounds);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  bounds: "+bounds;
    }   
}
