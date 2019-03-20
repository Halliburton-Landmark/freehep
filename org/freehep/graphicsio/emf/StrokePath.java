// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * StrokePath TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: StrokePath.java,v 1.1 2002/02/27 22:05:05 duns Exp $
 */
public class StrokePath
    extends EMFTag {

    private Rectangle bounds;

    StrokePath() {
        super(64, 1);
    }

    public StrokePath(Rectangle bounds) {
        this();
        this.bounds = bounds;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        StrokePath tag = new StrokePath(emf.readRECTL());
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
