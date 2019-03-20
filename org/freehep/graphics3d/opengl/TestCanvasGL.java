package org.freehep.graphics3d.opengl;

import javax.swing.JFrame;

/**
 * Test class to show a demo with the ArcBall, using OpenGL.
 * <p>
 * Original ArcBall C code from Ken Shoemake, Graphics Gems IV, 1993.
 *
 * @author Mark Donszelmann
 * @version $Id: TestCanvasGL.java,v 1.2 2004/01/16 23:05:05 duns Exp $
 */

public class TestCanvasGL extends JFrame {
    
    public TestCanvasGL() {
        
        CanvasGL panel = new CanvasGL();
        
        TestBody body = new TestBody(); 
        panel.add(body);       
        
        getContentPane().add("Center", panel);
        pack();
        setVisible(true);
        
        panel.init();
    }
    
    public static void main(String[] args) {
        TestCanvasGL tab = new TestCanvasGL();
    }
}
