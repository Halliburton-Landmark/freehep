// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.swf;

import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.util.zip.InflaterInputStream;
import java.util.zip.DeflaterOutputStream;

import com.sun.image.codec.jpeg.JPEGCodec;
import com.sun.image.codec.jpeg.JPEGImageDecoder;
import com.sun.image.codec.jpeg.JPEGImageEncoder;

/**
 * DefineBits TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: DefineBits.java,v 1.2 2003/04/30 22:16:15 duns Exp $
 */
public class DefineBits
    extends DefinitionTag {

    private int character;
    private byte[] data;
    private BufferedImage image;

    public DefineBits() {
        super(6, 1);
    }

    public SWFTag read(int tagID, SWFInputStream swf, int len)
        throws IOException {

        DefineBits tag = new DefineBits();
        tag.character = swf.readUnsignedShort();
        swf.getDictionary().put(tag.character, tag);

        tag.data = swf.readByte(len-2);

        return tag;
    }

    public void write(int tagID, SWFOutputStream swf)
        throws IOException {

        swf.writeUnsignedShort(character);
        swf.writeByte(data);
    }

    public String toString() {
        StringBuffer s = new StringBuffer();
        s.append(super.toString()+"\n");
        s.append("  character:  "+character+"\n");
        s.append("  length:     "+data.length+"\n");
        return s.toString();
    }
}
