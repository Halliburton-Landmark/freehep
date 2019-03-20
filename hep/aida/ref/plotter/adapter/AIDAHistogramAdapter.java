package hep.aida.ref.plotter.adapter;

import jas.hist.*;
import hep.aida.ref.*;
import hep.aida.ref.event.*;
import hep.aida.*;
import java.util.Observer;
import java.util.Observable;
/**
 * Creates a datasource from an IHistogram
 * @author  manj
 * @version $Id: AIDAHistogramAdapter.java,v 1.8 2005/07/29 17:21:00 serbo Exp $
 */
abstract class AIDAHistogramAdapter extends ObserverAdapter implements DataSource {
    /**
     * Create a DataSource from a Histogram
     */
    public static DataSource create(IHistogram h) {
        AIDAHistogramAdapter result;
        
        if      (h instanceof IHistogram1D) result = new AIDAHistogramAdapter1D((IHistogram1D)h);
        else if (h instanceof IHistogram2D) result = new AIDAHistogramAdapter2D((IHistogram2D)h);
        else throw new IllegalArgumentException("Argument is an unsupported subtype of IHistogram");
        return result;
    }
    
    protected AIDAHistogramAdapter(IHistogram h) {
        super(h);
        update = hu;
    }
    
    protected int xAxisType = DOUBLE;
    protected int yAxisType = DOUBLE;
    
    private final static jas.hist.HistogramUpdate hu = new jas.hist.HistogramUpdate(HistogramUpdate.TITLE_UPDATE+HistogramUpdate.DATA_UPDATE+HistogramUpdate.RANGE_UPDATE,false);
    static {
        hu.setAxis(hu.HORIZONTAL_AXIS);
        hu.setAxis(hu.VERTICAL_AXIS);
    }
    
}
