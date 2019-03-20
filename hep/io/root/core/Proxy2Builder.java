/*
 * Proxy2Builder.java
 *
 * Created on January 16, 2002, 11:49 AM
 */
package hep.io.root.core;


/**
 * @author tonyj
 * @version $Id: Proxy2Builder.java,v 1.2 2003/04/24 19:36:20 tonyj Exp $
 */
public class Proxy2Builder extends ProxyBuilder
{
   public Proxy2Builder()
   {
      super(false);
   }

   public String getStem()
   {
      return "hep.io.root.proxy2";
   }
}
