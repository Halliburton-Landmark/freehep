/*
 * Stoppable.java
 *
 * Created on February 27, 2001, 5:51 PM
 */

package org.freehep.application;
import javax.swing.BoundedRangeModel;

/**
 * A interface to be implemented by things that can be stopped.
 * @author  tonyj
 * @version $Id: Stoppable.java,v 1.1 2001/02/28 04:18:26 tonyj Exp $
 * @see StatusBar
 */
public interface Stoppable 
{
    BoundedRangeModel getModel();
    void stop();
}
