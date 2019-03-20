package hep.io.hbook.test;
import junit.framework.*;
import java.util.*;
import java.io.*;

/**
 *
 * @author The AIDA team @ SLAC.
 *
 */
public class HbookTestSuite extends TestCase {
    
    private TestSuite suite;
    
    public HbookTestSuite(java.lang.String testName) {
        super(testName);        
        suite = (TestSuite) suite();
    }
    
    private TestSuite getSuite() {
        return suite;
    }
        
    public static junit.framework.Test suite() {
        TestSuite suite = new TestSuite();
        
        // Add all the test suites here	
	
        suite.addTestSuite( HbookTest.class );	
        suite.addTestSuite( HbookTest2.class );
        suite.addTestSuite( HbookTest3.class );
        
        return suite;
    }
}
