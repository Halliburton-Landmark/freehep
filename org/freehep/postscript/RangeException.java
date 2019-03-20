// Copyright 2004, FreeHEP.
package org.freehep.postscript;


/**
 * Range(Check) Exception for PostScript Processor
 *
 * @author Mark Donszelmann
 * @version $Id: RangeException.java,v 1.1 2004/01/12 20:19:17 duns Exp $
 */
public class RangeException extends Exception {

    public RangeException() {
        super();
    }

    public RangeException(String msg) {
        super(msg);
    }
}
