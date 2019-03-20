package org.freehep.tools;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.InputStream;

import javax.xml.parsers.SAXParserFactory;
import javax.xml.transform.Result;
import javax.xml.transform.Source;
import javax.xml.transform.Templates;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.sax.SAXSource;
import javax.xml.transform.stream.StreamSource;
import javax.xml.transform.stream.StreamResult;

import org.xml.sax.EntityResolver;
import org.xml.sax.InputSource;
import org.xml.sax.XMLReader;

import org.apache.velocity.context.Context;
import org.apache.velocity.exception.ResourceNotFoundException;
import org.apache.velocity.runtime.resource.loader.FileResourceLoader;

public class WebPageFileResourceLoader extends FileResourceLoader {

    private Context context;

    public WebPageFileResourceLoader() throws Exception {
//        System.out.println("Construct: "+getClass());
        WebPage.setResourceLoader(this);
    }

    public void setContext(Context context) {
        this.context = context;
    }

    public InputStream getResourceStream(String templateName)
            throws ResourceNotFoundException {
//        System.out.println("Resource: "+templateName);
        if (templateName.endsWith(".vm")) {
            // FIXME handle special filter here
            context.put("title", templateName);
        }

        try {
            return super.getResourceStream(templateName);
        } catch (ResourceNotFoundException rnfe) {
        }

        return WebPage.class.getResourceAsStream(templateName);
    }
}
