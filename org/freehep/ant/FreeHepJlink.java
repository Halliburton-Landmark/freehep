// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import java.io.*;
import java.util.*;

import org.apache.tools.ant.*;
import org.apache.tools.ant.taskdefs.*;
import org.apache.tools.ant.types.*;
import org.apache.tools.ant.taskdefs.optional.jlink.*;


/**
 * Extends the standard "jlink" task with a few options.
 * <PRE>
 *      srcdir: directory to look for added and merged files
 *      addfiles: list of files to add
 *      inputfiles: list of files to merge
 * </PRE>
 * @author Mark Donszelmann
 * @version $Id: FreeHepJlink.java,v 1.6 2004/08/17 17:26:42 duns Exp $
 */

public class FreeHepJlink extends JlinkTask {

    private String srcdir = ".";
    private String prefix = "";
//    private String addfiles = null;
    private String mergefiles = null;

    public void setSrcDir(String str) {
         srcdir = str;
    }

//    public void setAddFiles(String str) {
//         addfiles = str;
//    }

    public void setInputFiles(String str) {
         mergefiles = str;
    }

    public void execute() throws BuildException {
        if (mergefiles == null) {
            throw new BuildException("'mergefiles' property must be set!");
        }

        // handle mergefiles
        if (mergefiles != null) {
            Path path = super.createMergefiles();
            StringTokenizer st = new StringTokenizer(mergefiles, ", ");
            while (st.hasMoreTokens()) {
                String merge = (String)st.nextToken();
                File file = new File(srcdir+File.separatorChar+merge);
                path.setLocation(file);
                log("Merging '"+file+"' to jlink", Project .MSG_VERBOSE);
            }
            super.setMergefiles(path);
        }

        super.execute();
    }
}
