// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * FillPath TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: FillPath.java,v 1.2 2003/09/29 22:05:54 duns Exp $
 */
public class FillPath
    extends EMFTag {

    private Rectangle bounds;

    FillPath() {
        super(62, 1);
    }

    public FillPath(Rectangle bounds) {
        this();
        this.bounds = bounds;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        FillPath tag = new FillPath(emf.readRECTL());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeRECTL(bounds);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  bounds: "+bounds;
    }   
     public Rectangle getBounds() { 
        return bounds;
    }
}
