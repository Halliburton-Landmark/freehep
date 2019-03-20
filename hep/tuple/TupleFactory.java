package hep.tuple;

import hep.tuple.interfaces.*;
import java.util.Map;
import org.freehep.util.Value;
import org.freehep.util.OptionParser;
import java.util.Date;

/**
 *
 * @author The FreeHEP team @SLAC.
 *
 */
public class TupleFactory implements FTupleFactory {
    
    public FillableTuple createFTuple(String name, String title) {
        return createFTuple(name, title, "");
    }
    
    public FillableTuple createFTuple(String name, String title, String options) {
        return new Tuple(name, title, options);
    }
    
    public FillableTupleColumn createFTupleColumn(String name, Class type, Value value) {
        return createFTupleColumn(name, type, value, "");
    }
    
    public FillableTupleColumn createFTupleColumn(String name, Class type, Value value, String options) {
        if ( type == Integer.TYPE ) return new TupleColumnInt( name, value, options);
        else if ( type == Short.TYPE ) return new TupleColumnShort( name, value, options);
        else if ( type == Long.TYPE ) return new TupleColumnLong( name, value, options);
        else if ( type == Float.TYPE ) return new TupleColumnFloat( name, value, options);
        else if ( type == Double.TYPE ) return new TupleColumnDouble( name, value, options);
        else if ( type == Boolean.TYPE ) return new TupleColumnBoolean( name, value, options);
        else if ( type == Byte.TYPE ) return new TupleColumnByte( name, value, options);
        else if ( type == Character.TYPE ) return new TupleColumnChar( name, value, options);
        else if ( type == String.class ) return new TupleColumnString( name, value, options);
        else if ( type == Date.class ) return new TupleColumnDate( name, value, options);
        else return new TupleColumnObject( name, type, value, options);
    }
    
    public FTuple createInMemoryTuple( FTuple tuple ) {

        Tuple newTuple = new Tuple(tuple.name(),tuple.title());
        
        Value value = new Value();
        
        int nColumns = tuple.columns();
	String[] columnNames = new String[nColumns];
	Class[] columnTypes  = new Class[nColumns];
	for (int i=0; i<nColumns; i++) {
	    columnNames[i] = tuple.columnName(i);
	    columnTypes[i] = tuple.columnType(i);
            if ( tuple.column(i).hasDefaultValue() ) {
                tuple.column(i).defaultValue(value);            
                newTuple.addColumn( this.createFTupleColumn( columnNames[i], columnTypes[i], value ) );
            } else 
                newTuple.addColumn( this.createFTupleColumn( columnNames[i], columnTypes[i], null) );
        }
        
        FTupleCursor cursor = tuple.cursor();
        cursor.start();
        while( cursor.next() ) {
            for (int i=0; i<nColumns; i++) {
                tuple.columnValue(i,cursor,value);
                newTuple.fill(i, value);
            }
            newTuple.addRow();
        }
        return newTuple;
    }
        
}
