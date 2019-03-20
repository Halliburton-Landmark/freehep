package hep.aida.ref.plotter.adapter;

import jas.hist.*;
import hep.aida.*;
import hep.aida.ref.*;
import hep.aida.ref.histogram.*;


/**
 *
 * @author  manj
 * @version $Id: AIDACloudAdapter1D.java,v 1.8 2005/05/11 19:28:00 serbo Exp $
 */
public class AIDACloudAdapter1D extends AIDACloudAdapter implements Rebinnable1DHistogramData, HasStatistics
{
   public AIDACloudAdapter1D(ICloud1D cloud)
   {
      super(cloud);
      this.cloud=cloud;
      this.bins = 50;
      String tmp = null;
        try {
            tmp = cloud.annotation().value("xAxisType");
            if (tmp != null && tmp.equalsIgnoreCase("date")) xAxisType = DataSource.DATE;
        } catch (IllegalArgumentException e) {}
   }
   public double[][] rebin(int bins, double min, double max, boolean wantErrors, boolean hurry)
   {
      IHistogram1D histo = null;
      setValid();
      if(isRebinnable()) histo=HistUtils.toShowableHistogram(cloud,bins,min,max);
      else               histo=cloud.histogram();
      
      double[][] data=new double [2][histo.axis().bins()];
      for(int i=0;i<histo.axis().bins();i++)
      {
         data[0][i]=histo.binHeight(i);
         if (Double.isInfinite(data[0][i])) data[0][i] = Double.NaN;
         data[1][i]=histo.binError(i);
      }
      return data;
   }
   public double getMin()
   {
       if ( isRebinnable() ) {
           if ( cloud instanceof Cloud1D ) 
               return ((Cloud1D)cloud).lowerEdgeWithMargin();
           else
               return cloud.lowerEdge();
       }
       return cloud.histogram().axis().lowerEdge();
   }
   public double getMax()
   {
       if ( isRebinnable() ) {
           if ( cloud instanceof Cloud1D ) 
               return ((Cloud1D)cloud).upperEdgeWithMargin();
           else
               return cloud.upperEdge();
       }
       return cloud.histogram().axis().upperEdge();
   }
   public int getBins()
   {
      return isRebinnable() ?  bins : cloud.histogram().axis().bins();
   }
   public boolean isRebinnable()
   {
      return (!cloud.isConverted());
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
      return cloud.title();
   }
   public Statistics getStatistics()
   {
      return new AIDACloudStatistics1D(cloud);
   }
   private ICloud1D cloud;
   private int bins;
}


