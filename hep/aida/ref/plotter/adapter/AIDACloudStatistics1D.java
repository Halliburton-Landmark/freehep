package hep.aida.ref.plotter.adapter;

import hep.aida.*;
import jas.hist.*;
import hep.aida.ref.*;
import hep.aida.ref.histogram.Cloud;
import java.util.ArrayList;

/**
 *
 * @author manj
 * @version $Id: AIDACloudStatistics1D.java,v 1.4 2005/06/04 00:38:08 turri Exp $
 */
class AIDACloudStatistics1D implements ExtendedStatistics
{
   public AIDACloudStatistics1D(ICloud1D histo)
   {
      this.histo=histo;
   }
   public String[] getStatisticNames()
   {
       ArrayList stat = new ArrayList();
       for ( int i = 0; i < statNames.length; i++ )
           stat.add(statNames[i]);
       if ( getExtendedStatistic(outOfRangeStat) != null && ((Integer) getExtendedStatistic(outOfRangeStat)).intValue() != 0 )
           stat.add(outOfRangeStat);
       if ( getExtendedStatistic(nanExtStat) != null && ((Integer) getExtendedStatistic(nanExtStat)).intValue() != 0 )
           stat.add(nanExtStat);
       if ( ((Integer) getExtendedStatistic("Entries")).intValue() != ((Double) getExtendedStatistic(sumOfWeightsStat)).doubleValue() )
           stat.add(sumOfWeightsStat);
       
        IAnnotation an = histo.annotation();
        if (an != null) {
            int n = an.size();
            for (int i=0; i<n; i++) {
                try {
                    String key = an.key(i);
                    if (key.toLowerCase().startsWith("stat:")) {
                        stat.add(key.substring(5));
                    }                 
                } catch (IllegalArgumentException e) {}
            }
        }
       
       String[] statArray = new String[stat.size()];
       for ( int i = 0; i < stat.size(); i++ )
           statArray[i] = (String)stat.get(i);
      return statArray;
   }
   public double getStatistic(String name)
   {
      if (name.equals("Mean")) return histo.mean();
      if (name.equals("Rms"))  return histo.rms();
      return 0;
   }
   public Object getExtendedStatistic(String name)
   {
      if (name.equals("Entries"))    return new Integer(histo.entries());
      if (name.equals(outOfRangeStat)) {
          if ( histo.isConverted() ) 
              return new Integer(histo.histogram().extraEntries());
      }
      if (name.equals(nanExtStat))
          return new Integer( histo.nanEntries() );
      if (name.equals(sumOfWeightsStat)) return new Double(histo.sumOfWeights());

        IAnnotation an = histo.annotation();
        if (an == null) return null;
        String v = null;
        try {
            v = an.value("stat:"+name);
        } catch (IllegalArgumentException e) {}
        return v;
   }
   private ICloud1D histo;
   private final String[] statNames = {"Entries","Mean","Rms"};
    private final String nanExtStat = "NaN";
    private final String sumOfWeightsStat = "SumOfWeights";
    private final String outOfRangeStat = "OutOfRange";
}