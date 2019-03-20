// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import java.util.*;

import org.apache.tools.ant.*;
import org.apache.tools.ant.taskdefs.*;


/**
 * Extends the standard "javac" task with a few options.
 * <PRE>
 * packages="dotnamed packages which may end in a *"
 *      * means include all subpackages
 * excludepackages="dotnames of packages to exclude, including all their subpackages"
 * </PRE>
 * @author Mark Donszelmann
 * @version $Id: FreeHepJavac.java,v 1.5 2004/01/14 00:24:56 duns Exp $
 */

public class FreeHepJavac extends Javac {

    private String extensions = "*.java";
    private String packages = "";
    private String excludePackages = "";

    public void setPackages(String str) {
        packages = str;
    }

    public void setExcludePackages(String str) {
        excludePackages = str;
    }

    public void execute() throws BuildException {

        String includes = Util.expand(packages.replace('.','/'), extensions);
        log("includes: "+includes, Project.MSG_VERBOSE);
        setIncludes(includes);

        String excludes = Util.expand(excludePackages.replace('.','/'), extensions);
        log("excludes: "+excludes, Project.MSG_VERBOSE);
        setExcludes(excludes);

        super.execute();
    }

}
