// Copyright 2003, FreeHEP.
package org.freehep.graphicsio.ps;

import java.awt.*;
import java.io.*;
import java.util.*;
import javax.swing.*;
import javax.swing.filechooser.FileFilter;

import org.freehep.swing.ExtensionFileFilter;
import org.freehep.util.UserProperties;

/**
 *
 * @author Charles Loomis, Simon Fischer
 * @version $Id: PSExportFileType.java,v 1.7 2004/01/15 19:16:56 duns Exp $
 */
public class PSExportFileType extends AbstractPSExportFileType {

    public String getDescription() {
        return "PostScript";
    }

    public String[] getExtensions() {
        return new String[] { "ps", "PS" };
    }

    public boolean isMultipageCapable() {
        return true;
    }
    
}
