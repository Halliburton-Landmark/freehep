package hep.aida.ref.xml;

import hep.aida.dev.*;

/**
 * An implementation of IStoreFactory that creates Aida XML Store.
 */
public class AidaXMLStoreFactory implements IStoreFactory
{   
    public String description()
    {
       return "xml";
    }    
    public boolean supportsType(String type)
    {
       return "xml".equalsIgnoreCase(type);
    }
    public IStore createStore()
    {
       return new AidaXMLStore();
    }
}
