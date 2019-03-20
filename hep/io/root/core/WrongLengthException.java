/*
 * WrongLengthException.java
 *
 * Created on January 2, 2002, 11:09 AM
 */
package hep.io.root.core;


/**
 *
 * @author tonyj
 * @version $Id: WrongLengthException.java,v 1.2 2003/04/24 19:36:20 tonyj Exp $
 */
public class WrongLengthException extends java.io.IOException
{
   public WrongLengthException(long offset, String className)
   {
      super("Unexpected Length for class " + className + " (offset " + offset + ")");
   }
}
