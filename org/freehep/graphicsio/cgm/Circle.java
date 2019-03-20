// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.geom.Point2D;
import java.io.IOException;

/**
 * Circle TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: Circle.java,v 1.1 2001/11/29 01:45:25 duns Exp $
 */
public class Circle
    extends CGMTag {

    private Point2D p;
    private double radius;

    public Circle() {
        super(4, 12, 1);
    }
    
    public Circle(Point2D p, double radius) {
        this();
        this.p = p;
        this.radius = radius;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writePoint(p);
        cgm.writeVDC(radius);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("CIRCLE ");
        cgm.writePoint(p);
        cgm.print(", ");
        cgm.writeVDC(radius);
    }
}
