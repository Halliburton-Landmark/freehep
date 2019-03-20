package hep.aida.ref;

import hep.aida.IPlotterFactory;
import hep.aida.ref.BatchAnalysisFactory;
import hep.aida.ref.plotter.PlotterFactory;

/**
 *
 * @author tonyj
 * @version $Id: AnalysisFactory.java,v 1.28 2003/06/05 21:55:40 turri Exp $
 */
public class AnalysisFactory extends BatchAnalysisFactory
{
    public IPlotterFactory createPlotterFactory() {
        return new PlotterFactory();
    }
}
