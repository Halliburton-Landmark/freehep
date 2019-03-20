// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * ConnectingEdge TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: ConnectingEdge.java,v 1.1 2002/01/23 11:09:43 duns Exp $
 */
public class ConnectingEdge
    extends CGMTag {

    public ConnectingEdge() {
        super(5, 21, 1);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("CONNEDGE");
    }
}
