package hep.io.stdhep;

import hep.io.mcfio.MCFIOBlock;

import hep.io.xdr.XDRDataInput;

import java.io.IOException;


/**
 * A base class from which all stdhep records inherit
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: StdhepRecord.java,v 1.4 2003/09/16 23:11:54 tonyj Exp $
 */
public abstract class StdhepRecord extends MCFIOBlock implements StdhepConstants
{
   StdhepRecord(int id)
   {
      super(id);
   }

   public void read(XDRDataInput xdr) throws IOException
   {
      super.read(xdr);

      //if (!version.equals("3.01")) 
      //	throw new IOException("Unsupported version "+version+" for EventHeader");
   }

   int getID()
   {
      return id;
   }
}
