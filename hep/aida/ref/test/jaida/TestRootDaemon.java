package hep.aida.ref.test.jaida;

import hep.aida.IAnalysisFactory;
import hep.aida.ITreeFactory;
import hep.aida.test.TestRoot;

/**
 *
 * @author Tony Johnson
 */
public class TestRootDaemon extends TestRoot
{
   public TestRootDaemon(String testName)
   {
      super(testName);
   }
   protected void openFile() throws Exception
   {
      // Open the test data
      IAnalysisFactory af = IAnalysisFactory.create();
      ITreeFactory tf = af.createTreeFactory();
      tree = tf.create("root://sldrh2.slac.stanford.edu/pawdemo.root","root",true,false,"scheme=anonymous");
   }   
}
