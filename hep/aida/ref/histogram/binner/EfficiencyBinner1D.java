/*
 * EfficiencyBinner1D.java
 *
 * Created on July 22, 2002, 10:19 AM
 */

package hep.aida.ref.histogram.binner;

/**
 *
 * @author  The AIDA team at SLAC.
 *
 */
public class EfficiencyBinner1D implements Binner1D {
    
    private int bins;
    private int[] entries;
    private double[] heights;
    private double[] plusErrors;
    private double[] minusErrors;
    private double[] means;
    private double[] rmss;
    
    /**
     * Creates a new instance of EfficiencyBinner1D.
     */
    
    public EfficiencyBinner1D(int bins) {
        if (bins < 0) throw new IllegalArgumentException("Number of bins cannot be negative!!! "+bins);
        setNumberOfBins(bins);
    }
    
    public void fill( int bin, double x, double weight) {
        if ( weight < 0 || weight > 1 ) throw new IllegalArgumentException("Wrong weight "+weight+" !! It has to be between 0 and 1");
        entries[bin]++;
        heights[bin]  += weight;
        means[bin]    += x*weight;
        rmss[bin]     += x*x*weight;
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
        if ( entries(bin) > 0 )
            return heights[bin]/entries(bin);
        return 0;
    }
    
    
    public double plusError(int bin) {
        return EfficiencyBinnerUtils.H95CL(heights[bin],entries[bin],1);
    }
    
    public double minusError(int bin) {
        return EfficiencyBinnerUtils.H95CL(heights[bin],entries[bin],2);
    }
    
    public double mean(int bin) {
        double h = heights[bin];
        if ( h != 0 ) return means[bin]/h;
        return Double.NaN;
    }
    
    public double rms(int bin) {
        double h = heights[bin];
        double m = mean(bin);
        if ( h != 0 ) return Math.sqrt( Math.abs(rmss[bin]/h - m*m) );
        return Double.NaN;
    }
    
    public void setBinContent(int bin, int entries, double height, double plusError, double minusError, double mean, double rms) {

        this.entries[bin] = entries;

        if ( ! Double.isNaN(height) )
            heights[bin] = height*entries;
        else
            heights[bin] = entries*entries;
        
        means[bin] = 0;
        rmss[bin] = 0;
        if ( heights[bin] != 0 ) {
            means[bin] = mean*heights[bin];
            rmss[bin] = rms*rms*heights[bin] + mean*mean*heights[bin];
        }
    }

    public void scale( double scaleFactor ) {
        for ( int bin = 0; bin < bins; bin++ ) {
            heights[bin]    *= scaleFactor;
            means[bin]      *= scaleFactor;
            rmss[bin]       *= scaleFactor;
        }
    }
    
    private void createArrays( int n ) {
        entries = new int[n];
        heights = new double[n];
        plusErrors = new double[n];
        minusErrors = new double[n];
        means = new double[n];
        rmss = new double[n];
    }    
}

