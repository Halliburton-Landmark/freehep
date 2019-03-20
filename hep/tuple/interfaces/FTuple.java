package hep.tuple.interfaces;
import org.freehep.util.Value;

/**
 * An interface implemented by all Tuples.
 * This is the minimal interface that a tuple should implement.
 * FTuples can be used with the TupleExplorer
 * 
 * @author The FreeHEP team @ SLAC.
 *
 */
public interface FTuple {
    
    static final int ROWS_UNKNOWN = -1;
    
    /**
     * Get the title of the Tuple.
     * @return The title of this Tuple
     *
     */
    String title();
    
    /**
     * Get the name of the Tuple.
     * @return The name of this Tuple
     *
     */
    String name();

    /**
     * Get the number of columns in the Tuple
     * @return The number of columns
     *
     */
    int columns();
    
    /**
     * Get the number of rows in the Tuple
     * @return The number of rows, or ROWS_UNKNOWN if the number of rows cannot be determined
     *
     */
    int rows();
    
    /**
     * Get a TupleColumn
     * @param index The index of the column to return
     * @return      The column at index n
     *
     */
    FTupleColumn column(int index);
    
    /**
     * Find the index of a column by name
     * @param name The name of the column to search for
     * @return The named column, or null if no column can be found
     *
     */
    FTupleColumn columnByName(String name);
    
    /**
     * Get the index corresponding to a given column.
     * @param name The column's name.
     * @return The index of the corresponding column.
     *
     */
    int columnIndexByName(String name);
    
    /**
     * Get the name of a column from its index
     * @param index The column's index
     * @return      The column's name
     *
     */
    String columnName(int index);
    
    /**
     * Get the type of a column from its index
     * @param index The column's index
     * @return      The column's type
     *
     */
    Class columnType(int index);
    
    /**
     * Get a value stored in the column.
     * @param column The column's index.
     * @param cursor The cursor that specifies which value to get.
     * @param value  The Value object in which the value is passed.
     *
     */
    void columnValue(int column, FTupleCursor cursor, Value value);

    /**
     * Get Folder at the current cursor position.
     * @param index The column's index of the Folder.
     * @return The folder.
     *
     */
    public FTuple tuple( int index );

    /**
     * Determine if the cursor returned by getCursor allows random access to the data
     * @return True if random access is supported
     *
     */
    boolean supportsRandomAccess();
    
    /**
     * Determine if this Tuple supports multiple cursors
     * @return True if multiple cursors are supported
     *
     */
    boolean supportsMultipleCursors();
    
    /**
     * Get a cursor for accessing data from the Tuple.
     * Some Tuples may support mutliple cursors, others may support
     * only single cursor access.
     * @return A Cursor that can be used to access data from the Tuple columns.
     * @throws IllegalStateEsxception If no cursor is currently available
     *
     */
    FTupleCursor cursor() throws IllegalStateException;
    
    /**
     * Free any resources associated with the Tuple (open disk files etc)
     *
     */
    void close();
    
    /**
     * The purpose of this method is to see if a FTuple would benefit from being
     * buffered in memory for performance issues.
     * @return <\true> if the implementer thinks that the performance would improve
     *         by buffering the FTuple in memory.
     *
     */
    boolean isInMemory();
}
