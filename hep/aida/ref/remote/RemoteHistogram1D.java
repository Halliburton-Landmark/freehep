/*
 * RemoteHistogram1D.java
 *
 * Created on May 28, 2003, 5:38 PM
 */

package hep.aida.ref.remote;

import hep.aida.IAnnotation;
import hep.aida.IHistogram1D;
import hep.aida.IManagedObject;
import hep.aida.IAxis;
import hep.aida.dev.IDevMutableStore;
import hep.aida.ref.Annotation;
import hep.aida.ref.ManagedObject;
import hep.aida.ref.ReadOnlyException;
import hep.aida.ref.histogram.FixedAxis;
import hep.aida.ref.histogram.UnfillableHistogramException;
import hep.aida.ref.event.IsObservable;
import hep.aida.ref.event.HistogramEvent;

/**
 * This is implementation of IHistogram1D that can not be modified
 * by the user. This is a simple implementation that does not guarantee
 * internal consistency. So extra care should be taken when setting
 * data for this class.
 * This Class is designed to work with the IDevMutableStore, but can
 * work with other Stores - overwrite makeSureDataIsValid() method.
 * Don't forget to call "setDataValid" after you fill new data, as
 * only this method fires events to notify AIDAListeners about change.
 *
 * Also please note that in our current AIDA implementation:
 *  UNDERFLOW_BIN = -2, OVERFLOW_BIN = -1, bins = [0, nBins-1]
 * But we keep them here as:
 *  UNDERFLOW_BIN = 0, OVERFLOW_BIN = nBins+1, bins = [1, nBins]
 * 
 * @author  serbo
 */
public class RemoteHistogram1D extends RemoteManagedObject implements IHistogram1D {
    
    private Annotation annotation = null;
    private IAxis axis = null;
    
    private double[] heights = null;
    private double[] errors = null;
    private int[] entries = null;
    private double[] means = null;
    private double[] rmss = null;
    
    private double mean = DEFAULT_DOUBLE;
    private double rms = DEFAULT_DOUBLE;
    private int inRangeEntries = DEFAULT_INT;
    private int nanEntries = DEFAULT_INT;
    private int minBinEntries = DEFAULT_INT;
    private int maxBinEntries = DEFAULT_INT;
    private double inRangeHeights = DEFAULT_DOUBLE;
    private double equivalentBinEntries = DEFAULT_DOUBLE;
    private double minBinHeights = DEFAULT_DOUBLE;
    private double maxBinHeights = DEFAULT_DOUBLE;
    
    
    /** Creates a new instance of RemoteHistogram1D */
    public RemoteHistogram1D(String name) {
        this(null, name);
    }
    
    public RemoteHistogram1D(IDevMutableStore store, String name) {
        this(store, name, name, 1, 0., 1.);
    }
    
    public RemoteHistogram1D(IDevMutableStore store, String name, String title, int bins, double min, double max) {
        super(name);
        aidaType = "IHistogram1D";
        this.store = store;
        annotation = new Annotation();
        annotation.setFillable(true);
        annotation.addItem(Annotation.titleKey,title,true);
        annotation.setFillable(false);
        dataIsValid = false;
        setAxis(bins, min, max);
    }
    
    
    // AIDAObservable methods
    protected java.util.EventObject createEvent()
    {
       return new HistogramEvent(this);
    }

    
    // Service methods
    
    private int convertAIDAIndex(int index) {
        int mi;
        if ( index == IAxis.UNDERFLOW_BIN )
            mi = 0;
        else if ( index == IAxis.OVERFLOW_BIN )
            mi = axis().bins()+1;
        else
            mi = index + 1;
        return mi;
    }
    
    public void setAxis(int bins, double min, double max) {
        axis = new FixedAxis(bins, min, max);
    }

    public void setEquivalentBinEntries(double d) {
        this.equivalentBinEntries = d;
    }
    
    public void setNanEntries(int i) {
        this.nanEntries = i;
    }
    
    public void setRms(double rms) {
        this.rms = rms;
    }
    
    public void setMean(double mean) {
        this.mean = mean;
    }
    
    public void setHeights(double[] h) {
        if (h == null || h.length == 0) {
            heights = null;
            inRangeHeights = DEFAULT_DOUBLE;
            minBinHeights = DEFAULT_DOUBLE;
            maxBinHeights = DEFAULT_DOUBLE;
            return;
        }
        heights = h;
        inRangeHeights = 0;
        minBinHeights = Double.MAX_VALUE;
        maxBinHeights = Double.MIN_VALUE;
        for (int i=1; i<h.length-1; i++) {
            inRangeHeights += h[i];
            if (h[i] > maxBinHeights) maxBinHeights = h[i];
            if (h[i] < minBinHeights) minBinHeights = h[i];
        }
    }

    public void setEntries(int[] h) {
        if (h == null || h.length == 0) {
            entries = null;
            inRangeEntries = DEFAULT_INT;
            minBinEntries = DEFAULT_INT;
            maxBinEntries = DEFAULT_INT;
            return;
        }
        entries = h;
        inRangeEntries = 0;
        minBinEntries = Integer.MAX_VALUE;
        maxBinEntries = Integer.MIN_VALUE;
        for (int i=1; i<h.length-1; i++) {
            inRangeEntries += h[i];
            if (h[i] > maxBinEntries) maxBinEntries = h[i];
            if (h[i] < minBinEntries) minBinEntries = h[i];
        }
    }

    public void setErrors(double[] h) {
        if (h == null || h.length == 0) {
            errors = null;
            return;
        }
        errors = h;
    }

    public void setMeans(double[] h) {
        if (h == null || h.length == 0) {
            means = null;
            return;
        }
        means = new double[h.length];
        System.arraycopy(h, 0, means, 0, h.length);
    }

    public void setRmss(double[] h) {
        if (h == null || h.length == 0) {
            rmss = null;
            return;
        }
        rmss = h;
    }

    public int[] getBinEntries() { return entries; }
    public double[] getBinHeights() { return heights; }
    public double[] getBinErrors() { return errors; }
    public double[] getBinMeans() { return means; }
    public double[] getBinRms() { return rmss; }
    
    
    // IHistogram1D methods
    public hep.aida.IAnnotation annotation() {
        makeSureDataIsValid();
        return annotation;
    }
    
    public hep.aida.IAxis axis() {
        makeSureDataIsValid();
        return axis;
    }
    
    public int dimension() {
        //makeSureDataIsValid();
        return 1;
    }
    
    public double mean() {
        makeSureDataIsValid();
        return mean;
    }
        
    public double rms() {
        makeSureDataIsValid();
        return rms;
    }
    
    public double equivalentBinEntries() {
        makeSureDataIsValid();
        if (entries == null) return DEFAULT_INT;
        return equivalentBinEntries;
    }
    
    public int entries() {
        makeSureDataIsValid();
        if (entries == null && heights != null) return (int) inRangeHeights;
        return inRangeEntries;
    }
    
    public int allEntries() {
        makeSureDataIsValid();
        if (entries == null) {
            if (heights != null) return (int) sumAllBinHeights();
            else return DEFAULT_INT;
        }
        return (entries() + extraEntries());
    }
    
    public int extraEntries() {
        makeSureDataIsValid();
        if (entries == null) {
            if (heights != null) return (int) (heights[0] + heights[heights.length-1]);
            else return DEFAULT_INT;
        }
        return (entries[0] + entries[entries.length-1]);
    }
    
    public int nanEntries() {
        makeSureDataIsValid();
        return nanEntries;
    }
    
    public double maxBinHeight() {
        makeSureDataIsValid();
        if ( heights == null && entries != null) return (double) maxBinEntries;
        return maxBinHeights;
    }
    
    public double minBinHeight() {
        makeSureDataIsValid();
        if ( heights == null && entries != null) return (double) minBinEntries;
        return minBinHeights;
    }

    public double sumAllBinHeights() {
        makeSureDataIsValid();
        if (heights == null) {
            if (entries != null) return (double) allEntries();
            else return DEFAULT_DOUBLE;
        }
        return (sumBinHeights() + sumExtraBinHeights());
    }
    
    public double sumBinHeights() {
        makeSureDataIsValid();
        if ( heights == null && entries != null) return (double) inRangeEntries;
        return inRangeHeights;
    }
    
    public double sumExtraBinHeights() {
        makeSureDataIsValid();
        if (heights == null) {
            if (entries != null) return (double) (entries[0] + entries[entries.length-1]);
            else return DEFAULT_DOUBLE;
        }
        return (heights[0] + heights[heights.length-1]);
    }
    
    public int binEntries(int param) throws java.lang.IllegalArgumentException {
        makeSureDataIsValid();
        if (entries == null) {
            if (heights != null) return (int) binHeight(param);
            else return DEFAULT_INT;
        }
        return entries[convertAIDAIndex(param)];
    }
    
    public double binError(int param) throws java.lang.IllegalArgumentException {
        makeSureDataIsValid();
        if (errors == null) return Math.sqrt(binHeight(param));
        return errors[convertAIDAIndex(param)];
    }
    
    public double binHeight(int param) throws java.lang.IllegalArgumentException {
        makeSureDataIsValid();
        if (heights == null) {
            if (entries != null) return (double) binEntries(param);
            else return DEFAULT_DOUBLE;
        }
        return heights[convertAIDAIndex(param)];
    }
    
    public double binMean(int param) throws java.lang.IllegalArgumentException {
        makeSureDataIsValid();
        double d = DEFAULT_DOUBLE;
        if (means == null) {
            if (param == IAxis.UNDERFLOW_BIN) d = Double.NEGATIVE_INFINITY;
            else if (param == IAxis.OVERFLOW_BIN) d = Double.POSITIVE_INFINITY;
            else d = axis.binCenter(param);
        } else
            d = means[convertAIDAIndex(param)];
        return d;
    }
    
   public double binRms(int param) {
        makeSureDataIsValid();
        double d = DEFAULT_DOUBLE;
        if (rmss == null) {
            if (param == IAxis.UNDERFLOW_BIN) d = DEFAULT_DOUBLE;
            else if (param == IAxis.OVERFLOW_BIN) d = DEFAULT_DOUBLE;
            else d = axis.binWidth(param)/rmsFactor;
        } else
            d = rmss[convertAIDAIndex(param)];
        return d;
    }    
    
    public int coordToIndex(double param) {
        makeSureDataIsValid();
        return axis.coordToIndex(param);
    }
    
    public String title() {
        //makeSureDataIsValid();
        return annotation.value(Annotation.titleKey);
    }
    
    public void setTitle(String title) throws java.lang.IllegalArgumentException {
        if (!fillable) throw new ReadOnlyException();
        annotation.setFillable(true);
        annotation.setValue(Annotation.titleKey,title);        
        annotation.setFillable(false);
    }
        

    public void add(hep.aida.IHistogram1D iHistogram1D) throws java.lang.IllegalArgumentException {
        throw new ReadOnlyException();
    }
    
    public void fill(double param) throws java.lang.IllegalArgumentException {
        throw new ReadOnlyException();
    }
    
    public void fill(double param, double param1) throws java.lang.IllegalArgumentException {
        throw new ReadOnlyException();
    }
    
    public void reset() throws java.lang.RuntimeException {
        throw new ReadOnlyException();
    }
    
    public void scale(double param) throws java.lang.IllegalArgumentException {
        throw new ReadOnlyException();
    }
    
}
