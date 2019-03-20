// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.geom.AffineTransform;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * ModifyWorldTransform TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: ModifyWorldTransform.java,v 1.1 2002/02/27 22:05:04 duns Exp $
 */
public class ModifyWorldTransform
    extends EMFTag implements EMFConstants {

    private AffineTransform transform;
    private int mode;

    ModifyWorldTransform() {
        super(36, 1);
    }

    public ModifyWorldTransform(AffineTransform transform, int mode) {
        this();
        this.transform = transform;
        this.mode = mode;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        ModifyWorldTransform tag = new ModifyWorldTransform(emf.readXFORM(), emf.readDWORD());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeXFORM(transform);
        emf.writeDWORD(mode);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  transform: "+transform+"\n"+
            "  mode: "+mode;
    }   
}
