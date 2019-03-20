// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * CharacterSpacing TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: CharacterSpacing.java,v 1.1 2001/11/29 01:45:25 duns Exp $
 */
public class CharacterSpacing
    extends CGMTag {
        
    private double spacing;

    public CharacterSpacing() {
        super(5, 13, 1);
    }
    
    public CharacterSpacing(double spacing) {
        this();
        this.spacing = spacing;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeReal(spacing);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("CHARSPACE ");
        cgm.writeReal(spacing);
    }
}
