// Copyright 2002, SLAC, Stanford University, U.S.A.
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
 *
 * @author Mark Donszelmann
 * @version $Id: TestTaggedString.java,v 1.4 2003/12/06 00:12:33 duns Exp $
 */
public class TestTaggedString
    extends TestingPanel {

    public TestTaggedString(String[] args) throws Exception {
        super(args);
        setName("Tagged String");
    }

    public void paintComponent(Graphics g) {
        if (g!=null) {

            VectorGraphics vg =
                VectorGraphics.create(g);

            Dimension dim = getSize();
            Insets insets = getInsets();

            vg.setColor(Color.white);
            vg.fillRect(insets.left, insets.top,
                        dim.width-insets.left-insets.right,
                        dim.height-insets.top-insets.bottom);

            int x = insets.left;
            int dy = dim.height/4;

            TagString text =
                new TagString("Ant<sup><b>Bull</b></sup>"+
                              "Cat<i><sub>Dog</sub></i>"+
                              "<u>Eel</u><sup><udash>Frog</udash></sup>"+
                              "<udot>Gecko</udot><sub>"+
                              "<strike>Hog</strike></sub>");
            vg.setColor(Color.black);
            vg.setFont(new Font("SansSerif", Font.PLAIN, 30));
            vg.drawString(text,x,1*dy+insets.top);
            vg.setFont(new Font("Serif", Font.PLAIN, 30));
            vg.drawString(text,x,2*dy+insets.top);
            vg.setFont(new Font("Monospaced", Font.PLAIN, 30));
            vg.drawString(text,x,3*dy+insets.top);

        }
    }

    public static void main(String[] args) throws Exception {
        new TestTaggedString(args).runTest();
    }
}
