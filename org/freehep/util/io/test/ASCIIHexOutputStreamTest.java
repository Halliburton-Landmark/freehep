// Copyright 2001, FreeHEP.
package org.freehep.util.io.test;

import java.io.*;

import org.freehep.util.io.*;

/**
 *
 * @author Mark Donszelmann
 * @version $Id: ASCIIHexOutputStreamTest.java,v 1.3 2001/06/14 16:03:27 duns Exp $
 */
public class ASCIIHexOutputStreamTest {

    public static void main(String[] args) throws IOException {
        if (args.length != 1) {
            System.out.println("Usage: ASCIIHexOutputStreamTest filename");
            System.exit(1);
        }
        
        ASCIIHexOutputStream out = new ASCIIHexOutputStream(System.out);
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        String line = reader.readLine();
        while (line != null) {
            out.write(line.getBytes());
            out.write('\r');
            out.write('\n');
            line = reader.readLine();
        }
        reader.close();
        out.close();
    }
}
