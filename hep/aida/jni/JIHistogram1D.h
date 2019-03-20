// -*- C++ -*-
#ifndef JAIDA_JIHISTOGRAM1D_H
#define JAIDA_JIHISTOGRAM1D_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/IAxis.h"
#include "AIDA/IHistogram1D.h"
#include "JIHistogram.h"
#include "JIManagedObject.h"

namespace JAIDA {

/**
 * User level interface to 1D Histogram.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIHistogram1D: public JIHistogram, public JIManagedObject, public virtual AIDA::IHistogram1D {

private:
    jmethodID binHeightOICDMethod;
    jmethodID coordToIndexODCIMethod;
    jmethodID rmsOCDMethod;
    jmethodID meanOCDMethod;
    jmethodID axisOCLhep_aida_IAxisEMethod;
    jmethodID binErrorOICDMethod;
    jmethodID binEntriesOICIMethod;
    jmethodID binMeanOICDMethod;
    jmethodID addOLhep_aida_IHistogram1DECVMethod;
    jmethodID fillODDCVMethod;
    mutable AIDA::IAxis* iXaxis;

protected:
    inline JIHistogram1D() { };
    inline JIHistogram1D(const JIHistogram1D& r):JIHistogram(r),JIManagedObject(r) { };
    inline JIHistogram1D& operator=(const JIHistogram1D&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIHistogram1D(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIHistogram1D();

    /**
     * Fill the IHistogram1D with a value and the
     * corresponding weight.
     * @param x      The value to be filled in.
     * @param weight The corresponding weight (by default 1).
     * @return false If the weight is <0 or >1 (?).
     *
     */
    JNIEXPORT virtual bool fill(double x, double weight);

    /**
     * The weighted mean of a bin.
     * @param index The bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The mean of the corresponding bin.
     *
     */
    JNIEXPORT virtual double binMean(int index) const;

    /**
     * Number of entries in the corresponding bin (ie the number of times fill was called for this bin).
     * @param index The bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The number of entries in the corresponding bin.
     *
     */
    JNIEXPORT virtual int binEntries(int index) const;

    /**
     * Total height of the corresponding bin (ie the sum of the weights in this bin).
     * @param index The bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The height of the corresponding bin.
     *
     */
    JNIEXPORT virtual double binHeight(int index) const;

    /**
     * The error of a given bin.
     * @param index The bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The error on the corresponding bin.
     *
     */
    JNIEXPORT virtual double binError(int index) const;

    /**
     * The mean of the whole IHistogram1D.
     * @return The mean of the IHistogram1D.
     *
     */
    JNIEXPORT virtual double mean() const;

    /**
     * The RMS of the whole IHistogram1D.
     * @return The RMS if the IHistogram1D.
     *
     */
    JNIEXPORT virtual double rms() const;

    /**
     * Get the x axis of the IHistogram1D.
     * @return The x coordinate IAxis.
     *
     */
    JNIEXPORT virtual const AIDA::IAxis & axis() const;

    /**
     * Get the bin number corresponding to a given coordinate along the x axis.
     * This is a convenience method, equivalent to <tt>axis().coordToIndex(coord)</tt>.
     * @see IAxis#coordToIndex(double)
     * @param coord The coordinalte along the x axis.
     * @return      The corresponding bin number.
     *
     */
    JNIEXPORT virtual int coordToIndex(double coord) const;

    /**
     * Add to this IHistogram1D the contents of another IHistogram1D.
     * @param hist The IHistogram1D to be added to this IHistogram1D.
     * @return false If the IHistogram1Ds binnings are incompatible.
     *
     */
    JNIEXPORT virtual bool add(const AIDA::IHistogram1D & hist);

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
    JNIEXPORT virtual void * cast(const std::string & className) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIHISTOGRAM1D_H */
