// Copyright 2001, FreeHEP.
package org.freehep.postscript;

import java.io.InputStream;
import java.io.IOException;

/**
 * Objects for PostScript Processor, as defined in 3.3 Data Types and Objects
 *
 * @author Mark Donszelmann
 * @version $Id: PSDataSource.java,v 1.3 2004/01/12 20:19:15 duns Exp $
 */
public interface PSDataSource {

    public InputStream getInputStream();
    public int read() throws IOException;
    public void reset() throws IOException;
    public DSC getDSC();
}
