package hep.io.root.reps;

import hep.io.root.core.AbstractRootObject;
import hep.io.root.core.RootInput;

import java.io.IOException;


/**
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: TStringRep.java,v 1.4 2004/06/28 15:21:25 tonyj Exp $
 */
public abstract class TStringRep extends AbstractRootObject implements hep.io.root.interfaces.TString
{
   private String string;

   public void readMembers(RootInput in) throws IOException
   {
      int l = in.readUnsignedByte();
      if (l == 255)
         l = in.readInt();

      byte[] chars = new byte[l];
      for (int i = 0; i < l; i++)
         chars[i] = in.readByte();
      string = new String(chars);
   }

   public String toString()
   {
      return string;
   }
}
