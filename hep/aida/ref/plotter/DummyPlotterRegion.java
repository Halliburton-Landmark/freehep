package hep.aida.ref.plotter;
import hep.aida.*;
import hep.aida.IInfo;
import hep.aida.IPlotterLayout;
import hep.aida.IPlotterStyle;
import hep.aida.ref.plotter.Info;
import hep.aida.ref.plotter.PlotterLayout;
import hep.aida.ref.plotter.PlotterStyle;

/**
 * A dummy implementation of PlotterRegion 
 * @author tonyj
 * @version $Id: DummyPlotterRegion.java,v 1.4 2005/06/04 00:38:05 turri Exp $
 */
class DummyPlotterRegion implements IPlotterRegion
{
    
    private IPlotterLayout plotterLayout = new PlotterLayout();
    private IInfo info = new Info();
    
   private static final String[] emptyArray = new String[0];
   DummyPlotterRegion(double x, double y, double width, double height)
   {
   }
   
   public String[] availableParameterOptions(String str)
   {
      return emptyArray;
   }
   
   public String[] availableParameters()
   {
      return emptyArray;
   }
   
   public void setParameter(String str)
   {
   }
   
   public void setParameter(String str, String str1)
   {
   }
   
   public void clear()
   {
   }
   
   public void plot(IBaseHistogram iBaseHistogram)
   {
   }
   
   public void plot(IDataPointSet iDataPointSet)
   {
   }
   
   public void plot(IFunction iFunction)
   {
   }
   
   public void remove(IDataPointSet iDataPointSet)
   {
   }
   
   public void remove(IFunction iFunction)
   {
   }
   
   public void remove(IBaseHistogram iBaseHistogram)
   {
   }   
   
    public void remove(IPlottable plottable) throws IllegalArgumentException {
    }
    
   public void plot(hep.aida.IDataPointSet iDataPointSet, hep.aida.IPlotterStyle iPlotterStyle) throws java.lang.IllegalArgumentException
   {
   }
   
   public void plot(hep.aida.IFunction iFunction, hep.aida.IPlotterStyle iPlotterStyle, String str) throws java.lang.IllegalArgumentException
   {
   }
   
   public void plot(hep.aida.IFunction iFunction, String str) throws java.lang.IllegalArgumentException
   {
   }
   
   public void plot(hep.aida.IDataPointSet iDataPointSet, hep.aida.IPlotterStyle iPlotterStyle, String str) throws java.lang.IllegalArgumentException
   {
   }
   
   public void plot(hep.aida.IDataPointSet iDataPointSet, String str) throws java.lang.IllegalArgumentException
   {
   }
   
   public void setXLimits(double param)
   {
   }
   
   public void setZLimits(double param)
   {
   }
   
   public void setYLimits(double param)
   {
   }
   
   public void plot(hep.aida.IBaseHistogram iBaseHistogram, hep.aida.IPlotterStyle iPlotterStyle, String str) throws java.lang.IllegalArgumentException
   {
   }
   
   public void plot(hep.aida.IBaseHistogram iBaseHistogram, String str) throws java.lang.IllegalArgumentException
   {
   }
   
   public void setZLimits(double param, double param1)
   {
   }
   
   public void setZLimits()
   {
   }
   
   public void setYLimits(double param, double param1)
   {
   }
   
   public void setYLimits()
   {
   }
   
    public double xLimitMin() {
        return Double.NaN;
    }

    public double xLimitMax() {
        return Double.NaN;
    }

    public double yLimitMin() {
        return Double.NaN;
    }

    public double yLimitMax() {
        return Double.NaN;
    }

    public double zLimitMin() {
        return Double.NaN;
    }

    public double zLimitMax() {
        return Double.NaN;
    }

    public void plot(hep.aida.IFunction iFunction, hep.aida.IPlotterStyle iPlotterStyle) throws java.lang.IllegalArgumentException
   {
   }
   
   public void plot(hep.aida.IBaseHistogram iBaseHistogram, hep.aida.IPlotterStyle iPlotterStyle) throws java.lang.IllegalArgumentException
   {
   }
   
    public void plot(IPlottable plottable) throws IllegalArgumentException {
    }

    public void plot(IPlottable plottable, String options) throws IllegalArgumentException {
    }

    public void plot(IPlottable plottable, IPlotterStyle style) throws IllegalArgumentException {
    }

    public void plot(IPlottable plottable, IPlotterStyle style, String options) throws IllegalArgumentException {
    }
    
   public void setXLimits(double param, double param1) throws java.lang.IllegalArgumentException
   {
   }
   
   public void setXLimits() throws java.lang.IllegalArgumentException
   {
   }
   
   public void setStyle(hep.aida.IPlotterStyle iPlotterStyle) throws java.lang.IllegalArgumentException
   {
   }
   
   public hep.aida.IPlotterLayout layout()
   {
      return plotterLayout;
   }
   
   public void applyStyle(hep.aida.IPlotterStyle iPlotterStyle) throws java.lang.IllegalArgumentException
   {
   }
   
   public hep.aida.IInfo info()
   {
      return info;
   }
   
   public void setLayout(hep.aida.IPlotterLayout iPlotterLayout)
   {
       this.plotterLayout = iPlotterLayout;
   }
   
   public hep.aida.IPlotterStyle style()
   {
      return null;
   }
   
   public void setTitle(String str)
   {
   }
   
   public String parameterValue(String str) {
       return null;
   }
   
   public String title() {
       return null;
   }
   
   public void refresh() {
   }
   
}
