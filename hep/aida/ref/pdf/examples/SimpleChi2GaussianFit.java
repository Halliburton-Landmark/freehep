import hep.aida.*;
import java.util.Random;
import hep.aida.ref.pdf.*;

public class SimpleChi2GaussianFit
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
    
      IHistogram1D h1 = histogramFactory.createHistogram1D("Histogram 1D",50,-3,3);

      Random r = new Random();

      for (int i=0; i<100000; i++)
          h1.fill(r.nextGaussian());

      Gaussian g = new Gaussian("myGauss");
      g.setParameter("norm",h1.maxBinHeight());
      g.setParameter("mean",h1.mean());
      g.setParameter("sigma",h1.rms());


      plotter.region(0).plot(h1);

      PdfFitter gaussFit = new PdfFitter("Chi2","minuit");
//      gaussFit.setUseFunctionGradient(false);

      long start = System.currentTimeMillis();
  
      gaussFit.fit(h1, g);
      long end = System.currentTimeMillis();
      long time = end-start;

      System.out.println("Time to fit : "+time);

      plotter.region(0).plot(g);
      plotter.show();
      
   }
}