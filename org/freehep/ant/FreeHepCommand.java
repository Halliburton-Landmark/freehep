// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import java.io.*;
import java.util.*;
import org.apache.tools.ant.*;
import org.apache.tools.ant.taskdefs.*;
import org.apache.tools.ant.types.*;

/**
 * Reads a set a property files, listed in the "commands" property
 * of the FreeHepCommand tag, and executes the commands listed
 * in the property "command", if any of the files in the property
 * "depends" are newer than the any of the files in the property "targets".
 *
 * If targets or depends are not specified the command is always executed.
 * The command itself can contain multiple command lines using a
 * semicolon to separate the commands.
 *
 * @author Mark Donszelmann
 * @version $Id: FreeHepCommand.java,v 1.2 2004/01/14 00:24:55 duns Exp $
 */
public class FreeHepCommand extends ExecTask {

    private Collection propertyFiles;

    public FreeHepCommand() {
    }

    public void setCommands(String str) {
        propertyFiles = new ArrayList();
        StringTokenizer st = new StringTokenizer(str, ", ");
        while (st.hasMoreTokens()) {
            propertyFiles.add(st.nextToken());
        }
    }

    /**
     * Executes the tasks based on the proeprty files
     */
    public void execute() throws BuildException {
        if (propertyFiles == null) {
            throw new BuildException("commands must be specified");
        }

        for (Iterator files=propertyFiles.iterator(); files.hasNext(); ) {
            String propsFileName = (String)files.next();

            Properties props = new Properties();
            try {
                props.load(new FileInputStream(propsFileName));
            } catch (FileNotFoundException e) {
                throw new BuildException("Property file '"+propsFileName+"' does not exist.");
            } catch (IOException e) {
                throw new BuildException("Problem reading property file '"+propsFileName+"'.");
            }

            boolean upToDate = true;

            if (props.getProperty("command", null) == null) {
                throw new BuildException("Property file '"+propsFileName+"' does not contain 'command' property.");
            }
            if (props.getProperty("depends", null) == null) upToDate = false;
            if (props.getProperty("targets", null) == null) upToDate = false;

            if (upToDate) {
                // all depends
                StringTokenizer dependsTokenizer = new StringTokenizer(props.getProperty("depends", ""), ", ");
                while (upToDate && dependsTokenizer.hasMoreTokens()) {
                    File dependsFile = new File(dependsTokenizer.nextToken());

                    // all targets
                    StringTokenizer targetsTokenizer = new StringTokenizer(props.getProperty("targets", ""), ", ");
                    while (upToDate && targetsTokenizer.hasMoreTokens()) {
                        File targetFile = new File(targetsTokenizer.nextToken());
                        // check for existence
                        if (!targetFile.exists()) {
                            log(targetFile+" does not exist.", Project.MSG_VERBOSE);
                            upToDate = false;
                            break;
                        }

                        // check for uptodateness
                        if (dependsFile.lastModified() > targetFile.lastModified()) {
                            log(dependsFile+" is newer than "+targetFile+".", Project.MSG_VERBOSE);
                            upToDate = false;
                            break;
                        }
                    }
                }
            }

            if (!upToDate) {
                StringTokenizer commandsTokenizer = new StringTokenizer(props.getProperty("command", ""), ";");
                while (commandsTokenizer.hasMoreTokens()) {
                    String command = commandsTokenizer.nextToken();
                    System.out.println(command);
                    cmdl = new Commandline(command);
                    super.execute();
                }
            }
        }
    }
}
