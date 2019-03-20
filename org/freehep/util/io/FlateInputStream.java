// Copyright 2001-2003, FreeHEP.
package org.freehep.util.io;

import java.awt.*;
import java.io.*;
import java.util.zip.*;
import javax.imageio.*;

/**
 * The FlateInputStream uses the Deflate mechanism to compress data.
 * The exact definition of Deflate encoding can be found
 * in the PostScript Language Reference (3rd ed.) chapter 3.13.3.
 *
 * @author Mark Donszelmann
 * @version $Id: FlateOutputStream.java,v 1.1 2001/06/05 10:32:52 duns Exp $
 */
public class FlateInputStream extends InflaterInputStream {

    public FlateInputStream(InputStream in) {
        super(in);
    }

    public Image readImage() throws IOException {
// FIXME
        return null;
    }
}
