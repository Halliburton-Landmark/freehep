// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Point;
import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * PolyDraw16 TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: PolyDraw16.java,v 1.1 2002/02/27 22:05:04 duns Exp $
 */
public class PolyDraw16
    extends EMFTag implements EMFConstants {

    private Rectangle bounds;
    private Point[] points;
    private byte[] types;

    PolyDraw16() {
        super(92, 1);
    }

    public PolyDraw16(Rectangle bounds, Point[] points, byte[] types) {
        this();
        this.bounds = bounds;
        this.points = points;
        this.types = types;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        int n;
        PolyDraw16 tag = new PolyDraw16(emf.readRECTL(), 
                                        emf.readPOINTS(n = emf.readDWORD()),
                                        emf.readBYTE(n));
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeRECTL(bounds);
        emf.writeDWORD(points.length);
        emf.writePOINTS(points);
        emf.writeBYTE(types);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  bounds: "+bounds+"\n"+
            "  #points: "+points.length;
    }   
}
