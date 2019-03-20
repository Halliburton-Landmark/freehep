// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Color;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * ColorValueExtent TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: ColorValueExtent.java,v 1.1 2001/11/29 01:45:25 duns Exp $
 */
public class ColorValueExtent
    extends CGMTag {
    
    Color minColor, maxColor;
    
    public ColorValueExtent() {
        super(1, 10, 1);
    }
    
    // FIXME: only RGB ColorModel allowed
    public ColorValueExtent(Color minColor, Color maxColor) {
        this();
        this.minColor = minColor;
        this.maxColor = maxColor;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {

        cgm.writeColorDirect(minColor);
        cgm.writeColorDirect(maxColor);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("COLRVALUEEXT ");
        cgm.writeColor(minColor);
        cgm.print(", ");
        cgm.writeColor(maxColor);
    }
}
