// Copyright 2004, FreeHEP.
package org.freehep.util.argv;

import java.io.*;
import java.math.*;
import java.util.*;

/**
 * Exception to handle options such as -version or -help which need to bail out from 
 * the parsing loop.
 *
 * @author Mark Donszelmann
 * @version $Id: BailOutException.java,v 1.1 2004/01/12 20:19:25 duns Exp $
 */ 
public class BailOutException extends Exception {
    public BailOutException() {
        super();
    }
}
