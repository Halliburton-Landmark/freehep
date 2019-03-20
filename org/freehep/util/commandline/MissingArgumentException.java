// Copyright 2000, CERN, Geneva, Switzerland.
package org.freehep.util.commandline;

/**
 * Too few arguments were provided.
 *
 * @author Mark Donszelmann
 * @version $Id: MissingArgumentException.java,v 1.2 2000/06/07 11:42:00 duns Exp $
 */ 
public class MissingArgumentException extends CommandLineException {
    public MissingArgumentException(String msg) {
        super(msg);
    }
    
    public MissingArgumentException() {
        super("Missing Argument Exception");
    }
}
