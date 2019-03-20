// -*- C++ -*-
#ifndef JAIDA_JIHISTOGRAM3D_H
#define JAIDA_JIHISTOGRAM3D_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/IAxis.h"
#include "AIDA/IHistogram3D.h"
#include "JIHistogram.h"
#include "JIManagedObject.h"

namespace JAIDA {

/**
 * User level interface to 3D Histogram.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIHistogram3D: public JIHistogram, public JIManagedObject, public  virtual AIDA::IHistogram3D {

private:
    jmethodID rmsZOCDMethod;
    jmethodID binHeightYOICDMethod;
    jmethodID meanXOCDMethod;
    jmethodID binHeightOIIICDMethod;
    jmethodID meanYOCDMethod;
    jmethodID fillODDDDCVMethod;
    jmethodID binEntriesOIIICIMethod;
    jmethodID addOLhep_aida_IHistogram3DECVMethod;
    jmethodID rmsXOCDMethod;
    jmethodID zAxisOCLhep_aida_IAxisEMethod;
    jmethodID binHeightZOICDMethod;
    jmethodID yAxisOCLhep_aida_IAxisEMethod;
    jmethodID binEntriesZOICIMethod;
    jmethodID xAxisOCLhep_aida_IAxisEMethod;
    jmethodID binErrorOIIICDMethod;
    jmethodID binHeightXOICDMethod;
    jmethodID binEntriesXOICIMethod;
    jmethodID rmsYOCDMethod;
    jmethodID binMeanZOIIICDMethod;
    jmethodID coordToIndexYODCIMethod;
    jmethodID coordToIndexZODCIMethod;
    jmethodID meanZOCDMethod;
    jmethodID binEntriesYOICIMethod;
    jmethodID binMeanXOIIICDMethod;
    jmethodID coordToIndexXODCIMethod;
    jmethodID binMeanYOIIICDMethod;
    mutable AIDA::IAxis* iXaxis;
    mutable AIDA::IAxis* iYaxis;
    mutable AIDA::IAxis* iZaxis;

protected:
    inline JIHistogram3D() { };
    inline JIHistogram3D(const JIHistogram3D& r):JIHistogram(r),JIManagedObject(r) { };
    inline JIHistogram3D& operator=(const JIHistogram3D&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIHistogram3D(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIHistogram3D();

    /**
     * Fill the IHistogram3D with a triplet of values and the
     * corresponding weight.
     * @param x      The x value to be filled in.
     * @param y      The y value to be filled in.
     * @param z      The z value to be filled in.
     * @param weight The corresponding weight (by default 1).
     * @return false If the weight is <0 or >1 (?).
     *
     */
    JNIEXPORT virtual bool fill(double x, double y, double z, double weight);

    /**
     * The weighted mean along the x axis of a given bin.
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexZ The z bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The mean of the corresponding bin along the x axis.
     *
     */
    JNIEXPORT virtual double binMeanX(int indexX, int indexY, int indexZ) const;

    /**
     * The weighted mean the y axis of a given bin.
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexZ The z bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The mean of the corresponding bin along the y axis.
     *
     */
    JNIEXPORT virtual double binMeanY(int indexX, int indexY, int indexZ) const;

    /**
     * The weighted mean the z axis of a given bin.
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexZ The z bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The mean of the corresponding bin along the z axis.
     *
     */
    JNIEXPORT virtual double binMeanZ(int indexX, int indexY, int indexZ) const;

    /**
     * Number of entries in the corresponding bin (ie the number of times fill was called for this bin).
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexZ The z bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return       The number of entries in the corresponding bin.
     *
     */
    JNIEXPORT virtual int binEntries(int indexX, int indexY, int indexZ) const;

    /**
     * Sum of all the entries of the bins along a given x bin.
     * This is equivalent to <tt>projectionXY().binEntriesX(index)</tt>.
     * @param index The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The number of entries in the corresponding set of bins.
     *
     */
    JNIEXPORT virtual int binEntriesX(int index) const;

    /**
     * Sum of all the entries of the bins along a given y bin.
     * This is equivalent to <tt>projectionXY().binEntriesY(index)</tt>.
     * @param index The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The number of entries in the corresponding set of bins.
     *
     */
    JNIEXPORT virtual int binEntriesY(int index) const;

    /**
     * Sum of all the entries of the bins along a given z bin.
     * This is equivalent to <tt>projectionXZ().binEntriesZ(index)</tt>.
     * @param index The z bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The number of entries in the corresponding set of bins.
     *
     */
    JNIEXPORT virtual int binEntriesZ(int index) const;

    /**
     * Total height of a give bin (ie the sum of the weights in this bin).
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexZ The z bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return       The height of the corresponding bin.
     *
     */
    JNIEXPORT virtual double binHeight(int indexX, int indexY, int indexZ) const;

    /**
     * Sum of all the heights of the bins along a given x bin.
     * This is equivalent to <tt>projectionXY().binHeightX(index)</tt>.
     * @param index The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The sum of the heights in the corresponding set of bins.
     *
     */
    JNIEXPORT virtual double binHeightX(int index) const;

    /**
     * Sum of all the heights of the bins along a given y bin.
     * This is equivalent to <tt>projectionXY().binHeightY(index)</tt>.
     * @param index The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The sum of the heights in the corresponding set of bins.
     *
     */
    JNIEXPORT virtual double binHeightY(int index) const;

    /**
     * Sum of all the heights of the bins along a given z bin.
     * This is equivalent to <tt>projectionXZ().binHeightZ(index)</tt>.
     * @param index The z bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The sum of the heights in the corresponding set of bins.
     *
     */
    JNIEXPORT virtual double binHeightZ(int index) const;

    /**
     * The error of a given bin.
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexZ The z bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return       The error on the corresponding bin.
     *
     */
    JNIEXPORT virtual double binError(int indexX, int indexY, int indexZ) const;

    /**
     * The mean of the IHistogram3D along the x axis.
     * @return The mean of the IHistogram3D along the x axis.
     *
     */
    JNIEXPORT virtual double meanX() const;

    /**
     * The mean of the IHistogram3D along the y axis.
     * @return The mean of the IHistogram3D along the y axis.
     *
     */
    JNIEXPORT virtual double meanY() const;

    /**
     * The mean of the IHistogram3D along the z axis.
     * @return The mean of the IHistogram3D along the z axis.
     *
     */
    JNIEXPORT virtual double meanZ() const;

    /**
     * The RMS of the IHistogram3D along the x axis.
     * @return The RMS if the IHistogram3D along the x axis.
     *
     */
    JNIEXPORT virtual double rmsX() const;

    /**
     * The RMS of the IHistogram3D along the y axis.
     * @return The RMS if the IHistogram3D along the y axis.
     *
     */
    JNIEXPORT virtual double rmsY() const;

    /**
     * The RMS of the IHistogram3D along the z axis.
     * @return The RMS if the IHistogram3D along the z axis.
     *
     */
    JNIEXPORT virtual double rmsZ() const;

    /**
     * Get the x axis of the IHistogram3D.
     * @return The x coordinate IAxis.
     *
     */
    JNIEXPORT virtual const AIDA::IAxis & xAxis() const;

    /**
     * Get the y axis of the IHistogram3D.
     * @return The y coordinate IAxis.
     *
     */
    JNIEXPORT virtual const AIDA::IAxis & yAxis() const;

    /**
     * Get the z axis of the IHistogram3D.
     * @return The z coordinate IAxis.
     *
     */
    JNIEXPORT virtual const AIDA::IAxis & zAxis() const;

    /**
     * Get the bin number corresponding to a given coordinate along the x axis.
     * This is a convenience method, equivalent to <tt>xAxis().coordToIndex(coord)</tt>.
     * @see IAxis#coordToIndex(double)
     * @param coord The coordinalte along the x axis.
     * @return      The corresponding bin number.
     *
     */
    JNIEXPORT virtual int coordToIndexX(double coord) const;

    /**
     * Get the bin number corresponding to a given coordinate along the y axis.
     * This is a convenience method, equivalent to <tt>yAxis().coordToIndex(coord)</tt>.
     * @see IAxis#coordToIndex(double)
     * @param coord The coordinalte along the y axis.
     * @return      The corresponding bin number.
     *
     */
    JNIEXPORT virtual int coordToIndexY(double coord) const;

    /**
     * Get the bin number corresponding to a given coordinate along the z axis.
     * This is a convenience method, equivalent to <tt>zAxis().coordToIndex(coord)</tt>.
     * @see IAxis#coordToIndex(double)
     * @param coord The coordinalte along the z axis.
     * @return      The corresponding bin number.
     *
     */
    JNIEXPORT virtual int coordToIndexZ(double coord) const;

    /**
     * Add to this IHistogram3D the contents of another IHistogram3D.
     * @param hist The IHistogram3D to be added to this IHistogram3D.
     * @return false If the IHistogram3Ds binnings are incompatible.
     *
     */
    JNIEXPORT virtual bool add(const AIDA::IHistogram3D & hist);

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
    JNIEXPORT virtual void * cast(const std::string & className) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIHISTOGRAM3D_H */
