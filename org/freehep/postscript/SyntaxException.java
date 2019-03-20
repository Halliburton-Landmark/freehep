// Copyright 2001, FreeHEP.
package org.freehep.postscript;


/**
 * Syntax Exception for PostScript Processor
 *
 * @author Mark Donszelmann
 * @version $Id: SyntaxException.java,v 1.1 2001/06/04 07:23:57 duns Exp $
 */
public class SyntaxException extends Exception {

    private int line;

    public SyntaxException(int line, String msg) {
        super(msg);
        this.line = line;
    }
    
    public int getLineNo() {
        return line;
    }
}
