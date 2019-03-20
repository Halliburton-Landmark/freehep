/*
 * RemoteProfile1D.java
 *
 * Created on October 28, 2004, 11:18 AM
 */

package hep.aida.ref.remote;

import hep.aida.*;
import hep.aida.dev.*;

import hep.aida.ref.ReadOnlyException;

/**
 *
 * @author  serbo
 */
public class RemoteProfile1D extends RemoteHistogram1D implements IProfile1D {
    
    /** Creates a new instance of RemoteProfile1D */
    public RemoteProfile1D(String name) {
        this(null, name);
    }
    
    public RemoteProfile1D(IDevMutableStore store, String name) {
        this(store, name, name, 50, 0., 1.);
    }
    
    public RemoteProfile1D(IDevMutableStore store, String name, String title, int bins, double min, double max) {
        super(store, name, title, bins, min, max);
        aidaType = "IProfile1D";
    }
    
    
    // Service methods
    
     
    // IProfile1D methods
    
    public double equivalentBinEntries() {
        throw new ReadOnlyException();
    }
    
     public void add(hep.aida.IProfile1D iProfile1D) throws java.lang.IllegalArgumentException {
          throw new ReadOnlyException();
   }
    
    public void fill(double param, double param1, double param2) throws java.lang.IllegalArgumentException {
        throw new ReadOnlyException();
    }
    
}
