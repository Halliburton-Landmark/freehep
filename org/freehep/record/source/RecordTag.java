package org.freehep.record.source;

/** 
 * A tag that identifies records in a TaggedRecordSet. 
 * @version $Id: RecordTag.java,v 1.1 2003/03/10 21:56:06 tonyj Exp $
 */
public interface RecordTag
{
   /** Obtain a user readable name for the record corresponding to this tag.
    * @return The human readable name.
    */   
   String humanReadableName();
}
