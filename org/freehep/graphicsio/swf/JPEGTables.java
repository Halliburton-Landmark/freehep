// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.swf;

import java.io.IOException;

/**
 * JPEGTables TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: JPEGTables.java,v 1.1 2001/11/29 01:45:31 duns Exp $
 */
public class JPEGTables
    extends DefinitionTag {

    private byte[] table;

    public JPEGTables() {
        super(8, 1);
    }

    public SWFTag read(int tagID, SWFInputStream swf, int len)
        throws IOException {
            
        JPEGTables tag = new JPEGTables();
        tag.table = swf.readByte(len);
        swf.setJPEGTable(tag.table);
        return tag;
    }

    public void write(int tagID, SWFOutputStream swf) throws IOException {
        swf.writeByte(table);
    }

    public String toString() {
        return super.toString()+"\n"+
               "  length: "+table.length+"\n";
    }
}
