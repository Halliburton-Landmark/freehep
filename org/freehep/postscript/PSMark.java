// Copyright 2001, FreeHEP.
package org.freehep.postscript;

/**
 * Objects for PostScript Processor, as defined in 3.3 Data Types and Objects
 *
 * @author Mark Donszelmann
 * @version $Id: PSMark.java,v 1.2 2001/06/19 09:39:25 duns Exp $
 */
public class PSMark extends PSSimple {
    public PSMark() {
        super("mark", true);
    }
        
    public boolean execute(OperandStack os) {
        os.push(this);
        return true;
    }
    
    public String getType() {
        return "marktype";
    }

    public int hashCode() {
        return getClass().hashCode();
    }

    public boolean equals(Object o) {
        if (o instanceof PSMark) {
            return true;
        }
        return false;
    }

    public Object clone() {
        return new PSMark();
    }
    
    public String cvs() {
        return toString();
    }
    
    public String toString() {
        return "--"+name+"--";
    }
}
