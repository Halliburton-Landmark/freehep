// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Point;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * SetViewportOrgEx TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: SetViewportOrgEx.java,v 1.1 2002/02/27 22:05:05 duns Exp $
 */
public class SetViewportOrgEx
    extends EMFTag {

    private Point point;

    SetViewportOrgEx() {
        super(12, 1);
    }

    public SetViewportOrgEx(Point point) {
        this();
        this.point = point;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        SetViewportOrgEx tag = new SetViewportOrgEx(emf.readPOINTL());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writePOINTL(point);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  point: "+point;
    }       
}
