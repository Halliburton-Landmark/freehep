// Copyright 2001, FreeHEP.
package org.freehep.util.io;

import java.io.IOException;

/**
 * Encoding Exception for any of the encoding streams.
 *
 * @author Mark Donszelmann
 * @version $Id: EncodingException.java,v 1.2 2001/10/29 14:07:06 duns Exp $
 */
public class EncodingException extends IOException {

    public EncodingException(String msg) {
        super(msg);
    }
}
