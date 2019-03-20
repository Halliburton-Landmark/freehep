// -*- C++ -*-
#ifndef JAIDA_JICLOUD1D_H
#define JAIDA_JICLOUD1D_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <vector>

#include "AIDA/ICloud1D.h"
#include "AIDA/IHistogram1D.h"
#include "JICloud.h"
#include "JIManagedObject.h"

namespace JAIDA {

/**
 * User level interface to a 1D Cloud.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JICloud1D: public JICloud, public JIManagedObject, public virtual AIDA::ICloud1D {

private:
    jmethodID convertOIDDCVMethod;
    jmethodID upperEdgeOCDMethod;
    jmethodID convertOADCVMethod;
    jmethodID rmsOCDMethod;
    jmethodID fillHistogramOLhep_aida_IHistogram1DECVMethod;
    jmethodID meanOCDMethod;
    jmethodID valueOICDMethod;
    jmethodID weightOICDMethod;
    jmethodID histogramOCLhep_aida_IHistogram1DEMethod;
    jmethodID fillODDCVMethod;
    jmethodID lowerEdgeOCDMethod;

protected:
    inline JICloud1D() { };
    inline JICloud1D(const JICloud1D& r):JICloud(r),JIManagedObject(r) { };
    inline JICloud1D& operator=(const JICloud1D&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JICloud1D(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JICloud1D();

    /**
     * Fill the ICloud1D with a value and a corresponding weight.
     * @param x      The value.
     * @param weight The corresponding weight. By default it is 1.
     * @return false If the ICloud1D is full, if the weight's value is
     *                                  is not between 0 and 1.
     *
     */
    JNIEXPORT virtual bool fill(double x, double weight);

    /**
     * Get the lower edge of the ICloud1D.
     * @return The lower edge.
     *
     */
    JNIEXPORT virtual double lowerEdge() const;

    /**
     * Get the upper edge of the ICloud1D.
     * @return The upper edge.
     *
     */
    JNIEXPORT virtual double upperEdge() const;

    /**
     * Get the value corresponding to a given entry.
     * @param index The entry's index.
     * @return      The value of the index-th entry.
     *              If the ICloud1D has already been converted, 0 is returned.
     *
     */










    JNIEXPORT virtual double value(int index) const;

    /**
     * Get the weight corresponding to a given entry.
     * @param index The entry's index.
     * @return      The weight of the index-th entry.
     *              If the ICloud1D has already been converted, 0 is returned.
     *
     */










    JNIEXPORT virtual double weight(int index) const;

    /**
     * Get the mean of the ICloud1D.
     * @return The mean.
     *
     */
    JNIEXPORT virtual double mean() const;

    /**
     * Get the RMS of the ICloud1D.
     * @return The RMS.
     *
     */
    JNIEXPORT virtual double rms() const;

    /**
     * Convert internally the ICloud1D to an IHistogram1D
     * with given number of bins, upper edge and lower edge.
     * @param nBins     The number of bins.
     * @param lowerEdge The lower edge.
     * @param upperEdge The upper edge.
     * @return false If the ICloud1D has already been converted.
     *
     */
    JNIEXPORT virtual bool convert(int nBins, double lowerEdge, double upperEdge);

    /**
     * Convert internally the ICloud1D to an IHistogram1D
     * with given bin edges.
     * @param binEdges The bins edges.
     * @return false If the ICloud1D has already been converted.
     *
     */
    JNIEXPORT virtual bool convert(const std::vector<double>  & binEdges);

    /**
     * Get the internal IHistogram1D in which the ICloud1D converted to.
     * @return The histogram.
     *                          or because of a convert() method invocation.
     *
     */
    JNIEXPORT virtual const AIDA::IHistogram1D & histogram() const;

    /**
     * Project the ICloud1D on an IHistogram1D.
     * @param hist The IHistogram1D to be filled.
     * @return false If the ICloud1D is already converted.
     *
     */
    JNIEXPORT virtual bool fillHistogram(AIDA::IHistogram1D & hist) const;

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
    JNIEXPORT virtual void * cast(const std::string & className) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JICLOUD1D_H */
