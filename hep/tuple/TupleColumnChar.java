/*
 * TupleColumnChar.java
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
public class TupleColumnChar extends TupleColumn {

	private char[] data;
	
    /**
     * The constructor.
     * @param name The TupleColumn's name.
     * @param type The TupleColumn's type.
     * @param value The TupleColumn's default value.
     * @param options The TupleColumn's options.
     *
     */
    TupleColumnChar( String name, Value value, String options) {
        super( name, Character.TYPE, value, options);
    }

    protected void createArray(int size) {
        char[] data = new char[ size ];
        if ( hasDefaultValue() )
            for ( int i = 0; i < size; i++ )
                data[ i ] = getDefaultValue().getChar();
        arrayList.add( data );
    }

    public void value(int index, Value value) {
        setCurrentArray( index );
        value.set( data[ index%arraySize ] );
    }

    public void setValue(int index, Value value) {
        try {
            setCurrentArray( index );
            data[ index%arraySize ] = value.getChar();
        } catch ( ClassCastException cce ) {
            throw new IllegalArgumentException( "Wrong argument for TupleColumnChar" );
        }
    }

    protected boolean hasStatistics() {
        return false;
    }
    
    public void defaultValue( Value value ) {
        if ( hasDefaultValue() )
            value.set( getDefaultValue().getChar() );
    }

    protected void currentArrayUpdated() {
    	data = (char[]) currentArray;
    }

}
