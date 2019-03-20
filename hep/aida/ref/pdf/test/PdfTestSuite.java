package hep.aida.ref.pdf.test;

import hep.aida.IAnalysisFactory;
import hep.aida.ICloud1D;
import hep.aida.ICloud2D;
import hep.aida.IHistogramFactory;
import hep.aida.ITree;
import junit.framework.*;
import java.util.*;
import java.io.*;

/**
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
public class PdfTestSuite extends TestCase {
    
    private TestSuite suite;
    
    public PdfTestSuite(java.lang.String testName) {
        super(testName);
        
        suite = (TestSuite) suite();
    }
    
    private TestSuite getSuite() {
        return suite;
    }

    public static void main(java.lang.String[] args) {
        PdfTestSuite pdfTestSuite = new PdfTestSuite("PdfTestSuite");
        junit.textui.TestRunner.run(pdfTestSuite.getSuite());
    }
    
    public static junit.framework.Test suite() {
        TestSuite suite = new TestSuite() {
            protected void tearDown() {
                System.out.println("********** Tearing down the test suite ");
            }
        };
        
        suite.addTestSuite( Chi2GaussianFit.class);
        suite.addTestSuite( UnbinnedGaussianFit.class);
        suite.addTestSuite( SumOfGaussianFit.class);
        return suite;
    }
    
}
