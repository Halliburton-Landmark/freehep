// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import java.util.*;

import org.apache.tools.ant.*;
import org.apache.tools.ant.taskdefs.*;


/**
 * Extends the standard "jar" task with a few options.
 * <PRE>
 * packages="dotnamed packages which may end in a *"
 *      * means include all subpackages
 * excludepackages="dotnames of packages to exclude, including all their subpackages"
 * extensions="extensions to include in the jar file", default is "class"
 * </PRE>
 * @author Mark Donszelmann
 * @version $Id: FreeHepJar.java,v 1.5 2004/01/14 00:24:56 duns Exp $
 */

public class FreeHepJar extends Jar {

    private String includes = null;
    private String excludes = null;
    private String extensions = "*.class";
    private String packages = "";
    private String excludePackages = "";

    public void setIncludes(String str) {
        includes = str;
    }

    public void setExcludes(String str) {
        excludes = str;
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

        String inc = includes + ", " + Util.expand(packages.replace('.','/'), extensions);
        log("includes: "+inc, Project.MSG_VERBOSE);
        super.setIncludes(inc);

        String ex = excludes + ", " + Util.expand(excludePackages.replace('.','/'), extensions);
        log("excludes: "+ex, Project.MSG_VERBOSE);
        super.setExcludes(ex);

        super.execute();
    }
}
