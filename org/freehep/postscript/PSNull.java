// Copyright 2001, FreeHEP.
package org.freehep.postscript;

/**
 * Objects for PostScript Processor, as defined in 3.3 Data Types and Objects
 *
 * @author Mark Donszelmann
 * @version $Id: PSNull.java,v 1.2 2001/06/19 09:39:25 duns Exp $
 */
public class PSNull extends PSSimple {
    public PSNull() {
        super("null", true);
    }
    
    public boolean execute(OperandStack os) {
        os.push(this);
        return true;
    }
    
    public String getType() {
        return "nulltype";
    }

    public Object clone() {
        return new PSNull();
    }
    
    public int hashCode() {
        return getClass().hashCode();
    }

    public boolean equals(Object o) {
        if (o instanceof PSNull) {
            return true;
        }
        return false;
    }
    
    public String cvs() {
        return toString();
    }
    
    public String toString() {
        return "--"+name+"--";
    }
}

