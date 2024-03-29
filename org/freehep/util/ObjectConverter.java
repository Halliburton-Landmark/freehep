// Copyright 2004, FreeHEP.
package org.freehep.util;


/**
 * Object converter which allows conversion of objects of one class into another.
 *
 *
 * @author Mark Donszelmann
 * @version $Id: ObjectConverter.java,v 1.1 2004/07/26 19:03:49 duns Exp $
 */
public interface ObjectConverter {

    /**
     * Returns the class the given source object can be converterd to by this converter.
     * Returns null if the given source object cannot be converted.
     */
    public Class convertsTo(Object source);

    /**
     * Returns the converted source object of a class compatible with the one returned under convertsTo().
     */
    public Object convert(Object source);  
} 

