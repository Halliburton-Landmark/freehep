// Copyright 2000, CERN, Geneva, Switzerland and SLAC, Stanford, U.S.A.
package org.freehep.graphics3d;

import java.awt.*;
import java.util.*;
import javax.swing.*;

import org.freehep.graphics2d.*;
import org.freehep.swing.graphics.*;

/**
 * A panel artists which handles 3D projections and manipulations with the mouse.
 * It uses an ArcBall for its rotations.
 * <p>
 *
 * @author Mark Donszelmann
 * @version $Id: PanelArtist3D.java,v 1.6 2002/08/12 17:17:15 duns Exp $
 */

public class PanelArtist3D extends AbstractPanelArtist {

    private ArcBall ball;
    private Vector providers;
    private Transform3D transform;
    private Matrix4 rotationMatrix = Matrix4.identity();

    private StackedPanel panel;

    /**
     * Creates a standard 3D panel artist, with mouse interactions enabled
     */
    public PanelArtist3D() {
        // FIXME: create non transparent canvas, by setting it to non-opaque = transparent ?
        // if set to true, canvas will not update unless a system repaint takes place!
//        super(false);

//        setLayout(new BorderLayout());
//        setBackground(Color.black);

//        ball = new ArcBall(this);
        providers = new Vector();
        transform = new Transform3D();
    }

    public String getDescription() {
        return "WIRED 3D Panel";
    }

    public void setEventData(Object data) {
    }

    public Object getEventData() {
        return null;
    }

    public void setStackedPanel(StackedPanel panel) {
        this.panel = panel;
    }

    public StackedPanel getStackedPanel() {
        return panel;
    }

    public void abortDraw() {
        System.out.println("Abort Draw");
    }

    public JComponent getControlPanel() {
        return null;
    }

    public void graphicalSelectionMade(GraphicalSelectionEvent event) {
        if (event.getSource().getClass().equals(RotationSelectionPanel.class)) {
            rotationMatrix = (Matrix4)event.getSelection();
            panel.setRedrawNeeded(true);
            panel.repaint();
        }
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
     * Applies the current ArcBall matrix to the model matrix and iterates over all the
     * drawable providers.
     */
    public boolean drawPanel() {
        long t0 = System.currentTimeMillis();
        Graphics graphicsContexts[] = new Graphics[1];
        panel.getGraphics("LAYER1", graphicsContexts);
        VectorGraphics g = VectorGraphics.create(graphicsContexts[0]);
        panel.clearLayer("LAYER1");

        transform.push();
        transform.multiply(rotationMatrix);

//        transform.multiply(m);
        // FIXME: we need to add scaling
        transform.scale(0.8, 0.8, 0.8);
        Matrix4 m = transform.getMatrix();

        // now draw all the elements
        for (Enumeration e = providers.elements(); e.hasMoreElements(); ) {
            DrawableProvider provider = (DrawableProvider)e.nextElement();
            drawObjects(g, provider.getDrawables(m));
        }

        transform.pop();
//        System.out.println("Draw took: "+(System.currentTimeMillis()-t0)+" ms.");
        return true;
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

            // draw fill
            if (poly.isClosed() && poly.isFilled()) {
                Color oldColor = g.getColor();
                g.setColor(poly.getFillColor());
                g.fillPolygon(cW[0], cW[1], nW);
                g.setColor(oldColor);
            }

            // draw outline on top
            if (poly.showLine()) {
                if (poly.isClosed()) {
                    g.drawPolygon(cW[0], cW[1], nW);
                } else {
                    g.drawPolyline(cW[0], cW[1], nW);
                }
            }

            // draw markers on top
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

    public void panelResized() {
        Rectangle r = panel.getBounds();
        if (r.height < r.width) {
            x0 = (r.width - r.height)/2;
            y0 = 0;
            w0 = r.height;
            h0 = r.height;
        } else {
            x0 = 0;
            y0 = (r.height - r.width) / 2;
            w0 = r.width;
            h0 = r.width;
        }

        transform = new Transform3D();
//        transform.ortho(-1.0, 1.0, -1.0, 1.0, 0.001, 100000.0);
//        transform.translate(0.0, 0.0, -3.0);

//        draw();
        panel.setRedrawNeeded(true);
        panel.repaint();
    }

    private int x0, y0, w0, h0;
}
