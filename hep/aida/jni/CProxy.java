package hep.aida.jni;

public class CProxy extends CAIDRef {

    public CProxy(long crefID) {
        super(crefID);
    }
    
    protected void finalize() throws Throwable {
        finalize(crefID);
        crefID = -1;
    }
    
    protected native void finalize(long crefID);
}
