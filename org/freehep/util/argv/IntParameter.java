// Copyright 2004, FreeHEP.
package org.freehep.util.argv;

import java.io.*;
import java.math.*;
import java.util.*;

/**
 * 
 *
 * @author Mark Donszelmann
 * @version $Id: IntParameter.java,v 1.1 2004/01/12 20:19:26 duns Exp $
 */ 
public class IntParameter extends NumberParameter {

    public IntParameter(String name, String description) {
        super(name, description);
    }
        
    public int getInt() {
        return super.getValue().intValue();
    }
      
}
