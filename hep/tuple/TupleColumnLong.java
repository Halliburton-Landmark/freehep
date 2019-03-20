/*
 * TupleColumnLong.java
 *
 * Created on February 14, 2002, 2:21 PM
 */

package hep.tuple;

import hep.tuple.interfaces.*;
import org.freehep.util.Value;

/**
 *
 * @author  turri
 */
public class TupleColumnLong extends TupleColumn {

	private long[] data;
	
    /**
     * The constructor.
     * @param name The TupleColumn's name.
     * @param type The TupleColumn's type.
     * @param value The TupleColumn's default value.
     * @param options The TupleColumn's options.
     *
     */
    TupleColumnLong( String name, Value value, String options) {
        super( name, Long.TYPE, value, options);
    }

    protected void createArray(int size) {
        long[] data = new long[ size ];
        if ( hasDefaultValue() )
            for ( int i = 0; i < size; i++ )
                data[ i ] = getDefaultValue().getLong();
        arrayList.add( data );
    }

    public void value(int index, Value value) {
        setCurrentArray( index );
        value.set( data[ index%arraySize ] );
    }

    public void setValue(int index, Value value) {
        try {
            setCurrentArray( index );
            data[ index%arraySize ] = value.getLong();
        } catch ( ClassCastException cce ) {
            throw new IllegalArgumentException( "Wrong argument for TupleColumnLong" );
        }
    }

    protected boolean hasStatistics() {
        return true;
    }
    
    public void defaultValue( Value value ) {
        if ( hasDefaultValue() )
            value.set( getDefaultValue().getLong() );
    }

    protected void currentArrayUpdated() {
    	data = (long[]) currentArray;
    }

}
