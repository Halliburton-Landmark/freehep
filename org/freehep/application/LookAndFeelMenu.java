package org.freehep.application;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JMenu;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;

/**
 * A menu for setting the look and feel of an application
 * @author tonyj
 * @version $Id: LookAndFeelMenu.java,v 1.2 2004/04/06 20:08:36 tonyj Exp $
 */
public class LookAndFeelMenu extends JMenu
{
   /**
    * Creates a Look and Feel menu
    */
   public LookAndFeelMenu()
   {
      super("Look and Feel");
   }
   public void fireMenuSelected()
   {
      removeAll();
      ActionListener listener = new LAFActionListener();
      LookAndFeelInfo info[] = UIManager.getInstalledLookAndFeels();
      String currentLAF = UIManager.getLookAndFeel().getClass().getName();
      for (int i=0; i<info.length; i++)
      {
         JRadioButtonMenuItem radio = new JRadioButtonMenuItem(info[i].getName());
         String className = info[i].getClassName();
         radio.setActionCommand(className);
         radio.setSelected(className.equals(currentLAF));
         radio.addActionListener(listener);
         add(radio);
      }
      super.fireMenuSelected();
   }
   private class LAFActionListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
         Application.getApplication().setLookAndFeel(e.getActionCommand());
      }
   }
}