// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * EndPath TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: EndPath.java,v 1.1 2002/02/27 22:05:03 duns Exp $
 */
public class EndPath
    extends EMFTag {

    public EndPath() {
        super(60, 1);
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        return this;
    }
    
}
