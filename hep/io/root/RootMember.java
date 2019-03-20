package hep.io.root;


/**
 * Represents a single member of a RootClass
 * @author tonyj
 * @version $Id: RootMember.java,v 1.6 2005/08/10 00:56:29 tonyj Exp $
 */
public interface RootMember
{
   public int getArrayDim();

   public String getComment();

   public String getName();

   public RootClass getType();

   public Object getValue(RootObject object);
}
