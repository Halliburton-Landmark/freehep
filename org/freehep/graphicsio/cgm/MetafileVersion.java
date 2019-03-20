// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * MetafileVersion TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: MetafileVersion.java,v 1.1 2001/11/29 01:45:26 duns Exp $
 */
public class MetafileVersion
    extends CGMTag {

    private int version;

    public MetafileVersion() {
        super(1, 1, 1);
    }
    
    public MetafileVersion(int version) {
        this();
        this.version = version;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeInteger(version);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("MFVERSION ");
        cgm.writeInteger(version);
    }
}
