// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

/**
 * EndSegment TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: EndSegment.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class EndSegment
    extends CGMTag {

    private String name;

    public EndSegment() {
        super(0, 7, 2);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.outdent();
        cgm.print("ENDSEG");
    }
}
