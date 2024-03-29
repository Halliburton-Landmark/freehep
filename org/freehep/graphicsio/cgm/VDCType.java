// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * VDCType TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: VDCType.java,v 1.2 2002/01/23 08:04:19 duns Exp $
 */
public class VDCType
    extends CGMTag {
        
    public final static int INTEGER = 0;
    public final static int REAL = 1;

    private int type;

    public VDCType() {
        super(1, 3, 1);
    }
    
    public VDCType(int type) {
        this();
        this.type = type;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.setVDCReal( (type == INTEGER) ? false : true);
        cgm.writeEnumerate(type);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.setVDCReal( (type == INTEGER) ? false : true);
        cgm.print("VDCTYPE ");
        cgm.print((type == INTEGER) ? "INTEGER" : "REAL");
    }
}
