// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * CharacterHeight TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: CharacterHeight.java,v 1.3 2002/01/23 11:09:42 duns Exp $
 */
public class CharacterHeight
    extends CGMTag {

    private double height;

    public CharacterHeight() {
        super(5, 15, 1);
    }

    public CharacterHeight(double height) {
        this();
        this.height = height;
    }

    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeVDC(height);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("CHARHEIGHT ");
        cgm.writeVDC(height);
    }
}
