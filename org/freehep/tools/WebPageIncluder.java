package org.freehep.tools;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStream;
import java.io.IOException;
import java.util.Map;
import java.util.HashMap;

import javax.xml.parsers.SAXParserFactory;
import javax.xml.transform.Result;
import javax.xml.transform.Source;
import javax.xml.transform.Templates;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.URIResolver;
import javax.xml.transform.sax.SAXSource;
import javax.xml.transform.stream.StreamSource;
import javax.xml.transform.stream.StreamResult;

import org.apache.velocity.context.Context;

public class WebPageIncluder {

    private Context context;
    private static TransformerFactory transformerFactory = TransformerFactory.newInstance();
    private static Map /*Templates*/ xslt = new HashMap();

    public WebPageIncluder(Context context) throws Exception {
        this.context = context;
    }

    /**
     * Converts 'xmlFile' using 'Menu.xslt'
     */
    public String menu(String xmlFile)
                throws TransformerConfigurationException, TransformerException {

        return xslt(xmlFile, "Menu.xslt");
    }

    /**
     * Converts 'xmlFile' using 'xsltFile'
     */
    public String xslt(String xmlFile, String xsltFile)
                throws TransformerConfigurationException, TransformerException {

        Templates templates = (Templates)xslt.get(xsltFile);
        if (templates == null) {
            // FIXME, should also load locally
            InputStream xsltInputStream = WebPageIncluder.class.getResourceAsStream("Menu.xslt");
            Source xsltSource = new StreamSource(xsltInputStream);
            templates = transformerFactory.newTemplates(xsltSource);
            xslt.put(xsltFile, templates);
        }
        Transformer transformer = templates.newTransformer();
        Object[] keys = context.getKeys();
        for (int i=0; i<keys.length; i++) {
            transformer.setParameter((String)keys[i], context.get((String)keys[i]));
        }

        File menu = new File(xmlFile);
        Source source = new StreamSource(menu);
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        Result result = new StreamResult(out);
        transformer.transform(source, result);
//        System.out.println(out);
        return out.toString();
    }

    public String xml(String xmlFile) throws IOException {
        // FIXME we should have a syntax colorizer here
        // FIXME maybe change into print stream and convert to string
        StringBuffer out = new StringBuffer("<table class=\"code\">");
        out.append("<tr>");
        out.append("<td>");
        out.append("<span class=\"codefrag\">");
        BufferedReader xml = new BufferedReader(new FileReader(xmlFile));
        String line = xml.readLine();
        while (line != null) {
            line = line.replaceAll("&","&amp;");
            line = line.replaceAll("<","&lt;");
            line = line.replaceAll("\"","&quot;");
            out.append(line);
            out.append("<br>\n");
            line = xml.readLine();
        }
        out.append("</span>");
        out.append("</td>");
        out.append("</tr>");
        out.append("</table>");
        return out.toString();
    }
}
