// Copyright 2000, CERN, Geneva, Switzerland and SLAC, Stanford, U.S.A.
package org.freehep.graphics3d.test;

import org.freehep.graphics3d.Transform3D;

/**
 * @author Mark Donszelmann
 * @version $Id: TestTransform3D.java,v 1.1 2000/11/17 15:43:58 duns Exp $
 */

public class TestTransform3D {
    
    public static void main(String[] args) {

        Transform3D t = new Transform3D();
        System.out.println(t);
        
        // rotate over x by 45 degrees
        t.rotate(1, 0, 0, Math.PI/4);
        
        // rotate over y by 45 degrees
        t.rotate(0, 1, 0, Math.PI/4);
        
        // rotate over z by 45 degrees
        t.rotate(0, 0, 1, Math.PI/4);
        
        // translate in x,y,z by 100,50,200
        t.translate(100, 50, 200);
        
        System.out.println(t);
        
        transform(t, 50,150,-50);
        transform(t, 0,0,0);
        transform(t, 100,100,-100);
        System.out.println();
        
        t.translate(-100,-50,-200);
        t.rotate(0, 0, 1, -Math.PI/4);
        t.rotate(0, 1, 0, -Math.PI/4);
        t.rotate(1, 0, 0, -Math.PI/4);
        System.out.println(t);        
    }
    
    private static void transform(Transform3D t, double x, double y, double z) {
        System.out.println("("+x+", "+y+", "+z+") -> ("+t.getU(x,y,z)+", "+t.getV(x,y,z)+", "+t.getW(x,y,z)+")");
    }        
}
