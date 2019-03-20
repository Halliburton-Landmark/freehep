package hep.io.root.interfaces;


/**
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: TDirectory.java,v 1.10 2005/08/10 00:56:33 tonyj Exp $
 */
public interface TDirectory extends hep.io.root.RootObject, TNamed
{
   public java.util.Date getDatimeC();

   public java.util.Date getDatimeM();

   public int getNbytesKeys();

   public int getNbytesName();

   public long getSeekDir();

   public long getSeekKeys();

   public long getSeekParent();

   TKey getKey(int index);

   /**
    * Gets the key for a specific name.
    * Assumes the highest cycle.
    */
   TKey getKey(String name);

   /**
    * Gets the key for a specific name and cycle
    */
   TKey getKey(String name, int cycle);

   TKey getKeyForTitle(String title);

   int nKeys();
}
