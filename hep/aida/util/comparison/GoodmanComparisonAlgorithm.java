package hep.aida.util.comparison;

import cern.jet.stat.Probability;
import hep.aida.ext.IComparisonAlgorithm;
import hep.aida.ext.IComparisonData;

/**
 *
 * @author The FreeHEP team @ SLAC.
 * Algorithm taken from http://www.ge.infn.it/geant4/analysis/HEPstatistics/
 *
 */
public class GoodmanComparisonAlgorithm extends KolmogorovSmirnovComparisonAlgorithm {
    
    private static final String[] names = new String[] {"Goodman","KolmogorovSmirnovChi2Approx","KSChi2Approx"};

    public String[] algorithmNames() {
        return names;
    }
    
    public double quality(IComparisonData d1, IComparisonData d2) {
        
        double distance = evaluateDistance(d1,d2);
        
        double entries1 = entries(d1);
        double entries2 = entries(d2);
        double n = entries1 * entries2 / (entries1 + entries2);

	double chi2 = 4 * distance * distance * n;
      	return Probability.chiSquare(3,chi2);        
    }
}
