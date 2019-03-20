// Copyright 2004, FreeHEP.
package org.freehep.util.argv;

import java.io.*;
import java.math.*;
import java.util.*;

/**
 * 
 *
 * @author Mark Donszelmann
 * @version $Id: IntOption.java,v 1.1 2004/01/12 20:19:26 duns Exp $
 */ 
public class IntOption extends NumberOption {

    public IntOption(String flag, String name, String description) {
        super(flag, name, description);
    }
    
    public IntOption(String flag, String shortCut, String name, String description) {
        super(flag, shortCut, name, description);
    }
    
    public IntOption(String flag, String name, int defaultValue, String description) {
        super(flag, name, new BigDecimal(defaultValue), description);
    }
    
    public IntOption(String flag, String shortCut, String name, int defaultValue, String description) {
        super(flag, shortCut, name, new BigDecimal(defaultValue), description);
    }
    
    public int getInt() {
        return super.getValue().intValue();
    }
      
}
