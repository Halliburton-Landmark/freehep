// -*- C++ -*-
#ifndef JAIDA_JIPROFILE_H
#define JAIDA_JIPROFILE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/IProfile.h"
#include "JIBaseHistogram.h"

namespace JAIDA {

/**
 * User level interface to a Profile histogram
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIProfile: public JIBaseHistogram, public virtual AIDA::IProfile {

private:
    jmethodID sumExtraBinHeightsOCDMethod;
    jmethodID allEntriesOCIMethod;
    jmethodID maxBinHeightOCDMethod;
    jmethodID minBinHeightOCDMethod;
    jmethodID sumBinHeightsOCDMethod;
    jmethodID extraEntriesOCIMethod;
    jmethodID sumAllBinHeightsOCDMethod;

protected:
    inline JIProfile() { };
    inline JIProfile(const JIProfile& r):JIBaseHistogram(r) { };
    inline JIProfile& operator=(const JIProfile&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIProfile(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIProfile();

    /**
     * Get the number or all the entries, both in range and
     * underflow/overflow bins of the IProfile.
     * @return The sum of all the entries.
     *
     */
    JNIEXPORT virtual int allEntries() const;

    /**
     * Get the number of entries in the underflow and overflow bins.
     * @return The numer of entries in the out-of-range bins.
     *
     */
    JNIEXPORT virtual int extraEntries() const;

    /**
     * Get the sum of in range bin heights in the IProfile.
     * @return The sum of all the in-range bins heights.
     *
     */
    JNIEXPORT virtual double sumBinHeights() const;

    /**
     * Get the sum of all the bins heights (including underflow and overflow bin).
     * @return The sum of all the bins heights.
     *
     */
    JNIEXPORT virtual double sumAllBinHeights() const;

    /**
     * Get the sum of the underflow and overflow bin height.
     * @return The sum of the out-of-range bins heights.
     *
     */
    JNIEXPORT virtual double sumExtraBinHeights() const;

    /**
     * Get the minimum height of the in-range bins.
     * @return The minimum height among the in-range bins.
     *
     */
    JNIEXPORT virtual double minBinHeight() const;

    /**
     * Get the maximum height of the in-range bins.
     * @return The maximum height among the in-range bins.
     *
     */
    JNIEXPORT virtual double maxBinHeight() const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIPROFILE_H */
