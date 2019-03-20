package hep.aida.util;

import hep.aida.IHistogram1D;

/**
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
public class HistUtils {
    
    /**
     * Test the distribution of h1 and h2 using the Kolmogorov algorithm.
     * The result is between 0 and 1; 1 is for identical histograms.
     *
     */
    public static double kolmogorovTest( IHistogram1D h1, IHistogram1D h2 ) {
               
        if ( h1 == null || h2 == null )
            throw new IllegalArgumentException("Null Histogram!");
        
        if ( ! h1.axis().equals( h2.axis() ) )
            throw new IllegalArgumentException("The two histograms must have the same binning!");
        
        int nBins = h1.axis().bins();
        
        double[] bins1 = new double[nBins];
        double[] bins2 = new double[nBins];
        
        for ( int i = 0; i < nBins; i++ ) {
            bins1[i] = h1.binHeight(i);
            bins2[i] = h2.binHeight(i);
        }
        return kolmogorovTest(bins1, bins2);        
    }
    
    /**
     * Test the distribution of h1 and h2 using the Kolmogorov algorithm.
     * The result is between 0 and 1; 1 is for identical histograms.
     *
     */
    public static double kolmogorovTest( double[] bins1, double[] bins2 ) {
        
        if ( bins1.length != bins2.length )
            throw new IllegalArgumentException("The two histograms must have the same number of bins!");
        
        int nBins = bins1.length;
        
        double sumOfHeights1 = 0;
        double sumOfHeights2 = 0;
        
        for ( int i = 0; i < nBins; i++ ) {
            sumOfHeights1 += bins1[i];
            sumOfHeights2 += bins2[i];
        }
        
        if ( sumOfHeights1 == 0 || sumOfHeights2 == 0 )
            throw new IllegalArgumentException("The histograms cannot have zero integral!");
        
        double norm1 = 1./sumOfHeights1;
        double norm2 = 1./sumOfHeights2;
        
        // Find largest difference for Kolmogorov Test
        double diff = 0, normSum1 = 0, normSum2 = 0;
        
        for ( int i = 0; i < nBins; i++ ) {
            normSum1 += norm1*bins1[i];
            normSum2 += norm2*bins2[i];
            double tmpDiff = Math.abs( normSum1 - normSum2 );
            if ( tmpDiff > diff ) diff = tmpDiff;
        }
        
        double prob = diff*Math.sqrt(sumOfHeights1*sumOfHeights2/(sumOfHeights1+sumOfHeights2));
        double p = 0;
        if ( prob < 0.2 ) return 1;
        if ( prob > 1 ) {
            // jf2[j] = -2* j**2
            double[] fj2 = {-2. , -8. , -18. , -32. , -50.};
            double s = -2;
            double p2 = prob*prob;
            for ( int i = 0; i < 5; i++ ) {
                s *= -1;
                double c = fj2[i] *p2;
                if (c < -100) return p;
                p += s*Math.exp(c);
            }
            return p;
        }
        
        double[] cons = { -1.233700550136 , -11.10330496 , -30.84251376};
        double sqr2pi = Math.sqrt( 2*Math.PI );
        
        double zinv = 1./prob;
        double a = sqr2pi*zinv;
        double zinv2 = zinv*zinv;
        
        double arg;
        for ( int i =0; i < 3; i++) {
            arg = cons[i]*zinv2;
            if (arg < -30) continue;
            p += Math.exp(arg);
        }
        p = 1 - a*p;
        return p;
        
    }    
}