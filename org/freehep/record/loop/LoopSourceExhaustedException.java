/*
 * class: LoopSourceExhaustedException
 *
 * Version $Id: LoopSourceExhaustedException.java,v 1.1 2003/05/06 23:13:16 tonyj Exp $
 *
 * Date: February 10 2003
 *
 * (c) 2003 LBNL
 */

package org.freehep.record.loop;

/**
This class is thrown by the "loop" method of the <code>{@link
SequentialRecordLoop}</code> interface if its
<code>SequentialRecordSource</code> throws a <code>EndOfSourceException</code>.
 *
 * @version $Id: LoopSourceExhaustedException.java,v 1.1 2003/05/06 23:13:16 tonyj Exp $
 * @author patton
 */
public class LoopSourceExhaustedException
		extends LoopException
{

	// public static final member data

	// protected static final member data

	// static final member data

	// private static final member data

	// private static member data

	// private instance member data

	// constructors

	/**
	 * Create an instance of this class.
	 * Default constructor is declared, but private, to stop accidental
	 * creation of an instance of the class.
	 */
	private LoopSourceExhaustedException()
	{
		super(0, 0);
	}

	/**
	 * Create an instance of this class without any detailed message.
	 *
	 * @param supplied the number of records that were supplied before the
	 * exception.
	 * @param countableSupplied the number of countable records that were
	 * supplied before the exception.
	 */
	public LoopSourceExhaustedException(long supplied, long countableSupplied)
	{
		super(supplied, countableSupplied);
	}

	/**
	 * Create an instance of this class with a detailed message.
	 *
	 * @param s the detailed message.
	 * @param supplied the number of records that were supplied before the
	 * exception.
	 * @param countableSupplied the number of countable records that were
	 * supplied before the exception.
	 */
	public LoopSourceExhaustedException(String s, long supplied,
										long countableSupplied)
	{
		super(s, supplied, countableSupplied);
	}

	// instance member function (alphabetic)

	// static member functions (alphabetic)

	// Description of this object.
	// public String toString() {}

	// public static void main(String args[]) {}
}
