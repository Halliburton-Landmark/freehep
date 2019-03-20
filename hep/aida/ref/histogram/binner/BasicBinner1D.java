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
public class BasicBinner1D implements Binner1D{
    
    private int[] entries;
    private double[] heights;
    private double[] plusErrors;
    private double[] means;
    private double[] rmss;
    
    private int bins;
    
    /**
     * Creates a new instance of OneDBinner.
     *
     */
    public BasicBinner1D(int bins) {
        if (bins < 0) throw new IllegalArgumentException("Number of bins cannot be negative!!! "+bins);
        setNumberOfBins(bins);
    }
    
    public void fill( int bin, double x, double weight) {
        entries[bin]++;
        heights[bin]    += weight;
        plusErrors[bin] += weight*weight;
        means[bin]      += x*weight;
        rmss[bin]       += x*x*weight;
    }
    
    public void clear() {
        createArrays( bins );
    }
    
    private void setNumberOfBins( int bins ) {
        this.bins = bins;
        createArrays(bins);
    }
    
    public int entries(int bin) {
        return entries[bin];
    }
    
    public double height(int bin) {
        return heights[bin];
    }
    
    public double plusError(int bin) {
        return Math.sqrt(plusErrors[bin]);
    }
    
    public double minusError(int bin) {
        return plusError(bin);
    }
    
    public double mean(int bin) {
        double h = height(bin);
        if ( h != 0 ) return means[bin]/h;
        return Double.NaN;
    }
    
    public double rms(int bin) {
        double h = height(bin);
        double m = mean(bin);
        if ( h != 0 ) return Math.sqrt( Math.abs(rmss[bin]/h - m*m) );
        return Double.NaN;
    }
    
    public void setBinContent(int bin, int entries, double height, double plusError, double minusError, double mean, double rms) {
        this.entries[bin] = entries;

        if ( ! Double.isNaN(height) )
            heights[bin] = height;
        else
            heights[bin] = entries;

        if ( ! Double.isNaN(plusError) )
            plusErrors[bin] = plusError*plusError;
        else
            plusErrors[bin] = entries;
        
        means[bin] = 0;
        rmss[bin] = 0;
        if ( height != 0 ) {
            means[bin] = mean*height;
            rmss[bin] = rms*rms*height + mean*mean*height;
        }
    }
    
    public void scale( double scaleFactor ) {
        for ( int bin = 0; bin < bins; bin++ ) {
            heights[bin]    *= scaleFactor;
            plusErrors[bin] *= scaleFactor*scaleFactor;
            means[bin]      *= scaleFactor;
            rmss[bin]       *= scaleFactor;
        }
    }
    
    private void createArrays( int n ) {
        entries = new int[n];
        heights = new double[n];
        plusErrors = new double[n];
        means = new double[n];
        rmss = new double[n];
    }
}
