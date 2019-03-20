// Copyright 2001, FreeHEP.
package org.freehep.util.io;

import java.io.*;

/**
 * The NoCloseOutputStream ignores the close so that one can keep writing to the underlying stream.
 *
 * @author Mark Donszelmann
 * @version $Id: NoCloseOutputStream.java,v 1.1 2003/04/30 22:16:15 duns Exp $
 */
public class NoCloseOutputStream extends BufferedOutputStream {

    public NoCloseOutputStream(OutputStream stream) {
        super(stream);
    }

    public NoCloseOutputStream(OutputStream stream, int size) {
        super(stream, size);
    }

    public void close() throws IOException {
        flush();
    }

    public void realClose() throws IOException {
        super.close();
    }
}
