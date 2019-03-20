// -*- C++ -*-
#ifndef JAIDA_JICLOUD2D_H
#define JAIDA_JICLOUD2D_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <vector>

#include "AIDA/ICloud2D.h"
#include "AIDA/IHistogram2D.h"
#include "JICloud.h"
#include "JIManagedObject.h"

namespace JAIDA {

/**
 * User level interface to a 2D Cloud.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JICloud2D: public JICloud, public JIManagedObject, public virtual AIDA::ICloud2D {

private:
    jmethodID convertOADADCVMethod;
    jmethodID lowerEdgeYOCDMethod;
    jmethodID rmsXOCDMethod;
    jmethodID upperEdgeXOCDMethod;
    jmethodID histogramOCLhep_aida_IHistogram2DEMethod;
    jmethodID meanXOCDMethod;
    jmethodID convertOIDDIDDCVMethod;
    jmethodID fillODDDCVMethod;
    jmethodID valueXOICDMethod;
    jmethodID rmsYOCDMethod;
    jmethodID meanYOCDMethod;
    jmethodID weightOICDMethod;
    jmethodID valueYOICDMethod;
    jmethodID upperEdgeYOCDMethod;
    jmethodID lowerEdgeXOCDMethod;
    jmethodID fillHistogramOLhep_aida_IHistogram2DECVMethod;

protected:
    inline JICloud2D() { };
    inline JICloud2D(const JICloud2D& r):JICloud(r),JIManagedObject(r) { };
    inline JICloud2D& operator=(const JICloud2D&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JICloud2D(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JICloud2D();

    /**
     * Fill the ICloud2D with a couple of values and a corresponding weight.
     * @param x      The x value.
     * @param y      The y value.
     * @param weight The corresponding weight. By default it is 1.
     * @return false If the ICloud2D is full, if the weight's value is
     *                                  is not between 0 and 1.
     *
     */
    JNIEXPORT virtual bool fill(double x, double y, double weight);

    /**
     * Get the lower edge of the ICloud2D along the x axis.
     * @return The lower edge along the x axis.
     *
     */
    JNIEXPORT virtual double lowerEdgeX() const;

    /**
     * Get the lower edge of the ICloud2D along the y axis.
     * @return The lower edge along the y axis.
     *
     */
    JNIEXPORT virtual double lowerEdgeY() const;

    /**
     * Get the upper edge of the ICloud2D along the x axis.
     * @return The upper edge along the x axis.
     *
     */
    JNIEXPORT virtual double upperEdgeX() const;

    /**
     * Get the upper edge of the ICloud2D along the y axis.
     * @return The upper edge along the y axis.
     *
     */
    JNIEXPORT virtual double upperEdgeY() const;

    /**
     * Get the x value corresponding to a given entry.
     * @param index The entry's index.
     * @return      The x value of the index-th entry.
     *              If the ICloud2D has already been converted, 0 is returned.
     *
     */










    JNIEXPORT virtual double valueX(int index) const;

    /**
     * Get the y value corresponding to a given entry.
     * @param index The entry's index.
     * @return      The y value of the index-th entry.
     *              If the ICloud2D has already been converted, 0 is returned.
     *
     */










    JNIEXPORT virtual double valueY(int index) const;

    /**
     * Get the weight corresponding to a given entry.
     * @param index The entry's index.
     * @return      The weight of the index-th entry.
     *              If the ICloud2D has already been converted, 0 is returned.
     *
     */










    JNIEXPORT virtual double weight(int index) const;

    /**
     * Get the mean of the ICloud2D along the x axis.
     * @return The mean along the x axis.
     *
     */
    JNIEXPORT virtual double meanX() const;

    /**
     * Get the mean of the ICloud2D along the y axis.
     * @return The mean along the y axis.
     *
     */
    JNIEXPORT virtual double meanY() const;

    /**
     * Get the RMS of the ICloud2D along the x axis.
     * @return The RMS along the x axis.
     *
     */
    JNIEXPORT virtual double rmsX() const;

    /**
     * Get the RMS of the ICloud2D along the y axis.
     * @return The RMS along the y axis.
     *
     */
    JNIEXPORT virtual double rmsY() const;

    /**
     * Convert internally the ICloud2D to an IHistogram2D
     * with given number of bins, upper edge and lower edge.
     * @param nBinsX     The number of bins of the x axis.
     * @param lowerEdgeX The lower edge of bins of the x axis.
     * @param upperEdgeX The upper edge of bins of the x axis.
     * @param nBinsY     The number of bins of the y axis.
     * @param lowerEdgeY The lower edge of bins of the y axis.
     * @param upperEdgeY The upper edge of bins of the y axis.
     * @return false If the ICloud2D has already been converted.
     *
     */
    JNIEXPORT virtual bool convert(int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY);

    /**
     * Convert internally the ICloud2D to an IHistogram2D
     * with given bin edges.
     * @param binEdgesX The bins edges of the x axis.
     * @param binEdgesY The bins edges of the y axis.
     * @return false If the ICloud2D has already been converted.
     *
     */
    JNIEXPORT virtual bool convert(const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY);

    /**
     * Get the internal IHistogram2D in which the ICloud2D converted to.
     * @return The histogram.
     *                          or because of a convert() method invocation.
     *
     */
    JNIEXPORT virtual const AIDA::IHistogram2D & histogram() const;

    /**
     * Project the ICloud2D on an IHistogram2D.
     * @param hist The IHistogram2D to be filled.
     * @return false If the ICloud2D is already converted.
     *
     */
    JNIEXPORT virtual bool fillHistogram(AIDA::IHistogram2D & hist) const;

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
    JNIEXPORT virtual void * cast(const std::string & className) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JICLOUD2D_H */
