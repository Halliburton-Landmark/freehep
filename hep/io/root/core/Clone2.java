/*
 * Clone.java
 *
 * Created on January 5, 2002, 12:35 AM
 */
package hep.io.root.core;

import hep.io.root.*;


/**
 * A base class for a member of a ClonesArray read in split mode
 * @author Tony Johnson
 */
public abstract class Clone2 implements RootObject, hep.io.root.interfaces.TObject
{
   public abstract void setData(int index, Clones2 clones);

   public RootClass getRootClass()
   {
      Class klass = getClass();
      RootClassLoader loader = (RootClassLoader) klass.getClassLoader();
      return loader.getRootClass(klass);
   }
}
