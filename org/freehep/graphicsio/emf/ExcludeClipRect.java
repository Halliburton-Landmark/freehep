// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * ExcludeClipRect TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: ExcludeClipRect.java,v 1.1 2002/02/27 22:05:03 duns Exp $
 */
public class ExcludeClipRect
    extends EMFTag {

    private Rectangle bounds;

    ExcludeClipRect() {
        super(29, 1);
    }

    public ExcludeClipRect(Rectangle bounds) {
        this();
        this.bounds = bounds;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        ExcludeClipRect tag = new ExcludeClipRect(emf.readRECTL());
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
