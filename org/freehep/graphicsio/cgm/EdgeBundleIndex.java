// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * EdgeBundleIndex TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: EdgeBundleIndex.java,v 1.1 2001/11/29 01:45:25 duns Exp $
 */
public class EdgeBundleIndex
    extends CGMTag {
        
    private int index;

    public EdgeBundleIndex() {
        super(5, 26, 1);
    }
    
    public EdgeBundleIndex(int index) {
        this();
        this.index = index;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeIntegerIndex(index);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("EDGEINDEX ");
        cgm.writeInteger(index);
    }
}
