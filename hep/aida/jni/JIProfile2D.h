// -*- C++ -*-
#ifndef JAIDA_JIPROFILE2D_H
#define JAIDA_JIPROFILE2D_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/IAxis.h"
#include "AIDA/IProfile2D.h"
#include "JIProfile.h"
#include "JIManagedObject.h"

namespace JAIDA {

/**
 * User level interface to a 2-dimensional profile histogram
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIProfile2D: public JIProfile, public JIManagedObject, public virtual AIDA::IProfile2D {

private:
    jmethodID binMeanYOIICDMethod;
    jmethodID binErrorOIICDMethod;
    jmethodID binHeightXOICDMethod;
    jmethodID binHeightYOICDMethod;
    jmethodID binEntriesXOICIMethod;
    jmethodID meanXOCDMethod;
    jmethodID binMeanXOIICDMethod;
    jmethodID binRmsOIICDMethod;
    jmethodID meanYOCDMethod;
    jmethodID rmsYOCDMethod;
    jmethodID fillODDDDCVMethod;
    jmethodID coordToIndexYODCIMethod;
    jmethodID rmsXOCDMethod;
    jmethodID binEntriesYOICIMethod;
    jmethodID addOLhep_aida_IProfile2DECVMethod;
    jmethodID yAxisOCLhep_aida_IAxisEMethod;
    jmethodID coordToIndexXODCIMethod;
    jmethodID xAxisOCLhep_aida_IAxisEMethod;
    jmethodID binEntriesOIICIMethod;
    jmethodID binHeightOIICDMethod;
    mutable AIDA::IAxis* iXaxis;
    mutable AIDA::IAxis* iYaxis;

protected:
    inline JIProfile2D() { };
    inline JIProfile2D(const JIProfile2D& r):JIProfile(r), JIManagedObject(r) { };
    inline JIProfile2D& operator=(const JIProfile2D&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIProfile2D(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIProfile2D();

    /**
     * Fill the IProfile2D.
     *
     */
    JNIEXPORT virtual bool fill(double x, double y, double z, double weight);

    /**
     * The weighted mean along x of a given bin.
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return       The mean of the corresponding bin along the x axis.
     *
     */
    JNIEXPORT virtual double binMeanX(int indexX, int indexY) const;

    /**
     * The weighted mean along y of a given bin.
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return       The mean of the corresponding bin along the x axis.
     *
     */
    JNIEXPORT virtual double binMeanY(int indexX, int indexY) const;

    /**
     * The number of entries (ie the number of times fill was called for this bin).
     * @param indexX the x bin number (0...Nx-1) or OVERFLOW or UNDERFLOW.
     * @param indexY the y bin number (0...Ny-1) or OVERFLOW or UNDERFLOW.
     *
     */
    JNIEXPORT virtual int binEntries(int indexX, int indexY) const;

    /**
     * Equivalent to <tt>projectionX().binEntries(indexX)</tt>.
     *
     */
    JNIEXPORT virtual int binEntriesX(int indexX) const;

    /**
     * Equivalent to <tt>projectionY().binEntries(indexY)</tt>.
     *
     */
    JNIEXPORT virtual int binEntriesY(int indexY) const;

    /**
     * Total height of the corresponding bin (ie the sum of the weights in this bin).
     * @param indexX the x bin number (0...Nx-1) or OVERFLOW or UNDERFLOW.
     * @param indexY the y bin number (0...Ny-1) or OVERFLOW or UNDERFLOW.
     *
     */
    JNIEXPORT virtual double binHeight(int indexX, int indexY) const;

    /**
     * Equivalent to <tt>projectionX().binHeight(indexX)</tt>.
     *
     */
    JNIEXPORT virtual double binHeightX(int indexX) const;

    /**
     * Equivalent to <tt>projectionY().binHeight(indexY)</tt>.
     *
     */
    JNIEXPORT virtual double binHeightY(int indexY) const;

    /**
     * The error on this bin.
     * @param indexX the x bin number (0...Nx-1) or OVERFLOW or UNDERFLOW.
     * @param indexY the y bin number (0...Ny-1) or OVERFLOW or UNDERFLOW.
     *
     */
    JNIEXPORT virtual double binError(int indexX, int indexY) const;

    /**
     * The spread (RMS) of this bin.
     * @param indexX the x bin number (0...Nx-1) or OVERFLOW or UNDERFLOW.
     * @param indexY the y bin number (0...Ny-1) or OVERFLOW or UNDERFLOW.
     *
     */
    JNIEXPORT virtual double binRms(int indexX, int indexY) const;

    /**
     * Returns the mean of the profile, as calculated on filling-time projected on the X axis.
     *
     */
    JNIEXPORT virtual double meanX() const;

    /**
     * Returns the mean of the profile, as calculated on filling-time projected on the Y axis.
     *
     */
    JNIEXPORT virtual double meanY() const;

    /**
     * Returns the rms of the profile as calculated on filling-time projected on the X axis.
     *
     */
    JNIEXPORT virtual double rmsX() const;

    /**
     * Returns the rms of the profile as calculated on filling-time projected on the Y axis.
     *
     */
    JNIEXPORT virtual double rmsY() const;

    /**
     * Return the X axis.
     *
     */
    JNIEXPORT virtual const AIDA::IAxis & xAxis() const;

    /**
     * Return the Y axis.
     *
     */
    JNIEXPORT virtual const AIDA::IAxis & yAxis() const;

    /**
     * Convenience method, equivalent to <tt>xAxis().coordToIndex(coord)</tt>.
     * @see IAxis#coordToIndex(double)
     *
     */
    JNIEXPORT virtual int coordToIndexX(double coordX) const;

    /**
     * Convenience method, equivalent to <tt>yAxis().coordToIndex(coord)</tt>.
     * @see IAxis#coordToIndex(double)
     *
     */
    JNIEXPORT virtual int coordToIndexY(double coordY) const;

    /**
     * Modifies this profile by adding the contents of profile to it.
     *
     * @param profile The IProfile2D to be added to this IProfile2D
     * @return false if the profile binnings are incompatible
     *
     */
    JNIEXPORT virtual bool add(const AIDA::IProfile2D & h);

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
    JNIEXPORT virtual void * cast(const std::string & className) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIPROFILE2D_H */
