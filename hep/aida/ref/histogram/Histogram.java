package hep.aida.ref.histogram;
import hep.aida.ref.event.*;

/**
 * Implementation of IHistogram.
 * @author The AIDA Team at SLAC.
 * @version $Id: Histogram.java,v 1.14 2005/06/04 00:38:02 turri Exp $
 *
 */

import hep.aida.*;

public abstract class Histogram extends AbstractBaseHistogram implements IHistogram, IsObservable
{
    protected final static int X_AXIS = 0;
    protected final static int Y_AXIS = 1;
    protected final static int Z_AXIS = 2;
    
    protected int allEntries = 0;
    protected int validEntries = 0;
    protected double sumOfWeights = 0;
    protected double sumOfWeightsSquared = 0;
    protected boolean isFillable = true;
    private String options;
    
    private boolean useOutflows = false;
    
    /**
     * Create a new Histogram.
     * @param name The name of the Histogram as a ManagedObject.
     * @param title The title of the Histogram.
     * @param dimension The dimension of the Histogram.
     *
     */
    protected Histogram(String name, String title, int dimension, String options) {
        super(name, title, dimension, options);        
        this.options = options;
    }
    protected java.util.EventObject createEvent()
    {
       return new HistogramEvent(this);
    }
    /**
     * Reset the Histogram. After calling this method the Histogram
     * is as it was just created.
     *
     */
    public void reset() {
        super.reset();
        allEntries = 0;
        validEntries = 0;
        isFillable = true;
        sumOfWeights = 0;
        sumOfWeightsSquared = 0;
        if (isValid) fireStateChanged();
    }

    /**
     * Get the entries that are within the range of the Histogram;
     * i.e. all the entries (the number of times the fill method was called)
     * minus the entries in the overflow or underflow bins.
     * @return The in-range entries.
     *
     */
    public int entries() {
        return validEntries;
    }
    
    /**
     * Get all the entries in the Histogram, i.e. the number of times the method
     * fill was called.
     * @return All the entries in the Histogram.
     *
     */
    public int allEntries() {
        return allEntries;
    }
    
    /**
     * Get the number of entries in the underflow and overflow bins.
     * @return The number of entries outside the range of the Histogram.
     *
     */
    abstract public int extraEntries();
    
    /**
     * Get the number of equivalent entries; i.e. <tt>SUM[ weight ] ^ 2 / SUM[ weight^2 ]</tt>.
     * @return The equivalent bin entries.
     *
     */    
    public double equivalentBinEntries() {
	if ( validEntries != 0 ) return sumOfWeights*sumOfWeights/sumOfWeightsSquared;
	return 0;
    }
    
    /**
     * Get the sum of the bin heights for in-range entries.
     * @return The sum of the bin heights.
     *
     */
    public double sumBinHeights() {
        return sumAllBinHeights()-sumExtraBinHeights();
    }
    
    /**
     * Get the sum of the bin heights for all the entries, in-range and out-range ones.
     * @return The sum of all the bin's heights.
     *
     */
    abstract public double sumAllBinHeights();
    
    /**
     * Get the sum of the bin heights for all the entries outside the Histogram's range.
     * @return The sum of the out of range bin's heights.
     *
     */
    abstract public double sumExtraBinHeights();
    
    /**
     * Get the minimum height of in-range bins in the Histogram.
     * @return The minimum bin height for in range bins.
     *
     */    
    abstract public double minBinHeight();

    /**
     * Get the maximum height of in-range bins in the Histogram.
     * @return The maximum bin height for in range bins.
     *
     */    
    abstract public double maxBinHeight();
    
    /**
     * Scale the weights and the errors by a given factor.
     * @param scaleFactor The scale factor.
     *
     */
    abstract public void scale(double scaleFactor);
    
    /**
     *
     *  Developer area. All the non-AIDA methods are down here.
     *
     */
    
   
    /**
     * Utility method to map the bin number from the external representation (from -2 to nBins-1 where -2 is the overflow and -1 is the underflow)
     * to the internal one (from 0 to nBins+1 where 0 is the underflow and nBins+1 if the overflow bin)
     * @param index The bin number in the external representation.
     * @param axis  The axis to which the bin belongs to.
     * @return The bin number in the internal representation.
     *
     */
    protected int mapBinNumber(int index, IAxis axis) {
        int bins = axis.bins()+2;
        if (index >= bins) throw new IllegalArgumentException("bin="+index);
        if (index >= 0) return index+1;
        if (index == IAxis.UNDERFLOW_BIN) return 0;
        if (index == IAxis.OVERFLOW_BIN) return bins-1;
        throw new IllegalArgumentException("bin="+index);
    }
    public void setNEntries(int entries)
    {
       allEntries = entries;
    }
    
    public void setValidEntries(int entries) {
       //FIXME this is not pretty. It is here for histograms from ROOT or
       //HBOOK as they don't have enough info to distinguish between allEntries
       //and valid entries.
       validEntries = entries;
    }

    protected String options() {
        return options;
    }
    
    protected boolean useOutflows() {
        return useOutflows;
    }
    
    protected void setUseOutflows(boolean useOutflows) {
        this.useOutflows = useOutflows;
    }

    public int nanEntries() {
        return allEntries()-entries()-extraEntries();
    }
}
