package hep.io.root.core;

import java.io.*;


/**
 * A ByteArrayInputStream that will reveal its current
 * position.
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: RootByteArrayInputStream.java,v 1.3 2003/05/23 20:59:14 duns Exp $
 */
class RootByteArrayInputStream extends ByteArrayInputStream
{
   private int offset;

   /**
    * @param buf The buffer from which to read
    */
   public RootByteArrayInputStream(byte[] buf, int offset)
   {
      super(buf);
      this.offset = offset;
   }

   void setOffset(int offset)
   {
      this.offset = offset;
   }

   void setPosition(long pos)
   {
      this.pos = (int) pos - offset;
   }

   long getPosition()
   {
      return pos + offset;
   }
}
