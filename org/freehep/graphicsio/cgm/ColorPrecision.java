// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * ColorPrecision TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: ColorPrecision.java,v 1.1 2001/11/29 01:45:25 duns Exp $
 */
public class ColorPrecision
    extends CGMTag {
        
    // FIXME: not complete
    public ColorPrecision() {
        super(1, 7, 1);
    }
        
    public void write(int tagID, CGMOutputStream cgm) throws IOException {

        cgm.setDirectColorPrecision(24);
        cgm.writeInteger(24);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.setDirectColorPrecision(24);
        cgm.print("COLRPREC ");
        cgm.writeInteger(255);
    }
}
