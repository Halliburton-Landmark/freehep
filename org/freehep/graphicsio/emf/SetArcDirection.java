// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * SetArcDirection TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: SetArcDirection.java,v 1.1 2002/02/27 22:05:05 duns Exp $
 */
public class SetArcDirection
    extends EMFTag implements EMFConstants {

    private int direction;

    SetArcDirection() {
        super(57, 1);
    }

    public SetArcDirection(int direction) {
        this();
        this.direction = direction;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        SetArcDirection tag = new SetArcDirection(emf.readDWORD());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeDWORD(direction);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  direction: "+direction;
    }       
}
