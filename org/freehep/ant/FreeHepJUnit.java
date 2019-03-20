// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import org.apache.tools.ant.*;
import org.apache.tools.ant.taskdefs.*;
import org.apache.tools.ant.taskdefs.optional.junit.*;
import org.apache.tools.ant.types.*;
import java.io.*;
import java.util.*;

/**
 * Executes a given list tests.
 *
 * Same parameters as JUnit, except for tests and todir.
 * <ul>
 * <li>tests: semicolon separated list of test classes, each passed to test subtag
 * <li>todir: todir attribute passed to test subtag
 * </ul>
 *
 * @author Mark Donszelmann
 * @version $Id: FreeHepJUnit.java,v 1.3 2004/01/14 00:24:56 duns Exp $
 */
public class FreeHepJUnit extends JUnitTask {

    String tests = null;
    File toDir = null;
    boolean fork = false;

    public FreeHepJUnit() throws Exception {
        super();
    }
    //Note, superclasses implementation of setFork does not work here, because
    //it calls setFork on all the contained test cases. In our case they do not exist
    //until execute is called.
    public void setFork(boolean value) {
       this.fork = value;
    }
    public void setTests(String tests) {
        this.tests = tests;
    }

    public void setToDir(String toDir) {
        this.toDir = new File(toDir);
    }

    public void execute() throws BuildException {
        if (tests != null) {
            StringTokenizer st = new StringTokenizer(tests, ", ");
            while (st.hasMoreTokens()) {
                JUnitTest test = new JUnitTest(st.nextToken());
                if (toDir != null) {
                    test.setTodir(toDir);
                }
                test.setFork(fork);
                addTest(test);
            }
        }

        super.execute();
    }
}
