// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * Rectangle TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: EMFRectangle.java,v 1.1 2002/07/30 19:11:17 duns Exp $
 */
public class EMFRectangle
    extends EMFTag {

    private Rectangle bounds;

    EMFRectangle() {
        super(43, 1);
    }

    public EMFRectangle(Rectangle bounds) {
        this();
        this.bounds = bounds;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len)
        throws IOException {

        EMFRectangle tag = new EMFRectangle(emf.readRECTL());
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
