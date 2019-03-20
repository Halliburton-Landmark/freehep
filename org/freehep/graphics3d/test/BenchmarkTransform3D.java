// Copyright 2000, CERN, Geneva, Switzerland and SLAC, Stanford, U.S.A.
package org.freehep.graphics3d.test;

import java.util.Random;

import org.freehep.graphics3d.Polyline3;
import org.freehep.graphics3d.Transform3D;

/**
 * @author Mark Donszelmann
 * @version $Id: BenchmarkTransform3D.java,v 1.2 2000/11/24 16:14:23 duns Exp $
 */

public class BenchmarkTransform3D {
    
    public static void main(String[] args) {

        int k = 100;
        int n = 100000;
        
        Transform3D t = new Transform3D();
        
        // rotate over x by 45 degrees
        t.rotate(1, 0, 0, Math.PI/4);
        
        // rotate over y by 45 degrees
        t.rotate(0, 1, 0, Math.PI/4);
        
        // rotate over z by 45 degrees
        t.rotate(0, 0, 1, Math.PI/4);
        
        // translate in x,y,z by 100,50,200
        t.translate(100, 50, 200);
        
        System.out.println("Generating "+n+" points.");
        double x[] = new double[n];
        double y[] = new double[n];
        double z[] = new double[n];
        Polyline3 poly = new Polyline3(n);
        Random rx = new Random(48638);
        Random ry = new Random(38268);
        Random rz = new Random(945746);
        
        for (int i=0; i<n; i++) {
            x[i] = rx.nextDouble();
            y[i] = ry.nextDouble();
            z[i] = rz.nextDouble();
            poly.add(x[i], y[i], z[i]);
        }
        
        double u[] = new double[n];
        double v[] = new double[n];
        double w[] = new double[n];
        
        System.out.println("Point by Point Transforming "+n+" points, "+k+" times.");
        long t0 = System.currentTimeMillis();
         
        for (int j=0; j<k; j++) {
            for (int i=0; i<n; i++) {
                u[i] = t.getU(x[i], y[i], z[i]);
                v[i] = t.getV(x[i], y[i], z[i]);
                w[i] = t.getW(x[i], y[i], z[i]);
            }
        }
               
        long t1 = System.currentTimeMillis();
        System.out.println("Point by Point Transform took: "+(t1-t0)+" ms.");
        System.out.println("Point by Point Transform took on average: "+((t1-t0)/(double)(n*k))+" ms.");



        double[][] pointResult = new double[n][3];
        System.out.println("Point Transforming "+n+" points, "+k+" times.");
        long t2 = System.currentTimeMillis();
         
        for (int j=0; j<k; j++) {
            for (int i=0; i<n; i++) {
                pointResult[i] = t.get(x[i], y[i], z[i], pointResult[i]);
            }
        }
               
        long t3 = System.currentTimeMillis();
        System.out.println("Point Transform took: "+(t3-t2)+" ms.");
        System.out.println("Point Transform took on average: "+((t3-t2)/(double)(n*k))+" ms.");

        double[][] arrayResult = new double[3][n];
        System.out.println("Array Transforming "+n+" points, "+k+" times.");
        long t4 = System.currentTimeMillis();
         
        for (int j=0; j<k; j++) {
            arrayResult = t.get(x, y, z, arrayResult);
        }
               
        long t5 = System.currentTimeMillis();
        System.out.println("Array Transform took: "+(t5-t4)+" ms.");
        System.out.println("Array Transform took on average: "+((t5-t4)/(double)(n*k))+" ms.");

        int[][] intResult = new int[2][poly.size()];
        System.out.println("Poly Transforming "+n+" points, "+k+" times.");
        long t6 = System.currentTimeMillis();
         
        for (int j=0; j<k; j++) {
            intResult = t.get(poly, 20, 20, 800, 600, intResult);
        }
               
        long t7 = System.currentTimeMillis();
        System.out.println("Poly Transform took: "+(t7-t6)+" ms.");
        System.out.println("Poly Transform took on average: "+((t7-t6)/(double)(n*k))+" ms.");

    }
}
