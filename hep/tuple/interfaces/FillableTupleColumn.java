package hep.tuple.interfaces;
import org.freehep.util.Value;

/**
 * An interface implemented by all TupleColumns that can be filled.
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
public interface FillableTupleColumn extends FTupleColumn {
        
    /**
     * Set the value of the column.
     * This method should only be used internally; not by the user filling the tuple.
     * The fill() and addRow() methods on the FillableTuple should be used instead. 
     * @param index The position in the FTupleColumn.
     * @param value The Value carrying the value to be set.
     *
     */
    void setValue(int index, Value value);
    
}
