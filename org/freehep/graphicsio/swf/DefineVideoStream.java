// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.swf;

import java.io.IOException;

/**
 * DefineVideoStream TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: DefineVideoStream.java,v 1.1 2003/04/15 18:03:05 duns Exp $
 */
public class DefineVideoStream
    extends DefinitionTag {

    private byte[] data;

    public DefineVideoStream() {
        super(60, 6);
    }

    public SWFTag read(int tagID, SWFInputStream swf, int len)
        throws IOException {

        DefineVideoStream tag = new DefineVideoStream();
        tag.data = swf.readByte(len);
        return tag;
    }

    public void write(int tagID, SWFOutputStream swf) throws IOException {
        swf.writeByte(data);
    }

    public String toString() {
        return super.toString()+"\n"+
               "  length: "+data.length+"\n";
    }
}
