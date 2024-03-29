// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * PatternIndex TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: PatternIndex.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class PatternIndex
    extends CGMTag {
        
    private int index;

    public PatternIndex() {
        super(5, 25, 1);
    }
    
    public PatternIndex(int index) {
        this();
        this.index = index;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeIntegerIndex(index);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("PATINDEX ");
        cgm.writeInteger(index);
    }
}
