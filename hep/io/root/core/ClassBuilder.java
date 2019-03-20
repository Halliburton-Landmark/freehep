/*
 * ClassBuilder.java
 *
 * Created on December 20, 2001, 6:22 PM
 */
package hep.io.root.core;

import org.apache.bcel.classfile.JavaClass;


/**
 * Interface implemented by all class builders
 * @author tonyj
 * @version $Id: ClassBuilder.java,v 1.2 2003/04/24 19:36:19 tonyj Exp $
 */
public interface ClassBuilder
{
   String getStem();

   JavaClass build(GenericRootClass name);
}
