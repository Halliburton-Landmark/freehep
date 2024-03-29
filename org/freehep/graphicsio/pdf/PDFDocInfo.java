package org.freehep.graphicsio.pdf;

import java.io.*;
import java.text.*;
import java.util.*;

/**
 * Implements the Document Information Dictionary (see Table 8.2).
 * <p>
 * @author Mark Donszelmann
 * @version $Id: PDFDocInfo.java,v 1.1 2001/11/29 01:45:29 duns Exp $
 */
public class PDFDocInfo extends PDFDictionary {
    
    PDFDocInfo(PDF pdf, PDFByteWriter writer, PDFObject parent) throws IOException {
        super(pdf, writer, parent);
    }
    
    public void setTitle(String title) throws IOException {
        entry("Title", title);
    }
    
    public void setAuthor(String author) throws IOException {
        entry("Author", author);
    }
    
    public void setSubject(String subject) throws IOException {
        entry("Subject", subject);
    }
    
    public void setKeywords(String keywords) throws IOException {
        entry("Keywords", keywords);
    }
    
    public void setCreator(String creator) throws IOException {
        entry("Creator", creator);
    }
    
    public void setProducer(String producer) throws IOException {
        entry("Producer", producer);
    }
    
    public void setCreationDate(Calendar date) throws IOException {
        entry("CreationDate", date);
    }
    
    public void setModificationDate(Calendar date) throws IOException {
        entry("ModDate", date);
    }
    
    public void setTrapped(String name) throws IOException {
        entry("Trapped", pdf.name(name));
    }    
}
