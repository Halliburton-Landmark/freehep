/*
 * TupleColumnInt.java
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
public class TupleColumnInt extends TupleColumn {

	private int[] data;
	
    /**
     * The constructor.
     * @param name The TupleColumn's name.
     * @param type The TupleColumn's type.
     * @param value The TupleColumn's default value.
     * @param options The TupleColumn's options.
     *
     */
    TupleColumnInt( String name, Value value, String options) {
        super( name, Integer.TYPE, value, options);
    }

    protected void createArray(int size) {
        int[] data = new int[ size ];
        if ( hasDefaultValue() ) {        	
            for ( int i = 0; i < size; i++ )
                data[ i ] = getDefaultValue().getInt();
        }
        arrayList.add( data );
    }

    public void value(int index, Value value) {
        setCurrentArray( index );
        value.set( data[ index%arraySize ] );
    }

    public void setValue(int index, Value value) {
        try {
            setCurrentArray( index );
            data[ index%arraySize ] = value.getInt();
        } catch ( ClassCastException cce ) {
            throw new IllegalArgumentException( "Wrong argument for TupleColumnInt" );
        }
    }

    protected boolean hasStatistics() {
        return true;
    }
    
    public void defaultValue( Value value ) {
        if ( hasDefaultValue() )
            value.set( getDefaultValue().getInt() );
    }
    
    protected void currentArrayUpdated() {
    	data = (int[]) currentArray;
    }
}
