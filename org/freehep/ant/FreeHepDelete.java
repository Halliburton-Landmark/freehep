// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import java.io.*;
import java.util.*;

import org.apache.tools.ant.*;
import org.apache.tools.ant.taskdefs.*;
import org.apache.tools.ant.types.*;


/**
 * Extends the standard "jar" task with a few options.
 * <PRE>
 * packages="dotnamed packages which may end in a *"
 *      * means include all subpackages
 * excludepackages="dotnames of packages to exclude, including all their subpackages"
 * extensions="extensions to delete", default is "class"
 * </PRE>
 * @author Mark Donszelmann
 * @version $Id: FreeHepDelete.java,v 1.5 2004/01/14 00:24:56 duns Exp $
 */

public class FreeHepDelete extends Delete {

    private File dir = null;
    private String extensions = "*.class";
    private String packages = "";
    private String excludePackages = "";

    public void setDir(File dir) {
        this.dir = dir;
    }

    public void setExtensions(String str) {
        extensions = str;
    }

    public void setPackages(String str) {
        packages = str;
    }

    public void setExcludePackages(String str) {
        excludePackages = str;
    }

    public void execute() throws BuildException {

        FileSet fs = new FileSet();
        if ((dir == null) && (file == null)) {
            throw new BuildException("'dir' or 'file' attribute must be specified!");
        }

        if (dir != null) {
            fs.setDir(dir);

            String includes = Util.expand(packages.replace('.','/'), extensions);
            log("includes: "+includes, Project.MSG_VERBOSE);
            fs.setIncludes(includes);

            String excludes = Util.expand(excludePackages.replace('.','/'), extensions);
            log("excludes: "+excludes, Project.MSG_VERBOSE);
            fs.setExcludes(excludes);

            addFileset(fs);
        }
        super.execute();
    }
}
