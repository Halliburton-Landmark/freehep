/*
 * class: ChainableRecordListener
 *
 * Version $Id: ChainableRecordListener.java,v 1.1 2003/05/06 23:02:05 tonyj Exp $
 *
 * Date: February 19 2003
 *
 * (c) 2003 LBNL
 */

package org.freehep.record.loop.event;

/**
This interface should be implemented by any <code>{@link
RecordListener}</code> which wants to be explicity part of a chain of
listeners. In most cases a <code>RecordListener</code> can simply use
the <code>{@link ChainableRecordListenerDecorator}</code> class which
implements this interface and allows any listener to become part of a
chain of listeners.
 *
 * @version $Id: ChainableRecordListener.java,v 1.1 2003/05/06 23:02:05 tonyj Exp $
 * @author patton
 */
public interface ChainableRecordListener
		extends RecordListener, RecordListenerManager
{

	// public static final member data

	// instance member function (alphabetic)

	// static member functions (alphabetic)
}
