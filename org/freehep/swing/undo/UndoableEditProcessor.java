// Copyright 2003, SLAC, Stanford, U.S.A.
package org.freehep.swing.undo;

import javax.swing.undo.UndoableEdit;

/**
 * Allows for the (compound) processing of UndoableEdits.
 * One can use UndoableEditSupport to implement this.
 *
 * @author Mark Donszelmann
 * @version $Id: UndoableEditProcessor.java,v 1.2 2004/04/08 20:13:04 duns Exp $
 */

public interface UndoableEditProcessor {

    /**
     * Starts a new CompoundEdit and adds subsequent edits to it.
     */
    public void beginUpdate();

    /**
     * Ends the CompoundEdit
     */
    public void endUpdate();

    /**
     * Post (execute) the edit.
     */
    public void postEdit(UndoableEdit edit);
    
    /**
     * Return true if this interface supports this edit
     */
    public boolean supports(UndoableEdit edit);
     
}
