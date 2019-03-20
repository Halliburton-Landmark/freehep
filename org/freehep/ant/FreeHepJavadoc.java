// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import java.io.*;
import java.util.*;
import org.apache.tools.ant.taskdefs.*;

/**
 * Allows for multiple link targets
 *
 * @author Mark Donszelmann
 * @version $Id: FreeHepJavadoc.java,v 1.2 2004/01/14 00:24:56 duns Exp $
 */

public class FreeHepJavadoc extends Javadoc {

    public void setLink(String src) {
        StringTokenizer st = new StringTokenizer(src, ", \t\n\r\f");
        while (st.hasMoreTokens()) {
            createLink().setHref((String)st.nextToken());
        }
    }
}
