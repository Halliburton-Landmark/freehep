// Copyright 2001, FreeHEP.
package org.freehep.util.io;

import java.io.IOException;

/**
 * Exception for the TaggedInputStream. Signals that the inputstream contains
 * more bytes than the stream has read for this tag.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: IncompleteTagException.java,v 1.1 2001/11/20 17:11:54 duns Exp $
 */
public class IncompleteTagException extends IOException {

    private Tag tag;
    private byte[] rest;

    public IncompleteTagException(Tag tag, byte[] rest) {
        super("Tag "+tag+" contains "+rest.length+" unread bytes");
        this.tag = tag;
        this.rest = rest;
    }

    public Tag getTag() {
        return tag;
    }

    public byte[] getBytes() {
        return rest;
    }
}
