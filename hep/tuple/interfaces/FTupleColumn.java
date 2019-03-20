package hep.tuple.interfaces;
import org.freehep.util.Value;

/**
 * An interface implemented by all TupleColumns
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
public interface FTupleColumn {
    
    /**
     * The name of che column.
     * @return The column's name.
     *
     */
    String name();
    
    /**
     * The type of the column.
     * If the column is a folder, i.e. and FTuple, its return type should either
     * be FTuple.class or FillableTuple.class
     * @return The column's type.
     *
     */
    Class type();
    
    /**
     * Get the minimum value stored in the column.
     * @param value The Value object in which the minimum value is passed.
     *
     */
    void minValue(Value value);
    
    /**
     * Get the maximum value stored in the column.
     * @param value The Value object in which the maximum value is passed.
     *
     */
    void maxValue(Value value);
    
    /**
     * Get the mean value stored in the column.
     * @param value The Value object in which the mean value is passed.
     *
     */
    void meanValue(Value value);

    /**
     * Get the rms value stored in the column.
     * @param value The Value object in which the rms value is passed.
     *
     */
    void rmsValue(Value value);

    /**
     * Get the default value stored in the column.
     * @param value The Value object in which che maximum value is passed.
     *
     */
    void defaultValue(Value value);
    
    /**
     * Check if the column has a default value.
     * @return true if the column has a default value.
     *
     */
    boolean hasDefaultValue();
}
