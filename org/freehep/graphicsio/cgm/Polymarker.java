// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.geom.Point2D;
import java.io.IOException;

/**
 * Polymarker TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: Polymarker.java,v 1.1 2001/11/29 01:45:27 duns Exp $
 */
public class Polymarker
    extends Polyline {
        
    public Polymarker() {
        super(4, 3, 1);
    }
    
    public Polymarker(Point2D[] p) {
        this();
        this.p = p;
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.println("MARKER");
        writePointList(cgm);
    }

}
