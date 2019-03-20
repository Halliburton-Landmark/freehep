// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.swf;

import java.util.Hashtable;
import java.util.Enumeration;

/**
 * SWF Definition Dictionary, which stores definitions being read from a stream.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: SWFDictionary.java,v 1.1 2001/11/29 01:45:32 duns Exp $
 */
public class SWFDictionary extends Hashtable {

    public void put(int id, DefinitionTag tag) {
        put(new Integer(id), tag);
    }

    public DefinitionTag get(int id) {
        return (DefinitionTag)get(new Integer(id));
    }
    
    public void remove(int id) {
        remove(new Integer(id));
    }
    
    public String toString() {
        StringBuffer s = new StringBuffer("SWF Dictionary\n");
        for (Enumeration e = keys(); e.hasMoreElements(); ) {
            Integer key = (Integer)e.nextElement();
            s.append("  ["+key.intValue()+"] ");
            s.append(get(key));
            s.append("\n");
        }
        return s.toString();
    }        
}
