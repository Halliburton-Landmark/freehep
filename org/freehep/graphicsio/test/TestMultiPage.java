// Copyright 2005 freehep
package org.freehep.graphicsio.test;

import java.awt.Dimension;

/**
 * @author Mark Donszelmann
 * @version $Id: TestMultiPage.java,v 1.1 2005/01/06 00:51:42 duns Exp $
 */
public class TestMultiPage extends TestingPanel {
    
    public TestMultiPage(String[] args) throws Exception {
        super(args);
        // Create a new instance of this class and add it to the frame.
        addPage("Colors",         new TestColors(null));
        addPage("Clip",           new TestClip(null));
        addPage("Lines",          new TestLineStyles(null));
        addPage("Shapes",         new TestShapes(null));
        addPage("Symbols",        new TestSymbols2D(null));
    }

    public static void main(String[] args) throws Exception {
        new TestMultiPage(args).runTest();
    }
}
