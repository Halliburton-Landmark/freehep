package hep.io.root;

/**
 * A representation of a RootObject
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: RootObject.java,v 1.4 2004/06/28 15:21:21 tonyj Exp $
 */
public interface RootObject
{
   /**
    * Get the class of this object
    * @return The RootClass for this object
    */
   RootClass getRootClass();
}
