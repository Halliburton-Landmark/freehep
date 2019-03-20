// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Color;
import java.io.IOException;

/**
 * EMF TriVertex
 *
 * @author Mark Donszelmann
 * @version $Id: TriVertex.java,v 1.1 2002/02/27 22:05:05 duns Exp $
 */
public class TriVertex {

    private int x, y;
    private Color color;

    public TriVertex(int x, int y, Color color) {
        this.x = x;
        this.y = y;
        this.color = color;
    }

    TriVertex(EMFInputStream emf) throws IOException {
        x = emf.readLONG();
        y = emf.readLONG();
        color = emf.readCOLOR16();
    }

    public void write(EMFOutputStream emf) throws IOException {
        emf.writeLONG(x);
        emf.writeLONG(y);
        emf.writeCOLOR16(color);
    }
    
    public String toString() {
        return "["+x+", "+y+"] "+color;
    }  
}

