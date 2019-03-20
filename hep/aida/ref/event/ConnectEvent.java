package hep.aida.ref.event;
import hep.aida.*;

/**
 * An event send to AIDAListeners if connection between AIDA object
 * and it's data provider is re-open
 * @author tonyj
 * @version $Id: ConnectEvent.java,v 1.1 2005/11/01 02:08:32 serbo Exp $
 */
public class ConnectEvent extends java.util.EventObject {
    protected boolean connected;
    
    public ConnectEvent(Object source) {
        this(source, true);
    }
    public ConnectEvent(Object source, boolean connected) {
        super(source);
        this.connected = connected;
    }

    public void setConnected(boolean connected) { this.connected = connected; }
    
    public boolean isConnected() { return connected; }
}
