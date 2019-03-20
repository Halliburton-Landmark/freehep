// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * LineBundleIndex TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: LineBundleIndex.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class LineBundleIndex
    extends CGMTag {
        
    private int index;

    public LineBundleIndex() {
        super(5, 1, 1);
    }
    
    public LineBundleIndex(int index) {
        this();
        this.index = index;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeIntegerIndex(index);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("LINEINDEX ");
        cgm.writeInteger(index);
    }
}
