package hep.aida.util.comparison;

import cern.jet.stat.Probability;
import hep.aida.ext.IComparisonData;

/**
 *
 * @author The FreeHEP team @ SLAC.
 * Algorithm taken from http://www.ge.infn.it/geant4/analysis/HEPstatistics/
 *
 */
public class Chi2ComparisonAlgorithm extends AbstractComparisonAlgorithm {
    
    private static final String[] names = new String[] {"chi2", "chiSquared"};
    private static final int dType = ONLY_BINNED_DATA;
    private static final int eType = ONLY_SAME_NUMBER_OF_EVENTS;
    
    
    public Chi2ComparisonAlgorithm() {
        super(dType, eType);
    }
    
    public String[] algorithmNames() {
        return names;
    }
    
    public double quality(IComparisonData d1, IComparisonData d2) {
        
        if ( ! canCompare(d1,d2) )
            throw new IllegalArgumentException("Invalid data. The "+names[0]+" cannot compare the given datasets. They MUST be binned with the SAME binning.");
                
        int n = d1.nPoints();
        double chi2 = 0;
        
        int nDf = 0;

        for (int i=0; i < n; i++) {
            double w1 = d1.weight(i);
            double w2 = d2.weight(i);
            double w = w1 + w2;
            if ( w > 0) {
                double dw = w1 - w2;
                chi2 += dw*dw /w; 
                nDf++;
            }
        }
        return Probability.chiSquare(nDf,chi2);
    }
    
    public int nDof(IComparisonData d1, IComparisonData d2) {
        int n = d1.nPoints();
        int nDf = 0;

        for (int i=0; i < n; i++) {
            double w1 = d1.weight(i);
            double w2 = d2.weight(i);
            double w = w1 + w2;
            if ( w > 0)
                nDf++;
        }
        return nDf;
    }    
    
    public boolean canCompare(IComparisonData d1, IComparisonData d2) {        
        boolean superCanCompare = super.canCompare(d1,d2);
        if ( ! superCanCompare )
            return false;
        
        int nPoints = d1.nPoints();
        if ( nPoints != d2.nPoints() )
            return false;
        
        for ( int i = 0; i < nPoints; i++ )
            if ( d1.value(i) != d2.value(i) )
                return false;
        return true;        
    }

}
