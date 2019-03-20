// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * IntegerPrecision TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: IntegerPrecision.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class IntegerPrecision
    extends CGMTag {
      
    // FIXME: not complete  
    public IntegerPrecision() {
        super(1, 4, 1);
    }
        
    public void write(int tagID, CGMOutputStream cgm) throws IOException {

        cgm.setIntegerPrecision(16);
        cgm.writeInteger(16);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.setIntegerPrecision(16);
        cgm.print("INTEGERPREC ");
        cgm.writeInteger(Short.MIN_VALUE);
        cgm.print(", ");
        cgm.writeInteger(Short.MAX_VALUE);
    }
}
