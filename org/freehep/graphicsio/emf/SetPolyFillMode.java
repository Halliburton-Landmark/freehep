// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * SetPolyFillMode TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: SetPolyFillMode.java,v 1.1 2002/02/27 22:05:05 duns Exp $
 */
public class SetPolyFillMode
    extends EMFTag implements EMFConstants {

    private int mode;

    SetPolyFillMode() {
        super(19, 1);
    }

    public SetPolyFillMode(int mode) {
        this();
        this.mode = mode;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        SetPolyFillMode tag = new SetPolyFillMode(emf.readDWORD());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeDWORD(mode);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  mode: "+mode;
    }   
}