package org.freehep.util.commanddispatcher;


/**
 * A boolean command target is a CommandTarget which corresponds to a command which
 * may have an on/off state associated with it.
 * @see SimpleCommandTarget
 * @see CommandTarget
 *
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: BooleanCommandTarget.java,v 1.4 2003/05/14 17:53:08 tonyj Exp $
 */
public interface BooleanCommandTarget extends CommandTarget
{
   /**
    * Called when the on/off state changes (i.e. when the comamnd is invoked).
    */
   void invoke(boolean onOff);
}
