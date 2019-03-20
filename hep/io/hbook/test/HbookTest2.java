package hep.io.hbook.test;
import hep.io.hbook.*;
import java.io.File;

import java.io.IOException;
import java.util.Enumeration;
import junit.framework.TestCase;

/**
 *
 * @author tonyj
 */
public class HbookTest2 extends TestCase
{
   private HbookFile hbook;
   private int nObjects;
   public HbookTest2(String name)
   {
      super(name);
   }
   
   public void testColumnWiseTuple() throws IOException
   {
      CompositeHbookObject file = hbook.getTopLevelDirectory();
      ColumnwiseTuple tuple = (ColumnwiseTuple) file.getChild("ORANGE");
      assertEquals(337,tuple.nChildren());
      assertEquals(100,tuple.getRows());

      ColumnwiseTupleColumn col = (ColumnwiseTupleColumn) tuple.getChild("Tltw_4");
      assertEquals("Tltw_4",col.getName());
      long total = 0;
      for (int i=1; i<=tuple.getRows(); i++)
      {
         tuple.setCurrentRow(i);
         total += col.getInt();
      }
      assertEquals(33685231556L,total);
      total = 0;
      for (int i=1; i<=tuple.getRows(); i++)
      {
         tuple.setCurrentRow(i);
         for (int j=0; j<tuple.nChildren(); j++)
         {
            ColumnwiseTupleColumn col2 = (ColumnwiseTupleColumn) tuple.getChild(j);
            if (col2.getColumnClass() == Double.TYPE) col2.getDouble();
         }
         total += col.getInt();
      }
      assertEquals(33685231556L,total); // Test for JAS-32
   }
   protected void tearDown() throws Exception
   {
      hbook.close();
   }
   
   protected void setUp() throws Exception
   {
      String testDataDir = System.getProperty("org.freehep.testData");
      File f = new File(testDataDir,"JAS.hbook");
      hbook = new HbookFile(f);
   }
}