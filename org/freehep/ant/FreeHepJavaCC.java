// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import java.io.*;
import java.util.*;

import org.apache.tools.ant.*;
import org.apache.tools.ant.taskdefs.*;
import org.apache.tools.ant.types.*;

/**
 * Allows for multiple targets, but no output directory
 *
 * works with JavaCC 3.0 and up
 *
 * @author Mark Donszelmann
 * @version $Id: FreeHepJavaCC.java,v 1.4 2004/01/19 21:23:47 duns Exp $
 */

public class FreeHepJavaCC extends Task {

    File javaccHome = null;
    String includes = null;

    public void setIncludes(String str) {
        includes = str;
    }

    public void setJavaCCHome(File dir) {
        javaccHome = dir;
    }

    public void execute() throws BuildException {
        if (includes == null) {
            throw new BuildException("'includes' attribute must be set!");
        }

        StringTokenizer st = new StringTokenizer(includes, ", ");
        while (st.hasMoreTokens()) {
            File target = new File(st.nextToken());
            if (target == null || !target.isFile()) {
                throw new BuildException("Invalid target: " + target);
            }

            CommandlineJava cmd = new CommandlineJava();

            cmd.setVm("java");
            cmd.setClassname("javacc");                      // version 3.x
            File outputDirectory = new File(target.getParent());
            cmd.createArgument().setValue("-OUTPUT_DIRECTORY:"+outputDirectory.getAbsolutePath());

            File dst = getDstFile(outputDirectory, target);
            if (dst.exists() && target.lastModified() < dst.lastModified()) {
                log("Skipping "+target, Project.MSG_VERBOSE);
                continue;
            }
            log("Compiling "+target, Project.MSG_INFO);
            cmd.createArgument().setValue(target.getAbsolutePath());

            if (javaccHome == null || !javaccHome.isDirectory()) {
                throw new BuildException("Javacchome not set.");
            }
            final Path classpath = cmd.createClasspath(getProject());

            classpath.createPathElement().setPath(javaccHome.getAbsolutePath() + "/javacc.jar");

            final Commandline.Argument arg = cmd.createVmArgument();
            arg.setValue("-mx140M");
            arg.setValue("-Dinstall.root="+javaccHome.getAbsolutePath());

            Execute.runCommand(this, cmd.getCommandline());
        }
    }

    private File getDstFile(File outputdir, File srcfile)
    {
        String path = srcfile.getPath();

        // get filename
        int sep = path.lastIndexOf(File.separator);
        if ( sep >= 0 ) {
            path = path.substring(sep+1);
        }

        // replace extension with .java
        int dot = path.lastIndexOf('.');
        path = (dot < 0) ? path + ".java" : path.substring(0, dot) + ".java";

        // add output dir
        if (outputdir != null) {
            path = outputdir + File.separator + path;
        }

        return new File(path);
    }
}
