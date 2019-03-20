// Copyright 2004, FreeHEP.
package org.freehep.swing.table;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.*;

/**
 * Abstract class listens for clicks on a table column header.
 *
 * @author Mark Donszelmann
 * @version $Id: TableColumnHeaderListener.java,v 1.2 2004/06/22 20:19:14 duns Exp $
 */
public abstract class TableColumnHeaderListener extends MouseAdapter {
    
    public void mouseClicked(MouseEvent evt) {
        JTable table = ((JTableHeader)evt.getSource()).getTable();
        TableColumnModel colModel = table.getColumnModel();

        // The index of the column whose header was clicked
        int vColIndex = colModel.getColumnIndexAtX(evt.getX());
        int mColIndex = table.convertColumnIndexToModel(vColIndex);

        // Return if not clicked on any column header
        if (vColIndex == -1) {
            return;
        }

        // Determine if mouse was clicked between column heads
        Rectangle headerRect = table.getTableHeader().getHeaderRect(vColIndex);
        if (vColIndex == 0) {
            headerRect.width -= 3;    // Hard-coded constant
        } else {
            headerRect.grow(-3, 0);   // Hard-coded constant
        }
        
        if (!headerRect.contains(evt.getX(), evt.getY())) {
            // Mouse was clicked between column heads
            // vColIndex is the column head closest to the click

            // vLeftColIndex is the column head to the left of the click
            int vLeftColIndex = vColIndex;
            if (evt.getX() < headerRect.x) {
                vLeftColIndex--;
            }
        } else {
            headerClicked(table, mColIndex);
        }
    }
    
    public abstract void headerClicked(JTable table, int col);
}
