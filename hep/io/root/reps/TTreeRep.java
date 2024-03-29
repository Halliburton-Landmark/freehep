/*
 * TTree.java
 *
 * Created on January 15, 2001, 6:58 PM
 */
package hep.io.root.reps;

import hep.io.root.core.AbstractRootObject;
import hep.io.root.interfaces.TBranch;


/**
 *
 * @author tonyj
 * @version $Id: TTreeRep.java,v 1.4 2004/06/28 15:21:25 tonyj Exp $
 */
public abstract class TTreeRep extends AbstractRootObject implements hep.io.root.interfaces.TTree
{
   public TBranch getBranch(int index)
   {
      return (TBranch) getBranches().get(index);
   }

   public TBranch getBranch(String name)
   {
      hep.io.root.interfaces.TObjArray branches = getBranches();

      // TODO: Something more efficient
      for (int i = 0; i < branches.size(); i++)
      {
         TBranch branch = (TBranch) branches.get(i);
         if (branch.getName().equals(name))
            return branch;
      }
      throw new RuntimeException("Branch " + name + " not found in tree " + getName());
   }

   public int getNBranches()
   {
      return getBranches().size();
   }
}
