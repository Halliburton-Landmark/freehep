// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * EdgeCap TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: EdgeCap.java,v 1.2 2002/01/22 08:15:30 duns Exp $
 */
public class EdgeCap
    extends CGMTag {
        
    public static final int UNSPECIFIED = 1;
    public static final int BUTT        = 2;
    public static final int ROUND       = 3;
    public static final int MATCH       = 3;        // for DASH
    public static final int SQUARE      = 4;
    public static final int TRIANGLE    = 5;

    private int cap;
    private int dash;

    public EdgeCap() {
        super(5, 37, 3);
    }
    
    public EdgeCap(int cap) {
        this(cap, BUTT);
    }
    
    public EdgeCap(int cap, int dash) {
        this();
        this.cap = cap;
        this.dash = dash;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeIntegerIndex(cap);
        cgm.writeIntegerIndex(dash);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("EDGECAP ");
        cgm.writeInteger(cap);
        cgm.print(", ");
        cgm.writeInteger(dash);
    }
}
