// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.io.IOException;

/**
 * SegmentPriorityExtent TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: SegmentPriorityExtent.java,v 1.1 2001/11/29 01:45:27 duns Exp $
 */
public class SegmentPriorityExtent
    extends CGMTag {
        
    private int min, max;

    public SegmentPriorityExtent() {
        super(1, 18, 2);
    }
    
    public SegmentPriorityExtent(int min, int max) {
        this();
        this.min = min;
        this.max = max;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeInteger(min);
        cgm.writeInteger(max);
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("SEGPRIEXT ");
        cgm.writeInteger(min);
        cgm.print(", ");
        cgm.writeInteger(max);
    }
}
