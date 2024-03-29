// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * MarkerType TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: MarkerType.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class MarkerType
    extends CGMTag {
        
    public static final int DOT          = 1;
    public static final int PLUS         = 2;
    public static final int ASTERISK     = 3;
    public static final int CIRCLE       = 4;
    public static final int CROSS        = 5;

    private int type;

    public MarkerType() {
        super(5, 6, 1);
    }
    
    public MarkerType(int type) {
        this();
        this.type = type;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeIntegerIndex(type);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("MARKERTYPE ");
        cgm.writeInteger(type);
    }
}
