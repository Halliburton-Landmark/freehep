package hep.io.root;


/**
 * Exception thrown if a definition of a Root class can not be found
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: RootClassNotFound.java,v 1.6 2003/05/23 20:59:14 duns Exp $
 */
public class RootClassNotFound extends Exception
{
   private String name;

   public RootClassNotFound(String name)
   {
      super("Could not find definition for " + name);
      this.name = name;
   }

   public String getClassName()
   {
      return name;
   }
}
