/*
 * RmiClient.java
 *
 * Created on October 15, 2003, 12:50 AM
 */

package hep.aida.ref.remote.rmi.interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;

import hep.aida.ref.remote.interfaces.AidaUpdateEvent;

/**
 *
 * @author  serbo
 */

public interface RmiClient extends Remote {
    
    String getBindName() throws RemoteException;
    
    void stateChanged(AidaUpdateEvent[] events) throws RemoteException;

}
