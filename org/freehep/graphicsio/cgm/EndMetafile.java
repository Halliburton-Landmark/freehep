// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

/**
 * EndMetafile TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: EndMetafile.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class EndMetafile
    extends CGMTag {

    public EndMetafile() {
        super(0, 2, 1);
    }
 
    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.outdent();
        cgm.print("ENDMF");
    }
}