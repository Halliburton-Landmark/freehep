// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Point;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * OffsetClipRgn TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: OffsetClipRgn.java,v 1.1 2002/02/27 22:05:04 duns Exp $
 */
public class OffsetClipRgn
    extends EMFTag {

    private Point offset;

    OffsetClipRgn() {
        super(26, 1);
    }

    public OffsetClipRgn(Point offset) {
        this();
        this.offset = offset;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        OffsetClipRgn tag = new OffsetClipRgn(emf.readPOINTL());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writePOINTL(offset);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  offset: "+offset;
    }   
}
