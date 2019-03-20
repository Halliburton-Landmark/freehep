package org.freehep.graphics3d;

import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.Toolkit;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseListener;
import java.util.Enumeration;
import java.util.Vector;

import org.freehep.graphics2d.*;
import org.freehep.swing.graphics.*;

/**
 * Implements an ArcBall. The ball sits on top of the Canvas, allowing the user to
 * grab it with the mouse and drag it to rotate the ball as well as the model shown
 * on the canvas. The ongoing drag, as well as the outline of the ball is shown, while
 * dragging. The resulting drag may also be shown by pressing Caps-Lock. Using the
 * Ctrl, Shift or Ctrl+Shift keys will constrain the rotation to Camera, Body or User
 * defined Axes. While moving the mouse and pressing the keys, the selected constraint
 * axis will highlight. After pressing the mouse button (and a key), a rotation will
 * start, constrained by the selected axis.
 * <p>
 * Original ArcBall C code from Ken Shoemake, Graphics Gems IV, 1993.
 *
 * @author Mark Donszelmann
 * @version $Id: RotationSelectionPanel.java,v 1.11 2002/12/13 17:40:48 duns Exp $
 */

public class RotationSelectionPanel extends GraphicalSelectionPanel  {

    private Transform3D transform;
    private double size;
    private Quaternion q0;
    private Quaternion qCurrent;

    private boolean enabled = false;

    private static final Color RIMCOLOR = new Color(255, 255, 255);
    private static final Color FARCOLOR = new Color(195, 127, 31);
    private static final Color NEARCOLOR = new Color(255, 255, 63);
    private static final Color DRAGCOLOR = new Color(127, 255, 255);
    private static final Color RESCOLOR = new Color(195, 31, 31);
    private static final Color FRAMECOLOR = new Color(0, 0, 0);

    private boolean showResult  = false;
    private boolean nextShowResult = !showResult;
    private boolean dragging    = false;
    private Vector3 from        = new Vector3(0,0,1);
    private Vector3 to          = new Vector3(0,0,1);
    private Vector3 fromResult  = new Vector3(0,0,1);
    private Vector3 toResult    = new Vector3(0,0,1);

    private static int NO_AXES = -1;
    private static int CAMERA_AXES = 0;
    private static int BODY_AXES = 1;
    private static int OTHER_AXES = 2;
    private Vector3[][] sets = {
          { // CAMERA_AXES
            new Vector3(1.0, 0.0, 0.0),
            new Vector3(0.0, 1.0, 0.0),
            new Vector3(0.0, 0.0, 1.0) },
          { // BODY_AXES
            new Vector3(1.0, 0.0, 0.0),
            new Vector3(0.0, 1.0, 0.0),
            new Vector3(0.0, 0.0, 1.0) },
          { // OTHER_AXES
            null,
            null,
            null }
        };
    private int axisSet = NO_AXES;
    private int axisIndex = 0;

    /**
     * Creates an ArcBall of default (0.8) size.
     */
    public RotationSelectionPanel() {
        this(0.8);
    }

    /**
     * Creates an ArcBall of given size.
     */
    public RotationSelectionPanel(double size) {
        this.size = size;
        q0 = new Quaternion();
        qCurrent = new Quaternion(0, 0, 0, 1);

        scale = new Scale(size, size, size);
        transform = new Transform3D();
        transform.scale(size, size, size);

        showResult = Toolkit.getDefaultToolkit().getLockingKeyState(KeyEvent.VK_CAPS_LOCK);
    }

    /**
     * Sets one of the user axes.
     *
     * @param index in range 0..2
     * @param axis
     */
    public void setOtherAxis(int index, Vector3 axis) {
        if ((index < 0) || (index > 2)) {
            throw new IllegalArgumentException("ArcBall.setOtherAxis: index should be in range 0..2: "+index);
        }
        sets[OTHER_AXES][index] = axis;
    }

    /**
     * @return an X screen coordinate between -1 and 1 for the
     * square part of the ball.
     */
    private double getX(MouseEvent event) {
        Rectangle d = event.getComponent().getBounds();
        double factor = 1.0;
        if (d.width > d.height) {
            factor = (double)d.width / d.height;
        }
        return (2.0*event.getX() - d.width)*factor/d.width;
    }

    /**
     * @return an Y screen coordinate between -1 and 1 for the
     * square part of the ball.
     */
    private double getY(MouseEvent event) {
        Rectangle d = event.getComponent().getBounds();
        double factor = 1.0;
        if (d.height > d.width) {
            factor = (double)d.height / d.width;
        }
        return (d.height - 2.0*event.getY())*factor/d.height;
    }

    /**
     * Left mouse button will store start state of the drag, as well as showing the
     * constraint axis if any.
     */
    public void mousePressed(MouseEvent event) {
        if ((event.getModifiers() & MouseEvent.BUTTON1_MASK ) != 0) {
            ArcBallMath.projectToSphere(size, getX(event), getY(event), from);
            ArcBallMath.projectToSphere(size, getX(event), getY(event), to);
    	    if (axisSet != NO_AXES) {
    	        ArcBallMath.constrainToAxis(from, sets[axisSet][axisIndex], from);
    	        ArcBallMath.constrainToAxis(to, sets[axisSet][axisIndex], from);
            }

            q0.set(qCurrent);
            dragging = true;

            repaint();
         }
    }

    /**
     * Left mouse button will store and if requested show the resulting dragged arc.
     */
    public void mouseReleased(MouseEvent event) {
        if ((event.getModifiers() & MouseEvent.BUTTON1_MASK ) != 0) {
            fromResult = from;
            toResult = to;
            dragging = false;

            repaint();
        }
    }

    private Quaternion qDrag;

    /**
     * Left mouse button will update the (matrix) state of the ArcBall, and show
     * the dragged (constraint) path.
     */
    public void mouseDragged(MouseEvent event) {
        if ((event.getModifiers() & MouseEvent.BUTTON1_MASK ) != 0) {
            ArcBallMath.projectToSphere(size, getX(event), getY(event), to);

    	    if ((axisSet != NO_AXES) && (axisIndex != -1)) {
    	        ArcBallMath.constrainToAxis(to, sets[axisSet][axisIndex], to);
    	    }
            qDrag = ArcBallMath.buildQuaternion(size, from, to, qDrag);
            if (qDrag != null) {
                q0.multiply(qDrag, qDrag);
                setState(qDrag);
                repaint();
                fireGraphicalSelectionMade(new GraphicalSelectionEvent(this, GraphicalSelectionEvent.NO_ACTION, toMatrix(),null));
            }
        }
    }

    /**
     * Moving the mouse will highlight (if a key is pressed) one of the constraint axes.
     */
    public void mouseMoved(MouseEvent event) {
    	if (axisSet != NO_AXES) {
            ArcBallMath.projectToSphere(size, getX(event), getY(event), to);
    	    axisIndex = ArcBallMath.nearestConstraintAxis(to, sets[axisSet]);
            repaint();
    	}
    }

    /**
     * Handles the pressing of the Ctrl, Shift and Caps-Lock keys
     */
    public void keyPressed(KeyEvent event) {
        boolean repaint = handleKeyEvent(event);

        // handle caps lock
        if (event.getKeyCode() == KeyEvent.VK_CAPS_LOCK) {
            repaint |= (showResult != nextShowResult);
            showResult = nextShowResult;
        }

        if (repaint) {
            repaint();
        }
    }

    /**
     * Handles the release of the Ctrl, Shift and Caps-Lock keys
     */
    public void keyReleased(KeyEvent event) {
        boolean repaint = handleKeyEvent(event);

        // handle caps lock
        if (event.getKeyCode() == KeyEvent.VK_CAPS_LOCK) {
            nextShowResult = !nextShowResult;
        }

        if (repaint) {
            repaint();
        }
    }

    /**
     * Ignored
     */
    public void keyTyped(KeyEvent event) {
        // ignored
    }

    /**
     * @return true if a repaint is needed for this particular key event.
     */
    private boolean handleKeyEvent(KeyEvent event) {
        boolean repaint = false;
        if (!dragging) {
            if (event.isControlDown() && event.isShiftDown()) {
                repaint = (axisSet != OTHER_AXES);
                axisSet = OTHER_AXES;
            } else if (event.isControlDown()) {
                repaint = (axisSet != BODY_AXES);
                axisSet = BODY_AXES;
            } else if (event.isShiftDown()) {
                repaint = (axisSet != CAMERA_AXES);
                axisSet = CAMERA_AXES;
            } else {
                repaint = (axisSet != NO_AXES);
                axisSet = NO_AXES;
            }
        }
        return repaint;
    }

    private final static int RENORMCOUNT = 97;
    private int count=0;
    private Matrix4 ssMatrix;

    /**
     * Sets the current (matrix) state, renormalizing for errors. The BodyAxes are also updated.
     */
    private void setState(Quaternion q) {
        qCurrent.set(q);
        if (count++ > RENORMCOUNT) {
            count = 0;
            qCurrent.normalize(qCurrent);
        }

        // update BodyAxes
        ssMatrix = qCurrent.toMatrix(ssMatrix);
        sets[BODY_AXES][0].x = ssMatrix.m00;
        sets[BODY_AXES][0].y = ssMatrix.m01;
        sets[BODY_AXES][0].z = ssMatrix.m02;

        sets[BODY_AXES][1].x = ssMatrix.m10;
        sets[BODY_AXES][1].y = ssMatrix.m11;
        sets[BODY_AXES][1].z = ssMatrix.m12;

        sets[BODY_AXES][2].x = ssMatrix.m20;
        sets[BODY_AXES][2].y = ssMatrix.m21;
        sets[BODY_AXES][2].z = ssMatrix.m22;
    }

    /**
     * @return the size of the ArcBall.
     */
    public double getBallSize() {
        return size;
    }

    private Ortho ortho = new Ortho(-1, 1, -1, 1, 0, 0);
//    private Translate translate = new Translate(0.2, 0.2, 0);
    private Scale scale;
    private Polyline3 cameraCircle;

    /**
     */
    public void paintComponent(Graphics g) {
        return;
        /*
        VectorGraphics vg = VectorGraphics.create(g);
        Rectangle d = getBounds();
        int w = Math.min(d.width, d.height);
        int x0, y0;
        if (d.width < d.height) {
            x0 = 0;
            y0 = (d.height - d.width) / 2;
        } else {
            x0 = (d.width - d.height) / 2;
            y0 = 0;
        }

        // draw frame
        drawBall(x0, y0, w, vg, 4, FRAMECOLOR, FRAMECOLOR, FRAMECOLOR, FRAMECOLOR, FRAMECOLOR);

        // draw ball
        drawBall(x0, y0, w, vg, 2, RIMCOLOR, FARCOLOR, NEARCOLOR, RESCOLOR, DRAGCOLOR);
        */
    }

    /**
     * Paint all arcs
     */
    private void drawBall(int x0, int y0, int w, VectorGraphics vg, int lineWidth,
                          Color rimColor, Color farColor, Color nearColor, Color resultColor, Color dragColor) {
        Polyline3 poly = Polyline3.circle(1.0, null);
        int[][] polyW = transform.get(poly, x0, y0, w, w, null);
        vg.setLineWidth(lineWidth);
        vg.setColor(rimColor);
        vg.drawPolygon(polyW[0], polyW[1], polyW[0].length);

        // resulting arc
        if (showResult) {
            vg.setColor(resultColor);
            drawAnyArc(x0, y0, w, vg, fromResult, toResult);
        }

        // contraining arcs
        drawConstraints(x0, y0, w, vg, farColor, nearColor);

        // dragging arc
        if (dragging) {
            vg.setColor(dragColor);
            drawAnyArc(x0, y0, w, vg, from, to);
        }
    }

    /**
     * draw all constraint arcs.
     */
    private void drawConstraints(int x0, int y0, int w, VectorGraphics vg, Color farColor, Color nearColor) {
        if (axisSet != NO_AXES) {
            Vector3[] set = sets[axisSet];
            for (int i=0; i<sets[axisSet].length; i++) {
        	    if (i != axisIndex) {
        	        if (dragging) {
//        	            continue;
        	        }
        	        vg.setColor(farColor);
        	    } else {
        	        vg.setColor(nearColor);
        	    }
        	    Vector3 axis = sets[axisSet][i];
        	    if (axis != null) {
            	    if ((axis.x == 0.0) && (axis.y == 0.0)) {
                        Polyline3 poly = Polyline3.circle(1.0, null);
                        int[][] polyW = transform.get(poly, x0, y0, w, w, null);
                        vg.drawPolygon(polyW[0], polyW[1], polyW[0].length);
            	    } else {
            	        drawHalfArc(x0, y0, w, vg, axis);
            	    }
            	}
            }
        }
    }


    private static final int arcPoints = 17;
    private Polyline3 anyArc = new Polyline3(arcPoints);
    private int[][] arcW;

    /**
     * @return an arc defined by its ends. The Polyline3 result is contained in the first 17 entries.
     */
    private void drawAnyArc(int x0, int y0, int w, VectorGraphics vg, Vector3 from, Vector3 to) {
        int n = anyArc.size();
        if (n < arcPoints) {
            for (int i=n; i<arcPoints; i++) {
                anyArc.add(0, 0, 0);
            }
            n = arcPoints;
        }
        double length = from.length();
        from.normalize(anyArc.p[0]);
        to.normalize(anyArc.p[1]);
        anyArc.p[n-1].set(anyArc.p[0].x, anyArc.p[0].y, anyArc.p[0].z);
        for (int i=0; i<(n-1)/((n-1) >>> 2); i++) {
            anyArc.p[0].bisect(anyArc.p[1], anyArc.p[1]);
        }
        double dot = 2.0*anyArc.p[0].dot(anyArc.p[1]);
        for (int i=2; i<n; i++) {
            anyArc.p[i-1].scale(dot, anyArc.p[i]);
    	    anyArc.p[i].sub(anyArc.p[i-2], anyArc.p[i]);
        }
        arcW = transform.get(anyArc, x0, y0, w, w, arcW);
        vg.drawPolyline(arcW[0], arcW[1], arcW[0].length);
    }

    private Vector3 ghaP = new Vector3();
    private Vector3 ghaCross = new Vector3();

    /**
     * @return the arc of a semi-circle defined by its axis.
     */
    private void drawHalfArc(int x0, int y0, int w, VectorGraphics vg, Vector3 n) {
        if (n.z != 1.0) {
    	    ghaP.set(n.y, -n.x, 0.0);
    	    ghaP.normalize(ghaP);
        } else {
    	    ghaP.set(0.0, 1.0, 0.0);
        }
        ghaP.cross(n, ghaCross);
        drawAnyArc(x0, y0, w, vg, ghaP, ghaCross);
        ghaP.negate(ghaP);
        drawAnyArc(x0, y0, w, vg, ghaCross, ghaP);
    }

    /**
     * @return a matrix representation of the current quaternion
     */
    public Matrix4 toMatrix() {
        return qCurrent.toMatrix(null);
    }

    /**
     * @return the current quaternion
     */
    public Quaternion toQuaternion() {
        return qCurrent;
    }
}
