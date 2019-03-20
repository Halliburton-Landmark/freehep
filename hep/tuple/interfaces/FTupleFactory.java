package hep.tuple.interfaces;

import org.freehep.util.Value;

/**
 * A TupleFactory is used to create new FillableTuples and FillableTupleColumns.
 * 
 * @author The FreeHEP team @SLAC.
 *
 */
public interface FTupleFactory {

    /**
     * Create a new FillableTuple.
     * @param name  The FillableTuple,s name
     * @param title The FillableTuple's title
     * @return      The new FillableTuple.
     *
     */
    public FillableTuple createFTuple(String name, String title);

    /**
     * Create a new FillableTuple.
     * @param name  The FillableTuple,s name
     * @param title The FillableTuple's title
     * @param options A set of comma or semicolon separated options.
     *                Check the specific implementation for the list of supported options.
     * @return      The new FillableTuple.
     *
     */
    public FillableTuple createFTuple(String name, String title, String options);

    /**
     * Create a new FillableTupleColumn.
     * @param name  The FillableTupleColumn's name
     * @param type  The FillableTupleColumn's type
     * @param value The Value containing the FillableTupleColumn's default value, i.e.
     *              the value of a give row if it is not filled.
     * @return      The new FillableTupleColumn
     *
     */
    public FillableTupleColumn createFTupleColumn(String name, Class type, Value value);

    /**
     * Create a new FillableTupleColumn.
     * @param name    The FillableTupleColumn's name
     * @param type    The FillableTupleColumn's type
     * @param value   The Value containing the FillableTupleColumn's default value, i.e.
     *                the value of a give row if it is not filled.
     * @param options A set of comma or semicolon separated options.
     *                Check the specific implementation for the list of supported options.
     * @return        The new FillableTupleColumn
     *
     */    
    public FillableTupleColumn createFTupleColumn(String name, Class type, Value value, String options);    
}
