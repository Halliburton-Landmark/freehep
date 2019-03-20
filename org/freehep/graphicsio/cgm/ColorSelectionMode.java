// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * ColorSelectionMode TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: ColorSelectionMode.java,v 1.1 2001/11/29 01:45:25 duns Exp $
 */
public class ColorSelectionMode
    extends CGMTag {
        
    public static final int INDEXED = 0;
    public static final int DIRECT = 1;

    private int mode;

    public ColorSelectionMode() {
        super(2, 2, 1);
    }
    
    public ColorSelectionMode(int mode) {
        this();
        this.mode = mode;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.setColorMode(mode == DIRECT);
        cgm.writeEnumerate(mode);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.setColorMode(mode == DIRECT);
        cgm.print("COLRMODE ");
        cgm.print((mode == DIRECT) ? "DIRECT" : "INDEXED");
    }
}
