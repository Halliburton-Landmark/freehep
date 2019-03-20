package hep.aida.ref.fitter.fitData;

import hep.aida.*;

/**
 *
 * Creates FitData.
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
public abstract class FitDataCreator {
    
    private static IFitData create(IBaseHistogram h) {
        FitData fitData = new FitData();
        if ( h instanceof IHistogram ) {
            switch (h.dimension()) {
                case 1 : {
                    fitData.create1DConnection((IHistogram1D)h);
                    break;
                }
                case 2 : {
                    fitData.create2DConnection((IHistogram2D)h);
                    break;
                }
                case 3 : {
                    fitData.create3DConnection((IHistogram3D)h);
                    break;
                }
            }
        } else if ( h instanceof ICloud ) {
            switch (h.dimension()) {
                case 1 : {
                    fitData.create1DConnection((ICloud1D)h);
                    break;
                }
                case 2 : {
                    fitData.create2DConnection((ICloud2D)h);
                    break;
                }
                case 3 : {
                    fitData.create3DConnection((ICloud3D)h);
                    break;
                }
            }
        } else if ( h instanceof IProfile ) {
            switch (h.dimension()) {
                case 1 : {
                    fitData.create1DConnection((IProfile1D)h);
                    break;
                }
                case 2 : {
                    fitData.create2DConnection((IProfile2D)h);
                    break;
                }
            }
        }
        return fitData;
    }

    private static IFitData create(IDataPointSet dps) {
        FitData fitData = new FitData();
        int[] indeces = new int[dps.dimension()-1];
        for ( int i = 0; i < indeces.length; i++ ) indeces[i] = i;
        int valIndex = dps.dimension()-1;
        fitData.createConnection( dps, indeces, valIndex );
        return fitData;
    }
    
    public static IFitData create(Object obj) {
        if ( obj instanceof IFitData )
            return (IFitData)obj;
        if ( obj instanceof IDataPointSet )
            return create((IDataPointSet)obj);
        if ( obj instanceof IBaseHistogram )
            return create((IBaseHistogram)obj);
        throw new IllegalArgumentException("Unsupported class "+obj.getClass()+". Cannot create IFitData from it.");
    }
    
}
