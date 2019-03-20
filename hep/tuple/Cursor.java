/*
 * Cursor.java
 *
 * Created on December 1, 2002, 6:36 PM
 */

package hep.tuple;

import hep.tuple.interfaces.*;

/**
 *
 * @author  The FreeHEP team @ SLAC.
 *
 */

public class Cursor implements FTupleCursor {
    
    private int endRow;
    private int startRow;
    private int currentRow;
    private boolean hasRandomAccess;
    
    protected Cursor(Tuple tuple) { 
        startRow = tuple.startRow();
        endRow = startRow+tuple.rows();
        hasRandomAccess = tuple.supportsRandomAccess();
        initCursor();
    }

    private Cursor(int startRow, int endRow ) {        
        this(startRow, endRow, false);
    }
    
    public Cursor(int startRow, int endRow, boolean hasRandomAccess ) { 
        if ( endRow < startRow ) throw new IllegalArgumentException("Wrong endRow. It has to be greater or equal to startRow");
        this.endRow = endRow;
        this.startRow = startRow;
        this.hasRandomAccess = hasRandomAccess;
        initCursor();
    }

    private void initCursor() {
        currentRow = startRow-1;
    }        
    
    public int row() { 
        return currentRow; 
    }
    
    public void start() {
        initCursor();
    }
    
    public boolean next() {
        if (currentRow+1 < endRow ) {
            currentRow++;
            return true;
        }
        return false;
    }
    
    public void setRow(int n) {
        if ( ! hasRandomAccess ) throw new IllegalArgumentException("The FTuple does not support random access");
        if (n < 0 || n >= endRow) throw new IndexOutOfBoundsException();
        currentRow = n;
    }
    
    public void close() {
    }
    
    public void skip(int rows) {
        if ( rows < 0 ) throw new IllegalArgumentException("Illegal number of rows "+rows);
        setRow( currentRow+rows );
    }
    
}

