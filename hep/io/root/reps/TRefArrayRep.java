package hep.io.root.reps;

import hep.io.root.core.AbstractRootObject;
import hep.io.root.core.RootInput;
import hep.io.root.interfaces.TObject;

import java.io.IOException;


/**
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: TRefArrayRep.java,v 1.4 2004/06/28 15:21:25 tonyj Exp $
 */
public abstract class TRefArrayRep extends AbstractRootObject implements hep.io.root.interfaces.TObjArray
{
   private String fName;
   private TObject fObject;
   private int[] fUIDs;
   private int fLowerBound;
   private int fNobjects;
   private int fSize;
   private short fPID;

   public int getLowerBound()
   {
      return fLowerBound;
   }

   public int getUpperBound()
   {
      return fLowerBound + fNobjects;
   }

   public void readMembers(RootInput in) throws IOException
   {
      int v = in.readVersion(this);
      fObject = (TObject) in.readObject("TObject");
      fName = in.readObject("TString").toString();
      fNobjects = in.readInt();
      fLowerBound = in.readInt();
      fUIDs = new int[fNobjects];
      fSize = 0;
      fPID = in.readShort();
      for (int i = 0; i < fNobjects; i++)
      {
         fUIDs[i] = in.readInt();
         if (fUIDs[i] != 0)
            fSize = i + 1;
      }
      in.checkLength(this);
   }
}
