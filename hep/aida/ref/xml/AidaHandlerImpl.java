/*
 * File:           AidaHandlerImpl.java
 * Date:           October 25, 2002  11:40 AM
 *
 * @author tonyj
 * @version $Id: AidaHandlerImpl.java,v 1.18 2005/09/28 14:52:49 turri Exp $
 */
package hep.aida.ref.xml;

import hep.aida.*;
import hep.aida.IFunction;
import hep.aida.IModelFunction;
import hep.aida.dev.*;

import hep.aida.ref.Annotation;
import hep.aida.ref.function.FunctionCatalog;
import hep.aida.ref.histogram.*;
import hep.aida.ref.tree.*;
import hep.aida.ref.tuple.*;
import hep.tuple.interfaces.*;

import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Stack;

import org.xml.sax.*;


public class AidaHandlerImpl implements AidaHandler
{
   public static final boolean DEBUG = false;
   private Cloud1D cloud1d;
   private Cloud2D cloud2d;
   private Cloud3D cloud3d;
   private DataPointSet dataPointSet;
   private IAnnotation annotation;
   private IAnnotation saveAnnotation;
   private IDataPoint dataPoint;
   private Stack stack = new Stack();
   private String aidaVersion;
   private String name;
   private String options;
   private String path;
   private String saveName;
   private String saveTitle;
   private String title;
   private hep.aida.ref.tree.Tree tree;
   private Tuple tuple;
   private IAxis[] axes = new IAxis[3];
   private double[] binBorders;
   private int[] entries1d;
   private int[][] entries2d;
   private int[][][] entries3d;
   private double[] errors1d;
   private double[][] errors2d;
   private double[][][] errors3d;
   private double[] heights1d;
   private double[][] heights2d;
   private double[][][] heights3d;
   private double[] mean = new double[3];
   private double[] means1d;
   private double[][] meansx2d;
   private double[][][] meansx3d;
   private double[][] meansy2d;
   private double[][][] meansy3d;
   private double[][][] meansz3d;
   private double[] rms = new double[3];
   private double[] rmss1d;
   private double[][] rmssx2d;
   private double[][][] rmssx3d;
   private double[][] rmssy2d;
   private double[][][] rmssy3d;
   private double[][][] rmssz3d;
   private boolean aida22;
   private boolean beforeAida33;
   private boolean hasBinMeanAndRms;
   private double binMax;
   private double binMin;
   private int column;
   private int nAxis;
   private int nBin;
   private int nBins;
   private int nextCoord;
   private IFunction function;
   private String argName;
   private boolean isNormalized;
   private String tupleString = "";
   private int innerFolders = 0;

   public AidaHandlerImpl(hep.aida.dev.IDevTree tree)
   {
      this.tree = (hep.aida.ref.tree.Tree) tree;      
   }

   public void end_aida() throws SAXException
   {
   }

   public void end_annotation() throws SAXException
   {
   }

   public void end_argument() throws SAXException
   {
   }

   public void end_arguments() throws SAXException
   {
       if ( function instanceof IModelFunction ) {
           IModelFunction model = (IModelFunction)function;
           model.normalize(isNormalized);
       }
   }

   public void end_axis() throws SAXException
   {
      if (binBorders != null)
      {
         axes[nAxis] = new VariableAxis(binBorders);
      }
      else
      {
         axes[nAxis] = new FixedAxis(nBins, binMin, binMax);
      }
   }

   public void end_cloud1d() throws SAXException
   {
      if (annotation != null)
      {
         cloud1d.setAnnotation(annotation);
         annotation = null;
      }
      cloud1d.setTitle((title == null) ? name : title);
      add(path, cloud1d);
      cloud1d = null;
   }

   public void end_cloud2d() throws SAXException
   {
      if (annotation != null)
      {
         cloud2d.setAnnotation(annotation);
         annotation = null;
      }
      cloud2d.setTitle((title == null) ? name : title);
      add(path, cloud2d);
      cloud2d = null;
   }

   public void end_cloud3d() throws SAXException
   {
      if (annotation != null)
      {
         cloud3d.setAnnotation(annotation);
         annotation = null;
      }
      cloud3d.setTitle((title == null) ? name : title);
      add(path, cloud3d);
      cloud3d = null;
   }

   public void end_columns() throws SAXException
   {       
       if ( innerFolders != 0 ) {
           tupleString += "}";
           innerFolders--;
       }
   }

   public void end_data1d() throws SAXException
   {
   }

   public void end_data2d() throws SAXException
   {
   }

   public void end_data3d() throws SAXException
   {
   }

   public void end_dataPoint() throws SAXException
   {
   }

   public void end_dataPointSet() throws SAXException
   {
      if (annotation != null)
      {
         dataPointSet.setAnnotation(annotation);
         annotation = null;
      }
      dataPointSet.setTitle((title == null) ? name : title);
      add(path, dataPointSet);
      dataPointSet = null;
   }

   public void end_entries1d() throws SAXException
   {
   }

   public void end_entries2d() throws SAXException
   {
      if (DEBUG)
      {
         System.err.println("end_entries2d()");
      }
   }

   public void end_entries3d() throws SAXException
   {
      if (DEBUG)
      {
         System.err.println("end_entries3d()");
      }
   }

   public void end_entryITuple() throws SAXException
   {
      Object[] elements = (Object[]) stack.pop();
      tuple = (Tuple) elements[0];
      column = ((Integer) elements[1]).intValue();
      column++;
   }

   public void end_function() throws SAXException
   {
       ((IDevManagedObject)function).setName(name);
       add(path, (IManagedObject)function);
   }

   public void end_histogram1d() throws SAXException
   {
      Histogram1D hist = new Histogram1D();
      hist.setName(name);
      hist.initHistogram1D(axes[0], options);

      hist.setContents(heights1d, errors1d, entries1d, means1d, rmss1d);
      if (!hasBinMeanAndRms)
      {
         hist.setMean(mean[0]);
         hist.setRms(rms[0]);
      }
      if (annotation != null)
      {
         hist.setAnnotation(annotation);
         annotation = null;
      }
      hist.setTitle((title == null) ? name : title);
      if (cloud1d != null)
      {
         cloud1d.setHistogram(hist);
         annotation = saveAnnotation;
         title = saveTitle;
         name = saveName;
      }
      else
      {
         add(path, hist);
      }
   }

   public void end_histogram2d() throws SAXException
   {
      Histogram2D hist = new Histogram2D();
      hist.setName(name);
      hist.initHistogram2D(axes[0], axes[1], options);

      hist.setContents(heights2d, errors2d, entries2d, meansx2d, rmssx2d, meansy2d, rmssy2d);
      if (!hasBinMeanAndRms)
      {
         hist.setMeanX(mean[0]);
         hist.setRmsX(rms[0]);
         hist.setMeanY(mean[1]);
         hist.setRmsY(rms[1]);
      }
      if (annotation != null)
      {
         hist.setAnnotation(annotation);
         annotation = null;
      }
      hist.setTitle((title == null) ? name : title);
      if (cloud2d != null)
      {
         cloud2d.setHistogram(hist);
         annotation = saveAnnotation;
         title = saveTitle;
         name = saveName;
      }
      else
      {
         add(path, hist);
      }
   }

   public void end_histogram3d() throws SAXException
   {
      Histogram3D hist = new Histogram3D();
      hist.setName(name);
      hist.initHistogram3D(axes[0], axes[1], axes[2], options);

      hist.setContents(heights3d, errors3d, entries3d, meansx3d, rmssx3d, meansy3d, rmssy3d, meansz3d, rmssz3d);
      if (!hasBinMeanAndRms)
      {
         hist.setMeanX(mean[0]);
         hist.setRmsX(rms[0]);
         hist.setMeanY(mean[1]);
         hist.setRmsY(rms[1]);
         hist.setMeanZ(mean[2]);
         hist.setRmsZ(rms[2]);
      }
      if (annotation != null)
      {
         hist.setAnnotation(annotation);
         annotation = null;
      }
      hist.setTitle((title == null) ? name : title);
      if (cloud3d != null)
      {
         cloud3d.setHistogram(hist);
         annotation = saveAnnotation;
         title = saveTitle;
         name = saveName;
      }
      else
      {
         add(path, hist);
      }
   }

   public void end_parameters() throws SAXException
   {
   }

   public void end_profile1d() throws SAXException
   {
      Profile1D hist = new Profile1D();
      hist.setName(name);
      hist.initProfile1D(axes[0]);
      hist.setContents(heights1d, errors1d, entries1d, rmss1d, means1d);
      hist.setMean(mean[0]);
      hist.setRms(rms[0]);
      if (annotation != null)
      {
         hist.setAnnotation(annotation);
         annotation = null;
      }
      hist.setTitle((title == null) ? name : title);
      add(path, hist);
   }

   public void end_profile2d() throws SAXException
   {
      Profile2D hist = new Profile2D();
      hist.setName(name);
      hist.initProfile2D(axes[0], axes[1]);
      hist.setContents(heights2d, errors2d, entries2d, rmssx2d, meansx2d, meansy2d);
      hist.setMeanX(mean[0]);
      hist.setRmsX(rms[0]);
      hist.setMeanY(mean[1]);
      hist.setRmsY(rms[1]);
      if (annotation != null)
      {
         hist.setAnnotation(annotation);
         annotation = null;
      }
      hist.setTitle((title == null) ? name : title);
      add(path, hist);
   }

   public void end_row() throws SAXException
   {
      tuple.addRow();
   }

   public void end_rows() throws SAXException
   {
   }

   public void end_statistics() throws SAXException
   {
      if (DEBUG)
      {
         System.err.println("end_statistics()");
      }
   }

   public void end_tuple() throws SAXException
   {
      if (annotation != null)
      {
         tuple.setAnnotation(annotation);
         annotation = null;
      }
      tuple.setTitle((title == null) ? name : title);
      add(path, tuple);
   }

   public void handle_bin1d(final Attributes meta) throws SAXException
   {
      int bin = binStringToInt(meta.getValue("binNum"), axes[0].bins());
      heights1d[bin] = toDouble(meta, "height",Double.NaN);
      errors1d[bin] = toDouble(meta, "error",Double.NaN);
      entries1d[bin] = toInt(meta, "entries");
      if (hasBinMeanAndRms)
      {
         int index1 = meta.getIndex("weightedMean");
         int index2 = meta.getIndex("weightedRms");
         if (index2 < 0)
         {
            index2 = meta.getIndex("rms");
         }
         if ((index1 < 0) || (index2 < 0))
         {
            hasBinMeanAndRms = false;
         }
         else
         {
            means1d[bin] = toDouble(meta, index1);
            rmss1d[bin] = toDouble(meta, index2);
         }
      }
   }

   public void handle_bin2d(final Attributes meta) throws SAXException
   {
      int xBin = binStringToInt(meta.getValue("binNumX"), axes[0].bins());
      int yBin = binStringToInt(meta.getValue("binNumY"), axes[1].bins());
      heights2d[xBin][yBin] = toDouble(meta, "height",Double.NaN);
      errors2d[xBin][yBin] = toDouble(meta, "error",Double.NaN);
      entries2d[xBin][yBin] = toInt(meta, "entries");
      if (hasBinMeanAndRms)
      {
         int index1 = meta.getIndex("weightedMeanX");
         int index2 = meta.getIndex("weightedRmsX");
         if (index2 < 0)
         {
            index2 = meta.getIndex("rms");
         }

         int index3 = meta.getIndex("weightedMeanY");
         int index4 = meta.getIndex("weightedRmsY");
         if ((index1 < 0) || (index2 < 0) || (index3 < 0))
         {
            hasBinMeanAndRms = false;
         }
         else
         {
            meansx2d[xBin][yBin] = toDouble(meta, index1);
            rmssx2d[xBin][yBin] = toDouble(meta, index2);
            meansy2d[xBin][yBin] = toDouble(meta, index3);
            if (index4 >= 0)
            {
               rmssy2d[xBin][yBin] = toDouble(meta, index4);
            }
         }
      }
   }

   public void handle_bin3d(final Attributes meta) throws SAXException
   {
      int xBin = binStringToInt(meta.getValue("binNumX"), axes[0].bins());
      int yBin = binStringToInt(meta.getValue("binNumY"), axes[1].bins());
      int zBin = binStringToInt(meta.getValue("binNumZ"), axes[2].bins());
      heights3d[xBin][yBin][zBin] = toDouble(meta, "height",Double.NaN);
      errors3d[xBin][yBin][zBin] = toDouble(meta, "error",Double.NaN);
      entries3d[xBin][yBin][zBin] = toInt(meta, "entries");
      if (hasBinMeanAndRms)
      {
         int index1 = meta.getIndex("weightedMeanX");
         int index2 = meta.getIndex("weightedRmsX");
         int index3 = meta.getIndex("weightedMeanY");
         int index4 = meta.getIndex("weightedRmsY");
         int index5 = meta.getIndex("weightedMeanZ");
         int index6 = meta.getIndex("weightedRmsZ");
         if ((index1 < 0) || (index2 < 0) || (index3 < 0) || (index4 < 0) || (index5 < 0) || (index6 < 0))
         {
            hasBinMeanAndRms = false;
         }
         else
         {
            meansx3d[xBin][yBin][zBin] = toDouble(meta, index1);
            rmssx3d[xBin][yBin][zBin] = toDouble(meta, index2);
            meansy3d[xBin][yBin][zBin] = toDouble(meta, index3);
            rmssy3d[xBin][yBin][zBin] = toDouble(meta, index4);
            meansz3d[xBin][yBin][zBin] = toDouble(meta, index5);
            rmssz3d[xBin][yBin][zBin] = toDouble(meta, index6);
         }
      }
   }

   public void handle_binBorder(final Attributes meta) throws SAXException
   {
      if (binBorders == null)
      {
         binBorders = new double[nBins + 1];
         binBorders[0] = binMin;
         binBorders[nBins] = binMax;
         nBin = 1;
      }
      binBorders[nBin++] = toDouble(meta, "value");
   }

   public void handle_codelet(final java.lang.String data, final Attributes meta) throws SAXException
   {
       String codelet = data;
       if ( codelet.startsWith("\n") ) codelet = codelet.substring(1);
       if ( codelet.endsWith("\n") ) codelet = codelet.substring(0,codelet.length()-1);
       codelet = codelet.trim();
       function = FunctionCatalog.getFunctionCatalog().getFunctionCreator().createFromCodelet(codelet);
       if ( title != null )
           function.setTitle( title );
   }

   public void handle_column(final Attributes meta) throws SAXException
   {
       String type = meta.getValue("type");       
       
       if ( ! tupleString.equals("") && ! tupleString.endsWith(",") && ! tupleString.endsWith("{") )
           tupleString += ",";
       
       tupleString += type+" "+meta.getValue("name");
       
       if ( ! beforeAida33 && type.equalsIgnoreCase("ITuple") ) {
           tupleString += "={";
           innerFolders++;
       }
   }

   public void handle_entry(final Attributes meta) throws SAXException
   {
      Class colType = tuple.columnType(column);
      String value = meta.getValue("value");

      if (colType == Integer.TYPE)
      {
         tuple.fill(column, Integer.parseInt(value));
      }
      else if (colType == Short.TYPE)
      {
         tuple.fill(column, Short.parseShort(value));
      }
      else if (colType == Long.TYPE)
      {
         tuple.fill(column, Long.parseLong(value));
      }
      else if (colType == Float.TYPE)
      {
         tuple.fill(column, Float.parseFloat(value));
      }
      else if (colType == Double.TYPE)
      {
         tuple.fill(column, parseDouble(value));
      }
      else if (colType == Boolean.TYPE)
      {
         tuple.fill(column, "true".equalsIgnoreCase(value));
      }
      else if (colType == Byte.TYPE)
      {
         tuple.fill(column, Byte.parseByte(value));
      }
      else if (colType == Character.TYPE)
      {
         tuple.fill(column, value.charAt(0));
      }
      else if (colType == String.class)
      {
         tuple.fill(column, value);
      }
      else
      {
         tuple.fill(column, value); // fix me!
      }
      column++;
   }

   public void handle_entry1d(final Attributes meta) throws SAXException
   {
      double value = toDouble(meta, "valueX");
      double weight = toDouble(meta, "weight", 1);
      cloud1d.fill(value, weight);
   }

   public void handle_entry2d(final Attributes meta) throws SAXException
   {
      double x = toDouble(meta, "valueX");
      double y = toDouble(meta, "valueY");
      double weight = toDouble(meta, "weight", 1);
      cloud2d.fill(x, y, weight);
   }

   public void handle_entry3d(final Attributes meta) throws SAXException
   {
      double x = toDouble(meta, "valueX");
      double y = toDouble(meta, "valueY");
      double z = toDouble(meta, "valueZ");
      double weight = toDouble(meta, "weight", 1);
      cloud3d.fill(x, y, z, weight);
   }

   public void handle_implementation(final Attributes meta) throws SAXException
   {
      if (DEBUG)
      {
         System.err.println("handle_implementation: " + meta);
      }
   }

   public void handle_item(final Attributes meta) throws SAXException
   {
      String key = meta.getValue("key");
      String val = meta.getValue("value");
      boolean sticky = "true".equalsIgnoreCase(meta.getValue("sticky"));
      annotation.addItem(key, val, sticky);
   }

   public void handle_measurement(final Attributes meta) throws SAXException
   {
      IMeasurement m = dataPoint.coordinate(nextCoord++);
      m.setValue(toDouble(meta, "value"));

      int index = meta.getIndex("errorPlus");
      if (index >= 0)
      {
         m.setErrorPlus(toDouble(meta, index));
      }
      index = meta.getIndex("errorMinus");
      if (index >= 0)
      {
         m.setErrorMinus(toDouble(meta, index));
      }
   }

   public void handle_parameter(final Attributes meta) throws SAXException
   {
       String parName = meta.getValue("name");
       function.setParameter( parName, toDouble( meta, "value" ) );
   }

   public void handle_range(final Attributes meta) throws SAXException
   {
       if ( function instanceof IModelFunction ) { 
           IModelFunction model = (IModelFunction) function;
           int argIndex = -1;
           for ( int i = 0; i < model.dimension(); i++ ) {
               if ( model.variableName(i).equals( argName ) ) {
                   argIndex = i;
                   break;
               }
           }
           double min = toDouble( meta, "min" );
           double max = toDouble( meta, "max" );
           model.normalizationRange( argIndex ).include( min, max );
      }   
   }

   public void handle_statistic(final Attributes meta) throws SAXException
   {
      int dir = toDirection(meta, "direction");
      mean[dir] = toDouble(meta, "mean");
      rms[dir] = toDouble(meta, "rms");
   }

   public void start_aida(final Attributes meta) throws SAXException
   {
      aidaVersion = meta.getValue("version");
      aida22 = aidaVersion.startsWith("2.2");
      
      StringTokenizer st = new StringTokenizer(aidaVersion,".");
      int nTokens = st.countTokens();
      if ( nTokens > 3 )
          throw new RuntimeException("Illegal version for parsing.");
      int majorVersion = Integer.parseInt(st.nextToken());
      int revisionVersion = Integer.parseInt(st.nextToken());
      int patchVersion = 0;
      if ( nTokens == 3 )
          Integer.parseInt(st.nextToken());
      
      beforeAida33 = ( majorVersion < 3 ) || ( majorVersion == 3 && revisionVersion <=2 );  
      
   }

   public void start_annotation(final Attributes meta) throws SAXException
   {
      annotation = new Annotation();
   }

   public void start_argument(final Attributes meta) throws SAXException
   {
       argName = meta.getValue("name");
   }

   public void start_arguments(final Attributes meta) throws SAXException
   {
   }

   public void start_axis(final Attributes meta) throws SAXException
   {
      binMin = toDouble(meta, "min");
      binMax = toDouble(meta, "max");
      nBins = toInt(meta, "numberOfBins");
      nAxis = toDirection(meta, "direction");
      binBorders = null;
   }

   public void start_cloud1d(final Attributes meta) throws SAXException
   {
      start_managedObject(meta);
      cloud1d = new Cloud1D();
      cloud1d.initCloud(toInt(meta, "maxEntries"), options);
      cloud1d.setName(name);

      double uE = toDouble(meta, "upperEdgeX", Double.NaN);
      double lE = toDouble(meta, "lowerEdgeX", Double.NaN);
      if (!Double.isNaN(uE))
      {
         cloud1d.setUpperEdge(uE);
      }
      if (!Double.isNaN(lE))
      {
         cloud1d.setLowerEdge(lE);
      }
      
      String conversionBinsStr = meta.getValue("conversionBins");
      if ( conversionBinsStr != null ) {
          int conversionBins = Integer.parseInt(conversionBinsStr);
          double le = toDouble(meta,"conversionLowerEdge", Double.NaN);
          double ue = toDouble(meta,"conversionUpperEdge", Double.NaN);
          cloud1d.setConversionParameters(conversionBins, le, ue );
      }
      
   }

   public void start_cloud2d(final Attributes meta) throws SAXException
   {
      start_managedObject(meta);
      cloud2d = new Cloud2D();
      cloud2d.initCloud(toInt(meta, "maxEntries"), options);
      cloud2d.setName(name);

      double uE = toDouble(meta, "upperEdgeX", Double.NaN);
      double lE = toDouble(meta, "lowerEdgeX", Double.NaN);
      if (!Double.isNaN(uE))
      {
         cloud2d.setUpperEdgeX(uE);
      }
      if (!Double.isNaN(lE))
      {
         cloud2d.setLowerEdgeX(lE);
      }
      uE = toDouble(meta, "upperEdgeY", Double.NaN);
      lE = toDouble(meta, "lowerEdgeY", Double.NaN);
      if (!Double.isNaN(uE))
      {
         cloud2d.setUpperEdgeY(uE);
      }
      if (!Double.isNaN(lE))
      {
         cloud2d.setLowerEdgeY(lE);
      }
      
      String conversionBinsXStr = meta.getValue("conversionBinsX");
      String conversionBinsYStr = meta.getValue("conversionBinsY");
      if ( conversionBinsXStr != null && conversionBinsYStr != null ) {
          int conversionBinsX = Integer.parseInt(conversionBinsXStr);
          int conversionBinsY = Integer.parseInt(conversionBinsYStr);
          double lex = toDouble(meta,"conversionLowerEdgeX", Double.NaN);
          double uex = toDouble(meta,"conversionUpperEdgeX", Double.NaN);
          double ley = toDouble(meta,"conversionLowerEdgeY", Double.NaN);
          double uey = toDouble(meta,"conversionUpperEdgeY", Double.NaN);
          cloud2d.setConversionParameters(conversionBinsX, lex, uex, conversionBinsY, ley, uey );
      }
      
   }

   public void start_cloud3d(final Attributes meta) throws SAXException
   {
      start_managedObject(meta);
      cloud3d = new Cloud3D();
      cloud3d.initCloud(toInt(meta, "maxEntries"), options);
      cloud3d.setName(name);

      double uE = toDouble(meta, "upperEdgeX", Double.NaN);
      double lE = toDouble(meta, "lowerEdgeX", Double.NaN);
      if (!Double.isNaN(uE))
      {
         cloud3d.setUpperEdgeX(uE);
      }
      if (!Double.isNaN(lE))
      {
         cloud3d.setLowerEdgeX(lE);
      }
      uE = toDouble(meta, "upperEdgeY", Double.NaN);
      lE = toDouble(meta, "lowerEdgeY", Double.NaN);
      if (!Double.isNaN(uE))
      {
         cloud3d.setUpperEdgeY(uE);
      }
      if (!Double.isNaN(lE))
      {
         cloud3d.setLowerEdgeY(lE);
      }
      uE = toDouble(meta, "upperEdgeZ", Double.NaN);
      lE = toDouble(meta, "lowerEdgeZ", Double.NaN);
      if (!Double.isNaN(uE))
      {
         cloud3d.setUpperEdgeZ(uE);
      }
      if (!Double.isNaN(lE))
      {
         cloud3d.setLowerEdgeZ(lE);
      }

      String conversionBinsXStr = meta.getValue("conversionBinsX");
      String conversionBinsYStr = meta.getValue("conversionBinsY");
      String conversionBinsZStr = meta.getValue("conversionBinsZ");
      if ( conversionBinsXStr != null && conversionBinsYStr != null && conversionBinsZStr != null) {
          int conversionBinsX = Integer.parseInt(conversionBinsXStr);
          int conversionBinsY = Integer.parseInt(conversionBinsYStr);
          int conversionBinsZ = Integer.parseInt(conversionBinsZStr);
          double lex = toDouble(meta,"conversionLowerEdgeX", Double.NaN);
          double uex = toDouble(meta,"conversionUpperEdgeX", Double.NaN);
          double ley = toDouble(meta,"conversionLowerEdgeY", Double.NaN);
          double uey = toDouble(meta,"conversionUpperEdgeY", Double.NaN);
          double lez = toDouble(meta,"conversionLowerEdgeZ", Double.NaN);
          double uez = toDouble(meta,"conversionUpperEdgeZ", Double.NaN);
          cloud3d.setConversionParameters(conversionBinsX, lex, uex, conversionBinsY, ley, uey, conversionBinsZ, lez, uez );
      }
   }

   public void start_columns(final Attributes meta) throws SAXException
   {
   }

   public void start_data1d(final Attributes meta) throws SAXException
   {
      int xBins = axes[0].bins() + 2;
      heights1d = new double[xBins];
      errors1d = new double[xBins];
      entries1d = new int[xBins];
      means1d = new double[xBins];
      rmss1d = new double[xBins];
      hasBinMeanAndRms = true;
   }

   public void start_data2d(final Attributes meta) throws SAXException
   {
      int xBins = axes[0].bins() + 2;
      int yBins = axes[1].bins() + 2;
      heights2d = new double[xBins][yBins];
      errors2d = new double[xBins][yBins];
      entries2d = new int[xBins][yBins];
      meansx2d = new double[xBins][yBins];
      rmssx2d = new double[xBins][yBins];
      meansy2d = new double[xBins][yBins];
      rmssy2d = new double[xBins][yBins];
      hasBinMeanAndRms = true;
   }

   public void start_data3d(final Attributes meta) throws SAXException
   {
      int xBins = axes[0].bins() + 2;
      int yBins = axes[1].bins() + 2;
      int zBins = axes[2].bins() + 2;
      heights3d = new double[xBins][yBins][zBins];
      errors3d = new double[xBins][yBins][zBins];
      entries3d = new int[xBins][yBins][zBins];
      meansx3d = new double[xBins][yBins][zBins];
      rmssx3d = new double[xBins][yBins][zBins];
      meansy3d = new double[xBins][yBins][zBins];
      rmssy3d = new double[xBins][yBins][zBins];
      meansz3d = new double[xBins][yBins][zBins];
      rmssz3d = new double[xBins][yBins][zBins];
      hasBinMeanAndRms = true;
   }

   public void start_dataPoint(final Attributes meta) throws SAXException
   {
      dataPointSet.addPoint();
      dataPoint = dataPointSet.point(dataPointSet.size() - 1);
      nextCoord = 0;
   }

   public void start_dataPointSet(final Attributes meta) throws SAXException
   {
      start_managedObject(meta);

      int dim = toInt(meta, "dimension");
      dataPointSet = new DataPointSet(name, title, dim);
   }

   public void start_entries1d(final Attributes meta) throws SAXException
   {
   }

   public void start_entries2d(final Attributes meta) throws SAXException
   {
      if (DEBUG)
      {
         System.err.println("start_entries2d: " + meta);
      }
   }

   public void start_entries3d(final Attributes meta) throws SAXException
   {
      if (DEBUG)
      {
         System.err.println("start_entries3d: " + meta);
      }
   }

   public void start_entryITuple(final Attributes meta) throws SAXException
   {
      stack.push(new Object[] { tuple, new Integer(column) });
      tuple = (Tuple) tuple.getObject(column);
      column = 0;
   }

   public void start_function(final Attributes meta) throws SAXException
   {
      start_managedObject(meta);
      isNormalized = toBoolean(meta, "isNormalized");
   }

   public void start_histogram1d(final Attributes meta) throws SAXException
   {
      if (cloud1d != null)
      {
         saveAnnotation = annotation;
         saveTitle = title;
         saveName = name;
      }
      start_managedObject(meta);
   }

   public void start_histogram2d(final Attributes meta) throws SAXException
   {
      if (cloud2d != null)
      {
         saveAnnotation = annotation;
         saveTitle = title;
         saveName = name;
      }
      start_managedObject(meta);
   }

   public void start_histogram3d(final Attributes meta) throws SAXException
   {
      if (cloud3d != null)
      {
         saveAnnotation = annotation;
         saveTitle = title;
         saveName = name;
      }
      start_managedObject(meta);
   }

   public void start_parameters(final Attributes meta) throws SAXException
   {
   }

   public void start_profile1d(final Attributes meta) throws SAXException
   {
      start_managedObject(meta);
   }

   public void start_profile2d(final Attributes meta) throws SAXException
   {
      start_managedObject(meta);
   }

   public void start_row(final Attributes meta) throws SAXException
   {
      column = 0;
   }

   public void start_rows(final Attributes meta) throws SAXException
   {
       if ( tupleString.endsWith(",") )
           tupleString = tupleString.substring(0, tupleString.length()-1);
      tuple = new Tuple(name, title, tupleString, options);
   }

   public void start_statistics(final Attributes meta) throws SAXException
   {
      if (DEBUG)
      {
         System.err.println("start_statistics: " + meta);
      }
   }

   public void start_tuple(final Attributes meta) throws SAXException
   {
      start_managedObject(meta);
      tupleString = "";
   }

   private void add(String path, IManagedObject obj)
   {
      if (path == null)
      {
         path = "/";
	 tree.hasBeenFilled("/");
      }
      else
      {
         tree.mkdirs(path);

	 StringTokenizer st = new StringTokenizer(path, "/");
	 String currentpath = "/";
	 if (st.countTokens()>0) {
	     while (st.hasMoreTokens()) {
		 String token = st.nextToken();
		 currentpath += token+"/";
		 tree.hasBeenFilled(currentpath);
		 if (obj instanceof Folder) tree.hasBeenFilled(currentpath + obj.name());
	     }
	 }
      }
      tree.add(path, obj);
   }

   private int binStringToInt(String bin, int nBins)
   {
      if (bin.equals("UNDERFLOW"))
      {
         return 0;
      }
      else if (bin.equals("OVERFLOW"))
      {
         return nBins + 1;
      }
      else
      {
         return Integer.parseInt(bin) + 1;
      }
   }

   private void start_managedObject(final Attributes meta) throws SAXException
   {
      name = meta.getValue("name");
      title = meta.getValue(aida22 ? "label" : "title");
      path = meta.getValue("path");
      options = meta.getValue("options");
   }

   private int toDirection(Attributes meta, String name) throws SAXException
   {
      String dir = meta.getValue(name);
      if ((dir == null) || dir.equalsIgnoreCase("x"))
      {
         return 0;
      }
      else if (dir.equalsIgnoreCase("y"))
      {
         return 1;
      }
      else if (dir.equalsIgnoreCase("z"))
      {
         return 2;
      }
      throw new SAXException("Illegal value for direction: " + dir);
   }

   private double toDouble(Attributes meta, String name)
   {       
      return parseDouble(meta.getValue(name));
   }

   private double toDouble(Attributes meta, int index)
   {
      return parseDouble(meta.getValue(index));
   }

   private double toDouble(Attributes meta, String name, double def)
   {
      String val = meta.getValue(name);
      if (val == null)
      {
         return def;
      }
      else
      {
         return parseDouble(val);
      }
   }
   
   private double parseDouble( String strDouble ) {
       //Fix to JAIDA-90
       if ( strDouble.equalsIgnoreCase("nan") )
           strDouble = "NaN";
       return Double.parseDouble(strDouble);
   }

   private int toInt(Attributes meta, String name)
   {
      return Integer.parseInt(meta.getValue(name));
   }

   private boolean toBoolean(Attributes meta, String name)
   {
      return Boolean.valueOf(meta.getValue(name)).booleanValue();
   }
}
