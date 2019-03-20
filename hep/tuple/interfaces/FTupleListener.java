package hep.tuple.interfaces;

import java.util.EventListener;

/**
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
public interface FTupleListener extends EventListener {
    public void rowsChanged(FTupleEvent e);
}