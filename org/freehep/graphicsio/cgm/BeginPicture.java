// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * BeginPicture TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: BeginPicture.java,v 1.1 2001/11/29 01:45:25 duns Exp $
 */
public class BeginPicture
    extends CGMTag {

    private String name;

    public BeginPicture() {
        super(0, 3, 1);
    }
    
    public BeginPicture(String name) {
        this();
        this.name = name;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeString(name);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("BEGPIC ");
        cgm.writeString(name);
        cgm.indent();
    }
}
