// Copyright 2003, FreeHEP.
package org.freehep.util.io;

import java.io.*;

/**
 * The NoCloseReader ignores the close so that one can keep reading 
 * from the underlying stream.
 *
 * @author Mark Donszelmann
 * @version $Id: NoCloseReader.java,v 1.1 2003/12/09 22:12:54 duns Exp $
 */
public class NoCloseReader extends BufferedReader {

    public NoCloseReader(Reader reader) {
        super(reader);
    }

    public NoCloseReader(Reader reader, int size) {
        super(reader, size);
    }

    public void close() throws IOException {
    }

    public void realClose() throws IOException {
        super.close();
    }
}
