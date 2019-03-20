// Copyright 2001, FreeHEP.
package org.freehep.util.io.test;

import java.io.*;

import org.freehep.util.io.*;

/**
 *
 * @author Mark Donszelmann
 * @version $Id: ASCII85InputStreamTest.java,v 1.3 2001/06/14 16:03:27 duns Exp $
 */
public class ASCII85InputStreamTest {

    public static void main(String[] args) throws IOException {
        if (args.length != 1) {
            System.out.println("Usage: ASCII85InputStreamTest filename");
            System.exit(1);
        }
        
        ASCII85InputStream in = new ASCII85InputStream(new FileInputStream(args[0]));
        int b = in.read();
        while (b != -1) {
            System.out.write(b);
            b = in.read();
        }
        in.close();
        System.out.flush();
    }
}
