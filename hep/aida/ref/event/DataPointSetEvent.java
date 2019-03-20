package hep.aida.ref.event;
import hep.aida.*;

/**
 * An event send from a Histogram to AIDAListeners
 * @author tonyj
 * @version $Id: DataPointSetEvent.java,v 1.1 2003/06/21 00:55:56 serbo Exp $
 */
public class DataPointSetEvent extends java.util.EventObject
{  
    public DataPointSetEvent(IDataPointSet source)
   {
      super(source);
   }
}
