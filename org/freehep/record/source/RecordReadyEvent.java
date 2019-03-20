package org.freehep.record.source;

import java.util.EventObject;

/**
 *
 * @version $Id: RecordReadyEvent.java,v 1.1 2003/03/10 21:56:06 tonyj Exp $
 */
public class RecordReadyEvent extends EventObject
{
   RecordReadyEvent(AsynchronousRecordSource source)
   {
      super(source);
   }
}
