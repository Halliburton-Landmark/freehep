// Copyright 2004, FreeHEP.
package org.freehep.util.argv;

import java.io.*;
import java.math.*;
import java.util.*;

/**
 * 
 *
 * @author Mark Donszelmann
 * @version $Id: ArgumentFormatException.java,v 1.1 2004/01/12 20:19:25 duns Exp $
 */ 
public class ArgumentFormatException extends Exception {
    public ArgumentFormatException(String msg) {
        super(msg);
    }
}
