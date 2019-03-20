package hep.aida.hbook;

/**
 * @author Mark Donszelmann
 * @version $Id: WeightFunction.java,v 1.1 2001/03/27 15:46:57 duns Exp $
 */
public class WeightFunction {

    long functionPtr;

    WeightFunction(long function) {
        this.functionPtr = function;
    }
    
    public native float weight(float x, int isel);
    
    public native float weight(float x, float y, int isel);
}
