/*
 * OneDBinner.java
 *
 * Created on July 18, 2002, 5:02 PM
 */

package hep.aida.ref.histogram.binner;

/**
 *
 * @author  The AIDA team at SLAC
 *
 */
public interface Binner1D {
    
    public void fill( int bin, double x, double weight);    
    public void clear();
    public int entries(int bin);
    public double height(int bin);
    public double plusError(int bin);
    public double minusError(int bin);
    public double mean(int bin);
    public double rms(int bin);
    public void setBinContent(int bin, int entries, double height, double plusError, double minusError, double mean, double rms);
    public void scale(double scaleFactor);
}
