// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * ColorIndexPrecision TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: ColorIndexPrecision.java,v 1.1 2001/11/29 01:45:25 duns Exp $
 */
public class ColorIndexPrecision
    extends CGMTag {
        
    // FIXME: incomplete
    public ColorIndexPrecision() {
        super(1, 8, 1);
    }
        
    public void write(int tagID, CGMOutputStream cgm) throws IOException {

        cgm.setColorIndexPrecision(24);
        cgm.writeInteger(24);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.setColorIndexPrecision(24);
        cgm.print("COLRINDEXPREC ");
        cgm.writeInteger(Short.MAX_VALUE);
    }
}
