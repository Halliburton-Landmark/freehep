// Copyright 2001, FreeHEP.
package org.freehep.util.io;

import java.io.IOException;

/**
 * @author Mark Donszelmann
 * @version $Id: TaggedOutput.java,v 1.1 2002/01/09 16:30:11 duns Exp $
 */
public interface TaggedOutput {

    /**
     * Write a tag. */
    public void writeTag(Tag tag) throws IOException;
    
    public void close() throws IOException;
}
