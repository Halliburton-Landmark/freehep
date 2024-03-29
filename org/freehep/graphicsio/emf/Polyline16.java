// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Point;
import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * Polyline16 TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: Polyline16.java,v 1.2 2002/08/06 14:59:16 duns Exp $
 */
public class Polyline16
    extends EMFTag {

    private Rectangle bounds;
    private int numberOfPoints;
    private Point[] points;

    Polyline16() {
        super(87, 1);
    }

    public Polyline16(Rectangle bounds, int numberOfPoints, Point[] points) {
        this();
        this.bounds = bounds;
        this.numberOfPoints = numberOfPoints;
        this.points = points;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len)
        throws IOException {

        Rectangle r = emf.readRECTL();
        int n = emf.readDWORD();
        Polyline16 tag = new Polyline16(r, n, emf.readPOINTS(n));
        return tag;
    }

    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeRECTL(bounds);
        emf.writeDWORD(numberOfPoints);
        emf.writePOINTS(numberOfPoints, points);
    }

    public String toString() {
        return super.toString()+"\n"+
            "  bounds: "+bounds+"\n"+
            "  #points: "+numberOfPoints;
    }
}
