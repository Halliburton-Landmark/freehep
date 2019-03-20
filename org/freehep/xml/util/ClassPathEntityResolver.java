// Copyright 2000-2003, SLAC, Stanford, California, U.S.A.
package org.freehep.xml.util;

import java.io.InputStream;
import org.xml.sax.EntityResolver;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;


/**
 * An implementation of an EntityResolver which can be used to locate
 * DTD files located on the current java class path
 *
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: ClassPathEntityResolver.java,v 1.5 2003/10/06 03:59:12 tonyj Exp $
 */
public class ClassPathEntityResolver implements EntityResolver
{
   private Class root;
   private String name;

   /**
    * Constructor
    * @param DTDName The DTDName to resolve
    * @param root A Class in the same package as the DTD
    */
   public ClassPathEntityResolver(String DTDName, Class root)
   {
      this.name = DTDName;
      this.root = root;
   }

   /*
    * Implementation of resolveEntity method
    */
   public InputSource resolveEntity(String publicId, String systemId) throws SAXException
   {
      if (systemId.endsWith(name))
      {
         InputStream in = root.getResourceAsStream(name);
         if (in == null) throw new SAXException(name+" not found");
         return new InputSource(in);
      }
      else
      {
         // use the default behaviour
         return null;
      }
   }
}
