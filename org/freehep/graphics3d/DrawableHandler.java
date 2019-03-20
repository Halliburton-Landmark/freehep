// Copyright 2000, CERN, Geneva, Switzerland and SLAC, Stanford, U.S.A.
package org.freehep.graphics3d;

/**
 * An implementor of this interface, such as a graphics engine, will
 * keep a list of DrawableProviders, each of which it will ask for
 * all its drawables, when the screen needs to be redrawn.
 *
 * @author Mark Donszelmann
 * @version $Id: DrawableHandler.java,v 1.1 2000/11/17 15:43:55 duns Exp $
 */

public interface DrawableHandler {
    
    /**
     * add this provider to the list
     */
    public void add(DrawableProvider provider);
    
    /**
     * remove this provider from the list
     */
    public void remove(DrawableProvider provider);

}
