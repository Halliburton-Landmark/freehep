package org.freehep.application;

import org.freehep.application.Application.InitializationException;
import java.util.*;
import javax.help.*;
import javax.swing.*;
import javax.help.Map.ID;
import java.net.URL;
import java.awt.*;


/**
 * An implementation of HelpService using JavaHelp. The only reference to
 * javax.help classes is from this class, which is loaded by name, so applications
 * can run even if jh.jar is not present. This is useful, in particular for WebStart
 * apps which do not have to download javahelp before they start.
 * @author Peter Armstrong
 * @author Tony Johnson
 * @version $Id: HelpServiceImpl.java,v 1.4 2004/06/01 05:11:02 tonyj Exp $
 */
class HelpServiceImpl implements HelpService, ApplicationListener
{
   HelpServiceImpl() throws InitializationException
   {
      try
      {
         Application app = Application.getApplication();
         Properties props = app.getUserProperties();
         URL helpsetURL = PropertyUtilities.getURL(props,"helpset",null);
         if (helpsetURL == null) throw new InitializationException("Application property \"helpset\" missing or invalid");
         HelpSet helpSet = new HelpSet(null, helpsetURL);
         helpBroker = new DefaultHelpBroker(helpSet);     
         app.addApplicationListener(this);
      }
      catch (HelpSetException x)
      {
         throw new InitializationException("Could not load helpset",x);
      }
   }
   public void showHelpTopic(String helpTopicTarget, String navigatorView, Component owner)
   {
      try
      {
         HelpSet hs = helpBroker.getHelpSet();
         ID id = helpTopicTarget == null ? hs.getHomeID() : ID.create(helpTopicTarget, hs);
         Window w = (Window) SwingUtilities.getAncestorOfClass(Window.class,owner);
         if (w != null) helpBroker.setActivationWindow(w);
         if (navigatorView != null) helpBroker.setCurrentView(navigatorView);
         helpBroker.setCurrentID(id);
         if (!helpBroker.isDisplayed())
         {
            Rectangle bounds = PropertyUtilities.getRectangle(Application.getApplication().getUserProperties(),"helpBrokerWindow",null);
            if (bounds != null)
            {
               helpBroker.setLocation(bounds.getLocation());
               helpBroker.setSize(bounds.getSize());
            }
            helpBroker.setDisplayed(true);
         }
      }
      catch (BadIDException x)
      {
         throw new IllegalArgumentException("Cannot find help topic: "+helpTopicTarget);
      }
      catch (InvalidHelpSetContextException x)
      {
         throw new IllegalArgumentException("Cannot find help topic: "+helpTopicTarget);
      }
   }
   
   public void aboutToExit(ApplicationEvent e)
   {
      Properties user = e.getApplication().getUserProperties();
      Rectangle bounds = new Rectangle();
      bounds.setSize(helpBroker.getSize());
      bounds.setLocation(helpBroker.getLocation());
      PropertyUtilities.setRectangle(user,"helpBrokerWindow",bounds);
   } 
   
   public void initializationComplete(ApplicationEvent e)
   {
   }
   
   public void applicationVisible(ApplicationEvent e)
   {
   }
   
   private DefaultHelpBroker helpBroker;
}