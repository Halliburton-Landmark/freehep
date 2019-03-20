package hep.tuple.interfaces;

/**
 * A TupleCursor is used to step through the rows of an Tuple
 *
 * @author The FreeHEP team @ SLAC.
 *
 */

public interface FTupleCursor {
    
    /**
     * Get the current row number
     * @return The current row number, or -1 if before the first row
     *
     */
    int row();
    
    /**
     * Rewind the Cursor to BEFORE the first row.
     */
    void start();
    
    /**
     * Step to the next row.
     * @return False if there are no more rows
     */
    boolean next();
    
    /**
     * Skips rows.
     * @param rows number of rows to skip, greater than 0.
     *
     */
    void skip(int rows);
    
    /**
     * Step to a specific row
     * @param n The row to move to
     * @throws IndexOutOfBoundsException if the index is < 0 or >= number of rows
     * @throws UnsupportedOperationException if the Tuple does not support random access
     */    
    void setRow(int n);
    
    /**
     * Close this cursor. Any further attempts to use the cursor will result in an IllegalStateException.
     */
    void close();
        
}
