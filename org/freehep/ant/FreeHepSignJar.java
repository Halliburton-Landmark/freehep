// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import java.io.*;
import java.util.*;

import org.apache.tools.ant.*;
import org.apache.tools.ant.taskdefs.*;
import org.apache.tools.ant.types.*;
import org.apache.tools.ant.taskdefs.optional.jlink.*;


/**
 * Extends the standard "signjar" task with a few options.
 * <PRE>
 *      srcdir: directory to look for unsigned jar files
 *      jars: list of names of all jar files
 *      dstdir: directory to put the signed jar files
 * </PRE>
 * @author Mark Donszelmann
 * @version $Id: FreeHepSignJar.java,v 1.4 2004/01/14 00:24:56 duns Exp $
 */

public class FreeHepSignJar extends SignJar {

    private String srcdir = ".";
    private String jars = null;
    private String dstdir = ".";

    public void setSrcDir(String str) {
         srcdir = str;
    }

    public void setDstDir(String str) {
         dstdir = str;
    }

    public void setJars(String str) {
         jars = str;
    }

    public void execute() throws BuildException {
        if (jars == null) {
            throw new BuildException("'jars' property must be set!");
        }

        StringTokenizer st = new StringTokenizer(jars, ", ");
        while (st.hasMoreTokens()) {
            String jar = (String)st.nextToken();
            setJar(new File(srcdir+"/"+jar));
            setSignedjar(new File(dstdir+"/"+jar));
            super.execute();
        }
    }
}
