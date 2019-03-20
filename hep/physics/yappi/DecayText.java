// Copyright 2000, CERN, Geneva, Switzerland
package hep.physics.yappi;

/**
 * Class <code>DecayText</code> implementing <code>DecayProduct</code>
 * @see ParticleType 
 * @see DecayProduct 
 * @see Family
 * @author	Patrick Hellwig
 * @version	$Id: DecayText.java,v 1.3 2000/12/06 07:44:48 duns Exp $
 * 
 */
import java.util.*;

public class DecayText extends DecayProduct
{
	public DecayText(String name)
	{
	    super(name);
    }

    public String getType()
    {
    	return "Text";
    }    	
   
    public String toString() {
        return getType()+": "+getName();
    }
}