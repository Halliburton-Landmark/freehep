// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.geom.Point2D;
import java.io.IOException;

/**
 * Polygon TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: Polygon.java,v 1.1 2001/11/29 01:45:27 duns Exp $
 */
public class Polygon
    extends Polyline {
        
    public Polygon() {
        super(4, 7, 1);
    }
    
    public Polygon(Point2D[] p) {
        this();
        this.p = p;
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.println("POLYGON");
        writePointList(cgm);
    }
}
