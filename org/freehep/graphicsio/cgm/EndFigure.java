// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

/**
 * EndFigure TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: EndFigure.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class EndFigure
    extends CGMTag {

    public EndFigure() {
        super(0, 9, 2);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.outdent();
        cgm.print("ENDFIGURE");
    }
}
