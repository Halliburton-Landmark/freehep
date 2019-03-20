// Copyright 2001, FreeHEP.
package org.freehep.postscript;


/**
 * Name Not Found Exception for PostScript Processor
 *
 * @author Mark Donszelmann
 * @version $Id: NameNotFoundException.java,v 1.1 2001/06/21 07:20:16 duns Exp $
 */
public class NameNotFoundException extends Exception {

    public NameNotFoundException(String msg) {
        super(msg);
    }
}
