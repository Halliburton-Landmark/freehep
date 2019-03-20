package hep.io.root.classes;

import hep.io.root.core.*;

import org.apache.bcel.generic.*;


/**
 *
 * @author Tony Johnson
 * @version $Id: TString.java,v 1.2 2003/04/24 19:36:19 tonyj Exp $
 */
public class TString extends GenericRootClass
{
   /** Creates a new instance of TSTring */
   public TString(String name, StreamerInfo info)
   {
      super(name, info);
   }

   /**
    * The method used to convert the object to its method type.
    */
   protected String getConvertMethod()
   {
      return "toString";
   }

   /**
    * The type that will be used when this class is stored as a member, or as a return
    * type from a method.
    */
   protected Type getJavaTypeForMethod()
   {
      return Type.STRING;
   }
}
