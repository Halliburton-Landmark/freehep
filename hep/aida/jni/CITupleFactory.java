package hep.aida.jni;

import hep.aida.*;

public class CITupleFactory extends CProxy implements ITupleFactory {

    public CITupleFactory(long crefID) {
        super(crefID);
    }

    public native ITuple create(String path, String title, String[] columnNames, Class[] columnType) throws IllegalArgumentException;
    public native ITuple create(String path, String title, String[] columnNames, Class[] columnType, String options) throws IllegalArgumentException;
    public native ITuple create(String path, String title, String columns) throws IllegalArgumentException;
    public native ITuple create(String path, String title, String columns, String options) throws IllegalArgumentException;
    public native ITuple createChained(String path, String title, ITuple[] set) throws IllegalArgumentException;
    public native ITuple createChained(String path, String title, String[] set) throws IllegalArgumentException;
    public native ITuple createFiltered(String path, ITuple tuple, IFilter filter) throws IllegalArgumentException;
    public native ITuple createFiltered(String path, ITuple tuple, IFilter filter, String[] columns) throws IllegalArgumentException;
    public native IFilter createFilter(String expression);
    public native IFilter createFilter(String expression, int rowsToProcess);
    public native IFilter createFilter(String expression, int rowsToProcess, int startingRow);
    public native IEvaluator createEvaluator(String expression);
} 
