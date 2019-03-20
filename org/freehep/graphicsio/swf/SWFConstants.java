// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.swf;

import java.io.IOException;

import org.freehep.util.io.Tag;
import org.freehep.util.io.TaggedInputStream;
import org.freehep.util.io.TaggedOutputStream;

/**
 * SWF Constants.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: SWFConstants.java,v 1.4 2003/04/15 18:03:06 duns Exp $
 */
public interface SWFConstants {

    /**
     * This defines the control tag type. */
    public static final int CONTROL                         = 1;

    /**
     * This defines the definition tag type. */
    public static final int DEFINITION                      = 2;

    public static final int DEFAULT_VERSION                 = 6;

    public static final int TWIPS                           = 20;

    public static final int LANGUAGE_LATIN                  = 1;
    public static final int LANGUAGE_JAPANESE               = 2;
    public static final int LANGUAGE_KOREAN                 = 3;
    public static final int LANGUAGE_SIMPLIFIED_CHINESE     = 4;
    public static final int LANGUAGE_TRADITIONAL_CHINESE    = 5;

}
