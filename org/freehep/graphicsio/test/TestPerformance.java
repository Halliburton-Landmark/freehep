// University of California, Santa Cruz, USA and
// CERN, Geneva, Switzerland, Copyright (c) 2000
package org.freehep.graphicsio.test;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import javax.swing.border.*;

import java.io.FileOutputStream;
import java.io.OutputStream;

import org.freehep.graphics2d.*;
import org.freehep.graphicsio.*;
import org.freehep.graphicsio.exportchooser.*;

/**
 * @author Charles Loomis
 * @author Mark Donszelmann
 * @version $Id: TestPerformance.java,v 1.1 2003/02/04 22:30:33 duns Exp $
 */
public class TestPerformance
    extends TestSymbols2D {

    public TestPerformance(String[] args) throws Exception {
        super(args);
	    setName("Performance");
    }

    public static void main(String[] args) throws Exception {
        long t0 = System.currentTimeMillis();
        new TestSymbols2D(args).runTest();
        if (args.length > 0) {
            System.out.println(args[0]+" took "+(System.currentTimeMillis()-t0)+" ms.");
        }
    }
}
