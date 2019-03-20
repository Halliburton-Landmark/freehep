// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import java.util.*;

import org.apache.tools.ant.*;
import org.apache.tools.ant.taskdefs.*;


/**
 * Checks if a property is defined and executes its target, or throws a message if specified.
 *
 * @author Mark Donszelmann
 * @version $Id: FreeHepDefined.java,v 1.3 2004/01/14 00:24:56 duns Exp $
 */

public class FreeHepDefined extends Task {

    protected String property = null;
    protected String message = null;
    protected String target = null;

    public void setProperty(String str) {
        property = str;
    }
    
    public void setMessage(String str) {
        message = str;
    }
    
    public void setTarget(String str) {
        target = str;
    }
        
    public void execute() throws BuildException {
        if (property == null) {
            throw new BuildException("property attribute must be set!");
        }
        
        if ((message == null) && (target == null)) {
            throw new BuildException("either target or message attribute must be set!");
        }            

        if (getProject().getProperty(property) != null) {
            if (message != null) {
                throw new BuildException(message);
            } 
                        
            getProject().executeTarget(target);            
        }
    }              
}
