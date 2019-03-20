package hep.aida.ref.event;
import java.util.EventObject;

/**
 * A interface to be implemented by those wishing to observe changes
 * to AIDA objects.
 * @author tonyj
 * @version $Id: AIDAListener.java,v 1.1 2002/10/02 00:15:14 tonyj Exp $
 */
public interface AIDAListener
{
   void stateChanged(EventObject e);
}
