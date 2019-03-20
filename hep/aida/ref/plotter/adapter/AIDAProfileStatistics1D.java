/*
 * AidaStatistics.java
 *
 * Created on March 19, 2001, 12:58 PM
 */

package hep.aida.ref.plotter.adapter;

import hep.aida.*;
import hep.aida.ref.*;
import jas.hist.*;
import java.util.ArrayList;

/**
 *
 * @author  manj
 * @version $Id: AIDAProfileStatistics1D.java,v 1.6 2005/06/04 00:38:08 turri Exp $
 */
class AIDAProfileStatistics1D implements ExtendedStatistics
{
    /** Creates new AidaStatistics */
    AIDAProfileStatistics1D(IProfile1D profile)
   {
      this.profile = profile;
   }
    /**
     * @return A list of statistic names
     */
   public String[] getStatisticNames()
   {
       ArrayList stat = new ArrayList();
       for ( int i = 0; i < statNames.length; i++ )
           stat.add(statNames[i]);
       if ( ((Integer) getExtendedStatistic(outOfRangeStat)).intValue() != 0 )
           stat.add(outOfRangeStat);
       if ( ((Integer) getExtendedStatistic(nanExtStat)).intValue() != 0 )
           stat.add(nanExtStat);
       if ( ((Integer) getExtendedStatistic("Entries")).intValue() != ((Double) getExtendedStatistic(sumOfWeightsStat)).doubleValue() )
           stat.add(sumOfWeightsStat);
       
        IAnnotation an = profile.annotation();
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
   /**
    * @param The statistic name, as returned by getStatisticNames()
    * @return The value for the statistic
    */
   public double getStatistic(String name)
   {
      if (name.equals("Mean"))       return profile.mean();
      if (name.equals("Rms"))        return profile.rms();
      return 0;
   }
   public Object getExtendedStatistic(String name)
   {
      if (name.equals("Entries"))    return new Integer(profile.entries());
      if (name.equals(outOfRangeStat)) return new Integer(profile.extraEntries());
      if (name.equals(nanExtStat))   return new Integer(profile.nanEntries());
        if (name.equals(sumOfWeightsStat)) return new Double(profile.sumBinHeights());

        IAnnotation an = profile.annotation();
        if (an == null) return null;
        String v = null;
        try {
            v = an.value("stat:"+name);
        } catch (IllegalArgumentException e) {}
        return v;
   }
   private IProfile1D profile;
   private final String[] statNames = {"Entries","Mean","Rms"};
   private final String nanExtStat = "NaN";
    private final String sumOfWeightsStat = "SumOfWeights";
    private final String outOfRangeStat = "OutOfRange";
}
