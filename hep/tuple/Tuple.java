/*
 * Tuple.java
 *
 * Created on December 14, 2001, 4:25 PM
 */

package hep.tuple;

import hep.tuple.interfaces.*;
import java.util.Hashtable;
import java.util.Enumeration;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.ArrayList;
import org.freehep.util.Value;

import javax.swing.event.EventListenerList;

/**
 *
 * @author  The FreeHEP team @ SLAC.
 *
 */
public class Tuple implements FillableTuple {
    
    private String title;
    private String name;
    private String options = "";
    
    protected static final int COLUMN_ROWS = 1000;
    protected int columnLength;
    protected int columnMaxLength;
    
    
    protected int startRow = 0;
    protected int endRow = -1;
    protected int filledRows = 0;
    
    protected Map optionMap;
    
    protected ArrayList tupleColumns = new ArrayList();
    protected ArrayList folderList = new ArrayList();
    protected Hashtable columnCounters = new Hashtable();
    
    protected Value tupleValue = new Value();
    
    protected Tuple(String name, String title) {
        this( name, title, "");
    }
    protected Tuple(String name, String title, String options) {
        this.name = name;
        this.title = title;
        this.options = options;
    }
    
    public void addColumn(FillableTupleColumn column) {
        tupleColumns.add( column );
    }
    
    public void removeColumn(FillableTupleColumn column) {
        tupleColumns.remove(column);
    }
    
    public int columns() {
        return tupleColumns.size();
    }
    
    public FTupleColumn column( int column ) {
        return (FTupleColumn)tupleColumns.get( column );
    }
    
    public FTupleColumn columnByName( String name ) {
        return column( columnIndexByName( name ) );
    }
    
    public int columnIndexByName(String name) {
        for ( int i = 0; i<columns(); i++ )
            if ( columnName(i).equals( name ) )
                return i;
        throw new IllegalArgumentException("Column "+name+" does not exist\n");
    }
    
    public String columnName(int column) {
        return column(column).name();
    }
    
    public Class columnType(int column) {
        return column(column).type();
    }
    
    public void columnMinValue(int column, Value value) {
        column(column).minValue(value);
    }
    
    public void columnMaxValue(int column, Value value) {
        column(column).maxValue(value);
    }
    
    public void columnMeanValue(int column, Value value) {
        column(column).meanValue(value);
    }
    
    public void columnRmsValue(int column, Value value) {
        column(column).rmsValue(value);
    }
    
    public void addRow() {
        for ( int i = 0; i < columns(); i++ )
            ((TupleColumn)column(i)).addRow();
        
        for ( Enumeration keys = columnCounters.keys(); keys.hasMoreElements(); ) {
            String folderName = (String)keys.nextElement();
            Tuple folder = (Tuple) getFolder( columnIndexByName( folderName ), filledRows );
            
            TupleColumn tc = (TupleColumn)columnCounters.get( folderName );
            tc.fill( tupleValue.set( folder.startRow()+folder.rows() ) );
            tc.addRow();
        }
        filledRows++;
    }
    
    public void resetRow() {
        for ( int i = 0; i<columns(); i++ )
            ((TupleColumn)tupleColumns.get(i)).resetRow();
        for ( Enumeration keys = columnCounters.keys(); keys.hasMoreElements(); ) {
            String folderName = (String)keys.nextElement();
            Tuple folder = (Tuple) getFolder( columnIndexByName( folderName ), filledRows );
            folder.resetRows( folder.rows() );
            TupleColumn tc = (TupleColumn)columnCounters.get( folder.name() );
            tc.resetRow();
        }
    }
    
    public void reset() {
        for ( int i = 0; i<columns(); i++ )
            ((TupleColumn)tupleColumns.get(i)).reset();
        filledRows = 0;
    }
    
    public int rows() {
        if ( endRow != -1 ) return endRow-startRow;
        return filledRows-startRow;
    }
    
    public void close() {
    }
    
    public FTupleCursor cursor() throws IllegalStateException {
        return new Cursor(this);
    }
    
    public boolean supportsMultipleCursors() {
        return true;
    }
    
    public boolean supportsRandomAccess() {
        return true;
    }
    
    public String title() {
        return title;
    }
    
    public String name() {
        return name;
    }
    
    
    /**
     * Get the start Point.
     * @return The start point.
     *
     */
    public int startRow() {
        return startRow;
    }
    
    /**
     * Set the start row.
     * @param startRow The start row.
     *
     */
    protected void setStartEndRow( int startRow, int endRow ) {
        this.startRow = startRow;
        this.endRow = endRow;
    }
    
    
    /**
     * Clears the values on the stack.
     */
    public void resetRows( int numberOfRows ) {
        for ( int i = 0; i<columns(); i++ )
            ((TupleColumn)tupleColumns.get(i)).resetRows( numberOfRows );
        int cf = filledRows;
        filledRows -= numberOfRows;
        
        for ( Enumeration keys = columnCounters.keys(); keys.hasMoreElements(); ) {
            String folderName = (String)keys.nextElement();
            while ( numberOfRows-- > 0 ) {
                cf--;
                Tuple folder = (Tuple) getFolder( columnIndexByName( folderName ), cf );
                TupleColumn tc = (TupleColumn)columnCounters.get( folder.name() );
                
                tc.value(numberOfRows, tupleValue);
                int end =  tupleValue.getInt();
                int start = 0;
                if ( numberOfRows > 0 ) {
                    tc.value(numberOfRows-1, tupleValue);
                    start =  tupleValue.getInt();
                }
                folder.setStartEndRow(start,end);
                folder.resetRows( folder.rows() );
                
                tc.resetRows(1);
            }
        }
    }
    
    
    
    /**
     * Get Folder at the current cursor position.
     * @param index The column's index of the Folder.
     * @return The folder.
     *
     */
    public FTuple tuple(int index) {
        return getFolder( index, filledRows );
    }
    
    /**
     * Get a Folder in a given configuration.
     * @param index The column's index for this Folder.
     * @param cursor The cursor position for the Folder.
     *
     */
    protected Tuple getFolder( int index, int cursor ) {
        Tuple tup = (Tuple)((TupleColumn)tupleColumns.get( index )).getDefaultValue().getObject();
        TupleColumn tc = (TupleColumn)columnCounters.get( tup.name() );
        if ( cursor > -1 && cursor < filledRows ) {
            tc.value(cursor, tupleValue);
            int end = tupleValue.getInt();
            int start = 0;
            if ( cursor > 0 ) {
                tc.value(cursor-1, tupleValue);
                start = tupleValue.getInt();
            }
            tup.setStartEndRow( start, end );
        } else if ( cursor == filledRows && cursor > 0 ) {
            tc.value(cursor-1, tupleValue);
            int start = tupleValue.getInt();
            tup.setStartEndRow( start, -1 );
        }
        return (Tuple) tup;
    }
    
    public void columnValue(int column, FTupleCursor cursor, Value value) {
        if ( columnType( column ) != FillableTuple.class )
            ( (TupleColumn)column(column) ).value(cursor, value);
        else
            value.set( getFolder( column, cursor.row() ) );
    }
    
    public void fill(int column, Value value) {
        ((TupleColumn)column(column)).fill( value );
    }
    
    public void addTuple(FillableTuple tuple) {
        columnCounters.put( ((Tuple)tuple).name(), new TupleColumnInt( ((Tuple)tuple).name(), new Value().set((int)0), "length=1000; maxlength=-1") );
        addColumn( new TupleColumnFolder( ((Tuple)tuple).name(), tuple, "" ) );
        folderList.add(tuple);
    }
    
    public void removeTuple(FillableTuple tuple) {
        String name = ((Tuple)tuple).name();
        columnCounters.remove(name);
        FTupleColumn col = columnByName(name);
        removeColumn((FillableTupleColumn)col);
        folderList.remove(tuple);
    }    
    
    public boolean isInMemory() {
        return true;
    }
    
}
