// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * RealizePalette TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: RealizePalette.java,v 1.1 2002/02/27 22:05:04 duns Exp $
 */
public class RealizePalette
    extends EMFTag {

    public RealizePalette() {
        super(52, 1);
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        return this;
    }
    
}
