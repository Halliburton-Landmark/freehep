package hep.aida.ref.plotter.adapter;

import jas.hist.*;
import hep.aida.*;

/**
 * @author manj
 * @version $Id: AIDAHistogramAdapter1D.java,v 1.6 2005/12/16 01:36:45 serbo Exp $
 */
public class AIDAHistogramAdapter1D extends AIDAHistogramAdapter implements Rebinnable1DHistogramData, HasStatistics
{
    
    AIDAHistogramAdapter1D(IHistogram1D histo)
   {
      super(histo);
      this.h1d=histo;
      String tmp = null;
       try {
            tmp = histo.annotation().value("xAxisType");
            if (tmp != null && tmp.equalsIgnoreCase("date")) xAxisType = DataSource.DATE;
        } catch (IllegalArgumentException e) {}
   }  
   public double[][] rebin(int bins, double min, double max, boolean wantErrors, boolean hurry)
   {
      double[][] data=new double[2][h1d.axis().bins()];
      for(int i=0;i<h1d.axis().bins();i++)
      {
         data[0][i]=h1d.binHeight(i);
         if (Double.isInfinite(data[0][i])) data[0][i] = Double.NaN;
         data[1][i]=h1d.binError(i);
      }
      setValid();
      return data;
   }
   /**
    * Returns the (suggested) minimum value for the X axis
    */
   public double getMin()
   {
      return h1d.axis().lowerEdge();
   }
   public double getMax()
   {
      return h1d.axis().upperEdge();
   }
   public int getBins()
   {
      return h1d.axis().bins();
   }
   public boolean isRebinnable()
   {
      return false;
   }
    
    public int getAxisType() {
        return xAxisType;
    }
    
    public void setAxisType(int type) {
        xAxisType = type;
    }   
   
   public String[] getAxisLabels()
   {
      return null;
   }
   public String getTitle()
   {
      return h1d.title();
   }
   public Statistics getStatistics()
   {
      return new AIDAHistogramStatistics1D(h1d);  
   }
   private IHistogram1D h1d;
}
