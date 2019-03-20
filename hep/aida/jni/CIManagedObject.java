package hep.aida.jni;

import hep.aida.*;

 
public class CIManagedObject extends CProxy implements IManagedObject {

    public CIManagedObject(long crefID) {
        super(crefID);
    }

    public native String name();

//    public native String type();
} 
