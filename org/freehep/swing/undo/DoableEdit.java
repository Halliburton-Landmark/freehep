// Copyright 2003, SLAC, Stanford, U.S.A.
package org.freehep.swing.undo;

import javax.swing.undo.UndoableEdit;

/**
 * Allows the Edit to be used to execute
 * the action the first time using the redo() method.
 *
 * @author Mark Donszelmann
 * @version $Id: DoableEdit.java,v 1.1 2003/06/10 18:26:16 duns Exp $
 */

public interface DoableEdit extends UndoableEdit {
}
