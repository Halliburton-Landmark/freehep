// Copyright 2002, SLAC, Stanford University, U.S.A.
package org.freehep.graphicsio.test;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import javax.swing.border.*;

import java.io.FileOutputStream;
import java.io.OutputStream;

import java.net.URL;

import org.freehep.graphics2d.*;
import org.freehep.graphicsio.*;
import org.freehep.graphicsio.exportchooser.*;
import org.freehep.util.images.*;

/**
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: TestImages.java,v 1.4 2003/05/08 22:46:23 duns Exp $
 */
public class TestImages
    extends TestingPanel {

    final static Color bg = Color.ORANGE;
    private Image image;

    public TestImages(String[] args) throws Exception {
    	super(args);
    	setName("Images");

        setBackground(bg);
        MediaTracker t = new MediaTracker(this);
        image = ImageHandler.getImage("images/transparent-image.gif", getClass());
        t.addImage(image, 0);
        try {
            t.waitForAll();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void paintComponent(Graphics g) {
        drawComponent(VectorGraphics.create(g));
    }

    protected void drawComponent(VectorGraphics g) {

    	// Fill in the background.
    	g.setBackground(bg);
    	g.clearRect(0,0,getWidth(),getHeight());

    	int cellWidth = getWidth()/4;
    	int cellHeight = getHeight()/2;

    	int x = 0;
    	int y = 0;

    	// Natural size at origin.
    	g.drawImage(image,x,y,Color.black,this);

    	// Scaled to half-width, half-height.
    	x += cellWidth;
      	g.drawImage(image,x+cellWidth/2,y+cellHeight/2,
    		    cellWidth/2,cellHeight/2,
      		    Color.black,this);

    	// Middle part scaled to 3/4 of cell.
    	x += cellWidth;
      	g.drawImage(image,x,y,
    		    x+3*cellWidth/4,y+3*cellHeight/4,
    		    64,64,192,192,
      		    Color.black,this);

    	// Flip in y-direction.
    	x += cellWidth;
      	g.drawImage(image,x,y,
    		    x+cellWidth/2,y+cellHeight,
    		    256,256,0,0,
      		    Color.black,this);

    	// Natural size at origin.
    	x = 0;
    	y += cellHeight;
    	g.drawImage(image,x,y,this);

    	// Scaled to half-width, half-height.
    	x += cellWidth;
      	g.drawImage(image,x+cellWidth/2,y+cellHeight/2,
    		    cellWidth/2,cellHeight/2,this);

    	// Middle part scaled to 3/4 of cell.
    	x += cellWidth;
      	g.drawImage(image,x,y,
    		    x+3*cellWidth/4,y+3*cellHeight/4,
    		    64,64,192,192,this);


    	// Flip in y-direction.
    	x += cellWidth;
      	g.drawImage(image,x,y,
    		    x+cellWidth/2,y+cellHeight,
    		    256,256,0,0,this);
    }

    public static void main(String[] args) throws Exception {
        new TestImages(args).runTest();
    }
}
