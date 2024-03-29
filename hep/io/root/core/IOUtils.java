package hep.io.root.core;
import java.io.IOException;
/**
 *
 * @author tonyj
 * @version $Id: IOUtils.java,v 1.1 2005/08/10 00:56:31 tonyj Exp $
 */
public class IOUtils
{
   public static void readVariableMultiArray(RootInput in, float[][] source, int[] lengths) throws IOException
   {
      for (int i=0; i<lengths.length; i++)
      {
         byte b = in.readByte();
         if (b == 0) continue;
         int l = lengths[i];
         source[i] = new float[l];
         in.readFixedArray(source[i]);
      }
   }
   public static void readFixedArray(RootInput in, Object[] data, String type) throws IOException
   {
      int n = data.length;
      for (int i = 0; i < n; i++)
         data[i] = in.readObject(type);
   }
}
