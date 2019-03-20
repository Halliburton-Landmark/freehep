package hep.aida.ref.plotter;

import hep.aida.IPlotter;
import java.awt.Component;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Properties;

/** Some utilities for using the JAIDA Plotter in other Java
 * applications.
 * @author tonyj
 * @version $Id: PlotterUtilities.java,v 1.1 2003/09/03 22:37:28 tonyj Exp $
 */
public abstract class PlotterUtilities
{
   /** A method to enable the JAIDA plotter to be embedded inside
    * a Java GUI.
    * @return The component associated with this IPlotter
    * @param plotter The plotter to be embedded
    * @throws IllegalArgumentException If the plotter passed in was not created by JAIDA's default analysis factory
    */   
   public static Component componentForPlotter(IPlotter plotter) throws IllegalArgumentException
   {
      return checkPlotter(plotter).getPanel();
   }
   /** Write a plot to a file, specifying extra properties
    * @param plotter The plotter to write
    * @param file The file to write to
    * @param type The format to write out. Supported types include cgm, emf, gif, pdf, ppm, ps, svg, swf,
    * png and jpg. See the JAIDA release notes for required jar files to support
    * different graphics formats.
    * @param props Properties that control how the image is produced.
    * Supported properties include plotWidth and plotHeight, as well as other format
    * specific properties.
    * @throws IllegalArgumentException If the plotter passed in was not created by JAIDA's default analysis factory
    */   
   public static void writeToFile(IPlotter plotter, String file, String type, Properties props) throws IOException, IllegalArgumentException
   {
      checkPlotter(plotter).writeToFile(file,type,props);
   }
   /** Write a plot to an output stream, specifying extra properties
    * @param plotter The plotter to write
    * @param out The output stream to write to
    * @param type The format to write out. Supported types include cgm, emf, gif, pdf, ppm, ps, svg, swf,
    * png and jpg. See the JAIDA release notes for required jar files to support
    * different graphics formats.
    * @param props Properties that control how the image is produced.
    * Supported properties include plotWidth and plotHeight, as well as other format
    * specific properties.
    * @throws IllegalArgumentException If the plotter passed in was not created by JAIDA's default analysis factory
    */   
   public static void writeToFile(IPlotter plotter, OutputStream out, String type, Properties props) throws IOException, IllegalArgumentException
   {
      checkPlotter(plotter).writeToFile(out,type,props);
   }
   private static Plotter checkPlotter(IPlotter plotter)
   {
      if (plotter instanceof Plotter) return (Plotter) plotter;
      else throw new IllegalArgumentException("Invalid plotter: "+plotter);
   }
}
