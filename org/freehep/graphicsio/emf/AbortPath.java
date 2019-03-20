// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * AbortPath TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: AbortPath.java,v 1.1 2002/02/27 22:05:03 duns Exp $
 */
public class AbortPath
    extends EMFTag {

    AbortPath() {
        super(68, 1);
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        return this;
    }    
}
