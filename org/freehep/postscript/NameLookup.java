// Copyright 2001, FreeHEP.
package org.freehep.postscript;


/**
 * Lookup Interface for PostScript Processor
 *
 * @author Mark Donszelmann
 * @version $Id: NameLookup.java,v 1.1 2001/06/21 07:20:16 duns Exp $
 */
public interface NameLookup {

    public PSObject lookup(PSObject key);
}