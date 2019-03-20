// Copyright 2000, CERN, Geneva, Switzerland
package hep.physics.yappi;

/**
 * @author Mark Donszelmann
 * @version	$Id: DecayGroup.java,v 1.1 2001/01/09 14:46:31 duns Exp $
 * 
 */

public class DecayGroup {
    
    private String name;
    	
    public DecayGroup(String name) {
        this.name = name;
    }

    /**
     * @return Name of the group
     */
    public String getName() {
    	return name;
    }
}