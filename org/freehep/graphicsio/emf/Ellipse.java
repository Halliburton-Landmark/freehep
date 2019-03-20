// Copyright 2002, FreeHEP.
package org.freehep.graphicsio.emf;
import java.awt.Rectangle;
import java.io.IOException;
import org.freehep.util.io.Tag;

/**
 * Ellipse TAG.
 *
 * @author Mark Donszelmann
 * @version $Id: Ellipse.java,v 1.2 2003/09/29 22:05:54 duns Exp $
 */
public class Ellipse extends EMFTag {
    private Rectangle bounds;

    public Ellipse( Rectangle bounds ) {
        this(  );
        this.bounds = bounds;
    }

    Ellipse(  ) {
        super( 42, 1 );
    }

    public EMFTag read( int tagID, EMFInputStream emf, int len )
        throws IOException {
        Ellipse tag = new Ellipse( emf.readRECTL(  ) );

        return tag;
    }

    public void write( int tagID, EMFOutputStream emf )
        throws IOException {
        emf.writeRECTL( bounds );
    }

    public String toString(  ) {
        return super.toString(  ) + "\n" + "  bounds: " + bounds;
    }

    public Rectangle getBounds(  ) {
        return bounds;
    }
}
