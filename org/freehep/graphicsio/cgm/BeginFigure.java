// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

/**
 * BeginFigure TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: BeginFigure.java,v 1.1 2001/11/29 01:45:24 duns Exp $
 */
public class BeginFigure
    extends CGMTag {

    public BeginFigure() {
        super(0, 8, 2);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("BEGFIGURE");
        cgm.indent();
    }
}
