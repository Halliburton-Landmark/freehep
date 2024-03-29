package org.freehep.swing.table;

import javax.swing.table.TableModel;

/**
 * An interface to be implemented by table models which are sortable.
 * @see org.freehep.swing.table.TableSorter
 * @author Tony Johnson
 * @version $Id: SortableTableModel.java,v 1.2 2004/06/22 23:00:20 duns Exp $
 */
public interface SortableTableModel extends TableModel
{   
   public final static int UNSORTED = -1; 
    
   /**
    * Sort the table model using the given column. Once this method
    * has been called the table model should reorder its rows so that
    * they are sorted using the given column. The table model should
    * generate appropriate change events to reflect any changes made
    * to the model as a result of the sort. If the table data is modified
    * after sort has been called, the table model should continue to sort
    * the data using the given column.
    * @param column The index of the column to sort on, or UNSORTED if no sort is necessary.
    * @param ascending If <CODE>true</CODE> sort in ascending order, else sort in descending order.
    */   
   void sort(int column, boolean ascending);
}