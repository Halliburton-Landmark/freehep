package hep.aida.ref.event;
import hep.aida.*;

/**
 * An event send from a Histogram to AIDAListeners
 * @author tonyj
 * @version $Id: HistogramEvent.java,v 1.1 2002/10/02 00:15:14 tonyj Exp $
 */
public class HistogramEvent extends java.util.EventObject
{  
   public HistogramEvent(IBaseHistogram source)
   {
      super(source);
   }
}
