// Copyright 2004, FreeHEP.
package org.freehep.swing.table;

import java.awt.Component;
import java.awt.Graphics;

import javax.swing.Icon;
import javax.swing.JLabel;
import javax.swing.JTable;
import javax.swing.event.TableModelEvent;
import javax.swing.event.TableModelListener;
import javax.swing.table.JTableHeader;


/**
 * Utility to add a sorter for columns to a JTable which has a SortableTableModel.
 * <p>
 * Example of use:
 * <pre>
 *  TableModel model = ...
 *  DefaultSortableTableModel sm = new DefaultSortableTableModel(model);
 *  JTable table = new JTable(sm);
 *  TableSorter sorter = new TableSorter(table);
 * </pre>
 * @author Mark Donszelmann
 * @version $Id: TableSorter.java,v 1.6 2004/07/26 18:07:37 tonyj Exp $
 * @see org.freehep.swing.table.SortableTableModel
 */
public class TableSorter {

    private int sortOnColumn;
    private boolean sortAscending;
    private Icon downTriangle, upTriangle; 

    private transient SortableTableModel model;
    private transient JTableHeader header;

    /**
     * Create a TableSorter. The table will initially be unsorted.
     * @param table The table to be sorted
     */    
    public TableSorter(JTable table) {
        this(table, SortableTableModel.UNSORTED);    
    }
    
    /**
     * Create a TableSorter. The table will initially be sorted in ascending order by the given column.
     * @param table The table to be sorted.
     * @param column The column on which to sort, or <CODE>SortableTableModel.UNSORTED</CODE>
     */    
    public TableSorter(JTable table, int column) {
        this(table, column, true);
    }

    /**
     * Create a TableSorter specifiying initial sorting parameters.
     * @param table The table to be sorted.
     * @param column The column on which to sort, or <CODE>SortableTableModel.UNSORTED</CODE>
     * @param ascending <CODE>true</CODE> for ascending order, <CODE>false</CODE> for descending order
     */    
    public TableSorter(JTable table, int column, boolean ascending) {
        sortOnColumn = column;
        sortAscending = ascending;
    
        try {
            model = (SortableTableModel)table.getModel();
            // FixMe: Never gets removed!
            model.addTableModelListener(new TableModelListener()
            {
               public void tableChanged(TableModelEvent event)
               {
                  if (event.getFirstRow() == TableModelEvent.HEADER_ROW && sortOnColumn != SortableTableModel.UNSORTED) {
                     int oldSort = sortOnColumn;
                     int type = event.getType();
                     int column = event.getColumn();
                     if (type == TableModelEvent.DELETE)
                     {
                        if (column < sortOnColumn) sortOnColumn--;
                        else if (column == sortOnColumn) sortOnColumn = SortableTableModel.UNSORTED;
                     }
                     else if (type == TableModelEvent.INSERT) 
                     {
                        if (column <= sortOnColumn) sortOnColumn++;
                     }
                     if (sortOnColumn != oldSort) header.resizeAndRepaint();
                  }
               }
            });
        } catch (ClassCastException e) {
            throw new IllegalArgumentException(getClass()+": table should have a SortableTableModel as TableModel.");
        }
    
        header = table.getTableHeader();
        header.addMouseListener(new TableColumnHeaderListener() {
            public void headerClicked(JTable table, int col) {
                if (col != sortOnColumn) {
                    sortOnColumn = col;
                    sortAscending = true;
                } else {              
                    // same column
                    sortAscending = !sortAscending;
                }
                sort();
            }
        });
        
        // Add images in header for sorted column
        downTriangle = new Triangle(false);         
        upTriangle = new Triangle(true);
        
        header.setDefaultRenderer(new TableHeaderCellRenderer() {
            public Component getTableCellRendererComponent(JTable table, Object value,
                                                           boolean isSelected, boolean hasFocus, 
                                                           int row, int col) {
                JLabel label = (JLabel)super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, col);
                if (table.convertColumnIndexToModel(col) == sortOnColumn) {
                    if (sortAscending) {
                        label.setIcon(downTriangle);
                    } else {
                        label.setIcon(upTriangle);
                    }                        
                } else {
                    label.setIcon(null);
                }
                return label;
            }
        });

        // Now sort if needed
        if (sortOnColumn != SortableTableModel.UNSORTED) sort();
    }

    /**
     * Find the current sort column.
     * @return The current sort column, or <CODE>SortableTableModel.UNSORTED</CODE>
     */    
    public int getSortOnColumn() {
        return sortOnColumn;
    }
    
    /**
     * Set the sort column.
     * @param column The column on which to sort, or <CODE>SortableTableModel.UNSORTED</CODE>
     */    
    public void setSortOnColumn(int column) {
        if (column != sortOnColumn) {
            sortOnColumn = column;
            sort();
        }
    }        

    /**
     * Get the current sort order.
     * @return <CODE>true</CODE> if ascending order, <CODE>false</CODE> for descending order.
     */    
    public boolean isSortAscending() {
        return sortAscending;
    }
    
    /**
     * Set the current sort order.
     * @param ascending <CODE>true</CODE> for ascending order, <CODE>false</CODE> for descending order
     */    
    public void setSortAscending(boolean ascending) {
        if (ascending != sortAscending) {
            sortAscending = ascending;
            sort();
        }
    }    
    
    private void sort() {
        model.sort(sortOnColumn, sortAscending);
        header.resizeAndRepaint();
    }    
    private static class Triangle implements Icon {
       private boolean up;
       private static final int size = 16;
       private static final int[] xxdown = { 3 , 12, 7 };
       private static final int[] yydown = { 5 , 5, 10 };
       private static final int[] xxup = { 2 , 12, 7 };
       private static final int[] yyup = { 10 , 10, 4 };       
       Triangle(boolean up) {
          this.up = up;
       }
       
       public int getIconHeight() {
          return size;
       }
       
       public int getIconWidth() {
          return size;
       }
       
       public void paintIcon(Component c, Graphics g, int x, int y) {
          int[] xp = new int[3];
          int[] yp = new int[3];
          for (int i=0; i<3; i++)
          {
            xp[i] = x + (up ? xxup[i] : xxdown[i]);
            yp[i] = y + (up ? yyup[i] : yydown[i]);
          }
          g.setColor(c.getForeground());
          g.fillPolygon(xp,yp,3);
       }
       
    }
}
