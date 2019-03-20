// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.font.truetype;

import java.io.IOException;

/**
 * VERSION Table.
 *
 *  @author Simon Fischer
 *  @version $Id: TTFVersionTable.java,v 1.1 2001/11/29 01:45:29 duns Exp $
 */
public abstract class TTFVersionTable extends TTFTable {

    public int minorVersion;
    public int majorVersion;

    public void readVersion() throws IOException {
        majorVersion = ttf.readUShort();
        minorVersion = ttf.readUShort();
    }

    public String toString() {
	    return super.toString()+" v"+majorVersion+"."+minorVersion;
    }

}
