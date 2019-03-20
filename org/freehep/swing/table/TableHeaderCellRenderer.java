// Copyright 2004, FreeHEP.
package org.freehep.swing.table;

import java.awt.Component;

import javax.swing.JLabel;
import javax.swing.JTable;
import javax.swing.UIManager;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.JTableHeader;

/**
 * Renders a header cell.
 *
 * @author Mark Donszelmann
 * @version $Id: TableHeaderCellRenderer.java,v 1.3 2004/07/26 18:07:37 tonyj Exp $
 */
public class TableHeaderCellRenderer extends DefaultTableCellRenderer {

    public Component getTableCellRendererComponent(JTable table, Object value,
                                                   boolean isSelected, boolean hasFocus, 
                                                   int row, int column) {
        // Inherit the colors and font from the header component
        if (table != null) {
            JTableHeader header = table.getTableHeader();
            if (header != null) {
                setForeground(header.getForeground());
                setBackground(header.getBackground());
                setFont(header.getFont());
            }
        }

        setText(value.toString());
        setBorder(UIManager.getBorder("TableHeader.cellBorder"));
        setHorizontalAlignment(JLabel.CENTER);
        return this;
    }
}
