package hep.aida.ref.optimizer.jminuit;

import hep.aida.IFunction;
import org.freehep.math.minuit.FCNBase;
import org.freehep.math.minuit.FCNGradientBase;

/**
 * @author The AIDA team @SLAC.
 * @version $Id: FunctionWrapper.java,v 1.2 2005/03/10 04:19:57 turri Exp $
 */
abstract class FunctionWrapper
{ 
   private FunctionWrapper()
   {
      
   }
   static FCNBase create(IFunction function)
   {
      if (function.providesGradient()) return new FunctionGradientWrapper(function);
      else return new FunctionBaseWrapper(function);
   }
   private static class FunctionBaseWrapper implements FCNBase
   {
      IFunction function;
      private FunctionBaseWrapper(IFunction function)
      {
         this.function = function;
      }
      public double valueOf(double[] values)
      {
          return function.value(values);
      }
   }
   private static class FunctionGradientWrapper extends FunctionBaseWrapper implements FCNGradientBase
   {
      private FunctionGradientWrapper(IFunction function)
      {
         super(function);
      }
      
      public double[] gradient(double[] par)
      {
          return function.gradient(par);
      }
   }
}
