// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Dimension;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * SetWindowExtEx TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: SetWindowExtEx.java,v 1.1 2002/02/27 22:05:05 duns Exp $
 */
public class SetWindowExtEx
    extends EMFTag {

    private Dimension size;

    SetWindowExtEx() {
        super(9, 1);
    }

    public SetWindowExtEx(Dimension size) {
        this();
        this.size = size;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        SetWindowExtEx tag = new SetWindowExtEx(emf.readSIZEL());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeSIZEL(size);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  size: "+size;
    }       
}
