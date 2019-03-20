package hep.aida.ref.function;

import hep.aida.ref.function.FunctionListener;

/**
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
public interface FunctionDispatcher {
    
    void addFunctionListener( FunctionListener listener );
    void removeFunctionListener( FunctionListener listener );
    
}
