// Copyright 2000, CERN, Geneva, Switzerland.
package org.freehep.util.commandline;

/**
 * Option does not exist, or an ampty option is provided.
 *
 * @author Mark Donszelmann
 * @version $Id: NoSuchOptionException.java,v 1.2 2000/06/07 11:42:00 duns Exp $
 */ 
public class NoSuchOptionException extends CommandLineException {
    public NoSuchOptionException(String msg) {
        super(msg);
    }
    
    public NoSuchOptionException() {
        super("No Such Option Exception");
    }
}
