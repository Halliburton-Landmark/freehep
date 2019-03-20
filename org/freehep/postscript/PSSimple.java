// Copyright 2001, FreeHEP.
package org.freehep.postscript;

/**
 * Objects for PostScript Processor, as defined in 3.3 Data Types and Objects
 *
 * @author Mark Donszelmann
 * @version $Id: PSSimple.java,v 1.2 2001/06/18 16:08:27 duns Exp $
 */
public abstract class PSSimple extends PSObject {
    
    public PSSimple(String name, boolean literal) {
        super(name, literal);
    }
    
    public PSObject copy() {
        return (PSObject)clone();
    }
}

