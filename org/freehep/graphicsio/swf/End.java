// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.swf;

import java.io.IOException;

/**
 * End TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: End.java,v 1.1 2001/11/29 01:45:31 duns Exp $
 */
public class End
    extends ControlTag {

    public End() {
        super(0, 1);
    }

    public SWFTag read(int tagID, SWFInputStream swf, int len) 
        throws IOException {

        return this;
    }    
}
