package hep.io.mcfio;

import java.io.IOException;


/**
 * An exception thrown for certain MCFIO specific errors.
 *
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: MCFIOException.java,v 1.3 2003/09/16 23:11:54 tonyj Exp $
 */
public class MCFIOException extends IOException
{
   MCFIOException(String message)
   {
      super(message);
   }
}
