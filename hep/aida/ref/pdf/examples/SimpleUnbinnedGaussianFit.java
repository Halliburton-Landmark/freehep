import hep.aida.*;
import java.util.Random;
import hep.aida.ref.pdf.*;
import hep.aida.ref.function.*;

public class SimpleUnbinnedGaussianFit
{
   public static void main(String[] args)
   {
      // Create factories
      IAnalysisFactory  analysisFactory = IAnalysisFactory.create();
      ITreeFactory      treeFactory = analysisFactory.createTreeFactory();
      ITree             tree = treeFactory.create();
      IPlotter          plotter = analysisFactory.createPlotterFactory().create("Plotter");
      IHistogramFactory histogramFactory = analysisFactory.createHistogramFactory(tree);
      IFunctionFactory  functionFactory = analysisFactory.createFunctionFactory(tree);
      IFitFactory       fitFactory = analysisFactory.createFitFactory();
    
      ICloud1D c1 = histogramFactory.createCloud1D("Cloud 1D");

      Random r = new Random(123);

      for (int i=0; i<100000; i++) {
          c1.fill(r.nextGaussian());
      }

      IHistogram1D h1 = histogramFactory.createHistogram1D("Histogram 1D",50,c1.lowerEdge(),c1.upperEdge());
      c1.fillHistogram(h1);

      Gaussian g = new Gaussian("myGauss");
      g.setParameter("mean",h1.mean());
      g.setParameter("sigma",h1.rms());

      IRangeSet r1 = g.normalizationRange(0);
      r1.excludeAll();
      r1.include(c1.lowerEdge(),c1.upperEdge());

      double h1Norm = h1.sumBinHeights()*(h1.axis().upperEdge()-h1.axis().lowerEdge())/h1.axis().bins();
      h1.scale(1./h1Norm);

      plotter.region(0).plot(h1);

      PdfFitter gaussFit = new PdfFitter("uml","minuit");

      long start = System.currentTimeMillis();
  
      gaussFit.fit(c1,g);
      long end = System.currentTimeMillis();
      long time = end-start;

      System.out.println("Time to fit : "+time);

      plotter.region(0).plot(g);
      plotter.show();
   }
}