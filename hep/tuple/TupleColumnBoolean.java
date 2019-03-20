/*
 * TupleColumnBoolean.java
 *
 * Created on February 14, 2002, 2:21 PM
 */

package hep.tuple;
import org.freehep.util.Value;
import hep.tuple.interfaces.*;

/**
 *
 * @author  turri
 */
public class TupleColumnBoolean extends TupleColumn {

	private boolean[] data;
	
    /**
     * The constructor.
     * @param name The TupleColumn's name.
     * @param type The TupleColumn's type.
     * @param value The TupleColumn's default value.
     * @param options The TupleColumn's options.
     *
     */
    TupleColumnBoolean( String name, Value value, String options) {
        super( name, Boolean.TYPE, value, options);
    }

    /**
     * Create a new array of the appropriate type with length
     * equal to arraySize.
     * @return The newly created array.
     *
     */
    protected void createArray(int size) {
        boolean[] data = new boolean[ size ];
        if ( hasDefaultValue() )
            for ( int i = 0; i < size; i++ )
                data[ i ] = getDefaultValue().getBoolean();
        arrayList.add( data );
    }

    public void value(int index, Value value) {
        setCurrentArray( index );
        value.set( data[ index%arraySize ] );
    }

    public void setValue(int index, Value value) {
        try {
            setCurrentArray( index );
            data[ index%arraySize ] = value.getBoolean();
        } catch ( ClassCastException cce ) {
            throw new IllegalArgumentException( "Wrong argument for TupleColumnBoolean" );
        }
    }

    protected boolean hasStatistics() {
        return false;
    }   
    
    public void defaultValue( Value value ) {
        if ( hasDefaultValue() )
            value.set( getDefaultValue().getBoolean() );
    }
 
    protected void currentArrayUpdated() {
    	data = (boolean[]) currentArray;
    }
}
