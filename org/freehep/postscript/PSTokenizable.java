// Copyright 2001, FreeHEP.
package org.freehep.postscript;

import java.io.IOException;

/**
 * Objects for PostScript Processor, as defined in 3.3 Data Types and Objects
 *
 * @author Mark Donszelmann
 * @version $Id: PSTokenizable.java,v 1.3 2001/06/21 07:20:17 duns Exp $
 */
public interface PSTokenizable {
    
    public PSObject token(boolean packingMode, NameLookup lookup) throws IOException, SyntaxException, NameNotFoundException;

}
