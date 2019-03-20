// Copyright 2004, FreeHEP.
package org.freehep.util.argv;

import java.io.*;
import java.math.*;
import java.util.*;

/**
 * 
 *
 * @author Mark Donszelmann
 * @version $Id: DoubleOption.java,v 1.1 2004/01/12 20:19:26 duns Exp $
 */ 
public class DoubleOption extends NumberOption {

    public DoubleOption(String flag, String name, String description) {
        super(flag, name, description);
    }
    
    public DoubleOption(String flag, String shortCut, String name, String description) {
        super(flag, shortCut, name, description);
    }
    
    public DoubleOption(String flag, String name, double defaultValue, String description) {
        super(flag, name, new BigDecimal(defaultValue), description);
    }
    
    public DoubleOption(String flag, String shortCut, String name, double defaultValue, String description) {
        super(flag, shortCut, name, new BigDecimal(defaultValue), description);
    }
    
    public double getDouble() {
        return super.getValue().doubleValue();
    }
      
}
