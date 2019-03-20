// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.geom.Point2D;
import java.io.IOException;

/**
 * DisjointPolyline TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: DisjointPolyline.java,v 1.1 2001/11/29 01:45:25 duns Exp $
 */
public class DisjointPolyline
    extends Polyline {
        
    public DisjointPolyline() {
        super(4, 2, 1);
    }
    
    public DisjointPolyline(Point2D[] p) {
        this();
        this.p = p;
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.println("DISJTLINE");
        writePointList(cgm);
    }

}
