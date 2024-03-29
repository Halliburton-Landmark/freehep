// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.io.IOException;

/**
 * EMF GradientRectangle
 *
 * @author Mark Donszelmann
 * @version $Id: GradientRectangle.java,v 1.1 2002/02/27 22:05:04 duns Exp $
 */
public class GradientRectangle extends Gradient {

    private int upperLeft, lowerRight;

    public GradientRectangle(int upperLeft, int lowerRight) {
        this.upperLeft = upperLeft;
        this.lowerRight = lowerRight;
    }

    GradientRectangle(EMFInputStream emf) throws IOException {
        upperLeft = emf.readULONG();
        lowerRight = emf.readULONG();
    }
    
    public void write(EMFOutputStream emf) throws IOException {
        emf.writeULONG(upperLeft);
        emf.writeULONG(lowerRight);
    }

    public String toString() {
        return "  GradientRectangle: "+upperLeft+", "+lowerRight;
    }   
}

