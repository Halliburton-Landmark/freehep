// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.geom.Point2D;
import java.io.IOException;

/**
 * CircularArcCentreClose TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: CircularArcCentreClose.java,v 1.1 2001/11/29 01:45:25 duns Exp $
 */
public class CircularArcCentreClose
    extends CircularArcCentre {

    public final static int PIE = 0;
    public final static int CHORD = 1;
    private int closure;

    public CircularArcCentreClose() {
        super(4, 16, 1);
    }
    
    public CircularArcCentreClose(Point2D p, Point2D dps, Point2D dpe,
                                  double radius,
                                  int closure) {
        this();
        this.p = p;
        this.dps = dps;
        this.dpe = dpe;
        this.radius = radius;
        this.closure = closure;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        super.write(tagID, cgm);
        cgm.writeEnumerate(closure);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("ARCCTRCLOSE ");
        writeArcSpec(cgm);
        cgm.print((closure == PIE) ? " PIE" : " CHORD");
    }
}
