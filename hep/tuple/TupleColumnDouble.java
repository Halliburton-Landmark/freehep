/*
 * TupleColumnDouble.java
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
public class TupleColumnDouble extends TupleColumn {

	private double[] data;
	
    /**
     * The constructor.
     * @param name The TupleColumn's name.
     * @param type The TupleColumn's type.
     * @param value The TupleColumn's default value.
     * @param options The TupleColumn's options.
     *
     */
    TupleColumnDouble( String name, Value value, String options) {
        super( name, Double.TYPE, value, options);
    }

    protected void createArray(int size) {
        double[] data = new double[ size ];
        if ( hasDefaultValue() )
            for ( int i = 0; i < size; i++ )
                data[ i ] = getDefaultValue().getDouble();
        arrayList.add( data );
    }

    public void value(int index, Value value) {
        setCurrentArray( index );
        value.set( data[ index%arraySize ] );
    }

    public void setValue(int index, Value value) {
        try {
            setCurrentArray( index );
            data[ index%arraySize ] = value.getDouble();
        } catch ( ClassCastException cce ) {
            throw new IllegalArgumentException( "Wrong argument for TupleColumnDouble" );
        }
    }

    protected boolean hasStatistics() {
        return true;
    }
        
    public void defaultValue( Value value ) {
        if ( hasDefaultValue() )
            value.set( getDefaultValue().getDouble() );
    }

    protected void currentArrayUpdated() {
    	data = (double[]) currentArray;
    }

}
