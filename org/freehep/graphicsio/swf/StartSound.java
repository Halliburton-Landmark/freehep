// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.swf;

import java.io.IOException;

/**
 * StartSound TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: StartSound.java,v 1.1 2001/11/29 01:45:33 duns Exp $
 */
public class StartSound
    extends ControlTag {

    private int character;
    private SoundInfo info;

    public StartSound(int id, SoundInfo info) {
        this();
        character = id;
        this.info = info;
    }
    
    public StartSound() {
        super(15, 1);
    }
    
    public SWFTag read(int tagID, SWFInputStream swf, int len) 
        throws IOException {

        StartSound tag = new StartSound();
        tag.character = swf.readUnsignedShort();
        tag.info = new SoundInfo(swf);            
        return tag;
    }

    public void write(int tagID, SWFOutputStream swf) throws IOException {
        swf.writeUnsignedShort(character);
        info.write(swf);   
    }
    
    public String toString() {
        return super.toString()+"\n"+
               "  character: "+character+"\n"+
               "  soundinfo: "+info;
    }
}
