// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * MetafileDescription TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: MetafileDescription.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class MetafileDescription
    extends CGMTag {

    private String description;

    public MetafileDescription() {
        super(1, 2, 1);
    }
    
    public MetafileDescription(String description) {
        this();
        this.description = description;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeString(description);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("MFDESC ");
        cgm.writeString(description);
    }
}
