// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * NoOp TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: NoOp.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class NoOp
    extends CGMTag {

    private int n;

    public NoOp() {
        super(0, 0, 1);
    }
    
    public NoOp(int n) {
        this();
        this.n = n;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        for (int i=0; i<n; i++) {
            cgm.writeUnsignedByte(0);
        }
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
    }
}
