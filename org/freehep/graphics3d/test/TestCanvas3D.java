package org.freehep.graphics3d.test;

import javax.swing.JFrame;

import org.freehep.graphics3d.Canvas3D;
import org.freehep.graphics3d.Vector3;

/**
 * Test class to show a demo with the ArcBall, using Canvas3D.
 * <p>
 * Original ArcBall C code from Ken Shoemake, Graphics Gems IV, 1993.
 *
 * @author Mark Donszelmann
 * @version $Id: TestCanvas3D.java,v 1.2 2004/01/16 23:05:05 duns Exp $
 */

public class TestCanvas3D extends JFrame {
    
    public TestCanvas3D() {
        
        Canvas3D panel = new Canvas3D();
        panel.getArcBall().setOtherAxis(0, new Vector3(-0.48, 0.80, 0.36));
        
        TestBody body = new TestBody(); 
        panel.add(body);       
        
        getContentPane().add(panel);
        pack();
        setSize(800, 640);
        setVisible(true);
//        panel.getArcBall().setEnabled(false);
    }
    
    public static void main(String[] args) {
        TestCanvas3D tab = new TestCanvas3D();
    }
}
