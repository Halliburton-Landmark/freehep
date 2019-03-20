// Copyright 2001, FreeHEP.
package org.freehep.graphicsio.swf;

import java.io.IOException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

/**
 * Protect TAG.
 *
 * @author Mark Donszelmann
 * @author Charles Loomis
 * @version $Id: Protect.java,v 1.2 2003/04/15 18:03:05 duns Exp $
 */
public class Protect
    extends ControlTag {

    private String password;

    public Protect(String password) {
        this();

        this.password = password;
        if (password != null) {
            try {
                MessageDigest md5 = MessageDigest.getInstance("MD5");
                byte[] b = md5.digest(password.getBytes());
                this.password = new String(b);
            } catch (NoSuchAlgorithmException nsae) {
            }
        }
    }

    public Protect() {
        super(24, 2);
    }

    public SWFTag read(int tagID, SWFInputStream swf, int len)
        throws IOException {

        if (len != 0) {
            Protect tag = new Protect();
            tag.password = new String(swf.readByte(len));
            return tag;
        } else {
            return this;
        }
    }

    public void write(int tagID, SWFOutputStream swf) throws IOException {
        if ((password != null) && (swf.getVersion() >= 5)) {
            swf.writeByte(password.getBytes());
        }
    }
}
