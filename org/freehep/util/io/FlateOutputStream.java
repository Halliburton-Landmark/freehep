// Copyright 2001-2005, FreeHEP.
package org.freehep.util.io;

import java.awt.*;
import java.awt.image.*;
import java.io.*;
import java.util.*;
import java.util.zip.*;
import javax.imageio.*;
import javax.imageio.stream.*;

/**
 * The FlateOutputStream uses the Deflate mechanism to compress data.
 * The exact definition of Deflate encoding can be found
 * in the PostScript Language Reference (3rd ed.) chapter 3.13.3.
 *
 * @author Mark Donszelmann
 * @version $Id: FlateOutputStream.java,v 1.5 2005/01/10 18:29:57 duns Exp $
 */
public class FlateOutputStream extends DeflaterOutputStream implements FinishableOutputStream {

    public FlateOutputStream(OutputStream out) {
        super(out);
    }

    public void finish() throws IOException {
        super.finish();
        if (out instanceof FinishableOutputStream) {
            ((FinishableOutputStream)out).finish();
        }
    }
}
