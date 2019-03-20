/*
 * TObjArray.java
 *
 * Created on January 12, 2001, 3:45 PM
 */
package hep.io.root.interfaces;


/**
 *
 * @author tonyj
 * @version $Id: TObjArray.java,v 1.3 2003/04/24 19:36:21 tonyj Exp $
 */
public interface TObjArray extends hep.io.root.RootObject, TSeqCollection, java.util.List
{
   int getLowerBound();

   int getUpperBound();
}
