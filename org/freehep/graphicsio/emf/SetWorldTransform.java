// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.geom.AffineTransform;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * SetWorldTransform TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: SetWorldTransform.java,v 1.1 2002/02/27 22:05:05 duns Exp $
 */
public class SetWorldTransform
    extends EMFTag {

    private AffineTransform transform;

    SetWorldTransform() {
        super(35, 1);
    }

    public SetWorldTransform(AffineTransform transform) {
        this();
        this.transform = transform;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        SetWorldTransform tag = new SetWorldTransform(emf.readXFORM());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeXFORM(transform);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  transform: "+transform;
    }   
}
