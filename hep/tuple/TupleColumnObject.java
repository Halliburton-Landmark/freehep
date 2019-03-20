/*
 * TupleColumnObject.java
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
public class TupleColumnObject extends TupleColumn {

	private Object[] data;
	
    /**
     * The constructor.
     * @param name The TupleColumn's name.
     * @param type The TupleColumn's type.
     * @param value The TupleColumn's default value.
     * @param options The TupleColumn's options.
     *
     */
    TupleColumnObject( String name, Class type, Value value, String options) {
        super( name, type, value, options);
    }

    protected void createArray(int size) {
        Object[] data = new Object[ size ];
        if ( hasDefaultValue() ) {
            Object def = getDefaultValue().getObject();
            for ( int i = 0; i < size; i++ )
                if ( def == null )
                    data[ i ] = def;
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
            data[ index%arraySize ] = value.getObject();
        } catch ( ClassCastException cce ) {
            throw new IllegalArgumentException( "Wrong argument for TupleColumnObject" );
        }
    }

    protected boolean hasStatistics() {
        return false;
    }

    public void defaultValue( Value value ) {
        if ( hasDefaultValue() )
            value.set( getDefaultValue().getObject() );
    }

    protected void currentArrayUpdated() {
    	data = (Object[]) currentArray;
    }

}
