// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Color;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * AuxiliaryColor TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: AuxiliaryColor.java,v 1.1 2001/11/29 01:45:24 duns Exp $
 */
public class AuxiliaryColor
    extends CGMTag {
        
    private Color color;

    public AuxiliaryColor() {
        super(3, 3, 1);
    }
    
    public AuxiliaryColor(Color color) {
        this();
        this.color = color;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeColor(color);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("AUXCOLR ");
        cgm.writeColor(color);
    }
}