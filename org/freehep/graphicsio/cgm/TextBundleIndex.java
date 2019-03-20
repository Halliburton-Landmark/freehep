// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * TextBundleIndex TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: TextBundleIndex.java,v 1.1 2001/11/29 01:45:27 duns Exp $
 */
public class TextBundleIndex
    extends CGMTag {
        
    private int index;

    public TextBundleIndex() {
        super(5, 9, 1);
    }
    
    public TextBundleIndex(int index) {
        this();
        this.index = index;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeIntegerIndex(index);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("TEXTINDEX ");
        cgm.writeInteger(index);
    }
}
