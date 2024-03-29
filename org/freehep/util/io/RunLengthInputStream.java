// Copyright 2001, FreeHEP.
package org.freehep.util.io;

import java.io.*;

/**
 * The RunLengthStream decodes Run Length encoding.
 * The exact definition of Run Length encoding can be found 
 * in the PostScript Language Reference (3rd ed.) chapter 3.13.3.
 * 
 * IMPORTANT: inherits from InputStream rather than FilterInputStream 
 * so that the correct read(byte[], int, int) method is used.
 * 
 * @author Mark Donszelmann
 * @version $Id: RunLengthInputStream.java,v 1.2 2001/06/15 14:11:18 duns Exp $
 */
public class RunLengthInputStream extends InputStream implements RunLength {

    private boolean endReached;
    private int[] buffer = new int[LENGTH];
    private int index;
    private int count;
    private InputStream in;
    
    public RunLengthInputStream(InputStream input) {
        super();
        in = input;
        endReached = false;
        index = 0;
        count = 0;
    }
    
    public int read() throws IOException {

        if ((index >= count) || (index > 128)) {
            if (!fillBuffer()) return -1;
        }
                
        int b = buffer[index];
        index++;
        return b & 0x00FF; 
    }
    
    private boolean fillBuffer() throws IOException {
        count = in.read();
        
        if (end(count)) return false;

        if (count < 128) {
            // buffered
            count++;
            for (int i=0; i<count; i++) {
                buffer[i] = in.read();
                if (end(buffer[i])) return false;
            }
        } else {
            // counted
            count = 257-count;
            int b = in.read();
            if (end(b)) return false;
                        
            for (int i=0; i<count; i++) {
                buffer[i] = b;
            } 
        }
        index = 0;
        return true;
    }

    private boolean end(int b) {
        if ((b < 0) || (b == EOD)) {
            endReached = true;
            return true;
        }
        return false; 
    }   
}
