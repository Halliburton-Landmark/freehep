// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

/**
 * BeginPictureBody TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: BeginPictureBody.java,v 1.1 2001/11/29 01:45:25 duns Exp $
 */
public class BeginPictureBody
    extends CGMTag {

    public BeginPictureBody() {
        super(0, 4, 1);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.outdent();
        cgm.print("BEGPICBODY");
        cgm.indent();
    }
}
