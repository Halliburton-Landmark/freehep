// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Color;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * MarkerColor TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: MarkerColor.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class MarkerColor
    extends CGMTag {
        
    private Color color;

    public MarkerColor() {
        super(5, 8, 1);
    }
    
    public MarkerColor(Color color) {
        this();
        this.color = color;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeColor(color);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("MARKERCOLR ");
        cgm.writeColor(color);
    }
}
