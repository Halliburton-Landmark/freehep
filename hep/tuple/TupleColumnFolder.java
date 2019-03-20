/*
 * TupleColumnFolder.java
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
public class TupleColumnFolder extends TupleColumn {

    private Value value = new Value();

    /**
     * The constructor.
     * @param name The TupleColumn's name.
     * @param type The TupleColumn's type.
     * @param value The TupleColumn's default value.
     * @param options The TupleColumn's options.
     *
     */
    TupleColumnFolder(String name, FillableTuple tuple, String options) {
        super( name, FillableTuple.class, new Value().set(tuple), "length=1; maxlength=2" );
    }

    protected void createArray(int size) {
	throw new UnsupportedOperationException("createArray not supported for TupleColumnFolder");
    }

    public void value(int index, Value value) {
        value.set( ((Tuple)getDefaultValue().getObject()) );
    }

    public void fill(Value value) {
	throw new UnsupportedOperationException("fill not supported for TupleColumnFolder");
    }
    public void setValue(int index, Value value) {
	throw new UnsupportedOperationException("setValue not supported for TupleColumnFolder");
    }

    
    public void fill(FillableTuple tp) {
        /*
	ITuple folder = ((Tuple) tuple).getTuple(tuple.findColumn(getName()));
	tp.start();
	while (tp.next()) {
	    for (int i=0; i<tp.columns(); i++) {
		Class columnType = tp.columnType(i);
		if ( columnType == Integer.TYPE ) folder.fill(i, tp.getInt(i));
		else if ( columnType == Short.TYPE) folder.fill(i, tp.getShort(i));
		else if ( columnType == Long.TYPE) folder.fill(i, tp.getLong(i));
		else if ( columnType == Float.TYPE) folder.fill(i, tp.getFloat(i));
		else if ( columnType == Double.TYPE) folder.fill(i, tp.getDouble(i));
		else if ( columnType == Boolean.TYPE) folder.fill(i, tp.getBoolean(i));
		else if ( columnType == Byte.TYPE) folder.fill(i, tp.getByte(i));
		else if ( columnType == Character.TYPE) folder.fill(i, tp.getChar(i));
		else if ( columnType == ITuple.class) {
		    Tuple tOld = (Tuple) tp.getObject(i);
		    //ITuple tNew = this.copy(tOld.name(), tOld.label(), tOld, null);
		    folder.fill(i, tOld);
		}
		else folder.fill(i, tp.getObject(i));
	    }
	    folder.addRow();
	}
         */
    }
    
    
    protected boolean hasStatistics() {
        return false;
    }

    private int getColumnLength() {
        return -1;
    }

    private int getFilledRows() {
        return -1;
    }

    private boolean isOpenEnded() {
        return false;
    }

    protected void setCurrentArray( int index ) {
        throw new RuntimeException("Unsupported method");
    }

    public void addRow() {
//        throw new RuntimeException("This method is not supported by Folders");
    }

    public void resetRow() {
//        throw new RuntimeException("This method is not supported by Folders");
    }

    public void resetRows(int numberOfRows) {
//        throw new RuntimeException("This method is not supported by Folders");
    }

    public void reset() {
//        throw new RuntimeException("This method is not supported by Folders");
    }

    public void defaultValue( Value value ) {
        value.set( getDefaultValue().getObject() );
    }

    protected void currentArrayUpdated() {
    }
}

