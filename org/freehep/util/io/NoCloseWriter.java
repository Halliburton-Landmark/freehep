// Copyright 2003, FreeHEP.
package org.freehep.util.io;

import java.io.*;

/**
 * The NoCloseWriter ignores the close so that one can keep writing 
 * to the underlying stream.
 *
 * @author Mark Donszelmann
 * @version $Id: NoCloseWriter.java,v 1.1 2003/12/09 22:12:54 duns Exp $
 */
public class NoCloseWriter extends BufferedWriter {

    public NoCloseWriter(Writer writer) {
        super(writer);
    }

    public NoCloseWriter(Writer writer, int size) {
        super(writer, size);
    }

    public void close() throws IOException {
        flush();
    }

    public void realClose() throws IOException {
        super.close();
    }
}
