package hep.io.mcfio;

import hep.io.xdr.XDRRandomAccessFile;

import java.io.IOException;


/**
 * The performance of XDRRandomAccessFile used directly is
 * pretty appaling. This is an "write-only" buffered implementation
 * that is much faster. 
 */
class BufferedRandomAccessFile extends XDRRandomAccessFile
{
   private byte[] buffer;
   private int offset; // Offset of buffer relative to base
   private int pos; // Current position in buffer
   private int used; // Number of bytes written to buffer

   BufferedRandomAccessFile(String name) throws IOException
   {
      super(name, "rw");
      buffer = new byte[8096];
      pos = 0;
      used = 0;
      offset = 0;
   }

   public long getFilePointer() throws IOException
   {
      return offset + pos;
   }

   public void close() throws IOException
   {
      flush();
      super.close();
      buffer = null;
   }

   public void flush() throws IOException
   {
      super.seek(offset);
      super.write(buffer, 0, used);
      offset += used;
      used = 0;
      pos = 0;
   }

   public int read() throws IOException
   {
      throw new IOException("Read not supported");
   }

   public int read(byte[] buf) throws IOException
   {
      throw new IOException("Read not supported");
   }

   public int read(byte[] buf, int start, int length) throws IOException
   {
      throw new IOException("Read not supported");
   }

   public void seek(long p1) throws IOException
   {
      if ((p1 >= offset) && (p1 <= (offset + used)))
      {
         pos = (int) p1 - offset;
      }
      else
      {
         flush();
         offset = (int) p1;
      }
   }

   public void write(byte[] buf, int start, int len) throws IOException
   {
      if ((buffer.length - pos) <= len)
      {
         System.arraycopy(buf, start, buffer, pos, len);
         pos += len;
         if (pos > used)
            used = pos;
      }
      else
      {
         used = pos;
         flush();
         super.write(buf, start, len);
         offset += len;
      }
   }

   public void write(byte[] buf) throws IOException
   {
      write(buf, 0, buf.length);
   }

   public void write(int b) throws IOException
   {
      if (pos == buffer.length)
         flush();
      buffer[pos++] = (byte) b;
      if (pos > used)
         used = pos;
   }
}
