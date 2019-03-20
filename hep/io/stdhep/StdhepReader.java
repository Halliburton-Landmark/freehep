package hep.io.stdhep;

import hep.io.mcfio.MCFIOBlock;
import hep.io.mcfio.MCFIOEvent;
import hep.io.mcfio.MCFIOReader;

import java.io.IOException;


/**
 * A class for reading stdhep files.
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: StdhepReader.java,v 1.5 2005/12/15 22:09:02 tonyj Exp $
 */
public class StdhepReader extends MCFIOReader implements StdhepConstants
{
   /**
* Open a stdhep file for reading
*/
   public StdhepReader(String file) throws IOException
   {
      super(file);
   }
/**
* Read the next stdhep record from the file.
* The record may be a begin run, end run, or event record.
*/
   public StdhepRecord nextRecord() throws IOException
   {
      // It is not clear why a stdHEP record would have 0
      // blocks, but it does sometimes seem to happen.
      for (;;)
      {
         MCFIOEvent event = super.nextEvent();
         int nBlocks = event.getNBlocks();
         if (nBlocks == 0)
            continue;
         if (nBlocks != 1)
            throw new IOException("Invalid stdhep record found (NBlocks=" + nBlocks + ")");
         return (StdhepRecord) event.getBlock(0);
      }
   }

/**
* Overrides the createUserBlock from MCFIO to create the
* necessary stdhep records. Override this method to add
* support for your own record types.
*/
   protected MCFIOBlock createUserBlock(int id) throws IOException
   {
      switch (id)
      {
      case MCFIO_STDHEP:
         return new StdhepEvent();

      case MCFIO_STDHEPBEG:
         return new StdhepBeginRun();

      case MCFIO_STDHEPEND:
         return new StdhepEndRun();

      case MCFIO_STDHEPEV4:
         return new StdhepExtendedEvent();
         
      default:
         return super.createUserBlock(id);
      }
   }
}
