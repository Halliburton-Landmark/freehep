// Copyright 2003, SLAC, Stanford, U.S.A.
package org.freehep.swing.undo;

import javax.swing.undo.UndoableEdit;

/**
 * Allows edits to be linked together to form undoable compound edits in a linked list.
 *
 * @author Mark Donszelmann
 * @version $Id: LinkableEdit.java,v 1.2 2004/04/30 23:37:24 duns Exp $
 */
public interface LinkableEdit extends UndoableEdit {

    /**
     * Returns the next edit.
     */
    public LinkableEdit getNextEdit();
    
    /**
     * Connects to the next edit.
     */
    public void setNextEdit(LinkableEdit edit);

    /**
     * Returns the previous edit.
     */
    public LinkableEdit getPreviousEdit();
    
    /**
     * Connext to the previous edit.
     */
    public void setPreviousEdit(LinkableEdit edit);

    /**
     * Returns the parent.
     */
    public LinkableEdit getParent();
    
    /**
     * Sets the parent, can only be called once.
     */
    public void setParent(LinkableEdit edit);
}
