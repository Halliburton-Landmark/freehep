package org.freehep.graphicsio.test;

import java.awt.*;

import org.freehep.graphics2d.VectorGraphics;
import org.freehep.graphicsio.pdf.PDFGraphics2D;
import org.freehep.graphicsio.ps.PSGraphics2D;
import org.freehep.util.UserProperties;

/**
 * @author Mark Donszelmann
 * @version $Id: TestPreviewThumbnail.java,v 1.2 2003/05/04 15:45:24 duns Exp $
 */
public class TestPreviewThumbnail
    extends TestAll {

    public TestPreviewThumbnail(String[] args) throws Exception {
        super(args);
        setName("Test Preview and/or Thumbnail");
    }

    public static void main(String[] args) throws Exception {
        UserProperties p = new UserProperties();
        p.setProperty(PDFGraphics2D.THUMBNAILS, true);
        p.setProperty(PSGraphics2D.PREVIEW, true);

        new TestPreviewThumbnail(args).runTest(p);
    }
}
