// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.swf;

import java.io.IOException;

/**
 * FrameLabel TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: FrameLabel.java,v 1.2 2003/04/15 18:03:05 duns Exp $
 */
public class FrameLabel
    extends ControlTag {

    private String label;
    private boolean anchor;

    public FrameLabel(String label) {
        this(label, false);
    }

    public FrameLabel(String label, boolean anchor) {
        this();
        this.label = label;
        this.anchor = anchor;
    }

    public FrameLabel() {
        super(43, 3);
    }

    public SWFTag read(int tagID, SWFInputStream swf, int len)
        throws IOException {

        FrameLabel tag = new FrameLabel();
        tag.label = swf.readString();
        anchor = (swf.getVersion() > 6) ? (swf.readUnsignedByte() != 0) : false;
        return tag;
    }

    public void write(int tagID, SWFOutputStream swf) throws IOException {
        swf.writeString(label);
        swf.writeUnsignedByte((swf.getVersion() > 6) ? anchor ? 1 : 0 : 0);
    }

    public String toString() {
        return super.toString()+"\n"+
               "  frame label: "+label +"\n"+
               "  anchor: "+anchor;
    }
}
