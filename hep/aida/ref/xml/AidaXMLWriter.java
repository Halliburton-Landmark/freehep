/*
 * XMLConverter.java
 *
 * Created on April 25, 2001, 11:39 AM
 */
package hep.aida.ref.xml;

import hep.aida.*;
import hep.aida.IFunction;
import hep.aida.IRangeSet;

import hep.aida.dev.*;

import hep.aida.ref.*;
import hep.aida.ref.histogram.*;
import hep.aida.ref.tuple.*;

import java.io.*;
import java.util.*;

import org.freehep.xml.util.XMLWriter;


/**
 * Convert AIDA objects to XML.
 * @author tonyj
 * @version $Id: AidaXMLWriter.java,v 1.14 2005/09/28 14:52:49 turri Exp $
 */
class AidaXMLWriter extends XMLWriter
{
    AidaXMLWriter(Writer writer) throws IOException
   {
      super(writer);
      openDoc("1.0", "ISO-8859-1", false);

      referToDTD("aida", "http://aida.freehep.org/schemas/" + IConstants.AIDA_VERSION + "/aida.dtd");
      setAttribute("version", IConstants.AIDA_VERSION);
      openTag("aida");

      setAttribute("package", "FreeHEP");
      setAttribute("version", "1.1");
      printTag("implementation");
   }

   public void close() throws IOException
   {
      closeTag();
      super.close();
   }

   private String binNumbToString(int bin)
   {
      if (bin == -2)
      {
         return "UNDERFLOW";
      }
      else if (bin == -1)
      {
         return "OVERFLOW";
      }
      else
      {
         return String.valueOf(bin);
      }
   }

   void toXML(ITree tree)
   {
      String[] objNames = tree.listObjectNames("/", true);
      for (int i = 0; i < objNames.length; i++)
      {
         int pos = objNames[i].lastIndexOf('/');
         if ((pos + 1) == objNames[i].length())
         {
            continue;
         }
         toXML(tree.find(objNames[i]), objNames[i].substring(0, pos + 1));
      }
   }

   private void toXML(IManagedObject o, String path)
   {
      if (o instanceof IHistogram1D)
      {
         toXML((IHistogram1D) o, path);
      }
      else if (o instanceof IHistogram2D)
      {
         toXML((IHistogram2D) o, path);
      }
      else if (o instanceof IHistogram3D)
      {
         toXML((IHistogram3D) o, path);
      }
      else if (o instanceof ICloud1D)
      {
         toXML((ICloud1D) o, path);
      }
      else if (o instanceof ICloud2D)
      {
         toXML((ICloud2D) o, path);
      }
      else if (o instanceof ICloud3D)
      {
         toXML((ICloud3D) o, path);
      }
      else if (o instanceof ITuple)
      {
         toXML((ITuple) o, path);
      }
      else if (o instanceof IDataPointSet)
      {
         toXML((IDataPointSet) o, path);
      }
      else if (o instanceof IProfile1D)
      {
         toXML((IProfile1D) o, path);
      }
      else if (o instanceof IProfile2D)
      {
         toXML((IProfile2D) o, path);
      }
      else if ( o instanceof IFunction )
      {
          toXML( (IFunction) o, path);
      }

      // otherwise silently ignore
   }

   private void toXML(IHistogram1D h, String path)
   {
      String name = ((IManagedObject) h).name();
      setAttribute("name", name);

      String title = h.title();
      if ((title != null) && (title != null) && !title.equals(""))
      {
         setAttribute("title", title);
      }
      if ( (path != null) && !path.equals(""))
      {
         setAttribute("path", path);
      }

      openTag("histogram1d");

      IAnnotation annotation = h.annotation();
      if (annotation != null)
      {
         toXML(annotation);
      }

      writeHistogramAxis(h.axis(), "x");

      setAttribute("entries", h.entries());
      openTag("statistics");
      setAttribute("direction", "x");
      setAttribute("mean", h.mean());
      setAttribute("rms", h.rms());
      printTag("statistic");
      closeTag();

      openTag("data1d");

      int bins = h.axis().bins();
      for (int i = -2; i < h.axis().bins(); i++)
      {
         double height = h.binHeight(i);
         double error = h.binError(i);
         int entries = h.binEntries(i);
         if ((height != 0) && (error != 0))
         {
            setAttribute("binNum", binNumbToString(i));
            if (h instanceof Histogram1D)
            {
               setAttribute("weightedMean", ((Histogram1D) h).binMean(i));
               setAttribute("weightedRms", ((Histogram1D) h).binRms(i));
            }
            
            if ( height != entries ) {            
                setAttribute("height", height);
                setAttribute("error", error);
            }

            //setAttribute("error2","fix me");
            setAttribute("entries", entries);
            printTag("bin1d");
         }
      }
      closeTag();
      closeTag();
   }

   private void toXML(IHistogram2D h, String path)
   {
      String name = ((IManagedObject) h).name();
      setAttribute("name", name);

      String title = h.title();
      if ((title != null) && !title.equals(""))
      {
         setAttribute("title", title);
      }
      if ((path != null) && !path.equals(""))
      {
         setAttribute("path", path);
      }
      openTag("histogram2d");

      IAnnotation annotation = h.annotation();
      if (annotation != null)
      {
         toXML(annotation);
      }

      writeHistogramAxis(h.xAxis(), "x");
      writeHistogramAxis(h.yAxis(), "y");

      setAttribute("entries", h.entries());
      openTag("statistics");
      setAttribute("direction", "x");
      setAttribute("mean", h.meanX());
      setAttribute("rms", h.rmsX());
      printTag("statistic");
      setAttribute("direction", "y");
      setAttribute("mean", h.meanY());
      setAttribute("rms", h.rmsY());
      printTag("statistic");
      closeTag();

      openTag("data2d");

      int xbins = h.xAxis().bins();
      int ybins = h.yAxis().bins();
      for (int i = -2; i < xbins; i++)
      {
         for (int j = -2; j < ybins; j++)
         {
            double height = h.binHeight(i, j);
            double error = h.binError(i, j);
            int entries = h.binEntries(i, j);
            if ((height != 0) && (error != 0))
            {
               setAttribute("binNumX", binNumbToString(i));
               setAttribute("binNumY", binNumbToString(j));
               if (h instanceof Histogram2D)
               {
                  setAttribute("weightedMeanX", ((Histogram2D) h).binMeanX(i, j));
                  setAttribute("weightedMeanY", ((Histogram2D) h).binMeanY(i, j));
                  setAttribute("weightedRmsX", ((Histogram2D) h).binRmsX(i, j));
                  setAttribute("weightedRmsY", ((Histogram2D) h).binRmsY(i, j));
               }
               
               if ( height != entries ) {
                   setAttribute("height", height);
                   setAttribute("error", error);
               }

               //setAttribute("error2","fix me");
               setAttribute("entries", entries);
               printTag("bin2d");
            }
         }
      }
      closeTag();
      closeTag();
   }

   private void toXML(IHistogram3D h, String path)
   {
      String name = ((IManagedObject) h).name();
      setAttribute("name", name);

      String title = h.title();
      if ((title != null) && !title.equals(""))
      {
         setAttribute("title", title);
      }
      if ((path != null) && !path.equals(""))
      {
         setAttribute("path", path);
      }
      openTag("histogram3d");

      IAnnotation annotation = h.annotation();
      if (annotation != null)
      {
         toXML(annotation);
      }

      writeHistogramAxis(h.xAxis(), "x");
      writeHistogramAxis(h.yAxis(), "y");
      writeHistogramAxis(h.zAxis(), "z");

      setAttribute("entries", h.entries());
      openTag("statistics");
      setAttribute("direction", "x");
      setAttribute("mean", h.meanX());
      setAttribute("rms", h.rmsX());
      printTag("statistic");
      setAttribute("direction", "y");
      setAttribute("mean", h.meanY());
      setAttribute("rms", h.rmsY());
      printTag("statistic");
      setAttribute("direction", "z");
      setAttribute("mean", h.meanZ());
      setAttribute("rms", h.rmsZ());
      printTag("statistic");
      closeTag();

      openTag("data3d");

      int xbins = h.xAxis().bins();
      int ybins = h.yAxis().bins();
      int zbins = h.zAxis().bins();
      for (int i = -2; i < xbins; i++)
      {
         for (int j = -2; j < ybins; j++)
         {
            for (int k = -2; k < zbins; k++)
            {
               double height = h.binHeight(i, j, k);
               double error = h.binError(i, j, k);
               int entries = h.binEntries(i, j, k);
               if ((height != 0) && (error != 0))
               {
                  setAttribute("binNumX", binNumbToString(i));
                  setAttribute("binNumY", binNumbToString(j));
                  setAttribute("binNumZ", binNumbToString(k));
                  if (h instanceof Histogram3D)
                  {
                     setAttribute("weightedMeanX", ((Histogram3D) h).binMeanX(i, j, k));
                     setAttribute("weightedMeanY", ((Histogram3D) h).binMeanY(i, j, k));
                     setAttribute("weightedMeanZ", ((Histogram3D) h).binMeanZ(i, j, k));
                     setAttribute("weightedRmsX", ((Histogram3D) h).binRmsX(i, j, k));
                     setAttribute("weightedRmsY", ((Histogram3D) h).binRmsY(i, j, k));
                     setAttribute("weightedRmsZ", ((Histogram3D) h).binRmsZ(i, j, k));
                  }
                  
                  if ( height != entries ) {
                      setAttribute("height", height);
                      setAttribute("error", error);
                  }

                  //setAttribute("error2","fix me");
                  setAttribute("entries", entries);
                  printTag("bin3d");
               }
            }
         }
      }
      closeTag();
      closeTag();
   }

   private void toXML(ICloud1D c, String path)
   {
      setAttribute("name", ((IManagedObject) c).name());
      setAttribute("maxEntries", ((Cloud) c).maxEntries());

      String title = c.title();
      if ((title != null) && !title.equals(""))
      {
         setAttribute("title", title);
      }
      if ((path != null) && !path.equals(""))
      {
         setAttribute("path", path);
      }

      String options = ((Cloud) c).getOptions();
      if ((options != null) && !options.equals(""))
      {
         setAttribute("options", options);
      }
      
      if ( c instanceof Cloud1D ) {
          Cloud1D cl = (Cloud1D) c;
          setAttribute("conversionBins", cl.conversionBins() );
          double le = cl.conversionLowerEdge();
          if ( ! Double.isNaN(le) )
              setAttribute("conversionLowerEdge",le);
          double ue = cl.conversionUpperEdge();
          if ( ! Double.isNaN(ue) )
              setAttribute("conversionUpperEdge",ue);
      }

      IHistogram1D hist = null;
      try
      {
         hist = c.histogram();
         setAttribute("lowerEdgeX", c.lowerEdge());
         setAttribute("upperEdgeX", c.upperEdge());
      }
      catch (RuntimeException re)
      {
      }
      openTag("cloud1d");

      IAnnotation annotation = c.annotation();
      if (annotation != null)
      {
         toXML(annotation);
      }

      if (hist != null)
      {
         toXML(hist, path);
      }
      else
      {
         openTag("entries1d");
         for (int i = 0; i < c.entries(); i++)
         {
            setAttribute("valueX", c.value(i));

            double w = c.weight(i);
            if (w != 1.)
            {
               setAttribute("weight", w);
            }
            printTag("entry1d");
         }
         closeTag();
      }
      closeTag();
   }

   private void toXML(ICloud2D c, String path)
   {
      setAttribute("name", ((IManagedObject) c).name());
      setAttribute("maxEntries", ((Cloud) c).maxEntries());

      String title = c.title();
      if ((title != null) && !title.equals(""))
      {
         setAttribute("title", title);
      }
      if ((path != null) && !path.equals(""))
      {
         setAttribute("path", path);
      }

      String options = ((Cloud) c).getOptions();
      if ((options != null) && !options.equals(""))
      {
         setAttribute("options", options);
      }

      if ( c instanceof Cloud2D ) {
          Cloud2D cl = (Cloud2D) c;
          setAttribute("conversionBinsX", cl.conversionBinsX() );
          double lex = cl.conversionLowerEdgeX();
          if ( ! Double.isNaN(lex) )
              setAttribute("conversionLowerEdgeX",lex);
          double uex = cl.conversionUpperEdgeX();
          if ( ! Double.isNaN(uex) )
              setAttribute("conversionUpperEdgeX",uex);
          setAttribute("conversionBinsY", cl.conversionBinsY() );
          double ley = cl.conversionLowerEdgeY();
          if ( ! Double.isNaN(ley) )
              setAttribute("conversionLowerEdgeY",ley);
          double uey = cl.conversionUpperEdgeY();
          if ( ! Double.isNaN(uey) )
              setAttribute("conversionUpperEdgeY",uey);
      }

      IHistogram2D hist = null;
      try
      {
         hist = c.histogram();
         setAttribute("lowerEdgeX", c.lowerEdgeX());
         setAttribute("upperEdgeX", c.upperEdgeX());
         setAttribute("lowerEdgeY", c.lowerEdgeY());
         setAttribute("upperEdgeY", c.upperEdgeY());
      }
      catch (RuntimeException re)
      {
      }
      openTag("cloud2d");

      IAnnotation annotation = c.annotation();
      if (annotation != null)
      {
         toXML(annotation);
      }

      if (hist != null)
      {
         toXML(hist, path);
      }
      else
      {
         openTag("entries2d");
         for (int i = 0; i < c.entries(); i++)
         {
            setAttribute("valueX", c.valueX(i));
            setAttribute("valueY", c.valueY(i));

            double w = c.weight(i);
            if (w != 1.)
            {
               setAttribute("weight", w);
            }
            printTag("entry2d");
         }
         closeTag();
      }
      closeTag();
   }

   private void toXML(ICloud3D c, String path)
   {
      setAttribute("name", ((IManagedObject) c).name());
      setAttribute("maxEntries", ((Cloud) c).maxEntries());

      String title = c.title();
      if ((title != null) && !title.equals(""))
      {
         setAttribute("title", title);
      }
      if ((path != null) && !path.equals(""))
      {
         setAttribute("path", path);
      }

      String options = ((Cloud) c).getOptions();
      if ((options != null) && !options.equals(""))
      {
         setAttribute("options", options);
      }

      if ( c instanceof Cloud3D ) {
          Cloud3D cl = (Cloud3D) c;
          setAttribute("conversionBinsX", cl.conversionBinsX() );
          double lex = cl.conversionLowerEdgeX();
          if ( ! Double.isNaN(lex) )
              setAttribute("conversionLowerEdgeX",lex);
          double uex = cl.conversionUpperEdgeX();
          if ( ! Double.isNaN(uex) )
              setAttribute("conversionUpperEdgeX",uex);
          setAttribute("conversionBinsY", cl.conversionBinsY() );
          double ley = cl.conversionLowerEdgeY();
          if ( ! Double.isNaN(ley) )
              setAttribute("conversionLowerEdgeY",ley);
          double uey = cl.conversionUpperEdgeY();
          if ( ! Double.isNaN(uey) )
              setAttribute("conversionUpperEdgeY",uey);
          setAttribute("conversionBinsZ", cl.conversionBinsZ() );
          double lez = cl.conversionLowerEdgeZ();
          if ( ! Double.isNaN(lez) )
              setAttribute("conversionLowerEdgeZ",lez);
          double uez = cl.conversionUpperEdgeZ();
          if ( ! Double.isNaN(uez) )
              setAttribute("conversionUpperEdgeZ",uez);
      }

      IHistogram3D hist = null;
      try
      {
         hist = c.histogram();
         setAttribute("lowerEdgeX", c.lowerEdgeX());
         setAttribute("upperEdgeX", c.upperEdgeX());
         setAttribute("lowerEdgeY", c.lowerEdgeY());
         setAttribute("upperEdgeY", c.upperEdgeY());
         setAttribute("lowerEdgeZ", c.lowerEdgeZ());
         setAttribute("upperEdgeZ", c.upperEdgeZ());
      }
      catch (RuntimeException re)
      {
      }
      openTag("cloud3d");

      IAnnotation annotation = c.annotation();
      if (annotation != null)
      {
         toXML(annotation);
      }

      if (hist != null)
      {
         toXML(hist, path);
      }
      else
      {
         openTag("entries3d");
         for (int i = 0; i < c.entries(); i++)
         {
            setAttribute("valueX", c.valueX(i));
            setAttribute("valueY", c.valueY(i));
            setAttribute("valueZ", c.valueZ(i));

            double w = c.weight(i);
            if (w != 1.)
            {
               setAttribute("weight", w);
            }
            printTag("entry3d");
         }
         closeTag();
      }
      closeTag();
   }

   private void toXML(ITuple tuple, String path)
   {
      setAttribute("name", ((IManagedObject) tuple).name());
      setAttribute("title", tuple.title());
      if ((path != null) && !path.equals(""))
      {
         setAttribute("path", path);
      }

      String options = null;
      if (tuple instanceof Tuple) options = ((Tuple) tuple).getOptions();
      if ((options != null) && !options.equals(""))
      {
         setAttribute("options", options);
      }

      openTag("tuple");

      IAnnotation annotation = tuple.annotation();
      if (annotation != null)
      {
         toXML(annotation);
      }

      writeTupleColumns(tuple);
      
      openTag("rows");

      writeTupleEntries(tuple);
      closeTag();
      closeTag();
   }

   private void toXML(IDataPointSet dps, String path)
   {
      setAttribute("name", ((IManagedObject) dps).name());
      setAttribute("title", dps.title());
      if ((path != null) && !path.equals(""))
      {
         setAttribute("path", path);
      }
      setAttribute("dimension", dps.dimension());
      openTag("dataPointSet");

      IAnnotation annotation = dps.annotation();
      if (annotation != null)
      {
         toXML(annotation);
      }
      for (int i = 0; i < dps.size(); i++)
      {
         IDataPoint point = dps.point(i);
         openTag("dataPoint");
         for (int j = 0; j < point.dimension(); j++)
         {
            IMeasurement m = point.coordinate(j);
            setAttribute("value", m.value());

            double ep = m.errorPlus();
            if (!Double.isNaN(ep))
            {
               setAttribute("errorPlus", ep);
            }

            double em = m.errorMinus();
            if (!Double.isNaN(em))
            {
               setAttribute("errorMinus", em);
            }
            printTag("measurement");
         }
         closeTag();
      }
      closeTag();
   }

   
   private void toXML(IProfile1D h, String path)
   {
      String name = ((IManagedObject) h).name();
      setAttribute("name", name);

      String title = h.title();
      if ((title != null) && !title.equals(""))
      {
         setAttribute("title", title);
      }
      if ((path != null) && !path.equals(""))
      {
         setAttribute("path", path);
      }
      openTag("profile1d");

      IAnnotation annotation = h.annotation();
      if (annotation != null)
      {
         toXML(annotation);
      }

      writeHistogramAxis(h.axis(), "x");

      setAttribute("entries", h.entries());
      openTag("statistics");
      setAttribute("direction", "x");
      setAttribute("mean", h.mean());
      setAttribute("rms", h.rms());
      printTag("statistic");
      closeTag();

      openTag("data1d");

      int bins = h.axis().bins();
      for (int i = -2; i < h.axis().bins(); i++)
      {
         double height = h.binHeight(i);
         double error = h.binError(i);
         if ((height != 0) && (error != 0))
         {
            setAttribute("binNum", binNumbToString(i));
            setAttribute("weightedMean", h.binMean(i));
            setAttribute("rms", h.binRms(i));
            setAttribute("height", height);
            setAttribute("error", error);


            //setAttribute("error2","fix me");
            setAttribute("entries", h.binEntries(i));
            printTag("bin1d");
         }
      }
      closeTag();
      closeTag();
   }

   private void toXML(IProfile2D h, String path)
   {
      String name = ((IManagedObject) h).name();
      setAttribute("name", name);

      String title = h.title();
      if ((title != null) && !title.equals(""))
      {
         setAttribute("title", title);
      }
      if ((path != null) && !path.equals(""))
      {
         setAttribute("path", path);
      }
      openTag("profile2d");

      IAnnotation annotation = h.annotation();
      if (annotation != null)
      {
         toXML(annotation);
      }

      writeHistogramAxis(h.xAxis(), "x");
      writeHistogramAxis(h.yAxis(), "y");

      setAttribute("entries", h.entries());
      openTag("statistics");
      setAttribute("direction", "x");
      setAttribute("mean", h.meanX());
      setAttribute("rms", h.rmsX());
      printTag("statistic");
      setAttribute("direction", "y");
      setAttribute("mean", h.meanY());
      setAttribute("rms", h.rmsY());
      printTag("statistic");
      closeTag();

      openTag("data2d");

      int xbins = h.xAxis().bins();
      int ybins = h.yAxis().bins();
      for (int i = -2; i < xbins; i++)
      {
         for (int j = -2; j < ybins; j++)
         {
            double height = h.binHeight(i, j);
            double error = h.binError(i, j);
            if ((height != 0) && (error != 0))
            {
               setAttribute("binNumX", binNumbToString(i));
               setAttribute("binNumY", binNumbToString(j));
               setAttribute("weightedMeanX", h.binMeanX(i, j));
               setAttribute("weightedMeanY", h.binMeanY(i, j));
               setAttribute("rms", h.binRms(i, j));
               setAttribute("height", height);
               setAttribute("error", error);


               //setAttribute("error2","fix me");
               setAttribute("entries", h.binEntries(i, j));
               printTag("bin2d");
            }
         }
      }
      closeTag();
      closeTag();
   }

   private void toXML(IAnnotation annotation)
   {
      openTag("annotation");
      for (int i = 0; i < annotation.size(); i++)
      {
         String key = annotation.key(i);
         setAttribute("key", key);
         setAttribute("value", annotation.value(key));
         if (annotation instanceof Annotation)
         {
            setAttribute("sticky", String.valueOf(((Annotation) annotation).isSticky(key)));
         }
         printTag("item");
      }
      closeTag();
   }

   private void writeHistogramAxis(IAxis axis, String direction)
   {
      setAttribute("direction", direction);
      setAttribute("min", axis.lowerEdge());
      setAttribute("max", axis.upperEdge());
      setAttribute("numberOfBins", axis.bins());
      if (axis instanceof VariableAxis)
      {
         openTag("axis");
         for (int i = 0; i < (axis.bins() - 1); i++)
         {
            setAttribute("value", axis.binUpperEdge(i));
            printTag("binBorder");
         }
         closeTag();
      }
      else
      {
         printTag("axis");
      }
   }

   private void writeTupleEntries(ITuple tup)
   {
      tup.start();
      for (int j = 0; j < tup.rows(); j++)
      {
         tup.next();
         openTag("row");
         for (int i = 0; i < tup.columns(); i++)
         {
            Class colType = tup.columnType(i);
            String vStr = "value";
            if (colType == ITuple.class)
            {
               ITuple tupp = (ITuple) tup.getObject(i);
               if (tupp == null)
               {
                  printTag("entryITuple");
               }
               else
               {
                  openTag("entryITuple");
                  writeTupleEntries(tupp);
                  closeTag();
               }
            }
            else
            {
               if (colType == Integer.TYPE)
               {
                  setAttribute(vStr, tup.getInt(i));
               }
               else if (colType == Short.TYPE)
               {
                  setAttribute(vStr, tup.getShort(i));
               }
               else if (colType == Long.TYPE)
               {
                  setAttribute(vStr, tup.getLong(i));
               }
               else if (colType == Float.TYPE)
               {
                  setAttribute(vStr, tup.getFloat(i));
               }
               else if (colType == Double.TYPE)
               {
                  setAttribute(vStr, tup.getDouble(i));
               }
               else if (colType == Boolean.TYPE)
               {
                  setAttribute(vStr, tup.getBoolean(i));
               }
               else if (colType == Byte.TYPE)
               {
                  setAttribute(vStr, tup.getByte(i));
               }
               else if (colType == Character.TYPE)
               {
                  setAttribute(vStr, tup.getChar(i));
               }
               else if (colType == String.class)
               {
                  setAttribute(vStr, tup.getString(i));
               }
               else if (colType == Object.class)
               {
                  setAttribute(vStr, tup.getObject(i).toString());
               }
               printTag("entry");
            }
         }
         closeTag();
      }
   }
   
   private void writeTupleColumns(ITuple tuple) {
       
      openTag("columns");

      int columns = tuple.columns();
      for (int i = 0; i < columns; i++)
      {
         Class colType = tuple.columnType(i);
         String def = null;
         if (tuple instanceof AbstractTuple) def = ((AbstractTuple) tuple).columnDefaultString(i);
         String tupName = tuple.columnName(i);
         if (def != null && ! def.equals("") )
         {
            tupName += ("=" + def);
         }
         if (colType == ITuple.class)
         {
            tupName = def;
         }
         if ( colType == ITuple.class ) {
             setAttribute("type", "ITuple");
             tupName = tupName.substring(0, tupName.indexOf("="));
             setAttribute("name", tupName);
             openTag("column");
             writeTupleColumns(tuple.findTuple(i));
             closeTag();
         }
         else {
             setAttribute("type", String.class.isAssignableFrom(colType) ? "string" : colType.getName());
             setAttribute("name", tupName);
             printTag("column");
         }         
      }
      closeTag();
       
       
       
       
   }
   
   
   private void toXML(IFunction function, String path)
   {
       IModelFunction model = null;
       if ( function instanceof IModelFunction )
           model = (IModelFunction) function;
       
      setAttribute("name", ((IManagedObject)function).name());
      setAttribute("title", function.title());
      if ( (path != null) && !path.equals("") )
          setAttribute("path", path);
      if ( model != null )
          setAttribute("isNormalized", String.valueOf(model.isNormalized()));

      openTag("function");

      //Function's elements annotation, codelet, arguments, parameters
      openTag("codelet");
      println(function.codeletString());
      closeTag();
      
      if ( model != null ) {
          openTag("arguments");
          for ( int i = 0; i < function.dimension(); i++ ) {
              setAttribute("name",model.variableName(i));
              openTag("argument");
              IRangeSet rangeSet = model.normalizationRange(i);
              double[] lb = rangeSet.lowerBounds();
              double[] ub = rangeSet.upperBounds();
              for ( int j = 0; j < lb.length; j++ ) {
                  setAttribute("min", lb[j]);
                  setAttribute("max", ub[j]);
                  printTag("range");
              }
              closeTag();
          }
          closeTag();
      }
      
      openTag("parameters");
      String[] parNames  = function.parameterNames();
      double[] parValues = function.parameters();
      
      for ( int i = 0; i < function.numberOfParameters(); i++ ) {
          setAttribute("name",parNames[i]);
          setAttribute("value",parValues[i]);
          printTag("parameter");
      }
      closeTag();
      
      closeTag();
   }   
   
   
   
   
}