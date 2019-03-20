// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Color;
import java.awt.Point;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * ExtFloodFill TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: ExtFloodFill.java,v 1.1 2002/02/27 22:05:03 duns Exp $
 */
public class ExtFloodFill
    extends EMFTag implements EMFConstants {

    private Point start;
    private Color color;
    private int mode;

    ExtFloodFill() {
        super(53, 1);
    }

    public ExtFloodFill(Point start, Color color, int mode) {
        this();
        this.start = start;
        this.color = color;
        this.mode = mode;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        ExtFloodFill tag = new ExtFloodFill(emf.readPOINTL(), 
                                            emf.readCOLORREF(), 
                                            emf.readDWORD());
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writePOINTL(start);
        emf.writeCOLORREF(color);
        emf.writeDWORD(mode);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  start: "+start+"\n"+
            "  color: "+color+"\n"+
            "  mode: "+mode;
    }   
}
