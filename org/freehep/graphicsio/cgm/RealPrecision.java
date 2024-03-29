// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * RealPrecision TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: RealPrecision.java,v 1.1 2001/11/29 01:45:27 duns Exp $
 */
public class RealPrecision
    extends CGMTag {
    
    // FIXME: not complete    
    public RealPrecision() {
        super(1, 5, 1);
    }
        
    public void write(int tagID, CGMOutputStream cgm) throws IOException {

        cgm.setRealPrecision(false, true);
        cgm.writeEnumerate(0);   // floating
        cgm.writeInteger(12);  // double exp
        cgm.writeInteger(52);  // double fract
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.setRealPrecision(false, true);
        cgm.print("REALPREC ");
        cgm.writeReal(Double.MIN_VALUE);
        cgm.print(", ");
        cgm.writeReal(Double.MAX_VALUE);
        cgm.print(", ");
        cgm.writeInteger(20);   // FIXME: check
    }
}
