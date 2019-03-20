// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import java.util.*;

import org.apache.tools.ant.*;
import org.apache.tools.ant.taskdefs.*;

/**
 * Call FreeHep-Ant in a sub-project, which executes as a true sub-ant, 
 * without inheriting anything from the super-ant.
 * <P>
 * Two options are possible, the first, a command-line like execution:
 *
 * <pre>
 *    <target name="foo" depends="init">
 *      <freehep.ant args="-Djar=2d target" />
 *    </target>
 * </pre>
 *
 * <P>
 * The second multiple invocations on the same target with "jar" defined
 * differently every time:
 *
 * <pre>
 *    <target name="foo" depends="init">
 *      <freehep.ant jars="2d, tools" args="-v dist" />
 *    </target>
 * </pre>
 *
 * @author Mark Donszelmann
 * @version $Id: FreeHepAnt.java,v 1.3 2004/01/14 00:24:55 duns Exp $
 */

public class FreeHepAnt extends Task {

    private String argString = null;
    private String jars = null;

    public void setArgs(String str) {
        argString = str;
    }
    
    public void setJars(String str) {
        jars = str;
    }
            
    public void execute() throws BuildException {
        if ((argString == null) && (jars == null)) {
            throw new BuildException("Property 'args' or 'jars' must be specified!");
        }

        int n = (jars == null) ? 0 : 1;
        
        String args[];    
        if (argString != null) {
            StringTokenizer st = new StringTokenizer(argString, " ");
            args = new String[n+st.countTokens()];
            for (int i=n; i<args.length; i++) {
                args[i] = (st.nextToken());
            }
        } else {
            args = new String[1];
        }
        
        if (jars == null) {
            log("ant "+argString, Project.MSG_VERBOSE);
            new FreeHepMain(args).runBuild(null);       
        } else {
            StringTokenizer jarTokenizer = new StringTokenizer(jars, ", ");
            while (jarTokenizer.hasMoreTokens()) {
                args[0] = "-Djar="+jarTokenizer.nextToken();
                log("ant "+args[0]+" "+((argString == null) ? "" : argString), Project.MSG_INFO);
                new FreeHepMain(args).runBuild(null);
            }
        }

    }       
}
