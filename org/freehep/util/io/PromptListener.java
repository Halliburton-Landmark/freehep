// Copyright 2002, FreeHEP.
package org.freehep.util.io;

import java.io.*;

/**
 * Listener to inform that Prompt of the PromptInputStream has been found.
 *
 * @author Mark Donszelmann
 * @version $Id: PromptListener.java,v 1.2 2002/12/06 16:55:13 duns Exp $
 */
public interface PromptListener {

    /**
     * Prompt was found, and can now be read.
     */
    public void promptFound(RoutedInputStream.Route route) throws IOException;
}
