// Copyright 2003, FreeHEP
package org.freehep.graphicsio.raw;

import java.awt.*;
import java.awt.image.*;
import java.awt.image.renderable.*;
import java.io.*;
import java.util.*;
import javax.imageio.*;
import javax.imageio.metadata.*;
import javax.imageio.spi.*;
import javax.imageio.stream.*;

import org.freehep.util.images.ImageUtilities;

/**
 *
 * @version $Id: RawImageWriter.java,v 1.1 2003/05/27 22:35:47 duns Exp $
 */
public class RawImageWriter extends ImageWriter {

    public RawImageWriter(RawImageWriterSpi originatingProvider) {
        super(originatingProvider);
    }

    public void write(IIOMetadata streamMetadata,
                      IIOImage image,
                      ImageWriteParam param)
                    throws IOException {
        if (image == null) throw new IllegalArgumentException("image == null");

        if (image.hasRaster()) throw new UnsupportedOperationException("Cannot write rasters");

        Object output = getOutput();
        if (output == null) throw new IllegalStateException("output was not set");

        if (param == null) param = getDefaultWriteParam();

        ImageOutputStream ios = (ImageOutputStream)output;
        RenderedImage ri = image.getRenderedImage();

        RawImageWriteParam rawParam = (RawImageWriteParam)param;
        byte[] bytes = ImageUtilities.getBytes(ri, rawParam.getBackground(),
                                               rawParam.getCode(), rawParam.getPad());
        ios.write(bytes);
    }

    public IIOMetadata convertStreamMetadata(IIOMetadata inData,
                                             ImageWriteParam param) {
        return null;
    }

    public IIOMetadata convertImageMetadata(IIOMetadata inData,
                                            ImageTypeSpecifier imageType,
                                            ImageWriteParam param) {
        return null;
    }

    public IIOMetadata getDefaultImageMetadata(ImageTypeSpecifier imageType,
                                               ImageWriteParam param) {
        return null;
    }

    public IIOMetadata getDefaultStreamMetadata(ImageWriteParam param) {
        return null;
    }

    public ImageWriteParam getDefaultWriteParam() {
        return new RawImageWriteParam(getLocale());
    }
}
                    