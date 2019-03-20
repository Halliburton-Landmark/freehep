/*
 * AidaXMLStore.java
 *
 * Created on October 28, 2002, 5:26 PM
 */
package hep.aida.ref.xml;

import hep.aida.dev.IStore;
import hep.aida.dev.IDevTree;

import java.io.BufferedInputStream;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Map;
import java.util.zip.GZIPInputStream;
import java.util.zip.GZIPOutputStream;

import org.freehep.xml.util.ClassPathEntityResolver;

import org.xml.sax.EntityResolver;
import org.xml.sax.InputSource;


/**
 *
 * @author tonyj
 * @version $Id: AidaXMLStore.java,v 1.10 2004/08/05 21:01:55 turri Exp $
 */
public class AidaXMLStore implements IStore
{
   public boolean isReadOnly()
   {
      return false;
   }

   public void read(IDevTree tree, Map optionsMap, boolean readOnly, boolean createNew) throws IOException
   {
      File file = new File(tree.storeName());
      boolean exists = file.exists();
      //System.out.println("AidaXMLStore:  name="+tree.storeName()+", exists="+exists+",  readOnly="+readOnly+",  createNew="+createNew);
      if (!exists && (readOnly || !createNew))
      {
         throw new IOException("File " + file + " does not exist.");
      }
      if (exists)
      {
         readOnly |= file.canWrite();

         InputStream in;
         try
         {
            in = new java.util.zip.GZIPInputStream(new FileInputStream(file));
         }
         catch (IOException x)
         {
            in = new BufferedInputStream(new FileInputStream(file));
         }
         try
         {
            EntityResolver er = new ClassPathEntityResolver("aida.dtd", AidaParser.class);
            AidaParser parser = new AidaParser(new AidaHandlerImpl(tree), er);
            String validateString = (String) optionsMap.get("validate");
            boolean validate = (validateString == null) || validateString.equalsIgnoreCase("true");
            parser.setValidate(true);

            InputSource is = new InputSource(in);
            is.setSystemId(tree.storeName());
            parser.parse(is);
         }
         catch (Exception x)
         {
            IOException xx = new IOException("Error reading " + tree.storeName());
            xx.initCause(x);
            throw xx;
         }
         finally
         {
            if (in != null)
            {
               in.close();
            }
         }
      }
   }

   public void commit(IDevTree tree, Map optionsMap) throws IOException
   {
      String cString = (String) optionsMap.get("compress");
      boolean compress = (cString == null) || cString.equalsIgnoreCase("yes") || cString.equalsIgnoreCase("true");

      File file = new File(tree.storeName());
      Writer writer;
      if (compress)
      {
         writer = new OutputStreamWriter(new GZIPOutputStream(new FileOutputStream(file)));
      }
      else
      {
         writer = new BufferedWriter(new FileWriter(file));
      }
      AidaXMLWriter out = new AidaXMLWriter(writer);
      out.toXML(tree);
      out.close();
   }
   
   public void close()
   {
   }
   
}
