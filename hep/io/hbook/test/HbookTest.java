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
public class HbookTest extends TestCase
{
   private HbookFile hbook;
   private int nObjects;
   public HbookTest(String name)
   {
      super(name);
   }
   
   public void testReadFile() throws IOException
   {
      CompositeHbookObject file = hbook.getTopLevelDirectory();
      assertEquals(53,file.nChildren());
      list(file.getChildren());
      assertEquals(280,nObjects);
   }
   private void list(Enumeration e)
   {
      while (e.hasMoreElements())
      {
         HbookObject o = (HbookObject) e.nextElement();
         nObjects++;
         if (o instanceof CompositeHbookObject) list(((CompositeHbookObject) o).getChildren());
      }
   }
   protected void tearDown() throws Exception
   {
      hbook.close();
   }
   
   protected void setUp() throws Exception
   {
      String testDataDir = System.getProperty("org.freehep.testData");
      File f = new File(testDataDir,"pawdemo.hbook");
      hbook = new HbookFile(f);
   }
}