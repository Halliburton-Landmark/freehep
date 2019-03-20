package org.freehep.graphicsio.pdf;

/**
 * Specifies a PDFName object.
 * <p>
 * @author Mark Donszelmann
 * @version $Id: PDFName.java,v 1.1 2001/11/29 01:45:29 duns Exp $
 */
public class PDFName implements PDFConstants {
    
    private String name;
    
    PDFName(String name) {
        this.name = name;
    }
    
    public String toString() {
        return "/"+name;
    }
}