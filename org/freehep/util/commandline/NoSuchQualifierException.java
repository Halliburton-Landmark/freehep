// Copyright 2000, CERN, Geneva, Switzerland.
package org.freehep.util.commandline;

/**
 * Qualifier does not exist.
 *
 * @author Mark Donszelmann
 * @version $Id: NoSuchQualifierException.java,v 1.2 2000/06/07 11:42:00 duns Exp $
 */ 
public class NoSuchQualifierException extends CommandLineException {
    public NoSuchQualifierException(String msg) {
        super(msg);
    }
    
    public NoSuchQualifierException() {
        super("No Such Qualifier Exception");
    }
}
