// Copyright 2001, FreeHEP.
package org.freehep.postscript;

import java.lang.reflect.Field;

/**
 * OperandStack for PostScript Processor
 *
 * @author Mark Donszelmann
 * @version $Id: GStateStack.java,v 1.1 2001/06/04 07:23:50 duns Exp $
 */
public class GStateStack extends PostScriptStack {
            
    public GStateStack() {
        super();
    }
    
    public Object push(Object o){
        throw new IllegalArgumentException("Only PSGState allowed on stack.");
    }
    
    public PSGState push(PSGState gs) {
        return (PSGState)super.push(gs);
    }
        
    public PSGState popGState() {
        return (PSGState)pop();
    }
 
    public String toString() {
        return "GStateStack";
    }
}