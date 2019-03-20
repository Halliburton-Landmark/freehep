package org.freehep.graphicsio.test;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.File;
import java.lang.reflect.Array;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

import junit.framework.Test;

import org.freehep.graphicsio.ImageGraphics2D;
import org.freehep.util.Assert;
import org.freehep.util.io.UniquePrintStream;

/**
 * @author Mark Donszelmann
 * @version $Id: TestSuite.java,v 1.29 2004/12/25 23:52:18 duns Exp $
 */
public class TestSuite {

    private static boolean compare;

    public static class TestCase extends junit.framework.TestCase {

        private String name, fmt, dir, ext;

        public TestCase(String name, String fmt, String dir, String ext) {
            super("Graphics2D Test for "+name+" in "+fmt);
            this.name = name;
            this.fmt = fmt;
            this.dir = dir;
            this.ext = ext;
        }

        protected void runTest() throws Throwable {
            String base = "org/freehep/graphicsio/";

            Class cls = Class.forName("org.freehep.graphicsio.test."+name);
            String targetName  = base+dir+"/test/"+name+"."+ext;
            String refName     = base+dir+"/test/"+name+".ref."+ext;
            String refGZIPName = base+dir+"/test/"+name+".ref."+ext+".gz";
            String altRefName  = base+dir+"/test/"+name+"."+ext+".ref";

            Object args;
            if (fmt.equals("GIF") || fmt.equals("PNG")
             || fmt.equals("PPM") || fmt.equals("JPG")) {
                args = Array.newInstance(String.class, 3);
                Array.set(args, 0, ImageGraphics2D.class.getName());
                Array.set(args, 1, fmt.toLowerCase());
                Array.set(args, 2, targetName);
            } else {
                args = Array.newInstance(String.class, 2);
                if (fmt.equals("LATEX")) fmt = "Latex";
                
                Array.set(args, 0, "org.freehep.graphicsio."+dir+"."+fmt+"Graphics2D");
                Array.set(args, 1, targetName);
            }
            Method main = cls.getMethod("main", new Class[] { args.getClass() });
            main.invoke(null, new Object[] { args });
            if (!compare) return;

            File refFile = new File(refGZIPName);
            if (!refFile.exists()) {
                refFile = new File(altRefName);
                if (!refFile.exists()) {
                    refFile = new File(refName);
                }
            }

            boolean isBinary = !fmt.equals("PS");
            Assert.assertEquals(refFile, new File(targetName), isBinary);
        }
    }

    private static void addTests(junit.framework.TestSuite suite, String fmt) {
        addTests(suite, fmt, fmt.toLowerCase(), fmt.toLowerCase());
    }
    
    private static void addTests(junit.framework.TestSuite suite, String fmt, String dir, String ext) {
        if (fmt.equals("PS") || fmt.equals("PDF")) {
// Disabled until files are smaller and performance is better
//            suite.addTest(new TestCase("TestFontType1", fmt, ext));
//            suite.addTest(new TestCase("TestFontType3", fmt, ext));
            suite.addTest(new TestCase("TestPreviewThumbnail", fmt, dir, ext));
        }

        // Alphabetically
        suite.addTest(new TestCase("TestAll", fmt, dir, ext));
        suite.addTest(new TestCase("TestClip", fmt, dir, ext));
        suite.addTest(new TestCase("TestColors", fmt, dir, ext));
        suite.addTest(new TestCase("TestFonts", fmt, dir, ext));
        suite.addTest(new TestCase("TestFontDerivation", fmt, dir, ext));
        suite.addTest(new TestCase("TestGraphicsContexts", fmt, dir, ext));
        suite.addTest(new TestCase("TestHTML", fmt, dir, ext));
        suite.addTest(new TestCase("TestImages", fmt, dir, ext));
        suite.addTest(new TestCase("TestImage2D", fmt, dir, ext));
        suite.addTest(new TestCase("TestLabels", fmt, dir, ext));
        suite.addTest(new TestCase("TestLineStyles", fmt, dir, ext));
        suite.addTest(new TestCase("TestOffset", fmt, dir, ext));
        suite.addTest(new TestCase("TestPaint", fmt, dir, ext));
        suite.addTest(new TestCase("TestPrintColors", fmt, dir, ext));
        suite.addTest(new TestCase("TestResolution", fmt, dir, ext));
        suite.addTest(new TestCase("TestShapes", fmt, dir, ext));
        suite.addTest(new TestCase("TestSymbols2D", fmt, dir, ext));
        suite.addTest(new TestCase("TestTaggedString", fmt, dir, ext));
        suite.addTest(new TestCase("TestText2D", fmt, dir, ext));
        suite.addTest(new TestCase("TestTransforms", fmt, dir, ext));
        suite.addTest(new TestCase("TestTransparency", fmt, dir, ext));
    }

    public static junit.framework.TestSuite suite() {
        // get command line arguments from environment var (set by ANT)
        StringTokenizer st = new StringTokenizer(System.getProperty("args", ""), " ");
        List argList = new ArrayList();
        while (st.hasMoreTokens()) {
            String arg = st.nextToken();
            System.out.println(arg);
            argList.add(arg);
        }
        String[] args = new String[argList.size()];
        argList.toArray(args);

        return suite(args);
    }

    public static junit.framework.TestSuite suite(String[] args) {
        junit.framework.TestSuite suite = new junit.framework.TestSuite();
        int first = 0;
        compare = true;
        if ((args.length > 0) && args[0].equals("-nc")) {
            compare = false;
            first = 1;
        }

        if (args.length-first > 0) {
            for (int i=first; i<args.length; i++) {
                String ext = args[i].toLowerCase();
                if (ext.equals("latex")) ext = "tex";
                if (ext.equals("svg")) ext = "svgz";
                addTests(suite, args[i].toUpperCase(), args[i].toLowerCase(), ext);
            }
        } else {
            addTests(suite, "CGM");
            addTests(suite, "EMF");
            addTests(suite, "GIF");
            addTests(suite, "JPG");
            addTests(suite, "LATEX", "latex", "tex");
            addTests(suite, "PDF");
            addTests(suite, "PNG");
            addTests(suite, "PS");
            addTests(suite, "SVG", "svg", "svgz");
            addTests(suite, "SWF");
            addTests(suite, "JAVA");
        }
        return suite;
    }

    public static void main(String[] args) {
        UniquePrintStream stderr = new UniquePrintStream(System.err);
        System.setErr(stderr);
        junit.textui.TestRunner.run(suite(args));
        stderr.finish();
    }
}
