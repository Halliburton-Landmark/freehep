/*
 * TListIterator.java
 *
 * Created on January 3, 2002, 11:31 AM
 */
package hep.io.root.core;

/**
 * @author tonyj
 * @version $Id: TListIterator.java,v 1.2 2003/04/24 19:36:20 tonyj Exp $
 */
public class TListIterator implements java.util.ListIterator
{
   private Object[] fArray;
   private int fSize;
   private int index;

   public TListIterator(Object[] array, int size, int start)
   {
      index = start;
      fSize = size;
      fArray = array;
   }

   public void add(Object obj)
   {
      throw new UnsupportedOperationException();
   }

   public boolean hasNext()
   {
      return index < fSize;
   }

   public boolean hasPrevious()
   {
      return index > 0;
   }

   public Object next()
   {
      return fArray[index++];
   }

   public int nextIndex()
   {
      return index;
   }

   public Object previous()
   {
      return fArray[--index];
   }

   public int previousIndex()
   {
      return index - 1;
   }

   public void remove()
   {
      throw new UnsupportedOperationException();
   }

   public void set(Object obj)
   {
      throw new UnsupportedOperationException();
   }
}
