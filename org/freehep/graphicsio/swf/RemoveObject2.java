// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.swf;

import java.io.IOException;

/**
 * RemoveObject2 TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: RemoveObject2.java,v 1.1 2001/11/29 01:45:32 duns Exp $
 */
public class RemoveObject2
    extends ControlTag {

    private int depth;

    public RemoveObject2(int depth) {
        this();
        this.depth = depth;
    }
    
    public RemoveObject2() {
        super(28, 3);
    }

    public SWFTag read(int tagID, SWFInputStream swf, int len) 
        throws IOException {
        RemoveObject2 tag = new RemoveObject2();
        tag.depth = swf.readUnsignedShort();
        return tag;
    }
    
    public void write(int tagID, SWFOutputStream swf) throws IOException {
        swf.writeUnsignedShort(depth);        
    }
    
    public String toString() {
        return super.toString()+"\n"+
               "  depth: "+depth;
    } 
}
