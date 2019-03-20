// Copyright 2000, CERN, Geneva, Switzerland and University of Santa Cruz, California, U.S.A.
package org.freehep.graphicsio.ppm;

import javax.imageio.*;
import javax.imageio.spi.*;

import org.freehep.graphicsio.exportchooser.ImageExportFileType;

/**
 *
 * @author Charles Loomis
 * @version $Id: PPMExportFileType.java,v 1.8 2003/06/05 17:23:42 tonyj Exp $
 */
public class PPMExportFileType extends ImageExportFileType {

    static {
        try {
            Class clazz = Class.forName("org.freehep.graphicsio.ppm.PPMImageWriterSpi");
            IIORegistry.getDefaultInstance().registerServiceProvider(clazz.newInstance(), ImageWriterSpi.class);
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public PPMExportFileType() {
        super("ppm");
    }
    
}
