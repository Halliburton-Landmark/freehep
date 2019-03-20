// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Color;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * BackgroundColor TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: BackgroundColor.java,v 1.1 2001/11/29 01:45:24 duns Exp $
 */
public class BackgroundColor
    extends CGMTag {
        
    private Color color;

    public BackgroundColor() {
        super(2, 7, 1);
    }
    
    public BackgroundColor(Color color) {
        this();
        this.color = color;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeColorDirect(color);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("BACKCOLR ");
        cgm.writeColorDirect(color);
    }
}
