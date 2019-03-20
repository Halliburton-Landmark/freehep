// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Color;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * SetBkColor TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: SetBkColor.java,v 1.1 2002/02/27 22:05:05 duns Exp $
 */
public class SetBkColor
    extends EMFTag {

    private Color color;

    SetBkColor() {
        super(25, 1);
    }

    public SetBkColor(Color color) {
        this();
        this.color = color;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        SetBkColor tag = new SetBkColor(emf.readCOLORREF());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeCOLORREF(color);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  color: "+color;
    }       
}
