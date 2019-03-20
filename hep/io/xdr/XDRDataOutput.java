package hep.io.xdr;

import java.io.*;


/**
 * An interface implemented by output streams that support XDR.
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: XDRDataOutput.java,v 1.3 2003/09/16 23:11:55 tonyj Exp $
 */
public interface XDRDataOutput extends DataOutput
{
   void pad() throws IOException;

   void writeDoubleArray(double[] array) throws IOException;

   void writeDoubleArray(double[] array, int start, int n) throws IOException;

   void writeFloatArray(float[] array) throws IOException;

   void writeFloatArray(float[] array, int start, int n) throws IOException;

   void writeIntArray(int[] array) throws IOException;

   void writeIntArray(int[] array, int start, int n) throws IOException;

   /**
    * Write a string preceeded by its (int) length
    */
   void writeString(String string) throws IOException;

   /**
    * Write a string (no length is written)
    */
   void writeStringChars(String string) throws IOException;
}
