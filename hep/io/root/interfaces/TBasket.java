package hep.io.root.interfaces;

import java.io.IOException;


/**
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: TBasket.java,v 1.5 2005/05/17 05:13:55 tonyj Exp $
 */
public interface TBasket extends hep.io.root.RootObject, TKey
{
   int getBufferSize();

   int[] getDisplacement();

   int[] getEntryOffset();

   byte getFlag();

   int getLast();

   int getNevBuf();

   int getNevBufSize();

   //Extra methods
   hep.io.root.core.RootInput setPosition(long index, long basketEntry, TLeaf leaf) throws IOException;

   void readEntryOffsets(int len) throws IOException;
}
