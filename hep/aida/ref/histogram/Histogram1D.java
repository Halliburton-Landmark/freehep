package hep.aida.ref.histogram;

/**
 * Implementation of IHistogram1D.
 * @author The AIDA Team at SLAC.
 * @version $Id: Histogram1D.java,v 1.23 2005/10/31 23:58:28 serbo Exp $
 *
 */

import hep.aida.*;
import java.util.Map;
import hep.aida.ref.histogram.binner.*;
import hep.aida.ref.event.*;

public class Histogram1D extends Histogram implements IHistogram1D, IsObservable {
    
    /**
     * Create a 1-dimensional Histogram.
     *
     */
    public Histogram1D(){
        super("","",1, "");
    }
    
    /**
     * Create a 1-dimensional Histogram.
     * @param name The name of the Histogram as a ManagedObject.
     * @param title The title of the Histogram.
     * @param axis The x-axis of the Histogram.
     *
     */
    public Histogram1D(String name, String title, IAxis axis) {
        this(name,title,axis,"");
    }
    
    /**
     * Create a 1-dimensional Histogram.
     * @param name The name of the Histogram as a ManagedObject.
     * @param title The title of the Histogram.
     * @param axis The x-axis of the Histogram.
     * @param options options of the Histogram.
     *
     */
    protected Histogram1D(String name, String title, IAxis axis, String options) {
        super(name, title, 1, options);
        initHistogram1D(axis,options);
    }
    
    
    /**
     * Fill the Histogram with unit weight.
     * @param x The value to be filled.
     *
     */
    public void fill(double x) {
        fill(x,1.);
    }
    
    /**
     * Fill the Histogram.
     * @param x The value to be filled.
     * @param weight The weight for this entry.
     *
     */
    public void fill(double x, double weight) {
        if ( ! isFillable() ) throw new UnfillableHistogramException();
        allEntries++;
        if ( (! Double.isNaN(x)) && (!Double.isNaN(weight)) ) {
            int coordToIndex = xAxis.coordToIndex(x);
            int bin = mapBinNumber(coordToIndex, axis());
            binner1D.fill(bin, x, weight);
            
            if ( coordToIndex >= 0 || useOutflows() ) {
                validEntries++;
                mean += x*weight;
                rms  += x*x*weight;
                sumOfWeights += weight;
                sumOfWeightsSquared += weight*weight;
            }
        }
        
        if (isValid) fireStateChanged();
    }
    
    /**
     * Reset the Histogram. After calling this method the Histogram
     * is as it was just created.
     *
     */
    public void reset() {
        
        binner1D.clear();
        mean = 0;
        rms  = 0;
        super.reset();
    }
    
    /**
     * Get the number of entries in the underflow and overflow bins.
     * @return The number of entries outside the range of the Histogram.
     *
     */
    public int extraEntries() {
        return binEntries(IAxis.UNDERFLOW_BIN) + binEntries(IAxis.OVERFLOW_BIN);
    }
    
    /**
     * Get the sum of the bin heights for all the entries, in-range and out-range ones.
     * @return The sum of all the bin's heights.
     *
     */
    public double sumAllBinHeights() {
        double sum = 0;
        for (int i=xAxis.bins(); --i >= -2; )
            sum += binHeight(i);
        return sum;
    }
    
    /**
     * Get the sum of the bin heights for all the entries outside the Histogram's range.
     * @return The sum of the out of range bin's heights.
     *
     */
    public double sumExtraBinHeights() {
        return binHeight(IAxis.UNDERFLOW_BIN) + binHeight(IAxis.OVERFLOW_BIN);
    }
    
    /**
     * Get the minimum height of in-range bins in the Histogram.
     * @return The minimum bin height for in range bins.
     *
     */
    public double minBinHeight() {
        double min=Double.NaN;
        for(int i=0; i<xAxis.bins(); i++)
            if(Double.isNaN(min) || binHeight(i) <= min) min=binHeight(i);
        return min;
    }
    
    /**
     * Get the maximum height of in-range bins in the Histogram.
     * @return The maximum bin height for in range bins.
     *
     */
    public double maxBinHeight() {
        double max=Double.NaN;
        for(int i=0; i<xAxis.bins(); i++)
            if(Double.isNaN(max) || binHeight(i) >= max) max=binHeight(i);
        return max;
    }
    
    /**
     * Number of entries in the corresponding bin (ie the number of times fill was called for this bin).
     * @param index the bin number in the external representation: (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return The number of entries for the corresponding bin.
     *
     */
    public int binEntries(int index) {
        return binner1D.entries(mapBinNumber(index, axis()));
    }
    
    /**
     * Total height of the corresponding bin.
     * @param index The bin number in the external representation: (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return The bin height for the corresponding bin.
     *
     */
    public double binHeight(int index) {
        return binner1D.height(mapBinNumber(index, axis()));
    }
    
    /**
     * The error on this bin.
     * @param index the bin number in the external representation: (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return The error on the corresponding bin.
     *
     */
    public double binError(int index) {
        return binner1D.plusError(mapBinNumber(index, axis()));
    }
    
    
    /**
     * Get the mean of the whole Histogram. It includes all the entries (in and out of range).
     * @return The mean of the Histogram.
     *
     */
    public double mean() {
        if ( validEntries != 0 ) return mean/sumOfWeights;
        return 0;
    }
    
    /**
     * Get the RMS of the whole Histogram. It includes all the entries (in and out of range).
     * @return The RMS of the Histogram.
     *
     */
    public double rms(){
        if ( validEntries != 0 ) return Math.sqrt(rms/sumOfWeights - mean*mean/sumOfWeights/sumOfWeights);
        return 0;
    }
    
    /**
     * Get the X axis.
     * @return The x axis.
     *
     */
    public IAxis axis() {
        return xAxis;
    }
    
    /**
     * Convenience method, equivalent to <tt>axis().coordToIndex(coord)</tt>.
     * @see IAxis#coordToIndex(double)
     */
    public int coordToIndex(double coord) {
        return axis().coordToIndex(coord);
    }
    
    /**
     * Scale the weights and the errors by a given factor.
     *
     */
    public void scale(double scaleFactor) throws IllegalArgumentException {
        if ( scaleFactor <= 0 ) throw new IllegalArgumentException("Illegal scale factor "+scaleFactor+" it has to be positive");
        binner1D.scale(scaleFactor);
        mean *= scaleFactor;
        rms  *= scaleFactor;
        sumOfWeights *= scaleFactor;
        sumOfWeightsSquared *= scaleFactor*scaleFactor;
        if (isValid) fireStateChanged();
    }
    
    /**
     * Modifies this histogram by adding the contents of h to it.
     *
     * @param hist The histogram to be added to this histogram
     * @throws IllegalArgumentException if histogram binnings are incompatible
     */
    public void add(IHistogram1D hist) throws IllegalArgumentException {
        if (! axis().equals( hist.axis() ) ) throw new IllegalArgumentException("Cannot add. Incompatible histogram binning!");
        int bins = axis().bins()+2;
        
        double[] newHeights = new double[bins];
        double[] newErrors  = new double[bins];
        double[] newMeans   = new double[bins];
        double[] newRmss    = new double[bins];
        int[]    newEntries = new int   [bins];
        
        for(int i=IAxis.UNDERFLOW_BIN; i<bins-2;i++) {
            double height1 = binHeight(i);
            double height2 = hist.binHeight(i);
            double h       = height1+height2;
            double mean1   = binMean(i);
            double mean2   = hist.binMean(i);
            double m    = 0;
            double rms1 = binRms(i);
            double rms2 = ((Histogram1D)hist).binRms(i);
            double r    = 0;
            if ( h != 0 ) {
                m = ( mean1*height1 + mean2*height2 )/(height1+height2);
                r = Math.sqrt(((rms1*rms1*height1 + mean1*mean1*height1)+(rms2*rms2*height2 + mean2*mean2*height2))/h - m*m);
            }
            
            int bin = mapBinNumber(i,axis());
            newHeights[bin] = h;
            newErrors [bin] = Math.sqrt( Math.pow(binError(i),2) + Math.pow(hist.binError(i),2) );
            newEntries[bin] = binEntries(i)+hist.binEntries(i);
            newMeans  [bin] = m;
            newRmss   [bin] = r;
        }
        setContents(newHeights,newErrors,newEntries,newMeans,newRmss);
    }
    
    /**
     *
     * All the non-AIDA methods should go below this point.
     *
     */
    
    
    /**
     * Set the rms of the Histogram.
     * @param rms The Historam's x rms
     *
     */
    public void setRms( double rms ) {
        this.rms = rms*rms*sumOfWeights + mean()*mean()*sumOfWeights;
    }
    
    /**
     * Set the mean of the Histogram.
     * @param mean The Histogram's x mean
     *
     */
    public void setMean( double mean ) {
        this.mean = mean*sumOfWeights;
    }
    
    /**
     * Get the mean of a bin.
     * @param index The bin number in the external representation: (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return The mean of the corresponding bin. If the bin has zero height, zero is returned.
     *
     */
    public double binMean(int index) {
        double m = binner1D.mean(mapBinNumber(index, axis()));
        return Double.isNaN(m) ? axis().binCenter(index) : m;
    }
    
    /**
     * Get the RMS of a bin.
     * @param index the bin number in the external representation:(0...N-1) or OVERFLOW or UNDERFLOW.
     * @return The RMS of the corresponding bin. If the bin has zero height, zero is returned.
     *
     */
    //protected double binRms(int index) {
    public double binRms(int index) {
        double r = binner1D.rms(mapBinNumber(index, axis()));
        return Double.isNaN(r) ? axis().binWidth(index) : r;
    }
    
    public void setBinError(int bin, double error) {
        binner1D.setBinContent(mapBinNumber(bin,axis()), binEntries(bin), binHeight(bin), error, error, binMean(bin), binRms(bin));
    }
    
    /**
     * Set the content of the whole Histogram at once. This is a convenience method for saving/restoring Histograms.
     * Of the arguments below the heights array cannot be null. The errors array should in general be non-null, but this depends on
     * the specific binner.
     * The entries array can be null, in which case the entry of a bin is taken to be the integer part of the height.
     * If the means array is null, the mean is defaulted to the geometric center of the bin.
     * If the rms array is null, the rms is taken to be the bin width over the root of 12.
     *
     * @param heights The bins heights
     * @param errors The bins errors
     * @param entries The bin entries.
     * @param means The means of the bins.
     * @param rmss The rmss of the bins
     *
     */
    public void setContents(double[] heights, double[] errors, int[] entries, double[] means, double[] rmss ) {
        reset();
        for (int i=0; i<axis().bins()+2; i++) {
            int mi;
            if ( i == 0 )
                mi = IAxis.UNDERFLOW_BIN;
            else if ( i == axis().bins()+1 )
                mi = IAxis.OVERFLOW_BIN;
            else
                mi = i - 1;
            
            double h = heights[i];
            int e;
            if ( entries != null )
                e = entries[i];
            else
                e = (int) h;
            
            
            double m;
            if ( means != null )
                m = means[i];
            else
                m = (axis().binLowerEdge(mi)+axis().binUpperEdge(mi))/2.;
            
            double r;
            if ( rmss != null )
                r = rmss[i];
            else
                r = (axis().binUpperEdge(mi)-axis().binLowerEdge(mi))/Math.sqrt(12);
            
            binner1D.setBinContent(i, e, h, errors[i], errors[i], m, r);
            
            h = binner1D.height(i);
            
            allEntries += e;
            
            if ( mi >= 0 || useOutflows() ) {
                if ( ! Double.isNaN(m) && ! Double.isInfinite(m) ) {
                    mean   += m*h;
                    rms    += r*r*h + m*m*h;
                }
                validEntries += e;
                sumOfWeights += h;
                sumOfWeightsSquared += h*h;
            }
        }
    }
    
    public void initHistogram1D( IAxis xAxis, String options ) {
        this.xAxis = xAxis;
        Map optionMap = hep.aida.ref.AidaUtils.parseOptions( options );
        String type = (String) optionMap.get("type");
        if ( type == null || type.equals("default") )
            binner1D = new BasicBinner1D(xAxis.bins()+2);
        else if ( type.equals("efficiency") )
            binner1D = new EfficiencyBinner1D(xAxis.bins()+2);
        else
            throw new IllegalArgumentException("Wrong histogram type "+type);
        
        String useOutflowsString = (String) optionMap.get("useOutflowsInStatistics");
        if ( useOutflowsString != null )
            setUseOutflows( Boolean.valueOf(useOutflowsString).booleanValue() );
        reset();
    }
    
    private double mean = 0, rms = 0;
    private IAxis xAxis;
    private Binner1D binner1D;
    
}
