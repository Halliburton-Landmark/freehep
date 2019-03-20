// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * CharacterExpansionFactor TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: CharacterExpansionFactor.java,v 1.1 2001/11/29 01:45:25 duns Exp $
 */
public class CharacterExpansionFactor
    extends CGMTag {
        
    private double factor;

    public CharacterExpansionFactor() {
        super(5, 12, 1);
    }
    
    public CharacterExpansionFactor(double factor) {
        this();
        this.factor = factor;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeReal(factor);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("CHAREXPAN ");
        cgm.writeReal(factor);
    }
}
