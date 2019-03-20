// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.swf;

import java.io.IOException;

/**
 * ShowFrame TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: ShowFrame.java,v 1.1 2001/11/29 01:45:32 duns Exp $
 */
public class ShowFrame
    extends ControlTag {

    public ShowFrame() {
        super(1, 1);
    }

    public SWFTag read(int tagID, SWFInputStream swf, int len) 
        throws IOException {            
        return this;
    }    
}
