package hep.aida.ref.test.jaida;
import junit.framework.*;
import java.util.*;
import java.io.*;

/**
 *
 * @author The AIDA team @ SLAC.
 *
 */
public class JAIDATestSuite extends TestCase {
    
    private TestSuite suite;
    
    public JAIDATestSuite(java.lang.String testName) {
        super(testName);
        
        suite = (TestSuite) suite();
    }
    
    private TestSuite getSuite() {
        return suite;
    }
    
    private TestCase getTest( String testName ) {
        for ( int i = 0; i < this.getSuite().testCount(); i++ ) {
            TestSuite testSuite = (TestSuite)(getSuite().testAt(i));
            for ( int j = 0; j < testSuite.testCount(); j++ ) {
                TestCase test = (TestCase)(testSuite.testAt(j));
                if ( test.getName().equals( testName ) ) return test;
            }
        }
        return null;
    }
    
    
    public static junit.framework.Test suite() {
        TestSuite suite = new TestSuite();
        
        // Add all the test suites here
        suite.addTestSuite( TestEvents.class );	
        suite.addTestSuite( TestOnDemandStore.class );
        suite.addTestSuite( TestPlotter.class );
        suite.addTestSuite( TestOptions.class );
        suite.addTestSuite( TestRootDaemon.class );
        suite.addTestSuite( TestFitting.class );
        
        return suite;
    }
}
