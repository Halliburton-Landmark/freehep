// Copyright 2001-2003, FreeHEP.
package org.freehep.graphicsio.swf;

import java.awt.Color;
import java.awt.Image;
import java.awt.image.ImageObserver;
import java.awt.image.BufferedImage;
import java.awt.image.RenderedImage;
import java.awt.image.WritableRaster;
import java.io.*;
import java.util.zip.InflaterInputStream;
import java.util.zip.DeflaterOutputStream;

import org.freehep.util.UserProperties;
import org.freehep.util.io.ByteOrderInputStream;
import org.freehep.util.io.ByteOrderOutputStream;
import org.freehep.util.io.FlateOutputStream;
import org.freehep.util.io.NoCloseOutputStream;
import org.freehep.util.images.ImageUtilities;

import org.freehep.graphicsio.ImageGraphics2D;
import org.freehep.graphicsio.raw.RawImageWriteParam;

/**
 * DefineBitsLossless TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: DefineBitsLossless.java,v 1.8 2003/05/27 22:35:49 duns Exp $
 */
public class DefineBitsLossless
    extends DefinitionTag {

    protected int character;
    protected RenderedImage image;
    protected Color bkg;

    public DefineBitsLossless(int id, Image image, Color bkg, ImageObserver observer) {
        this(id, ImageUtilities.createRenderedImage(image, observer, bkg), bkg);
    }

    public DefineBitsLossless(int id, RenderedImage image, Color bkg) {
        this();
        character = id;
        this.image = image;
        this.bkg = bkg;
    }

    public DefineBitsLossless() {
        super(20, 2);
    }

    protected DefineBitsLossless(int tagID, int version) {
        super(tagID, version);
    }

    public SWFTag read(int tagID, SWFInputStream swf, int len)
        throws IOException {

        DefineBitsLossless tag = new DefineBitsLossless();
        tag.read(tagID, swf, len, false);
        return tag;
    }

    protected void read(int tagID, SWFInputStream swf, int len, boolean hasAlpha)
        throws IOException {

        character = swf.readUnsignedShort();
        swf.getDictionary().put(character, this);

        int format = swf.readUnsignedByte();
        int width = swf.readUnsignedShort();
        int height = swf.readUnsignedShort();

        int colorTableSize = (format == 3) ? swf.readUnsignedByte() + 1 : 0;

        InflaterInputStream zip = new InflaterInputStream(swf);
        ByteOrderInputStream bois = new ByteOrderInputStream(zip, true);

        int[][] colors = new int[colorTableSize][hasAlpha ? 4 : 3];
        for (int i=0; i<colorTableSize; i++) {
            colors[i][0] = zip.read();
            colors[i][1] = zip.read();
            colors[i][2] = zip.read();
            if (hasAlpha) {
                colors[i][3] = zip.read();
            }
        }

        BufferedImage bi = new BufferedImage(width, height, (hasAlpha) ? BufferedImage.TYPE_INT_ARGB : BufferedImage.TYPE_INT_RGB);
        WritableRaster raster = bi.getRaster();
        int[] rgba = new int[hasAlpha ? 4 : 3];
        for (int y=0; y<height; y++) {
            for (int x=0; x<width; x++) {
                switch (format) {
                    default:System.out.println("ERROR: unknown format in LossLess image: "+format);
                            return;
                    case 3: raster.setPixel(x, y, colors[bois.readUnsignedByte()]);
                            break;
                    case 4: if (hasAlpha) {
                                System.out.println("ERROR: unknown format in LossLess2 image: 4");
                                return;
                            }
                            bois.readUBits(1);
                            rgba[0] = (int)bois.readUBits(5);
                            rgba[1] = (int)bois.readUBits(5);
                            rgba[2] = (int)bois.readUBits(5);
                            raster.setPixel(x, y, rgba);
                            break;
                    case 5:
                            if (hasAlpha) {
                                rgba[3] = bois.readUnsignedByte();
                            } else {
                                bois.readUnsignedByte();
                            }
                            rgba[0] = bois.readUnsignedByte();
                            rgba[1] = bois.readUnsignedByte();
                            rgba[2] = bois.readUnsignedByte();
                            raster.setPixel(x, y, rgba);
                            break;
                }
// FIXME padding not taken into account.
            }
        }

        image = bi;
    }

    public void write(int tagID, SWFOutputStream swf)
        throws IOException {

        write(tagID, swf, false);
    }

    protected void write(int tagID, SWFOutputStream swf, boolean hasAlpha)
        throws IOException {

        swf.writeUnsignedShort(character);
        swf.writeUnsignedByte(5);           // fixed to format 5
        swf.writeUnsignedShort(image.getWidth());
        swf.writeUnsignedShort(image.getHeight());

        swf.write(getImageBytes());
    }

    public int getLength() throws IOException {
        return getImageBytes().length + 7;
    }

    private byte[] imageBytes;
    private byte[] getImageBytes() throws IOException {
        if (imageBytes == null) {
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            FlateOutputStream flate = new FlateOutputStream(baos);

            UserProperties props = new UserProperties();
            props.setProperty(RawImageWriteParam.BACKGROUND, bkg);
            props.setProperty(RawImageWriteParam.CODE, "*ARGB");
            props.setProperty(RawImageWriteParam.PAD, 1);
            ImageGraphics2D.writeImage(image, "raw", props, flate);
            flate.close();

            imageBytes = baos.toByteArray();
        }
        return imageBytes;
    }

    public String toString() {
        StringBuffer s = new StringBuffer();
        s.append(super.toString()+"\n");
        s.append("  character:  "+character);
        s.append("  image: "+image);
        return s.toString();
    }
}
