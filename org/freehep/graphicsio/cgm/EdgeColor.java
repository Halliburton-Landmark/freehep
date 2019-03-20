// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Color;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * EdgeColor TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: EdgeColor.java,v 1.2 2002/01/09 16:30:11 duns Exp $
 */
public class EdgeColor
    extends CGMTag {
        
    private Color color;

    public EdgeColor() {
        super(5, 29, 1);
    }
    
    public EdgeColor(Color color) {
        this();
        this.color = color;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeColor(color);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("EDGECOLR ");
        cgm.writeColor(color);
    }
}
