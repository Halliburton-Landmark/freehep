package org.freehep.swing.table.test;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 *
 * @author Tony Johnson
 * @version $Id: TableTestSuite.java,v 1.1 2004/06/24 06:02:24 tonyj Exp $
 *
 */
public class TableTestSuite extends TestCase
{
   
   private TestSuite suite;
   
   public TableTestSuite(java.lang.String testName)
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
      
      suite.addTestSuite( DefaultSortableTableModelTest.class );
      
      return suite;
   }
}
