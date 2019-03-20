// Copyright 2000, CERN, Geneva, Switzerland and SLAC, Stanford, U.S.A.
package org.freehep.graphics3d;

import java.util.*;

/**
 * An implementor of this interface provides a set of drawable objects,
 * to be drawn by a graphics engine
 *
 * @author Mark Donszelmann
 * @version $Id: DrawableProvider.java,v 1.2 2002/06/12 23:15:15 duns Exp $
 */

public interface DrawableProvider {

    /**
     * @param matrix current matrix transformation
     *
     * @return enumeration of drawable objects
     */
    public Enumeration getDrawables(Matrix4 matrix);
}
