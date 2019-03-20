// Copyright 2003, FreeHEP
package org.freehep.graphicsio.raw;

import java.io.*;
import java.util.*;
import javax.imageio.*;
import javax.imageio.spi.*;


/**
 *
 * @version $Id: RawImageWriterSpi.java,v 1.2 2003/06/11 18:59:10 duns Exp $
 */
public class RawImageWriterSpi extends ImageWriterSpi {

    public RawImageWriterSpi() {
        super(
            "FreeHEP Java Libraries, http://java.freehep.org/",
            "1.0",
            new String[] {"raw"},
            new String[] {"raw"},
            new String[] {"image/x-raw"},
            "org.freehep.graphicsio.raw.RawImageWriter",
            STANDARD_OUTPUT_TYPE,
            null,
            false, null, null, null, null,
            false, null, null, null, null
        );
    }

    public String getDescription(Locale locale) {
        return "RAW image";
    }

    public ImageWriter createWriterInstance(Object extension)
                                          throws IOException {
        return new RawImageWriter(this);
    }

    public boolean canEncodeImage(ImageTypeSpecifier type) {
        // FIXME
        return true;
    }
}