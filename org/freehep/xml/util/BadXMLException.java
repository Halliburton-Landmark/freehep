package org.freehep.xml.util;

import org.xml.sax.SAXException;

/**
 * A SAXException with an optional nested exception
 * @author tonyj
 * @version $Id: BadXMLException.java,v 1.2 2004/04/06 20:06:08 tonyj Exp $
 */

public class BadXMLException extends SAXException
{
   public BadXMLException(String message)
   {
      super(message);
   }
   public BadXMLException(String message, Throwable detail)
   {
      super(message);
      initCause(detail);
   }
}
