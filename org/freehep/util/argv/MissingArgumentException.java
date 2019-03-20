// Copyright 2004, FreeHEP.
package org.freehep.util.argv;

import java.io.*;
import java.math.*;
import java.util.*;

/**
 * 
 *
 * @author Mark Donszelmann
 * @version $Id: MissingArgumentException.java,v 1.1 2004/01/12 20:19:26 duns Exp $
 */ 
public class MissingArgumentException extends Exception {
    public MissingArgumentException(String msg) {
        super(msg);
    }
}
