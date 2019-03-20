// Copyright 2003, FreeHEP.
package org.freehep.graphicsio;

/**
 *
 * @author Mark Donszelmann
 * @version $Id: FontConstants.java,v 1.1 2003/04/25 23:12:45 duns Exp $
 */
public class FontConstants {

    private FontConstants() {}

    // Font Embedding
    public static final String EMBED_FONTS          = "EmbedFonts";
    public static final String EMBED_FONTS_AS       = "EmbedFontsAs";

    public static final String EMBED_FONTS_TYPE1    = "Type1";
    public static final String EMBED_FONTS_TYPE3    = "Type3";

    public static final String[] getEmbedFontsAsList() {
        return new String[] { EMBED_FONTS_TYPE1, EMBED_FONTS_TYPE3 };
    }
}
