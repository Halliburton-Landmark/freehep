// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import org.apache.tools.ant.*;
import org.apache.tools.ant.taskdefs.*;
import org.apache.tools.ant.types.*;
import java.io.*;
import java.util.StringTokenizer;
import java.util.Vector;
import java.util.Date;

/**
 * Task to compile javah.
 *
 * <ul>
 * <li>base: specifies directory where to output files to
 * <li>classname: name of the class to run through javah, ending in .class
 * </ul>
 *
 * The output of running javah on class your.package.Example.class is put in
 * the file: your/package/Example.h
 *
 * @author Mark Donszelmann
 * @version $Id: FreeHepJavah.java,v 1.8 2004/01/14 00:24:56 duns Exp $
 */

public class FreeHepJavah extends MatchingTask {

    private String base;
    private String classname;
    private Path classpath = null;

    private String files[] = new String[1];

    public void setBase(String base) {
        this.base = base;
    }

    public void setClassname(String classname) {
        this.classname = classname;
    }

    public void setClasspath(Path classpath) {
        this.classpath = classpath;
    }

    public void execute() throws BuildException {
        File baseDir = getProject().resolveFile(base);
        if (baseDir == null) {
            throw new BuildException("base attribute must be set!", getLocation());
        }
        if (!baseDir.exists()) {
            throw new BuildException("base does not exist!", getLocation());
        }

        // scan base dirs to build up compile lists only if a
        // specific classname is not given
        if (classname == null) {
            DirectoryScanner ds = this.getDirectoryScanner(baseDir);
            files = ds.getIncludedFiles();
        } else {
            files[0] = classname;
        }

        char separator = System.getProperty("file.separator").charAt(0);

        int k = 0;
        if (files.length > 0) {
            for (int j = 0; j < files.length; j++) {
                ExecTask javah = new ExecTask();
                javah.setProject(getProject());
                javah.setExecutable("javah");

                if (classpath != null) {
                    javah.createArg().setValue("-classpath");
                    javah.createArg().setValue(classpath.toString());
                }
                javah.createArg().setValue("-force");
                javah.createArg().setValue("-jni");
                javah.createArg().setValue("-o");

                File file = new File(files[j]);
                String destName = baseDir.getAbsolutePath() + separator +
                                files[j].substring(0, files[j].indexOf(".class")) + ".h";
                javah.createArg().setValue(destName);
                File destFile = new File(destName);
                if (file.lastModified() > destFile.lastModified()) {
                    k++;
                    javah.createArg().setValue(files[j].substring(0, files[j].indexOf(".class")).replace(separator, '.'));
                    javah.execute();
                }
            }
        }

        if (k > 0) {
            log("javah Compiled "+k+" classes...", Project.MSG_INFO);
        }

    }

}

