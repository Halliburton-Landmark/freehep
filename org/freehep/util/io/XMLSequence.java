// Copyright 2003, FreeHEP.
package org.freehep.util.io;

import java.io.*;
import java.util.*;

/**
 * The XMLSequence allows parsing by an XML Parser of concatenated XML segments. 
 * Each segment needs to start with "<?xml". If the underlying stream contains
 * just one segment "<xml?" may be left out. 
 * Methods hasNext() and next() should be called to retrieve the inputstream for the 
 * XMLParser.
 *
 * Typical usage:
 * <PRE>
 *   XMLSequence sequence = new XMLSequence(new FileInputStream("file.xml"));
 *   
 *   SAXParserFactory factory = SAXParserFactory.newInstance();
 *   XMLReader xmlReader = factory.newSAXParser().getXMLReader();
 *   
 *   while (sequence.hasNext()) {
 *       InputStream input = sequence.next();
 *       InputSource source = new InputSource(input);
 *       xmlReader.parse(source);
 *       input.close();
 *   }
 *   sequence.close();
 * </PRE>
 *
 * IMPORTANT: inherits from InputStream rather than FilterInputStream
 * so that the correct read(byte[], int, int) method is used.
 *
 * @author Mark Donszelmann
 * @version $Id: XMLSequence.java,v 1.4 2004/07/24 06:05:18 duns Exp $
 */
public class XMLSequence extends InputStream {

    // xml declaration (lowercase!)
    private int[] xml = new int[] {'<', '?', 'x', 'm', 'l'};
    private int xmlIndex;
    
    // look ahead buffer
    private int buffer[] = new int[xml.length];
    private int index;
    private boolean bufferEmpty;
    
    // underlying stream
    private InputStream in;
    private boolean closed;
    private boolean eof;
    
    public XMLSequence(InputStream input) {
        super();
        in = input;
        closed = false;
        eof = false;
        xmlIndex = 0;
        index = 0;
        bufferEmpty = true;
    }
    
    public boolean hasNext() {
        if (closed) return false;
        
        try {
            return readUntilXMLDeclaration();
        } catch (IOException e) {
            return false;
        }
    } 
    
    public InputStream next() throws IOException {
        if (eof) throw new NoSuchElementException(getClass()+": at EOF.");
        if (closed) throw new NoSuchElementException(getClass()+": already closed.");
        
        if (!readUntilXMLDeclaration()) throw new NoSuchElementException(getClass()+": No more sequences.");
        
        xmlIndex = 0;        
        return new NoCloseInputStream(this);
    }

    public int read() throws IOException {
        if (xmlIndex == xml.length) return -1;
        if (closed) return -1;
        
        int a = -1;
        if (!eof) {
            
            // fill buffer (at start of stream) 
            if (bufferEmpty) {
                index = 0;
                for (int i=0; i<xml.length; i++) {
                    int c = in.read();
                    buffer[i] = c;
                    if (buffer[i] == xml[xmlIndex]) {
                        // we are reading <?xml or <
                        xmlIndex++;
                    } else if (xmlIndex > 0) {
                        // we are reading <..., which is also fine.
                        xmlIndex++;
                    } else {
                        xmlIndex = 0;
                    }
                }
                bufferEmpty = false;
                
                if (xmlIndex == xml.length) return -1;
            }        
            
            // read next character
            a = in.read();
            if (a != -1) {                
                // check if seq
                if (a == xml[xmlIndex]) {
                    xmlIndex++;
                } else {
                    xmlIndex = 0;
                }
            } else {
                // underlying end-of-file
                eof = true;
            }
        }
        
        // returned all...
        if (eof && (buffer[index] == -1)) return -1;
        
        // replace and return next character
        int b = buffer[index];
        buffer[index] = a;
        index = (index + 1) % buffer.length;
        return b;
    }

    public void mark(int readLimit) {
        in.mark(readLimit);
    }
        
    public boolean markSupported() {
        return in.markSupported();
    }
        
    public void reset() throws IOException {
        if (closed) throw new IOException(getClass()+": already closed.");
        
        if (!in.markSupported()) throw new IOException(getClass()+": does not support reset().");
        
        in.reset();
        xmlIndex = 0;
        index = 0;
        bufferEmpty = true;
        eof = false;
    }
    
    public void close() throws IOException {
        if (!closed) {
            in.close();
            closed = true;
        }
    }
    
    private boolean readUntilXMLDeclaration() throws IOException {
        while (read() >= 0);
        return (xmlIndex == xml.length);
    }
}
