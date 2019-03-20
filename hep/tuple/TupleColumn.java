/*
 * TupleColumn.java
 *
 * Created on February 12, 2002, 4:16 PM
 */

package hep.tuple;

import hep.tuple.interfaces.*;
import java.util.ArrayList;
import java.util.Map;
import org.freehep.util.Value;
import org.freehep.util.OptionParser;

/**
 *
 * @author  The FreeHEP team @ SLAC.
 *
 */
public abstract class TupleColumn implements FillableTupleColumn{

    /**
     * Each TupleColumn should be created with a given size, length = arraySize.
     * The TupleColumn is divided in three regions:
     * -1- a filled region for permanent storage.
     * -2- a stack region for temporary storage; the value on the stack
     *     is not used to calculate min, max, mean and rms.
     * -3- an unfilled region (filled with the default value if provided)
     *
     * At any given time the TupleColumn's configuration should be the
     * following:
     * - there should be nFilled rows with nFilled =< length-2.
     * - there should be a stack region with nStack = nFilled+1.
     * - there can be an unfilled set of rows.
     *
     * A TupleColumn is initialized with the default value.
     * To add data to the stack invoke the fill( value ) method.
     * To commit the stack to the filled region invoke the method addRow().
     * To reset the stack invoke the method resetRow().
     *
     * A TupleColumn comes in two flavours: open-ended or close-ended.
     * In the first case the TupleColumn's size is automatically increased by arraySize
     * when needed. In the second case the length of the array is fixed.
     * The default is an open-ended TupleColumn.
     *
     * When creating a new TupleColumn an array of the appropriate type is
     * created with length arraySize.If needed additional arrays of length arraySize
     * are created. All the arrays are stored in an ArrayList to avoid time consuming array copying.
     *
     */

    protected Value  defaultValue = null;
    protected ArrayList arrayList = new ArrayList();
    protected int arraySize;
    protected int maximumSize;
    protected int nStack;
    protected Object currentArray;
    protected int currentArrayIndex = -1;
    private boolean isOpenEnded;
    private int sizeOfLastCreatedArray;
    private int nFilled;
    private String columnName;
    private Class  columnType;
    private double minValue, maxValue;
    private double meanValue, rmsValue;
    private Value colValue = new Value();
    private boolean hasDefaultValue = false;
    private int nNaN = 0;
    private boolean calculateStatistics = true;

    /**
     * The constructor.
     * @param name The TupleColumn's name.
     * @param type The TupleColumn's type.
     * @param value The TupleColumn's default value.
     * @param length The TupleColumn's length.
     * @param maxLength The TupleColumn's maximum length. If negative the
     *                  TupleColumn is open-ended, if greater than length it
     *                  is close-ended; if greater than zero and less than length
     *                  an IllegalArgumentException is thrown.
     *
     */
    TupleColumn( String name, Class type, Value value, String options ) {

    	Map optionMap = OptionParser.parseOptions(options);

        int length = Tuple.COLUMN_ROWS;
        int maxLength = -1;
        
        if ( optionMap.containsKey( "length" ) ) length = Integer.parseInt( ( String ) ( optionMap.get( "length" ) ) );

        if ( optionMap.containsKey( "maxlength" ) ) {
            maxLength = Integer.parseInt( ( String ) ( optionMap.get( "maxlength" ) ) );
            if ( ! optionMap.containsKey( "length" ) )
                length = maxLength;
        } 
        
        if ( optionMap.containsKey("calculatestatistics") )
        	calculateStatistics = Boolean.valueOf( (String) (optionMap.get("calculatestatistics")) ).booleanValue();
                
        columnName = name;
        columnType = type;
        if ( value != null ) {
            if ( value.getObject() != null && ! ( type.isAssignableFrom(value.getType()) ) ) throw new IllegalArgumentException("The default value's type "+value.getType()+" is incompatible with the TupleColumn's type "+type);
            setDefaultValue( value );
            hasDefaultValue = true;
        }

	if ( hasStatistics() ) {
	    minValue = Double.NaN;
	    maxValue = Double.NaN;
	}

        if ( length < 0 ) throw new IllegalArgumentException("Wrong length "+length+" it must be positive!");
        arraySize = length;

        if ( maxLength < 0 ) isOpenEnded = true;
        else if ( maxLength >= length ) isOpenEnded = false;
        else throw new IllegalArgumentException("Wrong maximum length "+maxLength+" it cannot be smaller than the internal arraySize "+length);
        maximumSize = maxLength;

        reset();
    }

    public boolean hasDefaultValue() {
        return hasDefaultValue;
    }
    
    public String name() {
        return columnName;
    }

    public Class type() {
        return columnType;
    }

    public void value( FTupleCursor cursor, Value value ) {
        value( cursor.row(), value );
    }
    
    public abstract void value( int index, Value value );

    public void fill( Value value ) {
        setValue(nStack,value);
    }
    
    public abstract void setValue(int index, Value value);

    public void addRow() {
        if ( calculateStatistics && hasStatistics() ) {
            value( nStack, colValue );
            double v = colValue.getDouble();
            if ( v < minValue || Double.isNaN(minValue) ) minValue = v;
            if ( v > maxValue || Double.isNaN(maxValue) ) maxValue = v;
            if ( ! Double.isNaN(v) ) {
                meanValue += v;
                rmsValue += v*v;
            } else
                nNaN++;
        }
        nFilled = nStack;
        nStack++;

        int columnLength = getColumnLength();

        if ( nStack == columnLength ) {
            if ( !isOpenEnded() ) {
                int spaceLeft = maximumSize - columnLength;
                if ( spaceLeft < arraySize ) sizeOfLastCreatedArray = spaceLeft;
            }
            if ( sizeOfLastCreatedArray > 0 )
                createArray( sizeOfLastCreatedArray );
        }
    }

    public void resetRow() {
        if ( hasDefaultValue() )
            fill( getDefaultValue() );
    }

    public void reset() {
        arrayList.clear();
        sizeOfLastCreatedArray = arraySize;
        createArray( sizeOfLastCreatedArray );
        setCurrentArray( 0 );
        initTupleColumn();
    }

    public void minValue(Value value) {
        if ( ! hasStatistics() || nFilled < 0 ) value.set(Double.NaN);
        else value.set(minValue);
    }

    public void maxValue(Value value) {
        if ( ! hasStatistics() || nFilled < 0 ) value.set(Double.NaN);
        else value.set(maxValue);
    }

    public void meanValue(Value value) {
        if ( !hasStatistics() || nFilled < 0 ) value.set(Double.NaN);
        else value.set(meanValue/(getFilledRows()-nNaN));
    }
    public void rmsValue(Value value) {
        if ( !hasStatistics() || nFilled < 0 ) value.set(Double.NaN);
        else {
            double rows = getFilledRows()-nNaN;
            value.set(Math.sqrt( rmsValue/rows - meanValue*meanValue/rows/rows ));
        }
    }

    /**
     * Protected and Private Methods.
     *
     */
    
    /**
     * Initialize the TupleColumn.
     *
     */
    private void initTupleColumn() {
        nFilled = -1;
        nStack = 0;
        meanValue = 0.;
        rmsValue = 0.;
        nNaN = 0;
    }

    /**
     * Get the TupleColumn current length.
     * @return The TupleColumn's current length.
     *
     */
    private int getColumnLength() {
        return arraySize*( arrayList.size() - 1 ) + sizeOfLastCreatedArray;
    }

    /**
     * Get the number of filled rows of this TupleColumn.
     * @return The number of filled rows.
     *
     */
    private int getFilledRows() {
        return nFilled+1;
    }
    
    /**
     * Check if the TupleColumn is open-ended.
     * @return <code>true</code> if the TupleColumn is open-ended
     *         <code>false</code> otherwise.
     *
     */
    private boolean isOpenEnded() {
        return isOpenEnded;
    }

    /**
     * Create a new array of the appropriate type with given length.
     * @param size The size of the array to be created.
     *
     */
    abstract protected void createArray( int size );

    /**
     * Get the column's default value.
     * @return The default Value.
     *
     */
    protected Value getDefaultValue() {
        return defaultValue;
    }

    /**
     * Set the column's default value.
     * @param value The default value.
     *
     */
    protected void setDefaultValue( Value value ) {
        defaultValue = new Value(value);
    }
    
    /**
     * Does this column carry any statistic information?
     * @return <code>true</code> if the statistics is updated.
     *
     */
    protected abstract boolean hasStatistics();

    /**
     * Set the internal current array to the one corresponding to a given value's index.
     * @param index The value's index.
     *
     */
    protected void setCurrentArray( int index ) {
        if ( index < 0 || index > getFilledRows() ) {
            String message = "Illegal cursor position. ";
            if ( index < 0 ) 
                message += "next() has to be invoked after start() before accessing the data in the ITuple";
            if ( index > nFilled )
                message += "Before accessing the data start() has to be invoked.";
            throw new IllegalArgumentException(message);
        }
        int arrayIndex = index/arraySize;
        if ( arrayIndex != currentArrayIndex ) {
            currentArrayIndex = arrayIndex;
            currentArray = arrayList.get( currentArrayIndex );
            currentArrayUpdated();
        }
    }
    
    /**
     *  Update the current array in the column.
     *  This method is invoked within the setCurrentArray( int ) method when the current array is actually changed.
     *  The FTupleColumn on which the method is invoked should internally update the current array.
     * 
     */
    protected abstract void currentArrayUpdated();
        
    /**
     * Clears the values on the stack.
     */
    public void resetRows(int numberOfRows) {
        if ( hasDefaultValue() )
            fill( getDefaultValue() );
	while ( numberOfRows-- > 0 ) {
	    value( nFilled--, colValue );
	    if ( hasStatistics() ) {
		double v = colValue.getDouble();
                if ( Double.isNaN(v) )
                    nNaN--;
                else {
                    meanValue -= v;
                    rmsValue -= v*v;
                }
	    }
	    nStack--;
            if ( hasDefaultValue() )
                fill( getDefaultValue() );
	}
	if ( hasStatistics() ) calculateMinMax();
    }

    /**
     * Re-calculate Min and Max
     *
     */
    private void calculateMinMax() {
        minValue = Double.NaN; //defaultValue.getDouble();
        maxValue = Double.NaN; //defaultValue.getDouble();
	int rows = getFilledRows();
	for ( int i = 0; i<rows; i++ ) {
	    value( i, colValue );
	    double v = colValue.getDouble();
            if ( v < minValue ||Double.isNaN(minValue)) minValue = v;
            if ( v > maxValue ||Double.isNaN(maxValue)) maxValue = v;
	}
    }    
}
