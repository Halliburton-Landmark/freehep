package hep.io.mcfio;

import hep.io.xdr.*;

import java.io.IOException;


/**
 * An "event" read from an MCFIO file
 *
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: MCFIOEvent.java,v 1.3 2003/09/16 23:11:54 tonyj Exp $
 */
public interface MCFIOEvent
{
   MCFIOBlock getBlock(int index) throws IOException;

   int getBlockID(int index) throws IOException;

   int getEventNumber() throws IOException;

   int getNBlocks() throws IOException;

   int getRunNumber() throws IOException;

   int getStoreNumber() throws IOException;

   int getTrigMask() throws IOException;
}
