// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;

import java.awt.Rectangle;
import java.io.IOException;

import org.freehep.util.io.Tag;

/**
 * ExtTextOutA TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: ExtTextOutA.java,v 1.2 2002/04/07 22:48:03 tonyj Exp $
 */
public class ExtTextOutA
    extends EMFTag implements EMFConstants {

    private Rectangle bounds;
    private int mode;
    private float xScale, yScale;
    private Text text;

    ExtTextOutA() {
        super(83, 1);
    }

    public ExtTextOutA(Rectangle bounds, int mode, float xScale, float yScale, Text text) {
        this();
        this.bounds = bounds;
        this.mode = mode;
        this.xScale = xScale;
        this.yScale = yScale;
        this.text = text;
    }

    public EMFTag read(int tagID, EMFInputStream emf, int len) 
        throws IOException {
    
        ExtTextOutA tag = new ExtTextOutA(emf.readRECTL(), emf.readDWORD(),
                                          emf.readFLOAT(), emf.readFLOAT(),
                                          new Text(emf));
        return tag;
    }
    
    public void write(int tagID, EMFOutputStream emf) throws IOException {
        emf.writeRECTL(bounds);
        emf.writeDWORD(mode);
        emf.writeFLOAT(xScale);
        emf.writeFLOAT(yScale);
        text.write(emf);
    }
    
    public String toString() {
        return super.toString()+"\n"+
            "  bounds: "+bounds+"\n"+
            "  mode: "+mode+"\n"+
            "  xScale: "+xScale+"\n"+
            "  yScale: "+yScale+"\n"+
            text.toString();
    }   
}
