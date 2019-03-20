// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * DeleteObject TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: DeleteObject.java,v 1.2 2003/09/29 22:05:53 duns Exp $
 */
public class DeleteObject
    extends EMFTag {

    private int index;

    DeleteObject() {
        super(40, 1);
    }

    public DeleteObject(int index) {
        this();
        this.index = index;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        DeleteObject tag = new DeleteObject(emf.readDWORD());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeDWORD(index);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  index: 0x"+Integer.toHexString(index);
    }   
    public int getIndex() {
            return index;
    }
}
