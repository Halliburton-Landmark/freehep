package org.freehep.graphicsio.pdf;

import java.io.*;
import java.text.*;
import java.util.*;

/**
 * Implements the Viewer Preferences (see Table 7.1).
 * <p>
 * @author Mark Donszelmann
 * @version $Id: PDFViewerPreferences.java,v 1.1 2001/11/29 01:45:30 duns Exp $
 */
public class PDFViewerPreferences extends PDFDictionary {
    
    PDFViewerPreferences(PDF pdf, PDFByteWriter writer, PDFObject object) throws IOException {
        super(pdf, writer, object);
    }
    
    public void setHideToolbar(boolean hide) throws IOException {
        entry("HideToolbar", hide);
    }
    
    public void setHideMenubar(boolean hide) throws IOException {
        entry("HideMenubar", hide);
    }
    
    public void setHideWindowUI(boolean hide) throws IOException {
        entry("HideWindowUI", hide);
    }
    
    public void setFitWindow(boolean fit) throws IOException {
        entry("FitWindow", fit);
    }
    
    public void setCenterWindow(boolean center) throws IOException {
        entry("CenterWindow", center);
    }
    
    public void setNonFullScreenPageMode(String mode) throws IOException {
        entry("NonFullScreenPageMode", pdf.name(mode));
    }
    
    public void setDirection(String direction) throws IOException {
        entry("Direction", pdf.name(direction));
    }
}
