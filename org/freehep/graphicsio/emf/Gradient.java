// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Color;
import java.io.IOException;

/**
 * EMF Gradient
 *
 * @author Mark Donszelmann
 * @version $Id: Gradient.java,v 1.1 2002/02/27 22:05:04 duns Exp $
 */
public abstract class Gradient {

    public Gradient() {
    }

    public abstract void write(EMFOutputStream emf) throws IOException;
}

