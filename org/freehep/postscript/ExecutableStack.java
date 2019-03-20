// Copyright 2001, FreeHEP.
package org.freehep.postscript;

/**
 * Excutable Stack for PostScript Processor
 *
 * @author Mark Donszelmann
 * @version $Id: ExecutableStack.java,v 1.1 2001/06/04 07:23:49 duns Exp $
 */
public class ExecutableStack extends PostScriptStack {
    
    public PSFile getCurrentFile() {
        for (int i=elementCount-1; i>=0; i--) {
            if (elementData[i] instanceof PSFile) {
                return (PSFile)elementData[i];
            }
        }
        return null;
    }
    
    public String toString() {
        return "ExecutionStack";
    }
}