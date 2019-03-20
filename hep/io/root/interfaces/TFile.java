package hep.io.root.interfaces;

import java.io.IOException;
import java.util.List;


/**
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: TFile.java,v 1.7 2003/05/23 20:59:15 duns Exp $
 */
public interface TFile extends hep.io.root.RootObject, TDirectory
{
   int getVersion();

   /**
    * Close the file.
    */
   void close() throws IOException;

   /**
    * Get the StreamerInfo
    */
   List streamerInfo() throws IOException;

   TKey streamerInfoKey();
}
