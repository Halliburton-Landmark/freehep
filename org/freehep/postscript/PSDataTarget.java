// Copyright 2001, FreeHEP.
package org.freehep.postscript;

import java.io.IOException;
import java.io.OutputStream;

/**
 * Objects for PostScript Processor, as defined in 3.3 Data Types and Objects
 *
 * @author Mark Donszelmann
 * @version $Id: PSDataTarget.java,v 1.2 2001/06/16 09:04:29 duns Exp $
 */
public interface PSDataTarget {
    
    public OutputStream getOutputStream();
    public void write(int b, boolean secure) throws IOException;
}
