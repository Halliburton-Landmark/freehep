// Copyright 2003, FreeHEP.
package org.freehep.graphicsio;

import java.util.*;
import javax.imageio.*;

/**
 * This interface is to be implemented by sub classes of ImageWriteParam
 * to make properties available to the ImageWriter as an ImageWriteParam object.
 *
 * @author Mark Donszelmann
 * @version $Id: ImageParamConverter.java,v 1.1 2003/04/30 00:24:00 duns Exp $
 */
public interface ImageParamConverter {

    /**
     * Returns a subclass of ImageWriteParam with all the
     * instance variable set according to the properties
     */
    public ImageWriteParam getWriteParam(Properties properties);
}

