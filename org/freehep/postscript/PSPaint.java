// Copyright 2001, FreeHEP.
package org.freehep.postscript;

import java.awt.Paint;

/**
 * Objects for PostScript Processor, as defined in 3.3 Data Types and Objects
 *
 * @author Mark Donszelmann
 * @version $Id: PSPaint.java,v 1.1 2001/06/24 15:50:07 duns Exp $
 */
public class PSPaint extends PSSimple {
    private Paint value;
    
    public PSPaint(Paint v) {
        super("paint", false);
        value = v;
    }
        
    public boolean execute(OperandStack os) {
        os.push(this);
        return true;
    }

    public String getType() {
        return "painttype";
    }

    public Paint getValue() {
        return value;
    }
    
    public int hashCode() {
        return value.hashCode();
    }
    
    public boolean equals(Object o) {
        if (o instanceof PSPaint) {
            return value.equals(((PSPaint)o).getValue());
        }
        return false;
    }

    public Object clone() {
        return new PSPaint(value);
    }
    
    public String cvs() {
        return toString();
    }
    
    public String toString() {
        return "paint: "+value;
    }
}

