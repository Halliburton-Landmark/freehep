// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Color;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * FillColor TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: FillColor.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class FillColor
    extends CGMTag {

    private Color color;

    public FillColor() {
        super(5, 23, 1);
    }
    
    public FillColor(Color color) {
        this();
        this.color = color;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeColor(color);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("FILLCOLR ");
        cgm.writeColor(color);
    }
}
