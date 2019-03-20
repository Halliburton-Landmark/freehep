package hep.io.mcfio;

import hep.io.xdr.*;

import java.io.*;


/**
 * A class for reading MCFIO files
 *
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: MCFIOReader.java,v 1.5 2003/09/16 23:11:54 tonyj Exp $
 */
public class MCFIOReader implements MCFIOConstants
{
   private EventTable eventTable;
   private FileHeader fileHeader;
   private String file;
   private XDRDataInput xdr;
   private int currentEvent; // index in eventTable of next event

   public MCFIOReader(String file) throws IOException
   {
      // It sounds like a good idea to use a random access file,
      // but the performance seems terrible, so right now use
      // sequential access.
      //this(new XDRRandomAccessFile(file,"r"));
      this.file = file;
      init(new XDRInputStream(new FileInputStream(file)));
   }

   public MCFIOReader(InputStream input) throws IOException
   {
      init(new XDRInputStream(input));
   }

   /**
    * Get the comment associated with the file
    */
   public String getComment()
   {
      return fileHeader.getComment();
   }

   /**
    * Get the date when the file was created
    */
   public String getDate()
   {
      return fileHeader.getDate();
   }

   /**
    * The actual number of events on the file
    */
   public int getNumberOfEvents()
   {
      return fileHeader.getNumberOfEvents();
   }

   /**
    * The expected number of events in the file
    */
   public int getNumberOfEventsExpected()
   {
      return fileHeader.getNumberOfEventsExpected();
   }

   /**
    * Get the title of the file
    */
   public String getTitle()
   {
      return fileHeader.getTitle();
   }

   public void close() throws IOException
   {
      if (xdr instanceof RandomAccessFile)
      {
         ((RandomAccessFile) xdr).close();
      }
      else
         ((InputStream) xdr).close();
      fileHeader = null;
      eventTable = null;
   }

   /**
    * Get the next event.
    * Calling this method does not necessarily mean the full
    * event data will be read. Initially only the event number,
    * store number, run number, and trigger mask are available.
    * Once one of the methods requiring information about the
    * blocks inside the event are called the entire event will
    * be read. Thus it is possible to loop over events looking
    * for events which satisfy some criterion, without actually
    * paying the overhead of decoding the whole event.
    */
   public MCFIOEvent nextEvent() throws IOException
   {
      if (currentEvent >= eventTable.numevts())
      {
         // read the next event table
         int next = eventTable.nextTable();
         if (next <= 0)
            throw new EOFException();
         skipTo(next);
         eventTable.read(xdr);
         currentEvent = 0;
      }
      return new EventHeader(currentEvent++);
   }

   public void rewind() throws IOException
   {
      //TODO: Once we use a random access file this will be much easier
      if (file != null)
      {
         close();
         init(new XDRInputStream(new FileInputStream(file)));
      }
      else
         throw new IOException("Rewind not supported");
   }

   /**
    * Override this method to create user defined blocks
    */
   protected MCFIOBlock createUserBlock(int id) throws IOException
   {
      throw new IOException("Unknown user block " + id);
   }

   private void init(XDRDataInput xdr) throws IOException
   {
      this.xdr = xdr;

      // Read the file header
      fileHeader = new FileHeader();
      fileHeader.read(xdr);

      // Read the first event table
      eventTable = new EventTable();
      eventTable.read(xdr);
      currentEvent = 0;
   }

   private void skipTo(int target) throws IOException
   {
      if (xdr instanceof RandomAccessFile)
      {
         RandomAccessFile random = (RandomAccessFile) xdr;
         random.seek(target);
      }
      else
      {
         XDRInputStream input = (XDRInputStream) xdr;
         int pos = (int) input.getBytesRead();
         if (pos < target)
            input.skipBytes(target - pos);
         else if (pos > target)
            throw new MCFIOException("Cannot skip backwards in sequential file: " + pos + " " + target);
      }
   }

   /**
    * A private read-only implementation of MCFIOEvent.
    * We try to be slightly smart here. Some of the event
    * information is available directly in the event table,
    * so we only need to actually read the event if the user
    * asks for information which is not already available.
    * Thus if the user looks at the event/run/store/trigMask
    * and decides they are not interested in the rest of the
    * event, we never actually need to read the event at all.
    */
   private class EventHeader extends MCFIOBlock implements MCFIOEvent
   {
      private int[] blockIds;
      private int[] blockPtrs;
      private boolean haveRead;
      private int evtnum;
      private int nBlocks;
      private int pointer;
      private int runnum;
      private int storenum;
      private int trigMask;

      EventHeader(int index) throws IOException
      {
         super(EVENTHEADER);
         haveRead = false;
         evtnum = eventTable.evtnum(index);
         runnum = eventTable.runnum(index);
         storenum = eventTable.storenum(index);
         trigMask = eventTable.trigMask(index);
         pointer = eventTable.ptrEvent(index);
      }

      public MCFIOBlock getBlock(int index) throws IOException
      {
         if (!haveRead)
            readEvent();
         skipTo(blockPtrs[index]);

         MCFIOBlock block = createUserBlock(blockIds[index]);
         block.read(xdr);
         return block;
      }

      public int getBlockID(int index) throws IOException
      {
         if (!haveRead)
            readEvent();
         return blockIds[index];
      }

      public int getEventNumber()
      {
         return evtnum;
      }

      public int getNBlocks() throws IOException
      {
         if (!haveRead)
            readEvent();
         return nBlocks;
      }

      public int getRunNumber()
      {
         return runnum;
      }

      public int getStoreNumber()
      {
         return storenum;
      }

      public int getTrigMask()
      {
         return trigMask;
      }

      public void read(XDRDataInput xdr) throws IOException
      {
         super.read(xdr);
         if (fVersion > 2)
            throw new MCFIOException("Unsupported version " + version + " for EventHeader");

         evtnum = xdr.readInt();
         storenum = xdr.readInt();
         runnum = xdr.readInt();
         trigMask = xdr.readInt();
         nBlocks = xdr.readInt();

         int dimBlocks = xdr.readInt();
         if (fVersion >= 2)
         {
            int nNTuples = xdr.readInt();
            int dimNTuples = xdr.readInt();
            if (nNTuples > 0)
               throw new IOException("NTuples not supported");
         }
         blockIds = xdr.readIntArray(null);
         blockPtrs = xdr.readIntArray(null);

         // It appears that the blocks are a sort of 0 terminated list
         for (int i = 0; i < nBlocks; i++)
            if (blockPtrs[i] == 0)
               nBlocks = i;
      }

      public String toString()
      {
         StringBuffer b = new StringBuffer();
         b.append("Run ");
         b.append(runnum);
         b.append(" store ");
         b.append(storenum);
         b.append(" event ");
         b.append(evtnum);
         b.append(" mask ");
         b.append(trigMask);
         if (haveRead)
         {
            b.append(" blocks [");
            for (int i = 0;;)
            {
               b.append(blockIds[i]);
               if (++i == nBlocks)
                  break;
               b.append(",");
            }
            b.append("]");
         }
         return b.toString();
      }

      private void readEvent() throws IOException
      {
         skipTo(pointer);
         read(xdr);
         haveRead = true;
      }
   }
}
