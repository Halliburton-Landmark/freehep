// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * VDCRealPrecision TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: VDCRealPrecision.java,v 1.1 2001/11/29 01:45:27 duns Exp $
 */
public class VDCRealPrecision
    extends CGMTag {
      
    // FIXME: not complete  
    public VDCRealPrecision() {
        super(3, 2, 1);
    }
        
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.setVDCRealPrecision(false, true);
        cgm.writeEnumerate(0);   // floating
        cgm.writeInteger(12);  // double exp
        cgm.writeInteger(52);  // double fract
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.setVDCRealPrecision(false, true);
        cgm.print("VDCREALPREC ");
        cgm.writeReal(Double.MIN_VALUE);
        cgm.print(", ");
        cgm.writeReal(Double.MAX_VALUE);
        cgm.print(", ");
        cgm.writeInteger(20); // FIXME
    }
}
