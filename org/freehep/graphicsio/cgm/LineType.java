// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * LineType TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: LineType.java,v 1.2 2002/01/09 16:30:11 duns Exp $
 */
public class LineType
    extends CGMTag {
        
    public static final int SOLID          = 1;
    public static final int DASH           = 2;
    public static final int DOT            = 3;
    public static final int DASH_DOT       = 4;
    public static final int DASH_DOT_DOT   = 5;

    private int type;

    public LineType() {
        super(5, 2, 1);
    }
    
    public LineType(int type) {
        this();
        this.type = type;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeIntegerIndex(type);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("LINETYPE ");
        cgm.writeInteger(type);
    }
}
