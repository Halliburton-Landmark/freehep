package org.freehep.graphics3d;

import java.awt.Color;

import org.freehep.graphics2d.VectorGraphicsConstants;

/**
 * Implements a 3D (closed)polyline, made up out of points.
 * The point vectors are publicly accessible.
 *
 * @author Mark Donszelmann
 * @version $Id: Polyline3.java,v 1.9 2003/05/27 22:35:35 duns Exp $
 */

public class Polyline3 {

    private boolean showLine = true;
    private boolean closed = false;
    private boolean filled = false;
    private Color fillColor = Color.white;
    public boolean showMarkers = false;
    public int marker = VectorGraphicsConstants.SYMBOL_BOX;
    public Color markerColor = Color.white;
    public int markerSize = 5;

    private int size;
    private int increment = 100;

    /**
     * points
     */
    public Vector3[] p;

    /**
     * creates a polyline with n unfilled points
     */
    public Polyline3(int n) {
        p = new Vector3[n];
        size = 0;
    }

    /**
     * creates a polyline from an array of points
     */
    public Polyline3(Vector3[] points) {
        this(points.length);
        System.arraycopy(points, 0, p, 0, points.length);
        size = points.length;
    }

    /**
     * creates a default (100 points) polyline
     */
    public Polyline3() {
        this(100);
    }

    /**
     * true if this is a polygon
     */
    public boolean isClosed() {
        return closed;
    }

    /**
     * closes the polyline (no points are added)
     */
    public void setClosed(boolean closed) {
        this.closed = closed;
    }

    /**
     * true if line or polygon is to be shown
     *
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public boolean showLine() {
        return showLine;
    }

    /**
     * true if line or polygon is to be shown
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public void setShowLine(boolean showLine) {
        this.showLine = showLine;
    }

    /**
     * true if this polygon is filled
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public boolean isFilled() {
        return filled;
    }

    /**
     * sets the polygon to be filled
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    /**
     * color for fill
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public Color getFillColor() {
        return fillColor;
    }

    /**
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public void setFillColor(Color fillColor) {
        this.fillColor = fillColor;
    }

    /**
     * true if markers are to be shown
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public boolean showMarkers() {
        return showMarkers;
    }

    /**
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public void setShowMarkers(boolean showMarkers) {
        this.showMarkers = showMarkers;
    }

    /**
     * number showing the symbol to be used (as defined in VectorGraphicsConstants)
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public int getMarker() {
        return marker;
    }

    /**
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public void setMarker(int marker) {
        this.marker = marker;
    }

    /**
     * color of the Mark
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public Color getMarkerColor() {
        return markerColor;
    }

    /**
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public void setMarkerColor(Color markerColor) {
        this.markerColor = markerColor;
    }

    /**
     * size of the marker
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public int getMarkerSize() {
        return markerSize;
    }

    /**
     * FIXME ToBeRemoved, when graphics3d is updated.
     */
    public void setMarkerSize(int markerSize) {
        this.markerSize = markerSize;
    }


    /**
     * Sets size to 0, all allocated points are still part of the polyline.
     * @return old size before clearing
     */
    public int clear() {
        int oldSize = size;
        size = 0;
        return oldSize;
    }

    /**
     * adds point x,y,z to polyline
     */
    public Polyline3 add(double x, double y, double z) {
        ensureCapacity(size+1);
        if (p[size] == null) {
            p[size] = new Vector3(x, y, z);
        } else {
            p[size].set(x, y, z);
        }
        size++;
        return this;
    }

    /**
     * adds vector v to polyline
     */
    public Polyline3 add(Vector3 v) {
        return add(v.x, v.y, v.z);
    }

    /**
     * adds array p to polyline
     */
    public Polyline3 add(double[] p) {
        return add(p[0], p[1], p[2]);
    }

    /**
     * adds polyline line to this polyline; closed status is unchanged.
     */
    public Polyline3 add(Polyline3 line) {
        ensureCapacity(size()+line.size());
        for (int i=0; i<line.size(); i++) {
            add(line.p[i]);
        }
        return this;
    }

    /**
     * returns the number of points in this polyline
     */
    public int size() {
        return size;
    }

    public void translate(double tx, double ty, double tz) {
        for (int i=0; i<size; i++) {
            p[i].x += tx;
            p[i].y += ty;
            p[i].z += tz;
        }
    }

    /**
     * returns a string representation of this polyline
     */
    public String toString() {
        return "Polyline3 ["+size+"]";
    }

    /**
     * ensures the p vector is large enough to hold capacity
     */
    private void ensureCapacity(int capacity) {
        if (capacity > p.length) {
            Vector3 old[] = p;
            p = new Vector3[capacity+increment];
            System.arraycopy(old, 0, p, 0, old.length);
        }
    }

    private static final double PI = Math.PI;
    private static final double PI2 = PI * 2;

    public static Polyline3 circle(double r,
                                   Polyline3 p) {
        return arc(r, r, 0, PI2, 0, 0, 0, 0, 0, 0, p);
    }

    public static Polyline3 circle(double r,
                                   double x, double y, double z,
                                   Polyline3 p) {
        return arc(r, r, 0, PI2, x, y, z, 0, 0, 0, p);
    }

    public static Polyline3 circle(double r,
                                   double x, double y, double z,
                                   double phi, double theta,
                                   Polyline3 p) {
        return arc(r, r, 0, PI2, x, y, z, phi, theta, 0, p);
    }

    public static Polyline3 ellipse(double rx, double ry,
                                    Polyline3 p) {
        return arc(rx, ry, 0, PI2, 0, 0, 0, 0, 0, 0, p);
    }

    public static Polyline3 ellipse(double rx, double ry,
                                    double x, double y, double z,
                                    Polyline3 p) {
        return arc(rx, ry, 0, PI2, x, y, z, 0, 0, 0, p);
    }

    public static Polyline3 ellipse(double rx, double ry,
                                    double x, double y, double z,
                                    double phi, double theta, double omega,
                                    Polyline3 p) {
        return arc(rx, ry, 0, PI2, x, y, z, phi, theta, omega, p);
    }

    public static Polyline3 arc(double r,
                                double start, double end,
                                Polyline3 p) {
        return arc(r, r, start, end, 0, 0, 0, 0, 0, 0, p);
    }

    public static Polyline3 arc(double r,
                                double start, double end,
                                double x, double y, double z,
                                Polyline3 p) {
        return arc(r, r, start, end, x, y, z, 0, 0, 0, p);
    }

    public static Polyline3 arc(double r,
                                double start, double end,
                                double x, double y, double z,
                                double phi, double theta,
                                Polyline3 p) {
        return arc(r, r, start, end, x, y, z, phi, theta, 0, p);
    }

    public static Polyline3 arc(double rx, double ry,
                                double start, double end,
                                Polyline3 p) {
        return arc(rx, ry, start, end, 0, 0, 0, 0, 0, 0, p);
    }

    public static Polyline3 arc(double rx, double ry,
                                double start, double end,
                                double x, double y, double z,
                                Polyline3 p) {
        return arc(rx, ry, start, end, x, y, z, 0, 0, 0, p);
    }

    private static final int ELLIPSEPOINTS = 46;

    public static Polyline3 arc(double rx, double ry,
                                double start, double end,
                                double x, double y, double z,
                                double phi, double theta, double omega,
                                Polyline3 p) {

    // FIXME phi and theta and omega ignored
    // FIXME check on size
        if (p == null) p = new Polyline3(ELLIPSEPOINTS);

        rx = Math.abs(rx);
        ry = Math.abs(ry);

        // skip if degenerate
        if ((rx < 0.0001) && (ry < 0.0001)) {
            p.clear();
            p.add(0.0, 0.0, 0.0);
            return p;
        }

        int n = p.clear();
        if (n < ELLIPSEPOINTS) n = ELLIPSEPOINTS;
        double delta = (end - start) / (n - 1);
        for (int i=0; i<n; i++) {
            double angle = start + i*delta;
            p.add(rx * Math.cos(angle) + x, ry * Math.sin(angle) + y, 0.0 + z);
        }
        return p;
    }

    public static Polyline3[] linesOnArcs(double r1,
                                          double x1, double y1, double z1,
                                          double phi1, double theta1,
                                          double r2,
                                          double x2, double y2, double z2,
                                          double phi2, double theta2,
                                          double start, double end,
                                          int numberOfLines,
                                          Polyline3[] poly) {

        return linesOnArcs(r1, r1, x1, y1, z1, phi1, theta1, 0,
                           r2, r2, x2, y2, z2, phi2, theta2, 0,
                           start, end, numberOfLines, poly);
    }

    public static Polyline3[] linesOnArcs(double r1x, double r1y,
                                          double x1, double y1, double z1,
                                          double phi1, double theta1, double omega1,
                                          double r2x, double r2y,
                                          double x2, double y2, double z2,
                                          double phi2, double theta2, double omega2,
                                          double start, double end,
                                          int numberOfLines,
                                          Polyline3[] poly) {
        // FIXME ignores phi1, theta1, phi2 and theta2
    // FIXME check on size

        double dx = x2 - x1;
        double dy = y2 - y1;
        double dz = z2 - z1;

        double dt = Math.sqrt(dx*dx + dz*dz);
        double phi = Math.atan2(dy, dt);
        double theta = -Math.atan2(dx, dz);

        if ((poly == null) || (poly.length < numberOfLines)) {
            poly = new Polyline3[numberOfLines];
        }

        double delta = (end - start) / numberOfLines;
        for (int i=0; i<numberOfLines; i++) {
            double angle = start + i*delta;
            poly[i] = new Polyline3(2);

            poly[i].add(r1x * Math.cos(angle)+x1, r1y * Math.sin(angle)+y1, 0+z1);
            poly[i].add(r2x * Math.cos(angle)+x2, r2y * Math.sin(angle)+y2, 0+z2);
        }

        return poly;
    }
}
