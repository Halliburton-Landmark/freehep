// University of California, Santa Cruz, USA and
// CERN, Geneva, Switzerland, Copyright (c) 2000
package org.freehep.graphicsio.test;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import javax.swing.border.*;

import java.io.FileOutputStream;
import java.io.OutputStream;

import org.freehep.graphics2d.*;
import org.freehep.graphicsio.*;
import org.freehep.graphicsio.exportchooser.*;

/**
 * @author Charles Loomis
 * @author Mark Donszelmann
 * @version $Id: TestSymbols2D.java,v 1.4 2004/07/30 22:32:15 duns Exp $
 */
public class TestSymbols2D
    extends TestingPanel implements VectorGraphicsConstants {

    public TestSymbols2D(String[] args) throws Exception {
        super(args);
	    setName("Symbols");
    }

    public void paintComponent(Graphics g) {

        if (g!=null) {
            VectorGraphics vg =
                VectorGraphics.create(g);

            Dimension dim = getSize();
            Insets insets = getInsets();

            vg.setColor(Color.RED);
            vg.fillRect(insets.left, insets.top,
                        dim.width-insets.left-insets.right,
                        dim.height-insets.top-insets.bottom);

            int cols = 5;
            int rows = 8;

            int dw = dim.width/cols;
            int dh = dim.height/rows;

            int size = Math.min(dw,dh)*2/3;

            vg.setColor(Color.BLACK);
            int symbol = 0;
            for (int y=0; y<rows; y++) {
                symbol = (y / 2)*cols;
                if ((y % 2) == 0) {
                    vg.setLineWidth(1);
                } else {
                    vg.setLineWidth(5.0);
                }
                int iy = dh/2+dh*y;
                if (y >= 2) symbol = SYMBOL_CIRCLE;
                for (int x=0; x<cols; x++) {
                    int ix = dw/2+dw*x;
                    if (y<4) {
                        vg.drawSymbol(ix,iy,size,symbol++);
                    } else if (y<6) {
                        vg.fillSymbol(ix,iy,size,symbol++);
                    } else {
                        vg.fillAndDrawSymbol(ix,iy,size,symbol++, Color.CYAN);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        new TestSymbols2D(args).runTest();
    }
}
