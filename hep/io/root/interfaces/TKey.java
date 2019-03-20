package hep.io.root.interfaces;

import hep.io.root.*;
import java.io.IOException;


/**
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: TKey.java,v 1.11 2005/08/10 00:56:33 tonyj Exp $
 */
public interface TKey extends hep.io.root.RootObject, TNamed
{
   /**
    * Get the cycle number for this key
    */
   short getCycle();

   /**
    * Get the object associated with this key.
    */
   RootObject getObject() throws RootClassNotFound, IOException;

   /**
    * Get the class of the object associated with this key.
    */
   RootClass getObjectClass() throws RootClassNotFound, IOException;
}