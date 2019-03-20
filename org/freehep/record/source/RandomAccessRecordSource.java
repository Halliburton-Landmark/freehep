package org.freehep.record.source;

/** 
 * A record source which (efficiently) supports random access. 
 * @version $Id: RandomAccessRecordSource.java,v 1.1 2003/03/10 21:56:05 tonyj Exp $
 */
public interface RandomAccessRecordSource extends SequentialRecordSource
{
   /** Go to a specific record, specified by index.
    * @param index The index of the record to access (numbered from 0).
    * @throws NoSuchRecordException If the specified record does not exist.
    */   
   void goToRecord(int index) throws NoSuchRecordException;
   /**
    * Return the index of the current record.
    */
   int currentIndex();
}