package hep.aida.ref.function;

import hep.aida.ref.function.FunctionChangedEvent;

/**
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
public interface FunctionListener {
    
    public void functionChanged(FunctionChangedEvent event);
    
}
