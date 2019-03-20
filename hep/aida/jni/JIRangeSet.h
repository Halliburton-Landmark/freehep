// -*- C++ -*-
#ifndef JAIDA_JIRANGESET_H
#define JAIDA_JIRANGESET_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <vector>

#include "AIDA/IRangeSet.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * User level interface to RangeSet.
 *
 *
 * Proposed rules for ranges:
 *
 * - By default (no arguments) RangeSet object is created with
 *   one valid range: (-infinity, +infinity).
 *
 * - size=0 means no valid ranges (isInRange(double point) will
 *   return false for any point). It also can be used to check if
 *   any range is set - RangeSet include valid interval only
 *   if size!=0.
 *
 * - RangeSet can be smart, e.g merge overlapping valid ranges.
 *   So size() does not always equal to the number of times
 *   user call include method.
 *
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIRangeSet: public JProxy, public virtual AIDA::IRangeSet {

private:
    jmethodID includeAllOCVMethod;
    jmethodID excludeODDCVMethod;
    jmethodID includeODDCVMethod;
    jmethodID upperBoundsOCADMethod;
    jmethodID isInRangeODCZMethod;
    jmethodID excludeAllOCVMethod;
    jmethodID sizeOCIMethod;
    jmethodID lowerBoundsOCADMethod;
    jmethodID plusInfMethod;
    jmethodID minusInfMethod;
    std::vector<double> lowerBoundsVector;
    std::vector<double> upperBoundsVector;

protected:
    inline JIRangeSet() { };
    inline JIRangeSet(const JIRangeSet& r):JProxy(r) { };
    inline JIRangeSet& operator=(const JIRangeSet&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIRangeSet(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIRangeSet();

    /**
     * Return array of lower Bounds for the current set of ranges
     * @return Array of lower bounds for all valid ranges
     */
    JNIEXPORT virtual const std::vector<double>  & lowerBounds();

    /**
     * Return array of upper Bounds for the current set of ranges
     * @return Array of upper bounds for all valid ranges
     */
    JNIEXPORT virtual const std::vector<double>  & upperBounds();

    /**
     * Add [xMin, xMax] interval to existing set of valid ranges
     * @param xMin - lower bound of a new valid range
     * @param xMax - upper bound of a new valid range
     */
    JNIEXPORT virtual void include(double xMin, double xMax);

    /**
     * Exclude [xMin, xMax] interval from the existing set of valid ranges
     * @param xMin - lower bound of range to be excluded
     * @param xMax - upper bound of range to be excluded
     */
    JNIEXPORT virtual void exclude(double xMin, double xMax);

    /**
     * Set full range (from MINUS_INF to PLUS_INF ).
     */
    JNIEXPORT virtual void includeAll();

    /**
     * Set empty range.
     */
    JNIEXPORT virtual void excludeAll();

    /*
     * @return Return true if the point is in range
     */
    JNIEXPORT virtual bool isInRange(double point);

    /**
     * Return current number of disjoint ranges (non-overlapping intervals).
     * Note: it is not always equal to the number of times user set the range
     * @return Number of disjoint ranges
     */
    JNIEXPORT virtual int size();

    /*
     * Define +infinity according to specific implementation
     * @return Numeric definition for +infinity
     */
    JNIEXPORT virtual double PLUS_INF();

    /*
     * Define -infinity according to specific implementation
     * @return Numeric definition for -infinity
     */
    JNIEXPORT virtual double MINUS_INF();
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIRANGESET_H */
