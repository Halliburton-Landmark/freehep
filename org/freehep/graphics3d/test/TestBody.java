package org.freehep.graphics3d.test;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Polygon;
import java.util.Enumeration;
import java.util.Vector;

import org.freehep.graphics3d.Matrix4;
import org.freehep.graphics3d.Vector3;
import org.freehep.graphics3d.Polyline3;
import org.freehep.graphics3d.Scale;
import org.freehep.graphics3d.DrawableProvider;

/**
 * A boat (or was it a plane), which serves as a testbody for the ArcBall demo.
 * <p>
 * Original ArcBall C code from Ken Shoemake, Graphics Gems IV, 1993.
 *
 * @author Mark Donszelmann
 * @version $Id: TestBody.java,v 1.3 2002/06/12 23:15:15 duns Exp $
 */

public class TestBody implements DrawableProvider {

    private static final int noOfFaces = 7;

    private static final double bodyRadius = 3.0;
    private static final double points[][] = {
        { 3.0,     0.0,	    0.0,	1},
        {-1.0,     1.0,	    0.0,	1},
        {-1.0,    -1.0,	    0.0,	1},
        {-0.75,    0.0,    -0.25,	1},
        { 1.0,     0.0,	    0.0,	1},
        {-0.75,    0.0,	    0.75,	1},
        {-0.5,    -0.125,	0.0,	1},
        {-0.5,     0.125,	0.0,	1}
    };

    private static final int faceVertices[][] = {
        {3,	 0, 1, 2},
        {3,	 4, 5, 6},
        {3,	 4, 7, 5},
        {3,	 5, 7, 6},
        {3,	 0, 2, 3},
        {3,	 0, 3, 1},
        {3,	 1, 3, 2},
    };

    private static final double faceNormals[][] = {
        {0., 0., 1., 0},
        {0.08152896377979659767, -0.978347565357559172,  0.1902342488195253946,  0},
        {0.08152896377979659767, 0.978347565357559172,   0.1902342488195253946,  0},
        {-0.9486832980505137996, 0.,                     -0.3162277660168379332, 0},
        {0.06428243465332250222, -0.2571297386132900089, -0.9642365197998375334, 0},
        {0.06428243465332250222, 0.2571297386132900089,  -0.9642365197998375334, 0},
        {-0.7071067811865475244, 0.,                     -0.7071067811865475244, 0},
    };

    private static final int faceColors[][] = {
        {102, 204, 255},
        {  0, 153, 204},
        {  0, 153, 204},
        {204,  51, 157},
        { 51, 102, 157},
        { 51, 102, 157},
        {102, 102, 172},
    };

    private Vector out = new Vector(1 + noOfFaces);

    /**
     * Transforms body normals
     * @return enumeration of front drawables
     */
    public Enumeration getDrawables(Matrix4 m) {
        out.setSize(0);
        out.addElement(new Scale(1/bodyRadius, 1/bodyRadius, 1/bodyRadius));
        for (int j=0; j<noOfFaces; j++) {
            // XZ, YZ, ZZ
        	double dot = m.m20*faceNormals[j][0]
        		        +m.m21*faceNormals[j][1]
        		        +m.m22*faceNormals[j][2];

        	if (dot>0.0) {	  /* Front-facing polygon, so draw it */
        	    dot += 0.4;
        	    if (dot>1.0) {
        	        dot = 1.0;
        	    }
        	    int r = (int)(dot*faceColors[j][0]);
        	    int g = (int)(dot*faceColors[j][1]);
        	    int b = (int)(dot*faceColors[j][2]);
        	    Color c = new Color(r, g, b);
                out.addElement(c);
        	    int n = faceVertices[j][0];
        	    Polyline3 poly = new Polyline3(n);
        	    poly.setClosed(true);
        	    poly.setFilled(true);
        	    poly.setFillColor(c);
        	    poly.setShowLine(true);
        	    poly.setShowMarkers(true);
        	    for (int k=1; k<=n; k++) {
            		int i = faceVertices[j][k];
                    poly.add(points[i]);
        	    }
                out.addElement(poly);
        	}
        }
        return out.elements();
    }
}
