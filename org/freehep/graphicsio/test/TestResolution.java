// Copyright 2004, FreeHEP.
package org.freehep.graphicsio.test;

import java.awt.*;
import java.awt.geom.*;

import org.freehep.graphics2d.*;

/**
 *
 * @author Mark Donszelmann
 * @version $Id: TestResolution.java,v 1.3 2004/12/30 07:41:37 duns Exp $
 */
public class TestResolution
    extends TestingPanel {

    public TestResolution(String[] args) throws Exception {
        super(args);
        setName("Resolution");
    }

    public void paintComponent(Graphics g) {
        if (g==null) return;

        VectorGraphics vg = VectorGraphics.create(g);

        Dimension dim = getSize();
        Insets insets = getInsets();

        vg.setColor(Color.white);
        vg.fillRect(insets.left, insets.top,
                    dim.width-insets.left-insets.right,
                    dim.height-insets.top-insets.bottom);


    	double w = dim.width / 3;
    	double h = dim.height / 5;
    	double s = 0.0000001;
    	for (int i=0; i<15; i++) {
    	    VectorGraphics vgs = (VectorGraphics)vg.create();
            if (i<5) {
                vgs.translate(0, i*h);
            } else if (i<10) {
                vgs.translate(w, (i-5)*h);
            } else {
                vgs.translate(2*w, (i-10)*h);
            }
            vgs.translate(w/2,h/2);

            double sc = 0.5 * Math.min(w,h)/2;
    	    vgs.scale(sc,sc);    	    
            vgs.scale(1/s, 1/s);

            vgs.setStroke(new BasicStroke((float)(0.5*s),
     			      BasicStroke.CAP_ROUND,
    			      BasicStroke.JOIN_ROUND));
    			      
            
    	    vgs.setColor(Color.black);
  	        vgs.draw(new Ellipse2D.Double(-1*s,-1*s,2*s,2*s));
    	    vgs.dispose();

    	    s *= 10;
    	}
    }

    public static void main(String[] args) throws Exception {
        new TestResolution(args).runTest();
    }
}
