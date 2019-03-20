// -*- C++ -*-
#ifndef JAIDA_JICLOUD_H
#define JAIDA_JICLOUD_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/ICloud.h"
#include "JIBaseHistogram.h"

namespace JAIDA {

/**
 * User level interface to a Cloud.
 * A Cloud is an unbinned collection of points. It can be used to
 * represent scatter plots or dynamically rebinnable histograms.
 * If they number of entries in the cloud exceeds some threshold
 * they may be automatically converted to a binned histogram.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JICloud: public JIBaseHistogram, public virtual AIDA::ICloud {

private:
    jmethodID sumOfWeightsOCDMethod;
    jmethodID scaleODCVMethod;
    jmethodID isConvertedOCZMethod;
    jmethodID maxEntriesOCIMethod;
    jmethodID convertToHistogramOCVMethod;

protected:
    inline JICloud() { };
    inline JICloud(const JICloud& r):JIBaseHistogram(r) { };
    inline JICloud& operator=(const JICloud&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JICloud(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JICloud();

    /**
     * Get the sum of weights of all the entries.
     * @return The sum of the weights of all the entries.
     *
     */
    JNIEXPORT virtual double sumOfWeights() const;

    /**
     * Convert the ICloud to an IHistogram using the default number of bins.
     * @return false If the ICloud has already been converted.
     *
     */
    JNIEXPORT virtual bool convertToHistogram();

    /**
     * Check if the ICloud has been converted to an IHistogram.
     * @return <code>true</code> if it has been converted.
     *
     */
    JNIEXPORT virtual bool isConverted() const;

    /**
     * Get the number of entries after which the cloud will be converted to an IHistogram.
     * @return The number of entries.
     *
     */
    JNIEXPORT virtual int maxEntries() const;

    /**
     * Scale the weights by a given factor.
     * @param scaleFactor The scale factor.
     * @return false If a non-positive scale factor is provided.
     *
     */
    JNIEXPORT virtual bool scale(double scaleFactor);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JICLOUD_H */
