package hep.aida.ref.tree;
import hep.aida.*;
import java.util.Map;
import java.util.Iterator;

/**
 * A Link is a managed object representing a symbolic link.
 * It is used only within the Tree implementation, and is never exposed
 * to the user.
 * @author  The AIDA team @ SLAC.
 * @version $Id: Link.java,v 1.2 2005/06/04 00:38:12 turri Exp $
 */
public class Link extends hep.aida.ref.ManagedObject {

    private Path path;
    private boolean isBroken = false;

    Link(String name, Path path) {
      super(name);
      this.path = path;
    }
    
    Path path() {
        return path;
    }
    
    boolean isBroken() {
        return isBroken;
    }
    
    private void setIsBroken( boolean isBroken ) {
        this.isBroken = isBroken;
    }    
    
    public String type()
    {
        return "lnk";
    }
    
}
