/*
 * ReadOnlyException.java
 *
 * Created on November 1, 2002, 12:12 PM
 */

package hep.aida.ref;

/**
 * An exception thrown when an attempt is made to modify a readOnly AIDA object.
 * @author tonyj
 * @version $Id: ReadOnlyException.java,v 1.1 2002/11/02 01:58:31 tonyj Exp $
 */
public class ReadOnlyException extends RuntimeException
{
   public ReadOnlyException()
   {
      super("Attempt to modify readonly AIDA object");
   }
}