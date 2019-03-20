// Copyright 2003, FreeHEP
package org.freehep.graphicsio.exportchooser;

import java.util.Properties;

/**
 *
 * @author Mark Donszelmann
 * @version $Id: Options.java,v 1.3 2003/04/30 19:02:03 duns Exp $
 */
public interface Options {

    /**
     * Sets all the changed options in the properties object.
     *
     * @return true if any options were set
     */
    public boolean applyChangedOptions(Properties options);
}

