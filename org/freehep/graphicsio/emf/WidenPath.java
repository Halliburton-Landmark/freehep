// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * WidenPath TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: WidenPath.java,v 1.1 2002/02/27 22:05:05 duns Exp $
 */
public class WidenPath
    extends EMFTag {

    public WidenPath() {
        super(66, 1);
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {

        return this;    
    }    
}
