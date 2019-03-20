// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.swf;

/**
 * Abstract Definition TAG.
 * All definition tags inherit from this class.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: DefinitionTag.java,v 1.1 2001/11/29 01:45:31 duns Exp $
 */
public abstract class DefinitionTag
    extends SWFTag {

    protected DefinitionTag(int tagID, int version) {
        super(tagID, version);
    }

    public int getTagType() {
        return DEFINITION;
    }

    public String toString() {
        return "Definition: "+getName()+" ("+getTag()+")";
    }

}
