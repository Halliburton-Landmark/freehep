// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Point;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * SetBrushOrgEx TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: SetBrushOrgEx.java,v 1.1 2002/02/27 22:05:05 duns Exp $
 */
public class SetBrushOrgEx
    extends EMFTag {

    private Point point;

    SetBrushOrgEx() {
        super(13, 1);
    }

    public SetBrushOrgEx(Point point) {
        this();
        this.point = point;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        SetBrushOrgEx tag = new SetBrushOrgEx(emf.readPOINTL());
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
