// Copyright 2000-2005, FreeHEP.
package org.freehep.graphicsio.test;

import java.awt.*;
import java.awt.event.*;
import java.lang.reflect.*;
import java.io.*;
import java.util.*;
import javax.swing.*;
import javax.swing.border.*;
import java.util.List;

import org.freehep.swing.*;
import org.freehep.graphicsio.*;
import org.freehep.graphicsio.java.*;
import org.freehep.graphicsio.exportchooser.*;
import org.freehep.graphics2d.VectorGraphics;
import org.freehep.util.UserProperties;

/**
 * @author Mark Donszelmann
 * @version $Id: TestingPanel.java,v 1.15 2005/01/06 00:51:42 duns Exp $
 */
public class TestingPanel extends JPanel {

    protected String[] args;
    protected VectorGraphics graphics;
    protected List/*<String>*/ names = new ArrayList();
    protected List/*<JComponent>*/ pages = new ArrayList();

    public TestingPanel(String[] args) throws Exception {
        this.args = args;
        if ((args != null) && (args.length != 0)) {
            if (args[0].equals(ImageGraphics2D.class.getName())) {
                if (args.length != 3) {
                    System.err.println("Usage: Test... "+ImageGraphics2D.class+" format OutputFile");
                    System.exit(1);
                }
            } else {
                if (args.length != 2) {
                    System.err.println("Usage: Test... VectorGraphicsClassName OutputFile");
                    System.exit(1);
                }
            }
        }
    }
    
    protected void addPage(String name, JComponent c) {
        names.add(name);
        pages.add(c);
    }

    public void runTest() throws Exception {
        runTest(null);
    }

    public void runTest(int width, int height) throws Exception {
        runTest(width, height, null);
    }

    public void runTest(Properties options) throws Exception {
        runTest(600, 600, options);
    }

    public void runTest(int width, int height, Properties options) throws Exception {

        setPreferredSize(new Dimension(width, height));

        if ((args == null) || (args.length == 0)) {
            // Create a new frame to hold everything.
            TestingFrame frame = new TestingFrame(getClass().toString());

            if (names.size() > 0) {
                for (int i=0; i<names.size(); i++) {
                    frame.addPanel((String)names.get(i), (JComponent)pages.get(i));
                }
                frame.setSize(600, 600);
            } else {
                // Create a new instance of this class and add it to the frame.
                frame.addPanel(this);
                frame.pack();
            }

            // Give the frame a size and make it visible.
            frame.setVisible(true);
        } else {
            // run with -Djava.awt.headless=true
            Headless headless = new Headless(this);
            headless.pack();
            headless.setVisible(true);

            if (args[0].equals(ImageGraphics2D.class.getName())) {
                File file = new File(args[2]);
                graphics = new ImageGraphics2D(file, this, args[1]);
            } else {
                try {
                    File file = new File(args[1]);
                    Class cls = Class.forName(args[0]);
                    Constructor constructor = cls.getConstructor(new Class[] {File.class, Component.class});
                    graphics = (VectorGraphics)constructor.newInstance(new Object[] {file, this});
                } catch (ClassNotFoundException e) {
                    System.out.println("Cannot find class: "+args[0]);
                    throw e;
                } catch (ClassCastException e) {
                    System.out.println("Class: "+args[0]+" does not extend VectorGraphics");
                    throw e;
                } catch (NoSuchMethodException e) {
                    System.out.println("Class: "+args[0]+" does not have constructor(File, Component)");
                    throw e;
                } catch (InvocationTargetException e) {
                    System.out.println(e.getTargetException());
                    e.getTargetException().printStackTrace();
                    throw e;
                }
            }

// FIXME we should also set the properties in interactive mode
            UserProperties user = (options == null) ? new UserProperties() : new UserProperties(options);

// FIXME enable these when we can know if we run interactively or from ANT
//            user.setProperty(AbstractVectorGraphicsIO.EMIT_WARNINGS, true);
//            user.setProperty(AbstractVectorGraphicsIO.EMIT_ERRORS, true);

            // Text Antialiasing seems to produce something time dependent
            user.setProperty(ImageGraphics2D.ANTIALIAS_TEXT, false);
            user.setProperty(JAVAGraphics2D.PACKAGE_NAME, "org.freehep.graphicsio.java.test");

            // FIXME FREEHEP-219, we need something here to write multi-page documents...

            graphics.setProperties(user);

            graphics.setDeviceIndependent(true);
            graphics.startExport();
            print(graphics);
            graphics.endExport();
        }
    }
}
