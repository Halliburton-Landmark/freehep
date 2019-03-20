// -*- C++ -*-
#ifndef JAIDA_JIHISTOGRAM2D_H
#define JAIDA_JIHISTOGRAM2D_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/IAxis.h"
#include "AIDA/IHistogram2D.h"
#include "JIHistogram.h"
#include "JIManagedObject.h"

namespace JAIDA {

/**
 * User level interface to 2D Histogram.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIHistogram2D: public JIHistogram, public JIManagedObject, public virtual AIDA::IHistogram2D {

private:
    jmethodID binMeanYOIICDMethod;
    jmethodID binErrorOIICDMethod;
    jmethodID binHeightXOICDMethod;
    jmethodID binHeightYOICDMethod;
    jmethodID binEntriesXOICIMethod;
    jmethodID meanXOCDMethod;
    jmethodID fillODDDCVMethod;
    jmethodID binMeanXOIICDMethod;
    jmethodID meanYOCDMethod;
    jmethodID rmsYOCDMethod;
    jmethodID addOLhep_aida_IHistogram2DECVMethod;
    jmethodID coordToIndexYODCIMethod;
    jmethodID rmsXOCDMethod;
    jmethodID binEntriesYOICIMethod;
    jmethodID yAxisOCLhep_aida_IAxisEMethod;
    jmethodID xAxisOCLhep_aida_IAxisEMethod;
    jmethodID coordToIndexXODCIMethod;
    jmethodID binEntriesOIICIMethod;
    jmethodID binHeightOIICDMethod;
    mutable AIDA::IAxis* iXaxis;
    mutable AIDA::IAxis* iYaxis;

protected:
    inline JIHistogram2D() { };
    inline JIHistogram2D(const JIHistogram2D& r):JIHistogram(r),JIManagedObject(r) { };
    inline JIHistogram2D& operator=(const JIHistogram2D&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIHistogram2D(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIHistogram2D();

    /**
     * Fill the IHistogram2D with a couple of values and the
     * corresponding weight.
     * @param x      The x value to be filled in.
     * @param y      The y value to be filled in.
     * @param weight The corresponding weight (by default 1).
     * @return false If the weight is <0 or >1 (?).
     *
     */
    JNIEXPORT virtual bool fill(double x, double y, double weight);

    /**
     * The weighted mean along the x axis of a given bin.
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The mean of the corresponding bin along the x axis.
     *
     */
    JNIEXPORT virtual double binMeanX(int indexX, int indexY) const;

    /**
     * The weighted mean along the y axis of a given bin.
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The mean of the corresponding bin along the y axis.
     *
     */
    JNIEXPORT virtual double binMeanY(int indexX, int indexY) const;

    /**
     * Number of entries in the corresponding bin (ie the number of times fill was called for this bin).
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return       The number of entries in the corresponding bin.
     *
     */
    JNIEXPORT virtual int binEntries(int indexX, int indexY) const;

    /**
     * Sum of all the entries of the bins along a given x bin.
     * This is equivalent to <tt>projectionX().binEntries(index)</tt>.
     * @param index The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The number of entries in the corresponding set of bins.
     *
     */
    JNIEXPORT virtual int binEntriesX(int index) const;

    /**
     * Sum of all the entries of the bins along a given y bin.
     * This is equivalent to <tt>projectionY().binEntries(index)</tt>.
     * @param index The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The number of entries in the corresponding set of bins.
     *
     */
    JNIEXPORT virtual int binEntriesY(int index) const;

    /**
     * Total height of a give bin (ie the sum of the weights in this bin).
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return       The height of the corresponding bin.
     *
     */
    JNIEXPORT virtual double binHeight(int indexX, int indexY) const;

    /**
     * Sum of all the heights of the bins along a given x bin.
     * This is equivalent to <tt>projectionX().binHeight(index)</tt>.
     * @param index The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The sum of the heights in the corresponding set of bins.
     *
     */
    JNIEXPORT virtual double binHeightX(int index) const;

    /**
     * Sum of all the heights of the bins along a given y bin.
     * This is equivalent to <tt>projectionY().binHeight(index)</tt>.
     * @param index The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return      The sum of the heights in the corresponding set of bins.
     *
     */
    JNIEXPORT virtual double binHeightY(int index) const;

    /**
     * The error of a given bin.
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return       The error on the corresponding bin.
     *
     */
    JNIEXPORT virtual double binError(int indexX, int indexY) const;

    /**
     * The mean of the IHistogram2D along the x axis.
     * @return The mean of the IHistogram2D along the x axis.
     *
     */
    JNIEXPORT virtual double meanX() const;

    /**
     * The mean of the IHistogram2D along the y axis.
     * @return The mean of the IHistogram2D along the y axis.
     *
     */
    JNIEXPORT virtual double meanY() const;

    /**
     * The RMS of the IHistogram2D along the x axis.
     * @return The RMS if the IHistogram2D along the x axis.
     *
     */
    JNIEXPORT virtual double rmsX() const;

    /**
     * The RMS of the IHistogram2D along the y axis.
     * @return The RMS if the IHistogram2D along the y axis.
     *
     */
    JNIEXPORT virtual double rmsY() const;

    /**
     * Get the x axis of the IHistogram2D.
     * @return The x coordinate IAxis.
     *
     */
    JNIEXPORT virtual const AIDA::IAxis & xAxis() const;

    /**
     * Get the y axis of the IHistogram2D.
     * @return The y coordinate IAxis.
     *
     */
    JNIEXPORT virtual const AIDA::IAxis & yAxis() const;

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
     * Add to this IHistogram2D the contents of another IHistogram2D.
     * @param hist The IHistogram2D to be added to this IHistogram2D.
     * @return false If the IHistogram2Ds binnings are incompatible.
     *
     */
    JNIEXPORT virtual bool add(const AIDA::IHistogram2D & hist);

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
    JNIEXPORT virtual void * cast(const std::string & className) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIHISTOGRAM2D_H */
