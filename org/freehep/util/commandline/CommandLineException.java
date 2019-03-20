// Copyright 2000, CERN, Geneva, Switzerland.
package org.freehep.util.commandline;

/**
 * Superclass of all Command Line exceptions.
 *
 * @author Mark Donszelmann
 * @version $Id: CommandLineException.java,v 1.2 2000/06/07 11:42:00 duns Exp $
 */ 
public abstract class CommandLineException extends Exception {
    public CommandLineException(String msg) {
        super(msg);
    }
}
