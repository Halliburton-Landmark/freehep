// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

/**
 * BeginSegment TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: BeginSegment.java,v 1.1 2001/11/29 01:45:25 duns Exp $
 */
public class BeginSegment
    extends CGMTag {

    private int name;

    public BeginSegment() {
        super(0, 6, 2);
    }
    
    public BeginSegment(int name) {
        this();
        this.name = name;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeName(name);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("BEGSEG ");
        cgm.writeName(name);
        cgm.indent();
    }
}