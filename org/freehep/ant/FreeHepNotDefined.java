// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import java.util.*;

import org.apache.tools.ant.*;
import org.apache.tools.ant.taskdefs.*;


/**
 * Checks if a property is NOT defined and executes its target, or throws a message if specified.
 *
 * @author Mark Donszelmann
 * @version $Id: FreeHepNotDefined.java,v 1.2 2004/01/14 00:24:56 duns Exp $
 */

public class FreeHepNotDefined extends FreeHepDefined {
        
    public void execute() throws BuildException {
        if (getProject().getProperty(property) == null) {
            if (message != null) {
                throw new BuildException(message);
            } 
                        
            getProject().executeTarget(target);            
        }
    }              
}
