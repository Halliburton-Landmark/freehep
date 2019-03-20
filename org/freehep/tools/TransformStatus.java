package org.freehep.tools;

import javax.xml.transform.*;
import javax.xml.transform.dom.*;
import javax.xml.transform.stream.*;
import java.io.*;

public class TransformStatus
{
   public static void main(String[] args) throws Exception
   {
      if (args.length < 2 || args.length > 3) usage(); 
      File xml = new File(args[0]); // Document to be transformed
      File out = new File(args[1]); // Where to put result document
      File xslt = args.length>2 ? new File(args[2]) : null; // Source for transformation
      
      Source xsltSource = xslt != null ? new StreamSource(xslt) :
         new StreamSource(TransformStatus.class.getResourceAsStream("project.xslt"));
         Source source = new StreamSource(xml);
         Result result = new StreamResult(out);
         
         // Start off with a factory object
         TransformerFactory tf = TransformerFactory.newInstance();
         // Use the factory to read the XSLT file into a Templates object
         Templates transformation = tf.newTemplates(xsltSource);
         // Create a Transformer object from the Templates object
         Transformer transformer = transformation.newTransformer();
         // Finally, perform the transformation
         transformer.transform(source, result);
   }
   private static void usage()
   {
      System.out.println("java "+TransformStatus.class.getName()+" <infile> <outfile> <xsltfile>");
      System.exit(0);
   }
}
