// Copyright 2001, FreeHEP.
package org.freehep.util.io;

import java.io.*;
import java.util.*;

/**
 * The UniquePrintStream keeps Strings buffered in sorted order,
 * but any duplicates are removed. This stream can be used to print
 * error messages exactly once. When finish is called all messages are
 * printed.
 *
 * It only acts on the println(String) method, any other method will
 * print directly.
 *
 * @author Mark Donszelmann
 * @version $Id: UniquePrintStream.java,v 1.1 2002/07/01 21:25:18 duns Exp $
 */
public class UniquePrintStream extends PrintStream implements FinishableOutputStream {

    SortedSet msg = new TreeSet();

    public UniquePrintStream(OutputStream out) {
        super(out);
    }

    public void println(String s) {
        synchronized(this) {
            msg.add(s);
        }
    }

    public void finish() {
        for (Iterator i=msg.iterator(); i.hasNext(); ) {
            String s = (String)i.next();
            super.println(s);
        }
        msg = new TreeSet();
    }
}
