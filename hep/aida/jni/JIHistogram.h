// -*- C++ -*-
#ifndef JAIDA_JIHISTOGRAM_H
#define JAIDA_JIHISTOGRAM_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/IHistogram.h"
#include "JIBaseHistogram.h"

namespace JAIDA {

/**
 * User level interface to Histogram.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIHistogram: public JIBaseHistogram, public virtual AIDA::IHistogram {

private:
    jmethodID equivalentBinEntriesOCDMethod;
    jmethodID sumExtraBinHeightsOCDMethod;
    jmethodID allEntriesOCIMethod;
    jmethodID maxBinHeightOCDMethod;
    jmethodID minBinHeightOCDMethod;
    jmethodID sumBinHeightsOCDMethod;
    jmethodID extraEntriesOCIMethod;
    jmethodID scaleODCVMethod;
    jmethodID sumAllBinHeightsOCDMethod;

protected:
    inline JIHistogram() { };
    inline JIHistogram(const JIHistogram& r):JIBaseHistogram(r) { };
    inline JIHistogram& operator=(const JIHistogram&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIHistogram(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIHistogram();

    /**
     * Sum of the entries in all the IHistogram's bins,
     * i.e in-range bins, UNDERFLOW and OVERFLOW.
     * This is equivalent to the number of times the
     * method fill was invoked.
     * @return The sum of all the entries.
     *
     */
    JNIEXPORT virtual int allEntries() const;

    /**
     * Number of entries in the UNDERFLOW and OVERFLOW bins.
     * @return The number of entries outside the range of the IHistogram.
     *
     */
    JNIEXPORT virtual int extraEntries() const;

    /**
     * Number of equivalent entries, i.e. <tt>SUM[ weight ] ^ 2 / SUM[ weight^2 ]</tt>
     * @return The number of equivalent entries.
     *
     */
    JNIEXPORT virtual double equivalentBinEntries() const;

    /**
     * Sum of in-range bin heights in the IHistogram,
     * UNDERFLOW and OVERFLOW bins are excluded.
     * @return The sum of the in-range bins heights.
     *
     */
    JNIEXPORT virtual double sumBinHeights() const;

    /**
     * Sum of the heights of all the IHistogram's bins,
     * i.e in-range bins, UNDERFLOW and OVERFLOW.
     * @return The sum of all the bins heights.
     *
     */
    JNIEXPORT virtual double sumAllBinHeights() const;

    /**
     * Sum of heights in the UNDERFLOW and OVERFLOW bins.
     * @return The sum of the heights of the out-of-range bins.
     *
     */
    JNIEXPORT virtual double sumExtraBinHeights() const;

    /**
     * Minimum height of the in-range bins,
     * i.e. not considering the UNDERFLOW and OVERFLOW bins.
     * @return The minimum height among the in-range bins.
     *
     */
    JNIEXPORT virtual double minBinHeight() const;

    /**
     * Maximum height of the in-range bins,
     * i.e. not considering the UNDERFLOW and OVERFLOW bins.
     * @return The maximum height among the in-range bins.
     *
     */
    JNIEXPORT virtual double maxBinHeight() const;

    /**
     * Scale the weights and the errors of all the IHistogram's bins
     * (in-range and out-of-range ones) by a given scale factor.
     * @param scaleFactor The scale factor.
     * @return false If the scale factor is negative.
     *
     */
    JNIEXPORT virtual bool scale(double scaleFactor);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIHISTOGRAM_H */
