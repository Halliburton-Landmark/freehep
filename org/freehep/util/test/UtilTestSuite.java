package org.freehep.util.test;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 *
 * @author Tony Johnson
 * @version $Id: UtilTestSuite.java,v 1.2 2004/12/29 07:18:05 duns Exp $
 *
 */
public class UtilTestSuite extends TestCase
{
   
   private TestSuite suite;
   
   public UtilTestSuite(java.lang.String testName)
   {
      super(testName);
      suite = (TestSuite) suite();
   }
   
   private TestSuite getSuite()
   {
      return suite;
   }
   
   public static Test suite()
   {
      TestSuite suite = new TestSuite();
      
      // Add all the test suites here
      
      suite.addTestSuite( DoubleHashtableTest.class );
      suite.addTestSuite( VersionComparatorTest.class );
      suite.addTestSuite( ScientificFormatTest.class );
      
      return suite;
   }
}
