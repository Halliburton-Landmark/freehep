// -*- C++ -*-
#ifndef JAIDA_JIFITDATA_H
#define JAIDA_JIFITDATA_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>
#include <map>

#include "AIDA/ICloud1D.h"
#include "AIDA/ICloud2D.h"
#include "AIDA/ICloud3D.h"
#include "AIDA/IDataPointSet.h"
#include "AIDA/IEvaluator.h"
#include "AIDA/IFitData.h"
#include "AIDA/IHistogram1D.h"
#include "AIDA/IHistogram2D.h"
#include "AIDA/IHistogram3D.h"
#include "AIDA/IProfile1D.h"
#include "AIDA/IProfile2D.h"
#include "AIDA/IRangeSet.h"
#include "AIDA/ITuple.h"

#include "JProxy.h"

namespace JAIDA {

/** @interface
 *
 * Abstract representation of the fit data. Serves for several purposes:
 *  - decouple fitter from the details of the particular data
 *    objects (Histograms etc)
 *  - provide range restriction capability ("cut of the tails...")
 *  - creates the image of the virtual data source
 *
 * Design notes:
 *
 * 1)
 * we try to be explicit in the method names which should indicate the
 * dimensionality of the fit data.
 *
 * this way we have more compile-time/run-time safety and clearer code.
 * in C++ we can handle default arguments which otherwise would be ambigeous.
 *
 * 2)
 * string names of the arguments are at the end of the methods'
 * signatures and have default (empty) values.
 * so if function argument name is missing,
 * assume the ordering is taken from the histogram axis it connects to
 * the name of the pipes then are generated automatically using
 * the same default scheme as for functions x[1], x[2] etc.
 *
 * 3)
 * There are two ends to pipes: one connected to the
 * data source and one pouring data out. Both their orders has to be specified.
 *
 * For IHistogram, ICloud, IProfile the connections to the data source are
 * ordered as the axis (x=0, y=1, z=2); the user has to provide the order
 * with which the pipes are providing the data. So for example in the constructor
 *   create2DConnection(hist2D,xIndex,yIndex);
 * xIndex specifies the exit order of the pipe connected to the x Axis (and similarly
 * for yIndex). So the default method
 *   create2DConnection(hist2D);
 * corresponds to
 *   create2DConnection(hist2D,0,1);
 * In the methods for IHistograms, IClouds, and IProfiles one index could have
 * been dropped as the second could be inferred by the dimensionality. We
 * preferred being redundant just to avoid confusion in interpreting what
 *   create2DConnection(hist2D,1);
 * really means.
 *
 * For ITuple and IDataPointSet the order in the connection to the data source
 * is specified by the user by providing, respectively, the array of column names (or evaluators)
 * and the array of coordinate indexes to which to connect the pipes.
 * In this case we assume that the pipes are parallel, i.e. the exit order is the same
 * as the one of the connection to the data source.
 * In the createXDConnection methods to IDataPointSets we preferred not to provide
 * defaults for the valIndex to avoid confusion in interpreting it.
 * We can always add it later.
 *
 * PENDING: clarify the relation between data range and normalization range
 *
 * @author The AIDA Team.
 *
 */

class JIFitData: public JProxy, public virtual AIDA::IFitData {

private:
    jmethodID create2DConnectionOLhep_aida_IDataPointSetEIIICVMethod;
    jmethodID create1DConnectionOLhep_aida_IProfile1DECVMethod;
    jmethodID create2DConnectionOLhep_aida_IHistogram2DEIICVMethod;
    jmethodID create2DConnectionOLhep_aida_ICloud2DEIICVMethod;
    jmethodID create2DConnectionOLhep_aida_IProfile2DECVMethod;
    jmethodID create1DConnectionOLhep_aida_ICloud1DECVMethod;
    jmethodID createConnectionOLhep_aida_ITupleEALhep_aida_IEvaluatorECVMethod;
    jmethodID createConnectionOLhep_aida_ITupleEALjava_lang_StringECVMethod;
    jmethodID resetOCVMethod;
    jmethodID rangeOICLhep_aida_IRangeSetEMethod;
    jmethodID create2DConnectionOLhep_aida_IHistogram2DECVMethod;
    jmethodID dataDescriptionOCLjava_lang_StringEMethod;
    jmethodID create1DConnectionOLhep_aida_IHistogram1DECVMethod;
    jmethodID createConnectionOLhep_aida_IDataPointSetEAIICVMethod;
    jmethodID create3DConnectionOLhep_aida_IHistogram3DEIIICVMethod;
    jmethodID create2DConnectionOLhep_aida_ICloud2DECVMethod;
    jmethodID create1DConnectionOLhep_aida_IDataPointSetEIICVMethod;
    jmethodID create3DConnectionOLhep_aida_IDataPointSetEIIIICVMethod;
    jmethodID create2DConnectionOLhep_aida_IProfile2DEIICVMethod;
    jmethodID create3DConnectionOLhep_aida_IHistogram3DECVMethod;
    jmethodID create3DConnectionOLhep_aida_ICloud3DEIIICVMethod;
    jmethodID dimensionOCIMethod;
    jmethodID create3DConnectionOLhep_aida_ICloud3DECVMethod;
    mutable std::map<int, AIDA::IRangeSet*> rangeSetMap;

protected:
    inline JIFitData() { };
    inline JIFitData(const JIFitData& r):JProxy(r) { };
    inline JIFitData& operator=(const JIFitData&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIFitData(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIFitData();

    /**
     * One dimensional connections.
     *
     */

    /**
     * Create a one dimensional connection to an IHistogram1D.
     * @param h       The 1D histogram to which to connect to.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create1DConnection(const AIDA::IHistogram1D & h);

    /**
     * Create a one dimensional connection to an ICloud1D.
     * @param c       The 1D cloud to which to connect to.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create1DConnection(const AIDA::ICloud1D & c);

    /**
     * Create a one dimensional connection to an IProfile1D.
     * @param p       The 1D profile to which to connect to.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create1DConnection(const AIDA::IProfile1D & p);

    /**
     * Create a one dimensional connection to an IDataPointSet.
     * @param dp       The dataPointSet to which to connect to.
     * @param xIndex   The index of the coordinate to which the variable is connected.
     * @param valIndex The index of the coordinate used as "height".
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create1DConnection(const AIDA::IDataPointSet & dp, int xIndex, int valIndex);

    /**
     * Two dimensional connections.
     *
     */

    /**
     * Create a two dimensional connection to an IHistogram2D.
     * @param h        The 2D histogram to which to connect to.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create2DConnection(const AIDA::IHistogram2D & h);

    /**
     * Create a two dimensional connection to an IHistogram2D.
     * @param h        The 2D histogram to which to connect to.
     * @param xIndex   The index of the axis to which the x variable is connected.
     * @param yIndex   The index of the axis to which the y variable is connected.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create2DConnection(const AIDA::IHistogram2D & h, int xIndex, int yIndex);

    /**
     * Create a two dimensional connection to an ICloud2D.
     * @param c        The 2D cloud to which to connect to.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create2DConnection(const AIDA::ICloud2D & c);

    /**
     * Create a two dimensional connection to an ICloud2D.
     * @param c        The 2D cloud to which to connect to.
     * @param xIndex   The index of the axis to which the x variable is connected.
     * @param yIndex   The index of the axis to which the y variable is connected.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create2DConnection(const AIDA::ICloud2D & c, int xIndex, int yIndex);

    /**
     * Create a two dimensional connection to an IProfile2D.
     * @param p       The 2D profile to which to connect to.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create2DConnection(const AIDA::IProfile2D & p);

    /**
     * Create a two dimensional connection to an IProfile2D.
     * @param p        The 2D profile to which to connect to.
     * @param xIndex   The index of the axis to which the x variable is connected.
     * @param yIndex   The index of the axis to which the y variable is connected.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create2DConnection(const AIDA::IProfile2D & p, int xIndex, int yIndex);

    /**
     * Create a two dimensional connection to an IDataPointSet.
     * @param dp       The dataPointSet to which to connect to.
     * @param xIndex   The index of the coordinate to which the x variable is connected.
     * @param yIndex   The index of the coordinate to which the y variable is connected.
     * @param valIndex The index of the coordinate used as "height".
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create2DConnection(const AIDA::IDataPointSet & dp, int xIndex, int yIndex, int valIndex);

    /**
     * Three dimensional connections.
     *
     */

    /**
     * Create a three dimensional connection to an IHistogram3D.
     * @param h        The 3D histogram to which to connect to.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create3DConnection(const AIDA::IHistogram3D & h);

    /**
     * Create a three dimensional connection to an IHistogram3D.
     * @param h        The 3D histogram to which to connect to.
     * @param xIndex   The index of the axis to which the x variable is connected.
     * @param yIndex   The index of the axis to which the y variable is connected.
     * @param zIndex   The index of the axis to which the z variable is connected.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create3DConnection(const AIDA::IHistogram3D & h, int xIndex, int yIndex, int zIndex);

    /**
     * Create a three dimensional connection to an ICloud3D.
     * @param c        The 3D cloud to which to connect to.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create3DConnection(const AIDA::ICloud3D & c);

    /**
     * Create a three dimensional connection to an ICloud3D.
     * @param c        The 3D cloud to which to connect to.
     * @param xIndex   The index of the axis to which the x variable is connected.
     * @param yIndex   The index of the axis to which the y variable is connected.
     * @param zIndex   The index of the axis to which the z variable is connected.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create3DConnection(const AIDA::ICloud3D & c, int xIndex, int yIndex, int zIndex);

    /**
     * Create a three dimensional connection to an IDataPointSet.
     * @param dp       The dataPointSet to which to connect to.
     * @param xIndex   The index of the coordinate to which the x variable is connected.
     * @param yIndex   The index of the coordinate to which the y variable is connected.
     * @param zIndex   The index of the coordinate to which the z variable is connected.
     * @param valIndex The index of the coordinate used as "height".
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool create3DConnection(const AIDA::IDataPointSet & dp, int xIndex, int yIndex, int zIndex, int valIndex);

    /**
     * General connections.
     *
     */

    /**
     * Tuples are for UNBINNED fits, so no value column required.
     */

    /**
     * Create a connection to an ITuple.
     * @param t        The ITuple.
     * @param colNames The names of the columns to which to connect.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool createConnection(const AIDA::ITuple & t, std::vector<std::string>  colNames);

    /**
     * Create a connection to an ITuple.
     * @param t     The ITuple.
     * @param evals The list of the IEvaluator used to calculate the variable's value.
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool createConnection(const AIDA::ITuple & t, std::vector<AIDA::IEvaluator *>  & evals);

    /**
     * Create a connection to an IDataPointSet.
     * @param dp       The dataPointSet to which to connect to.
     * @param indeces  The indeces of the coordinates to which the variables are connected.
     * @param valIndex The index of the coordinate used as "height".
     * @return false If something is wrong.
     *
     */
    JNIEXPORT virtual bool createConnection(const AIDA::IDataPointSet & dp, std::vector<int>  indeces, int valIndex);

    /**
     * Remove all Ranges and connections; after this is like newly create.
     *
     */
    JNIEXPORT virtual void reset();

    /**
     * The dimension of this IFitData, i.e. the number of connections.
     * @return The dimension of the IFitData.
     *
     */
    JNIEXPORT virtual int dimension() const;

    /// Return a string describing the data. This should be considered as a
    /// hint to the user where to find the original data objects and how
    /// to connect the data pipes. PENDING: probably this can be part of
    /// XML streaming.
    JNIEXPORT virtual std::string dataDescription() const;

    /**
     * Get Range of the corresponding connection by index.
     * The index represent the order in which
     * connections are coming out of the IFitData.
     * @param  The index of the connection.
     * @return      The Range
     *
     */
    JNIEXPORT virtual AIDA::IRangeSet & range(int index) const;

    /** @link aggregation */
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIFITDATA_H */
