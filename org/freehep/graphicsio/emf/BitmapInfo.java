// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.io.IOException;

/**
 * EMF BitmapInfo
 *
 * @author Mark Donszelmann
 * @version $Id: BitmapInfo.java,v 1.1 2002/02/27 22:05:03 duns Exp $
 */
public class BitmapInfo {

    private BitmapInfoHeader header;

    public BitmapInfo(BitmapInfoHeader header) {
        this.header = header;
    }

    public BitmapInfo(EMFInputStream emf) throws IOException {
        header = new BitmapInfoHeader(emf);
        // colormap not necessary for true color image
    }

    public void write(EMFOutputStream emf) throws IOException {
        header.write(emf);
        // colormap not necessary for true color image
    }
    
    public String toString() {
        return "  BitmapInfo\n"+
               header.toString();
    }
}

