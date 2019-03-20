package hep.aida.ref.plotter.adapter;

import jas.hist.*;
import hep.aida.ref.*;
import hep.aida.ref.event.*;
import hep.aida.*;
import java.lang.Boolean;
import java.util.Observer;
import java.util.Observable;

/**
 *
 * @author  The AIDA team @ SLAC
 *
 */
public abstract class AIDAProfileAdapter  extends ObserverAdapter implements DataSource
{
    private final static jas.hist.HistogramUpdate hu = new jas.hist.HistogramUpdate(HistogramUpdate.TITLE_UPDATE+HistogramUpdate.DATA_UPDATE+HistogramUpdate.RANGE_UPDATE,false);
   static
   {
      hu.setAxis(hu.HORIZONTAL_AXIS);
      hu.setAxis(hu.VERTICAL_AXIS);
   } 

    public static int USE_SPREAD = 0;
    public static int USE_ERROR_ON_MEAN = 1;
    private int errorMode = USE_SPREAD;
    
    protected int xAxisType = DOUBLE;
    protected int yAxisType = DOUBLE;
    
   /**
    * Create a DataSource from a Profile
    */
   public static DataSource create(IProfile c) {
      AIDAProfileAdapter result;
      if      (c instanceof IProfile1D) result = new AIDAProfileAdapter1D((IProfile1D)c);
      else if (c instanceof IProfile2D) result = new AIDAProfileAdapter2D((IProfile2D)c);
      else throw new IllegalArgumentException("Argument is an unknown subtype of IProfile");  
      return result;
   }
   protected AIDAProfileAdapter(IProfile p)
   {
       super(p);
       update = hu;
   }

   int errorMode() {
       return errorMode;
   }

   public void setErrorMode( int errorMode ) {
       if ( this.errorMode != errorMode ) {
           this.errorMode = errorMode;
           stateChanged(new java.util.EventObject(this));
       }
       
   }
}
