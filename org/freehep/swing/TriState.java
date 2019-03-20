// Copyright 2000, CERN, Geneva, Switzerland.
package org.freehep.swing;


import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

/**
 * @author Mark Donszelmann
 * @version $Id: TriState.java,v 1.1 2000/05/23 07:57:38 duns Exp $
 */
public interface TriState {

    public int getTriState(); 
    
    public void setTriState(int state);
    public void setTriState(boolean state);    
}
  
