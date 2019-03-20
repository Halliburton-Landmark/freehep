package hep.io.root.core;

import hep.io.root.*;
import hep.io.root.interfaces.*;

import java.util.*;


/**
 *
 * @author tonyj
 * @version $Id: SingleLeaf.java,v 1.2 2003/04/24 19:36:20 tonyj Exp $
 */
public class SingleLeaf extends AbstractList implements TObjArray
{
   private TLeaf leaf;

   public SingleLeaf(TLeaf leaf)
   {
      this.leaf = leaf;
   }

   public int getBits()
   {
      return 0;
   }

   public Object getElementAt(int index)
   {
      return leaf;
   }

   public int getLast()
   {
      return 1;
   }

   public int getLowerBound()
   {
      return 0;
   }

   public String getName()
   {
      return null;
   }

   public RootClass getRootClass()
   {
      return null;
   }

   public int getSize()
   {
      return 1;
   }

   public String getTitle()
   {
      return null;
   }

   public int getUniqueID()
   {
      return 0;
   }

   public int getUpperBound()
   {
      return 1;
   }

   public Object get(int index)
   {
      return leaf;
   }

   public int size()
   {
      return 1;
   }
}