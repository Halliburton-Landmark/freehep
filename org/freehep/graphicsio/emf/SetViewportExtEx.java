// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Dimension;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * SetViewportExtEx TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: SetViewportExtEx.java,v 1.1 2002/02/27 22:05:05 duns Exp $
 */
public class SetViewportExtEx
    extends EMFTag {

    private Dimension size;

    SetViewportExtEx() {
        super(11, 1);
    }

    public SetViewportExtEx(Dimension size) {
        this();
        this.size = size;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        SetViewportExtEx tag = new SetViewportExtEx(emf.readSIZEL());
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
