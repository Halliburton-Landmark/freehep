package org.freehep.graphics3d.test;

import java.awt.Color;
import javax.swing.JFrame;

import org.freehep.swing.graphics.StackedPanel;
import org.freehep.graphics3d.PanelArtist3D;
import org.freehep.graphics3d.RotationSelectionPanel;


/**
 * Test class to show a demo with the ArcBall, using Canvas3D.
 * <p>
 * Original ArcBall C code from Ken Shoemake, Graphics Gems IV, 1993.
 *
 * @author Mark Donszelmann
 * @version $Id: TestPanelArtist3D.java,v 1.3 2004/01/16 23:05:05 duns Exp $
 */

public class TestPanelArtist3D extends JFrame {
    
    public TestPanelArtist3D() {
        
        PanelArtist3D artist = new PanelArtist3D();
        StackedPanel panel = new StackedPanel(artist);
        // FIXME: setting the layer to opaque does not draw!
        panel.addLayer("LAYER1", 1, false);

        // FIXME: background how to
        panel.setBackground(Color.black); 
        
        try {       
            panel.activateGraphicalSelectionPanelOfClass(RotationSelectionPanel.class);
        } catch (InstantiationException ie) {
            System.out.println("Error: cannot create RotationSelectionPanel");
        } catch (IllegalAccessException iae) {
            System.out.println("Error: cannot create RotationSelectionPanel");
        }
        
//        panel.getArcBall().setOtherAxis(0, new Vector3(-0.48, 0.80, 0.36));
        
        TestBody body = new TestBody(); 
        artist.add(body);       
        
        getContentPane().add(panel);
        pack();
        setSize(800, 640);
        setVisible(true);
//        panel.getArcBall().setEnabled(false);
    }
    
    public static void main(String[] args) {
        new TestPanelArtist3D();
    }
}
