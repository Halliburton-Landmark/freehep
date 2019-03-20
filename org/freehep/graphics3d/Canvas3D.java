// Copyright 2000, CERN, Geneva, Switzerland and SLAC, Stanford, U.S.A.
package org.freehep.graphics3d;

import java.awt.*;
import java.util.*;
import javax.swing.*;

import org.freehep.graphics2d.*;
import org.freehep.swing.graphics.*;

/**
 * A canvas which handles 3D projections and manipulations with the mouse.
 * It uses an ArcBall for its rotations.
 * <p>
 *
 * @author Mark Donszelmann
 * @version $Id: Canvas3D.java,v 1.13 2003/02/06 18:58:04 duns Exp $
 */

public class Canvas3D extends BackedPanel implements DrawableHandler {

    private ArcBall ball;
    private Vector providers;
    private Transform3D transform;

    /**
     * Creates a standard 3D canvas, with mouse interactions enabled
     */
    public Canvas3D() {
        // FIXME: create non transparent canvas, by setting it to non-opaque = transparent ?
        // if set to true, canvas will not update unless a system repaint takes place!
        super(false);

        setLayout(new BorderLayout());
        setBackground(Color.black);

        ball = new ArcBall(this);
        providers = new Vector();
        transform = new Transform3D();
    }

    /**
     * @return the ArcBall
     */
    public ArcBall getArcBall() {
        return ball;
    }

    /**
     * Adds a drawable provider to the list
     */
    public void add(DrawableProvider provider) {
        if (!providers.contains(provider)) {
            providers.addElement(provider);
        }
    }

    /**
     * removes a drawable procvider from the list
     */
    public void remove(DrawableProvider provider) {
        providers.removeElement(provider);
    }

    /**
     * Delegates to draw. This method is to be called when a User repaint has to be made.
     * Since we use the BackedPanel, a System repaint will just copy the buffered image
     */
    public void repaint() {
        draw();
    }

    /**
     * Applies the current ArcBall matrix to the model matrix and iterates over all the
     * drawable providers.
     */
    public void draw() {
        if ((getLock() == null) || (getGraphics() == null) ) return;
        long t0 = System.currentTimeMillis();
	    synchronized (getLock()) {
            VectorGraphics g = VectorGraphics.create(getGraphics());
            Rectangle clip = getBounds();
            g.setColor(Color.black);
            g.fillRect(0, 0, clip.width, clip.height);
            g.setColor(Color.white);

            transform.push();
            Matrix4 m = ball.toMatrix();

            transform.multiply(m);
            // FIXME: we need to add scaling
            transform.scale(0.8, 0.8, 0.8);
//            transform.translate(0.2, 0.2, 0);
            m = transform.getMatrix();

            // now draw all the elements
            for (Enumeration e = providers.elements(); e.hasMoreElements(); ) {
                DrawableProvider provider = (DrawableProvider)e.nextElement();
                drawObjects(g, provider.getDrawables(m));
            }

            if (ball.isEnabled()) {
                drawObjects(g, ball.getDrawables(m));
            }
            transform.pop();

            // now issue the real repaint
            super.repaint();
        }
        System.out.println("Draw took: "+(System.currentTimeMillis()-t0)+" ms.");
    }

    /**
     * Iterates over al drawable providers and calls drawObject on them
     */
    protected void drawObjects(VectorGraphics g, Enumeration e) {
        transform.push();
        while (e.hasMoreElements()) {
            drawObject(g, e.nextElement());
        }
        transform.pop();
    }

    private int nW = 10;
    private int[][] cW = new int[2][nW];

    /**
     * Draws/handles a single object. Currently there is support for:
     * <ul>
     * <li>Color
     * <li>Polyline3
     * <li>Matrix
     * <li>Ortho
     * <li>Frustum
     * <li>Scale
     * </ul>
     */
    protected void drawObject(VectorGraphics g, Object obj) {
        if (obj instanceof Color) {
            Color color = (Color)obj;
            g.setColor(color);
        } else if (obj instanceof Polyline3) {
            Polyline3 poly = (Polyline3)obj;

            // grow array if necessary
            if (poly.size() > cW[0].length) {
                nW = poly.size();
                cW[0] = new int[nW];
                cW[1] = new int[nW];
            }
            nW = poly.size();
            cW = transform.get(poly, x0, y0, w0, h0, cW);

            if (poly.showLine()) {
                if (poly.isClosed()) {
                    if (poly.isFilled()) {
                        Color oldColor = g.getColor();
                        g.setColor(poly.getFillColor());
                        g.fillPolygon(cW[0], cW[1], nW);
                        g.setColor(oldColor);
                    } else  {
                        g.drawPolygon(cW[0], cW[1], nW);
                    }
                } else {
                    g.drawPolyline(cW[0], cW[1], nW);
                }
            }

            if (poly.showMarkers) {
                Color oldColor = g.getColor();
                g.setColor(poly.getMarkerColor());
                for (int i=0; i<nW; i++) {
                    g.drawSymbol(cW[0][i], cW[1][i], poly.getMarkerSize(), poly.getMarker());
                }
                g.setColor(oldColor);
            }
        } else if (obj instanceof Matrix4) {
            Matrix4 matrix = (Matrix4)obj;
            transform.setMatrix(matrix);
        } else if (obj instanceof Ortho) {
            Ortho ortho = (Ortho)obj;
            transform.ortho(ortho.left, ortho.right, ortho.bottom, ortho.top, ortho.near, ortho.far);
        } else if (obj instanceof Frustum) {
            Frustum frustum = (Frustum)obj;
            transform.frustum(frustum.left, frustum.right, frustum.bottom, frustum.top, frustum.near, frustum.far);
        } else if (obj instanceof Scale) {
            Scale scale = (Scale)obj;
            transform.scale(scale.x, scale.y, scale.z);
        } else if (obj instanceof Translate) {
            Translate translate = (Translate)obj;
            transform.translate(translate.x, translate.y, translate.z);
        } else {
            System.err.println("Unknown object of class: "+obj.getClass());
        }
    }

    /**
     * Changes the bounds of the window
     */
    public void setBounds(int x, int y, int width, int height) {
        super.setBounds(x, y, width, height);
        if (height < width) {
            x0 = (width - height)/2;
            y0 = 0;
            w0 = height;
            h0 = height;
        } else {
            x0 = 0;
            y0 = (height - width) / 2;
            w0 = width;
            h0 = width;
        }

        transform = new Transform3D();
//        transform.ortho(-1.0, 1.0, -1.0, 1.0, 0.001, 100000.0);
//        transform.translate(0.0, 0.0, -3.0);

        draw();
    }

    private int x0, y0, w0, h0;

    /**
     * @return the transformed and viewport modified X window coordinate
     */
/*
    private int getX(double x, double y, double z) {
        double u = transform.getU(x, y, z);
        int xW = (int)((u + 1)*w0)/2 + x0;
        return xW;
    }
*/
    /**
     * @return the transformed and viewport modified Y window coordinate
     */
/*
    private int getY(double x, double y, double z) {
        double v = transform.getV(x, y, z);
        int yW = h0 - (int)((v + 1)*h0)/2 + y0;
        return yW;
    }
*/
}
