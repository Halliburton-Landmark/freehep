// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import org.apache.tools.ant.*;
import org.apache.tools.ant.taskdefs.*;
import org.apache.tools.ant.types.*;
import java.io.*;
import java.util.*;

/**
 * Executes a given SET OF COMMANDS if the os platform is appropriate.
 *
 * Same parameters as Exec, except for command.
 * <ul>
 * <li>command: semicolon separated list of commands
 * </ul>
 *
 * @author Mark Donszelmann
 * @version $Id: FreeHepExec.java,v 1.3 2004/01/14 00:24:56 duns Exp $
 */
public class FreeHepExec extends ExecTask {

    String commandList = null;

    public void setCommandList(String commandList) {
        this.commandList = commandList;
    }

    public void execute() throws BuildException {
        if (commandList != null) {
            StringTokenizer st = new StringTokenizer(commandList, ";");
            while (st.hasMoreTokens()) {
                String command = st.nextToken();
                System.out.println(command);
                cmdl = new Commandline(command);
                super.execute();
            }
        }
    }
}
