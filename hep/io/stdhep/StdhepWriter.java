package hep.io.stdhep;

import hep.io.mcfio.*;

import java.io.*;


/**
 * A class for writing stdhep files.
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: StdhepWriter.java,v 1.3 2003/09/16 23:11:55 tonyj Exp $
 */
public class StdhepWriter extends MCFIOWriter implements StdhepConstants
{
   private static int[] blockIds = 
   {
      MCFIO_STDHEP, MCFIO_STDHEPM, MCFIO_STDHEPBEG, MCFIO_STDHEPEND
   };
   private static String[] blockNames = 
   {
      "Stdhep Event", "Stdhep Multi", "Stdhep Begin Run", "Stdhep End Run"
   };
   private MCFIOEventWrapper event = new MCFIOEventWrapper();

   public StdhepWriter(String file, String title, String comment, int numevts) throws IOException
   {
      super(file, title, comment, numevts, blockIds, blockNames);
   }

   public static void main(String[] argv) throws Exception
   {
      StdhepReader r = new StdhepReader("c:\\temp\\pybms-ZZ-500-990115-gen-98.dat");
      StdhepWriter w = new StdhepWriter("test.stdhep", r.getTitle(), r.getComment(), r.getNumberOfEvents());
      try
      {
         for (;;)
         {
            StdhepRecord record = r.nextRecord();
            System.out.println("record=" + record);
            w.writeRecord(record);
         }
      }
      finally
      {
         w.close();
         r.close();
      }
   }

   public void writeRecord(StdhepRecord record) throws IOException
   {
      if (compatibilityMode && record instanceof StdhepEvent)
      {
         if (((StdhepEvent) record).getNHEP() > 4000)
         {
            throw new IOException("Too many particles");
         }
      }
      event.setRecord(record);
      write(event);
   }

   private class MCFIOEventWrapper implements MCFIOEvent
   {
      private StdhepRecord record;

      public MCFIOBlock getBlock(int index)
      {
         return record;
      }

      public int getBlockID(int index)
      {
         return record.getID();
      }

      public int getEventNumber()
      {
         if (record instanceof StdhepEvent)
            return ((StdhepEvent) record).getNEVHEP();
         return 0;
      }

      public int getNBlocks()
      {
         return 1;
      }

      public int getRunNumber()
      {
         return 0;
      }

      public int getStoreNumber()
      {
         return 0;
      }

      public int getTrigMask()
      {
         return 0;
      }

      void setRecord(StdhepRecord record) throws IOException
      {
         this.record = record;
      }
   }
}
