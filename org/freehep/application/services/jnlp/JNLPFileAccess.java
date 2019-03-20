/*
 * JNLPFileAccess.java
 *
 * Created on February 22, 2001, 11:39 AM
 */

package org.freehep.application.services.jnlp;
import org.freehep.application.services.*;
import javax.jnlp.*;
import java.io.*;

/**
 * Implementation of FileAccess for use in unsigned JNLP applications.
 * @author tonyj
 * @version $Id: JNLPFileAccess.java,v 1.1 2001/02/23 01:18:08 tonyj Exp $
 */
public class JNLPFileAccess implements FileAccess
{
    private FileContents fc;
    
    /** Creates new JNLPFileAccess */
    public JNLPFileAccess(FileContents fc) 
    {
        this.fc = fc;
    }
    public boolean canRead() throws IOException 
    {
        return fc.canRead();
    }
    public boolean canWrite() throws IOException 
    {
        return fc.canWrite();
    }
    public InputStream getInputStream() throws IOException
    {
        return fc.getInputStream();
    }
    public OutputStream getOutputStream(boolean append) throws IOException 
    {
        return fc.getOutputStream(append);
    }
    public String getName() throws IOException 
    {
        return fc.getName();
    }
    public long getLength() throws IOException 
    {
        return fc.getLength();
    }
    public long getMaxLength() throws IOException 
    {
        return fc.getMaxLength();
    }
    public long setMaxLength(long length) throws IOException 
    {
        return fc.setMaxLength(length);
    }
    public File getFile() throws IOException, SecurityException 
    {
        throw new SecurityException("JNLP does not allow access to File");
    }
}

