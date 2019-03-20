// Copyright 2001, FreeHEP.
package org.freehep.postscript;

/**
 * Extra Operators for PostScript Processor
 *
 * @author Mark Donszelmann
 * @version $Id: ExtraOperator.java,v 1.3 2004/01/12 20:19:13 duns Exp $
 */
public class ExtraOperator extends PSOperator {
    
    public static Class[] operators = {
        Break.class
    };

    public boolean execute(OperandStack os) {
        throw new RuntimeException("Cannot execute class: "+getClass());
    }
}

class Break extends ExtraOperator {

    public boolean execute(OperandStack os) {
        os.execStack().pop();
        throw new BreakException();
    }
}