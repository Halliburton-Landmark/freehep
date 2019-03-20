// Copyright 2000, CERN, Geneva, Switzerland.
package org.freehep.util.commandline;

/**
 * Too many arguments were provided. 
 *
 * @author Mark Donszelmann
 * @version $Id: TooManyArgumentsException.java,v 1.2 2000/06/07 11:42:00 duns Exp $
 */ 
public class TooManyArgumentsException extends CommandLineException {
    public TooManyArgumentsException(String msg) {
        super(msg);
    }
    
    public TooManyArgumentsException() {
        super("Too Many Arguments Exception");
    }
}
