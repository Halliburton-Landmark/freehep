// -*- C++ -*-
#ifndef JAIDA_JIAXIS_H
#define JAIDA_JIAXIS_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/IAxis.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * An IAxis represents a binned histogram axis. A 1D Histogram would have
 * one Axis representing the X axis, while a 2D Histogram would have two
 * axes representing the X and Y Axis.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIAxis: public JProxy, public virtual AIDA::IAxis {

private:
    jmethodID upperEdgeOCDMethod;
    jmethodID binWidthOICDMethod;
    jmethodID coordToIndexODCIMethod;
    jmethodID binUpperEdgeOICDMethod;
    jmethodID binsOCIMethod;
    jmethodID binLowerEdgeOICDMethod;
    jmethodID lowerEdgeOCDMethod;
    jmethodID isFixedBinningOCZMethod;

protected:
    inline JIAxis() { };
    inline JIAxis(const JIAxis& r):JProxy(r) { };
    inline JIAxis& operator=(const JIAxis&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIAxis(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIAxis();

  /**
   * Check if the IAxis has fixed binning, i.e. if all the bins have the same width.
   * @return <code>true</code> if the binning is fixed, <code>false</code> otherwise.
   *
   */
    JNIEXPORT virtual bool isFixedBinning() const;

  /**
   * Get the lower edge of the IAxis.
   * @return The IAxis's lower edge.
   *
   */
    JNIEXPORT virtual double lowerEdge() const;

  /**
   * Get the upper edge of the IAxis.
   * @return The IAxis's upper edge.
   *
   */
    JNIEXPORT virtual double upperEdge() const;

  /**
   * The number of bins (excluding underflow and overflow) on the IAxis.
   * @return The IAxis's number of bins.
   *
   */
    JNIEXPORT virtual int bins() const;

  /**
   * Get the lower edge of the specified bin.
   * @param index The bin number: 0 to bins()-1 for the in-range bins or OVERFLOW or UNDERFLOW.
   * @return      The lower edge of the corresponding bin; for the underflow bin this is <tt>Double.NEGATIVE_INFINITY</tt>.
   *
   */
    JNIEXPORT virtual double binLowerEdge(int index) const;

  /**
   * Get the upper edge of the specified bin.
   * @param index The bin number: 0 to bins()-1 for the in-range bins or OVERFLOW or UNDERFLOW.
   * @return      The upper edge of the corresponding bin; for the overflow bin this is <tt>Double.POSITIVE_INFINITY</tt>.
   *
   */
    JNIEXPORT virtual double binUpperEdge(int index) const;

  /**
   * Get the width of the specified bin.
   * @param index The bin number: 0 to bins()-1) for the in-range bins or OVERFLOW or UNDERFLOW.
   * @return      The width of the corresponding bin.
   *
   */
    JNIEXPORT virtual double binWidth(int index) const;

  /**
   * Convert a coordinate on the axis to a bin number.
   * If the coordinate is less than the lowerEdge UNDERFLOW is returned; if the coordinate is greater or
   * equal to the upperEdge OVERFLOW is returned.
   * @param coord The coordinate to be converted.
   * @return      The corresponding bin number.
   *
   */
    JNIEXPORT virtual int coordToIndex(double coord) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIAXIS_H */
