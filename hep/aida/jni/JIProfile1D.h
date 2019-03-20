// -*- C++ -*-
#ifndef JAIDA_JIPROFILE1D_H
#define JAIDA_JIPROFILE1D_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/IAxis.h"
#include "AIDA/IProfile1D.h"
#include "JIProfile.h"
#include "JIManagedObject.h"

namespace JAIDA {

/**
 * User level interface to a 1-dimensional profile histogram
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIProfile1D: public JIProfile, public JIManagedObject, public virtual AIDA::IProfile1D {

private:
    jmethodID binHeightOICDMethod;
    jmethodID coordToIndexODCIMethod;
    jmethodID rmsOCDMethod;
    jmethodID binRmsOICDMethod;
    jmethodID meanOCDMethod;
    jmethodID axisOCLhep_aida_IAxisEMethod;
    jmethodID binErrorOICDMethod;
    jmethodID fillODDDCVMethod;
    jmethodID addOLhep_aida_IProfile1DECVMethod;
    jmethodID binEntriesOICIMethod;
    jmethodID binMeanOICDMethod;
    mutable AIDA::IAxis* iXaxis;

protected:
    inline JIProfile1D() { };
    inline JIProfile1D(const JIProfile1D& r):JIProfile(r), JIManagedObject(r) { };
    inline JIProfile1D& operator=(const JIProfile1D&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIProfile1D(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIProfile1D();

    /**
     * Fill the IProfile1D.
     *
     */
    JNIEXPORT virtual bool fill(double x, double y, double weight);

    /**
     * The weighted mean of the corresponding bin.
     * @param index the bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The mean of the corresponding bin along the x axis.
     *
     */
    JNIEXPORT virtual double binMean(int index) const;

    /**
     * Number of entries in the corresponding bin (ie the number of times fill was called for this bin).
     * @param index the bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     */
    JNIEXPORT virtual int binEntries(int index) const;

    /**
     * Total height of the corresponding bin (ie the sum of the weights in this bin).
     * @param index the bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     */
    JNIEXPORT virtual double binHeight(int index) const;

    /**
     * The error on this bin.
     * @param index the bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     */
    JNIEXPORT virtual double binError(int index) const;

    /**
     * The spread (RMS) of a bin.
     * @param index the bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     *
     */
    JNIEXPORT virtual double binRms(int index) const;

    /**
     * Returns the mean of the whole profile as calculated on filling-time.
     */
    JNIEXPORT virtual double mean() const;

    /**
     * Returns the rms of the whole profile as calculated on filling-time.
     */
    JNIEXPORT virtual double rms() const;

    /**
     * Returns the X axis.
     */
    JNIEXPORT virtual const AIDA::IAxis & axis() const;

    /**
     * Convenience method, equivalent to <tt>axis().coordToIndex(coord)</tt>.
     * @see IAxis#coordToIndex(double)
     */
    JNIEXPORT virtual int coordToIndex(double coord) const;

    /**
     * Modifies this IProfile1D by adding the contents of profile to it.
     *
     * @param profile The IProfile1D to be added to this IProfile1D
     * @return false if profile binnings are incompatible
     */
    JNIEXPORT virtual bool add(const AIDA::IProfile1D & profile);

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
    JNIEXPORT virtual void * cast(const std::string & className) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIPROFILE1D_H */
