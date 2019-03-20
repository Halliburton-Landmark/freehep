package hep.aida.ref.pdf.test;

import hep.aida.*;
import java.util.Random;
import hep.aida.ref.pdf.*;

public class UnbinnedGaussianFit extends AbstractPdfTestCase {
    
    private ICloud1D c1;
    
    public UnbinnedGaussianFit(String name) {
        super(name);
        
        c1 = histogramFactory().createCloud1D("Cloud 1D");
        Random r = new Random();
        for (int i=0; i<100000; i++)
            c1.fill(r.nextGaussian());
    }
    
    public void testFit() {

        Gaussian g = new Gaussian("myGauss");
        IModelFunction gauss = FunctionConverter.getIModelFunction(g);
        
        IRangeSet r1 = gauss.normalizationRange(0);
        r1.excludeAll();
        r1.include(c1.lowerEdge(),c1.upperEdge());
        
        gauss.setParameter("mean",c1.mean());
        gauss.setParameter("sigma",c1.rms());
        
        IFitter gaussFit = fitFactory().createFitter("uml","minuit","noClone=true");
        
        // Fit the first gaussian
        
        long start = System.currentTimeMillis();
        IFitResult gaussFitResult = gaussFit.fit(c1,gauss);
        long end = System.currentTimeMillis();
        long time = end-start;
        
        assertEquals(c1.mean(), g.getParameter("mean").value(),0.001);
        assertEquals(c1.rms(), g.getParameter("sigma").value(),0.002);
        
        assertEquals(time, 6000, 3000);
                
    }
}