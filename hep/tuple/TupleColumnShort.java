/*
 * TupleColumnShort.java
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
public class TupleColumnShort extends TupleColumn {

	private short[] data;
	
    /**
     * The constructor.
     * @param name The TupleColumn's name.
     * @param type The TupleColumn's type.
     * @param value The TupleColumn's default value.
     * @param options The TupleColumn's options.
     *
     */
    TupleColumnShort( String name, Value value, String options) {
        super( name, Short.TYPE, value, options);
    }

    protected void createArray(int size) {
        short[] data = new short[ size ];
        if ( hasDefaultValue() )
            for ( int i = 0; i < size; i++ )
                data[ i ] = getDefaultValue().getShort();
        arrayList.add( data );
    }

    public void value(int index, Value value) {
        setCurrentArray( index );
        short[] data = (short[]) currentArray;
        value.set( data[ index%arraySize ] );
    }

    public void setValue(int index, Value value) {
        try {
            setCurrentArray( index );
            short[] data = (short[]) currentArray;
            data[ index%arraySize ] = value.getShort();
        } catch ( ClassCastException cce ) {
            throw new IllegalArgumentException( "Wrong argument for TupleColumnShort" );
        }
    }

    protected boolean hasStatistics() {
        return true;
    }
    
    public void defaultValue( Value value ) {
        if ( hasDefaultValue() )
            value.set( getDefaultValue().getShort() );
    }

    protected void currentArrayUpdated() {
    	data = (short[]) currentArray;
    }

}
