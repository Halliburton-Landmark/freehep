// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Color;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * LineBundleIndex TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: LineColor.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class LineColor
    extends CGMTag {
        
    private Color color;

    public LineColor() {
        super(5, 4, 1);
    }
    
    public LineColor(Color color) {
        this();
        this.color = color;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeColor(color);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("LINECOLR ");
        cgm.writeColor(color);
    }
}
