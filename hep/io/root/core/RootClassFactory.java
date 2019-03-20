package hep.io.root.core;

import hep.io.root.*;


/**
 * Creates RootClass objects
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: RootClassFactory.java,v 1.4 2003/05/23 20:59:15 duns Exp $
 */
public interface RootClassFactory
{
   RootClassLoader getLoader();

   BasicRootClass create(String name) throws RootClassNotFound;
}
