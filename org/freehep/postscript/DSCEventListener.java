// Copyright 2004, FreeHEP.
package org.freehep.postscript;

import java.util.*;

/**
 * Class for signalling DSC comments
 *
 * @author Mark Donszelmann
 * @version $Id: DSCEventListener.java,v 1.1 2004/01/12 20:19:13 duns Exp $
 */
public interface DSCEventListener {

    public void dscCommentFound(DSCEvent event);
}
