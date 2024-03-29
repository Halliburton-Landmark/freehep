// Copyright 2001, FreeHEP.
package org.freehep.postscript;

import java.util.EmptyStackException;

/**
 * Objects for PostScript Processor, as defined in 3.3 Data Types and Objects
 *
 * @author Mark Donszelmann
 * @version $Id: PSOperator.java,v 1.6 2001/06/19 09:39:25 duns Exp $
 */
public abstract class PSOperator extends PSSimple {
    
    protected Class[] operandTypes = new Class[0];
    
    public PSOperator() {
        super("operator", false);
    }
    
    // lowercased name of the final part of the Class Name
    public String getName() {
        String name = getClass().getName();
        int pos = name.lastIndexOf('.');
        if (pos >= 0) {
            name = name.substring(pos+1);
        }
        return name.toLowerCase();
    }

    public boolean checkAndExecute(OperandStack os) {
        // set the mark for errors
        os.mark();
        
        // Check for StackUnderflow
        if (operandTypes.length > os.size()) {
            error(os, new StackUnderflow());
            return true;
        }
        
        // Check for TypeCheck
        if (!os.checkType(operandTypes)) {
            error(os, new TypeCheck());
            return true;
        }
        
        // excecute operator implementation
        return execute(os);
    }
    
    public String getType() {
        return "operatortype";
    }

    public int hashCode() {
        return getClass().hashCode();
    }

    public boolean equals(Object o) {
        if (o instanceof PSOperator) {
            return getClass().equals(o.getClass());
        }
        return false;
    }

    // careful: do not add any instance variables
    public Object clone() {
        return this;
    }
    
    // careful: do not add any instance variables
    public PSObject copy() {
        return this;
    }
    
    public String cvs() {
        return getName();
    }
    
    public String toString() {
        return "//"+getName();
    }
}
