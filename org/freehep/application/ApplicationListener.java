/*
 * ApplicationListener.java
 *
 * Created on April 5, 2001, 12:15 PM
 */

package org.freehep.application;
import java.util.EventListener;

/**
 * Listen for ApplicationEvents
 * @author  Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: ApplicationListener.java,v 1.4 2004/06/01 22:45:12 tonyj Exp $
 */
public interface ApplicationListener extends EventListener
{
   void initializationComplete(ApplicationEvent e);
   //TODO: Maybe add this method back in at some future date (breaks backwards compatibility)
   //void applicationVisible(ApplicationEvent e);
   void aboutToExit(ApplicationEvent e);
}
