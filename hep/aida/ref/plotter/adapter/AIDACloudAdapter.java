package hep.aida.ref.plotter.adapter;

import jas.hist.*;
import hep.aida.ref.*;
import hep.aida.ref.event.*;
import hep.aida.*;
import java.util.Observer;
import java.util.Observable;

/**
 *
 * @author  manj
 * @version $Id: AIDACloudAdapter.java,v 1.7 2005/05/11 19:28:00 serbo Exp $
 */
abstract class AIDACloudAdapter extends ObserverAdapter implements DataSource
{
    /**
    * Create a DataSource from a Cloud
    */
   public static DataSource create(ICloud c)
   {
      AIDACloudAdapter result;
      if      (c instanceof ICloud1D) result = new AIDACloudAdapter1D((ICloud1D)c);
      else if (c instanceof ICloud2D) result = new AIDACloudAdapter2D((ICloud2D)c);
      else throw new IllegalArgumentException("Argument is an unknown subtype of ICloud");
  
      return result;
   }
   protected AIDACloudAdapter(ICloud h)
   {
       super(h);
       update = hr;
       
   }
   
   protected int xAxisType = DOUBLE;
   protected int yAxisType = DOUBLE;
    
   private final static jas.hist.HistogramUpdate hr = new jas.hist.HistogramUpdate(HistogramUpdate.TITLE_UPDATE+HistogramUpdate.DATA_UPDATE+HistogramUpdate.RANGE_UPDATE,false);
   static
   {
      hr.setAxis(hr.HORIZONTAL_AXIS);
      hr.setAxis(hr.VERTICAL_AXIS);
   } 
}
