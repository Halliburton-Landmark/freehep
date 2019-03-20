package org.freehep.util.commanddispatcher;

import java.util.Observer;

/**
 * A CommandGroup represents a collection of CommandTargets. The CommandGroup is Observable,
 * and is normally Observed by the CommandTargetManager. When the CommandGroup calls
 * its notifies its observers, the CommandTargetManager prompts each CommandSource currently
 * attached to CommandTargets within the CommandGroup to update their enabled/disabled status.
 * @author tonyj
 * @version $Id: CommandGroup.java,v 1.1 2003/05/14 17:53:08 tonyj Exp $
 */
public interface CommandGroup
{
   CommandTarget acceptCommand(String command);
   void addObserver(Observer observer);
   void deleteObserver(Observer observer);
   void setManager(CommandTargetManager manager);
}
