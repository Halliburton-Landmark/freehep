// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.cgm;

import java.awt.Color;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * ScalingMode TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: ScalingMode.java,v 1.1 2001/11/29 01:45:27 duns Exp $
 */
public class ScalingMode
    extends CGMTag {
    
    public static final int ABSTRACT = 0;
    public static final int METRIC = 1;
    private int type;
    private double factor;

    public ScalingMode() {
        super(2, 1, 1);
    }
    
    public ScalingMode(int type) {
        this(ABSTRACT, 0.0);
    }

    public ScalingMode(int type, double factor) {
        this();
        this.type = type;
        this.factor = factor;
    }
    
    public void write(int tagID, CGMOutputStream cgm) throws IOException {
        cgm.writeEnumerate(type);
        if (type == METRIC) {
            cgm.writeFloatingPoint(factor);
        }
    }

    public void write(int tagID, CGMWriter cgm) throws IOException {
        cgm.print("SCALEMODE ");
        cgm.print((type == ABSTRACT) ? "ABSTRACT " : "METRIC ");
        if (type == METRIC) {
            cgm.writeFloatingPoint(factor);
        }
    }
}
