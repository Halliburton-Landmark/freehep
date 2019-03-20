// Copyright 2001, FreeHEP.
package org.freehep.postscript;

import java.awt.PaintContext;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.TexturePaint;
import java.awt.geom.AffineTransform;
import java.awt.geom.NoninvertibleTransformException;
import java.awt.geom.Rectangle2D;
import java.awt.image.BufferedImage;
import java.awt.image.ColorModel;

/**
 * Texture Paint for PostScript Processor
 *
 * @author Mark Donszelmann
 * @version $Id: FixedTexturePaint.java,v 1.1 2001/06/28 14:24:55 duns Exp $
 */
public class FixedTexturePaint extends TexturePaint {

    private OperandStack os;
    private AffineTransform matrix;

    public FixedTexturePaint(OperandStack os, AffineTransform m, BufferedImage texture, Rectangle2D anchor) {
        super(texture, anchor);
        this.os = os;
        matrix = m;
    }

    public PaintContext createContext(ColorModel cm,
				                      Rectangle deviceBounds,
				                      Rectangle2D userBounds,
				                      AffineTransform xform,
                                      RenderingHints hints) {
        AffineTransform mirror;
        try {
            // calculate Mirror: x = M*ctm --> M = x*ctm-1
            mirror = os.gstate().getTransform();
            mirror = mirror.createInverse();
            mirror.preConcatenate(xform);
        } catch (NoninvertibleTransformException e) {
            System.err.println("Pattern problem: could not invert matrix");
            mirror = xform;
        }
        AffineTransform at = new AffineTransform();
        at.preConcatenate(matrix);
        at.preConcatenate(mirror);
        return super.createContext(cm, deviceBounds, userBounds, at, hints);
    }
}
