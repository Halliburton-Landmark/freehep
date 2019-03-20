/*
 * TupleColumnDate.java
 *
 * Created on February 14, 2002, 2:21 PM
 */

package hep.tuple;

import hep.tuple.interfaces.*;
import java.text.*;
import java.util.Date;
import org.freehep.util.Value;

/**
 *
 * @author  turri
 */
public class TupleColumnDate extends TupleColumn {

	private Date[] data;
	
    /**
     * The constructor.
     * @param name The TupleColumn's name.
     * @param type The TupleColumn's type.
     * @param value The TupleColumn's default value.
     * @param options The TupleColumn's options.
     *
     */
    TupleColumnDate( String name, Value value, String options) {
        super( name, Date.class, value, options);
    }

    protected void createArray(int size) {
        Date[] data = new Date[ size ];
        if ( hasDefaultValue() )
            for ( int i = 0; i < size; i++ )
                data[ i ] = getDefaultValue().getDate();
        arrayList.add( data );
    }

    public void value(int index, Value value) {
        setCurrentArray( index );
        value.set( data[ index%arraySize ] );
    }

    public void setValue(int index, Value value) {
        try {
            setCurrentArray( index );
            data[ index%arraySize ] = value.getDate();
        } catch ( ClassCastException cce ) {
            throw new IllegalArgumentException( "Wrong argument for TupleColumnDate" );
        }
    }

    protected boolean hasStatistics() {
        return true;
    }
    
    public void defaultValue( Value value ) {
        if ( hasDefaultValue() )
            value.set( getDefaultValue().getDate() );
    }

    protected void currentArrayUpdated() {
    	data = (Date[]) currentArray;
    }

}
