package org.freehep.graphicsio.pdf.test;

import java.awt.*;
import java.io.*;
import java.util.*;

import javax.swing.*;

import org.freehep.graphicsio.pdf.*;
import org.freehep.util.images.*;

/**
 * This class tests the user-level PDF Writer interfaces.
 * It simply writes a document with several pages, including
 * some text and graphics.
 * <p>
 * @author Mark Donszelmann
 * @version $Id: PDFWriterTest.java,v 1.7 2003/05/31 00:02:30 duns Exp $
 */
public class PDFWriterTest {

    public static void main(String[] args) throws Exception {
        FileOutputStream out = new FileOutputStream("PDFWriterUserTest.pdf");

        // PDF file
        PDFWriter pdf = new PDFWriter(out, "1.3");
        pdf.comment("PDFGraphicsTest file generated by PDFWriterTest, Freehep lib");

        // info
        PDFDocInfo info = pdf.openDocInfo("DocInfo");
        info.setTitle("PDFWriter Test Output");
        info.setAuthor("Mark Donszelmann");
        info.setSubject("Test File of the PDFWriter of the FreeHEP library");
        info.setKeywords("PDFWriter; FreeHEP");
        info.setCreator("org.freehep.util.pdf.PDFWriter");
        info.setCreationDate(Calendar.getInstance());
        pdf.close(info);

        // catalog
        PDFCatalog catalog = pdf.openCatalog("Catalog", "RootPage");
        catalog.setOutlines("Outlines");
        catalog.setPageMode("UseOutlines");
        catalog.setViewerPreferences("Preferences");
        catalog.setOpenAction(new Object[] { pdf.ref("FirstPage"), pdf.name("Fit")});
        pdf.close(catalog);

        // preferences
        PDFViewerPreferences prefs = pdf.openViewerPreferences("Preferences");
        prefs.setFitWindow(true);
        prefs.setCenterWindow(false);
        pdf.close(prefs);

        // outlines
        PDFOutlineList outlines = pdf.openOutlineList("Outlines", "FirstOutline", "LastOutline");
        pdf.close(outlines);

        // outline FIXME: need to connect still
        PDFOutline firstOutline = pdf.openOutline("FirstOutline", "Text Page",
                                                  "Outlines", null, "SecondOutline");
        firstOutline.setDest(new Object[] { pdf.ref("FirstPage"), pdf.name("Fit")});
        pdf.close(firstOutline);

        PDFOutline secondOutline = pdf.openOutline("SecondOutline", "Graphics Page",
                                                  "Outlines", "FirstOutline", "LastOutline");
        secondOutline.setDest(new Object[] { pdf.ref("SecondPage"), pdf.name("Fit")});
        pdf.close(secondOutline);

        PDFOutline lastOutline = pdf.openOutline("LastOutline", "Image Page",
                                                 "Outlines", "SecondOutline", null);
        lastOutline.setDest(new Object[] { pdf.ref("ThirdPage"), pdf.name("Fit")});
        pdf.close(lastOutline);

        // pages
        PDFPageTree pages = pdf.openPageTree("RootPage", null);
        pages.addPage("FirstPage");
        pages.addPage("SecondPage");
        pages.addPage("ThirdPage");
        pages.setMediaBox(0, 0, 612, 792);
        pages.setResources("Resources");
        pdf.close(pages);

        // resources
        PDFDictionary resources = pdf.openDictionary("Resources");
        resources.entry("ProcSet", pdf.ref("OurPageProcSet"));
        PDFDictionary fontList = resources.openDictionary("Font");
        fontList.entry("F1", pdf.ref("Helvetica"));
        resources.close(fontList);
        pdf.close(resources);

        // first page
        PDFPage firstPage = pdf.openPage("FirstPage", "RootPage");
        firstPage.setContents("FirstPageContent");
        pdf.close(firstPage);

        // first page content
        pdf.comment("hello word");
        PDFStream first = pdf.openStream("FirstPageContent", new String[] { "Flate", "ASCIIHex" });
        first.beginText();
        first.font(pdf.name("F1"), 24);
        first.text(100, 100);
        first.show("Hello");
        first.show(" World");
        first.endText();
        pdf.close(first);

        // second page
        PDFPage secondPage = pdf.openPage("SecondPage", "RootPage");
        secondPage.setContents("SecondPageContent");
        secondPage.setThumb("SecondPageThumbnail");
        pdf.close(secondPage);

        // second page thumbnail
        PDFStream secondThumb = pdf.openStream("SecondPageThumbnail");
        MediaTracker tracker = new MediaTracker(new Panel());
	    Image image1 = ImageHandler.getImage("../../test/images/BrokenCursor.gif", PDFWriterTest.class);
        Image image2 = ImageHandler.getImage("../../test/images/transparent-image.gif", PDFWriterTest.class);
        tracker.addImage(image1,0);
        tracker.addImage(image2,1);
        try {
            tracker.waitForAll();
        } catch (Exception e) {
            e.printStackTrace();
        }
        secondThumb.image(ImageUtilities.createRenderedImage(image2, null, Color.BLACK),
                          Color.BLACK, new String[] { "Flate", "ASCII85" });
        pdf.close(secondThumb);


        // second page content
        PDFStream second = pdf.openStream("SecondPageContent", new String[] { "Flate", "ASCII85" });
        second.comment("Draw a black line segment, using the default line width.");
        second.move(150, 250);
        second.line(150, 350);
        second.stroke();
        second.comment("Draw a thicker, dashed line segment.");
        second.width(4);
        second.comment("Set line width to 4 points");
        second.dash(new int[] {4,6}, 0);
        second.comment("Set dash pattern to 4 units on, 6 units off");
        second.move(150, 250);
        second.line(400, 250);
        second.stroke();
        second.dash(new int[0], 0);
        second.comment("Reset dash pattern to a solid line");
        second.width(1);
        second.comment("Reset line width to 1 unit");
        second.comment("Draw a rectangle with a 1 unit red border, filled with light blue.");
        second.colorSpaceStroke(1.0, 0.0, 0.0);
        second.comment("Red for stroke color");
        second.colorSpace(0.5, 0.75, 1.0);
        second.comment("Light blue for fill color");
        second.rectangle(200, 300, 50, 75);
        second.fillAndStroke();
        second.comment("Draw a curve filled with gray and with a colored border.");
        second.colorSpaceStroke(0.5, 0.1, 0.2);
        second.colorSpace(0.7);
        second.move(300, 300);
        second.cubic(300, 400, 400, 400, 400, 300);
        second.closeFillAndStroke();
        pdf.close(second);

        // third page
        PDFPage thirdPage = pdf.openPage("ThirdPage", "RootPage");
        thirdPage.setContents("ThirdPageContent");
        pdf.close(thirdPage);

        // third page content
        PDFStream third = pdf.openStream("ThirdPageContent");
        third.save();
        third.matrix(32, 0, 0, 32, 298, 388);
        third.inlineImage(ImageUtilities.createRenderedImage(image1, null, Color.BLACK),
                          Color.BLACK,
                          new String[] {"Flate", "ASCII85"});
        third.restore();
        pdf.close(third);

        // our page proc set
        pdf.object("OurPageProcSet", new Object[] {pdf.name("PDF"),
                                                   pdf.name("Text"),
                                                   pdf.name("ImageC") });

        // font
        PDFDictionary font = pdf.openDictionary("Helvetica");
        font.entry("Type", pdf.name("Font"));
        font.entry("Subtype", pdf.name("Type1"));
        font.entry("Name", pdf.name("F1"));
        font.entry("BaseFont", pdf.name("Helvetica"));
        pdf.close(font);

        // close pdf
        pdf.close();
        out.close();

        System.exit(0);
    }
}
