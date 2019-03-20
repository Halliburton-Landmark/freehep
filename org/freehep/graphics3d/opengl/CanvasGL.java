// Copyright 2000, CERN, Geneva, Switzerland and SLAC, Stanford, U.S.A.
package org.freehep.graphics3d.opengl;

import java.awt.*;
import java.util.*;

import com.hermetica.magician.*;

/**
 * A canvas which handles 3D projections and manipulations with the mouse.
 * It uses an ArcBall for its rotations.
 * <p>
 * This class relies on the OpenGL library provided by Magician:
 * <p>
 * http://www.arcana.co.uk/products/magician
 *
 * @author Mark Donszelmann
 * @version $Id: CanvasGL.java,v 1.3 2002/06/12 23:15:15 duns Exp $
 */

public class CanvasGL extends Panel implements DrawableHandler, GLEventListener {

    private CoreGL coregl;
    private GL gl;
    private GLComponent glc;

    private ArcBall ball;
    private Vector providers;
    private boolean once;
    private double[][] matrixArray = new double[4][4];
    private double[] matrixArray1D = new double[16];

    /**
     * Creates a standard GL canvas, with mouse interactions enabled
     */
    public CanvasGL(int width, int height) {
        setLayout(new BorderLayout());
        providers = new Vector();
        once = true;

        coregl = new CoreGL();
        gl = coregl;
        glc = (GLComponent)GLDrawableFactory.createGLComponent(width, height);
        add("Center", glc);

        ball = new ArcBall(glc);
    }

    /**
     * Creates a GL canvas of size 800x640
     */
    public CanvasGL() {
        this(800,640);
    }

    /**
     * Initializes the OpenGL system. To ba called after "showing" the CanvasGL
     */
    public void init() {
        if (once) {
            once = false;
            GLCapabilities cap = glc.getContext().getCapabilities();
            cap.setDoubleBuffered(GLCapabilities.DOUBLEBUFFER);
            cap.setDepthBits(12);
            cap.setColourBits(24);
            cap.setPixelType(GLCapabilities.RGBA);
            glc.addGLEventListener(this);
            glc.initialize();
        }
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
     * Initialize openGL callback
     */
    public void initialize(GLDrawable c) {
        gl.glClearColor(0,0,0,1);
    }

    /**
     * Display openGL callback, applies ball matrix to model matrix and iterates over
     * all drawable providers.
     */
    public void display(GLDrawable c) {
        gl.glClear(GL.GL_COLOR_BUFFER_BIT);
        gl.glColor3d(1, 1, 1);
        gl.pushMatrix();
        Matrix4 m = ball.toMatrix();

        m.toArray(matrixArray);
        gl.multMatrix(matrixArray);
        // FIXME: we need to add scaling
        gl.scale(0.8, 0.8, 0.8);
//        gl.translate(0.2, 0.2, 0);

        double x[] = new double[16];
        gl.getDouble(GL.GL_PROJECTION_MATRIX, x);
        m = new Matrix4(x);

        for (Enumeration e = providers.elements(); e.hasMoreElements(); ) {
            DrawableProvider provider = (DrawableProvider)e.nextElement();
            drawObjects(provider.getDrawables(m));
        }

        if (ball.isEnabled()) {
            drawObjects(ball.getDrawables(m));
        }
        gl.popMatrix();
    }

    /**
     * Iterates over al drawable providers and calls drawObject on them
     */
    protected void drawObjects(Enumeration e) {
        gl.pushMatrix();
        while (e.hasMoreElements()) {
            drawObject(e.nextElement());
        }
        gl.popMatrix();
    }

    /**
     * Draws/handles a single object. Currently there is support for:
     * <ul>
     * <li>Color
     * <li>Polyline3
     * <li>Matrix
     * <li>Ortho
     * <li>Frustum
     * <li>Scale
     * <li>Translate
     * </ul>
     */
    protected void drawObject(Object obj) {
        if (obj instanceof Color) {
            Color color = (Color)obj;
            gl.color(color.getRed()/255.0, color.getGreen()/255.0, color.getBlue()/255.0);
        } else if (obj instanceof Polyline3) {
            Polyline3 poly = (Polyline3)obj;
            if (poly.closed) {
                gl.begin(GL.GL_POLYGON);
            } else {
                gl.begin(GL.GL_LINE_STRIP);
            }
            for (int j=0; j<poly.size(); j++) {
                Vector3 point = poly.p[j];
                gl.vertex(point.x, point.y, point.z);
            }
            gl.end();
        } else if (obj instanceof Matrix4) {
            Matrix4 matrix = (Matrix4)obj;
            matrix.toArray1D(matrixArray1D);
            gl.loadMatrix(matrixArray1D);
        } else if (obj instanceof Ortho) {
            Ortho ortho = (Ortho)obj;
            gl.ortho(ortho.left, ortho.right, ortho.bottom, ortho.top, ortho.near, ortho.far);
        } else if (obj instanceof Frustum) {
            Frustum frustum = (Frustum)obj;
            gl.frustum(frustum.left, frustum.right, frustum.bottom, frustum.top, frustum.near, frustum.far);
        } else if (obj instanceof Scale) {
            Scale scale = (Scale)obj;
            gl.scale(scale.x, scale.y, scale.z);
        } else if (obj instanceof Translate) {
            Translate translate = (Translate)obj;
            gl.translate(translate.x, translate.y, translate.z);
        } else {
            System.err.println("Unknown object of class: "+obj.getClass());
        }
    }

    /**
     * OpenGL reshape callback, Changes the bounds of the window an sets the viewport
     */
    public void reshape(GLDrawable c, int x, int y, int width, int height) {
        if (height < width) {
            x = (width - height)/2;
            width = height;
        } else if (width < height) {
            y = (height - width) / 2;
            height = width;
        }
        gl.viewport(c, x, y, width, height);
        gl.matrixMode(GL.GL_PROJECTION);
        gl.loadIdentity();
//        gl.ortho(-1.0, 1.0, -1.0, 1.0, 0.001, 100000.0);
//        gl.translate(0.0, 0.0, -3.0);
    }

    /**
     * @return current GL
     */
    public GL getGL() {
        return gl;
    }
}
