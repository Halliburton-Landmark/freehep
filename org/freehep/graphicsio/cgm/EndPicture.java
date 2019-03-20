// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

/**
 * EndPicture TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: EndPicture.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class EndPicture
    extends CGMTag {

    public EndPicture() {
        super(0, 5, 1);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.outdent();
        cgm.print("ENDPIC");
    }
}
