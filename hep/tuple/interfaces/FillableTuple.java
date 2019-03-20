package hep.tuple.interfaces;
import org.freehep.util.Value;

/**
 * An interface implemented by all mutable tuples.
 * Through this interface tuples can be modified. Columns and folders can
 * be added and removed. Columns can be filled, rows can be added.
 * 
 * @author The FreeHEP team @ SLAC.
 *
 */
public interface FillableTuple extends FTuple {
    
    /**
     * Fill the stack for a column with String.
     * If the column has an incompatible type an IllegalArgumentException is thrown.
     * @param column the column's index
     * @param value the value to be stored
     */
    void fill(int column, Value value);

    /**
     * Should be called after fill is called for the columns.
     * Unfilled columns will be filled with the default value for that column.
     *
     */
    void addRow();
        
    /**
     * Clears the values on the stack.
     *
     */
    void resetRow();

    /**
     * Clears all rows from the FillableTuple.
     *
     */
    void reset();
    
    /**
     * Add a new FTupleColumn to the FillableTuple.
     *
     */
    void addColumn(FillableTupleColumn column);
    
    /**
     * Remove a new FTupleColumn to the FillableTuple.
     *
     */
    void removeColumn(FillableTupleColumn column);

    /**
     * When a FillableTuple is added a corresponding FillableTupleColumn with type FillableTuple.class must be added as well!
     *
     */
    void addTuple(FillableTuple tuple);
        
    /**
     * Remove the whole FillableTuple.
     *
     */
    void removeTuple(FillableTuple tuple);
    
}
