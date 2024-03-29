// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * SelectPalette TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: SelectPalette.java,v 1.1 2002/02/27 22:05:05 duns Exp $
 */
public class SelectPalette
    extends EMFTag {

    private int index;

    SelectPalette() {
        super(48, 1);
    }

    public SelectPalette(int index) {
        this();
        this.index = index;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        SelectPalette tag = new SelectPalette(emf.readDWORD());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeDWORD(index);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  index: 0x"+Integer.toHexString(index);
    }       
}
