// -*- C++ -*-
#ifndef JAIDA_JICLOUD3D_H
#define JAIDA_JICLOUD3D_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <vector>

#include "AIDA/ICloud3D.h"
#include "AIDA/IHistogram3D.h"
#include "JICloud.h"
#include "JIManagedObject.h"

namespace JAIDA {

/**
 * User level interface to a 3D Cloud.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JICloud3D: public JICloud, public JIManagedObject, public virtual AIDA::ICloud3D {

private:
    jmethodID rmsZOCDMethod;
    jmethodID upperEdgeZOCDMethod;
    jmethodID histogramOCLhep_aida_IHistogram3DEMethod;
    jmethodID lowerEdgeYOCDMethod;
    jmethodID valueZOICDMethod;
    jmethodID meanXOCDMethod;
    jmethodID fillHistogramOLhep_aida_IHistogram3DECVMethod;
    jmethodID meanYOCDMethod;
    jmethodID rmsYOCDMethod;
    jmethodID fillODDDDCVMethod;
    jmethodID meanZOCDMethod;
    jmethodID convertOIDDIDDIDDCVMethod;
    jmethodID lowerEdgeZOCDMethod;
    jmethodID upperEdgeXOCDMethod;
    jmethodID rmsXOCDMethod;
    jmethodID valueXOICDMethod;
    jmethodID upperEdgeYOCDMethod;
    jmethodID valueYOICDMethod;
    jmethodID weightOICDMethod;
    jmethodID convertOADADADCVMethod;
    jmethodID lowerEdgeXOCDMethod;

protected:
    inline JICloud3D() { };
    inline JICloud3D(const JICloud3D& r):JICloud(r),JIManagedObject(r) { };
    inline JICloud3D& operator=(const JICloud3D&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JICloud3D(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JICloud3D();

    /**
     * Fill the ICloud3D with a triplet of values and a corresponding weight.
     * @param x      The x value.
     * @param y      The y value.
     * @param z      The z value.
     * @param weight The corresponding weight. By default it is 1.
     * @return false If the ICloud3D is full, if the weight's value is
     *                                  is not between 0 and 1.
     *
     */
    JNIEXPORT virtual bool fill(double x, double y, double z, double weight);

    /**
     * Get the lower edge of the ICloud3D along the x axis.
     * @return The lower edge along the x axis.
     *
     */
    JNIEXPORT virtual double lowerEdgeX() const;

    /**
     * Get the lower edge of the ICloud3D along the y axis.
     * @return The lower edge along the y axis.
     *
     */
    JNIEXPORT virtual double lowerEdgeY() const;

    /**
     * Get the lower edge of the ICloud3D along the z axis.
     * @return The lower edge along the z axis.
     *
     */
    JNIEXPORT virtual double lowerEdgeZ() const;

    /**
     * Get the upper edge of the ICloud3D along the x axis.
     * @return The upper edge along the x axis.
     *
     */
    JNIEXPORT virtual double upperEdgeX() const;

    /**
     * Get the upper edge of the ICloud3D along the y axis.
     * @return The upper edge along the y axis.
     *
     */
    JNIEXPORT virtual double upperEdgeY() const;

    /**
     * Get the upper edge of the ICloud3D along the z axis.
     * @return The upper edge along the z axis.
     *
     */
    JNIEXPORT virtual double upperEdgeZ() const;

    /**
     * Get the x value corresponding to a given entry.
     * @param index The entry's index.
     * @return      The x value of the index-th entry.
     *              If the ICloud3D has already been converted, 0 is returned.
     *
     */










    JNIEXPORT virtual double valueX(int index) const;

    /**
     * Get the y value corresponding to a given entry.
     * @param index The entry's index.
     * @return      The y value of the index-th entry.
     *              If the ICloud3D has already been converted, 0 is returned.
     *
     */










    JNIEXPORT virtual double valueY(int index) const;

    /**
     * Get the z value corresponding to a given entry.
     * @param index The entry's index.
     * @return      The z value of the index-th entry.
     *              If the ICloud3D has already been converted, 0 is returned.
     *
     */










    JNIEXPORT virtual double valueZ(int index) const;

    /**
     * Get the weight corresponding to a given entry.
     * @param index The entry's index.
     * @return      The weight of the index-th entry.
     *              If the ICloud3D has already been converted, 0 is returned.
     *
     */










    JNIEXPORT virtual double weight(int index) const;

    /**
     * Get the mean of the ICloud3D along the x axis.
     * @return The mean along the x axis.
     *
     */
    JNIEXPORT virtual double meanX() const;

    /**
     * Get the mean of the ICloud3D along the y axis.
     * @return The mean along the y axis.
     *
     */
    JNIEXPORT virtual double meanY() const;

    /**
     * Get the mean of the ICloud3D along the z axis.
     * @return The mean along the z axis.
     *
     */
    JNIEXPORT virtual double meanZ() const;

    /**
     * Get the RMS of the ICloud3D along the x axis.
     * @return The RMS along the x axis.
     *
     */
    JNIEXPORT virtual double rmsX() const;

    /**
     * Get the RMS of the ICloud3D along the y axis.
     * @return The RMS along the y axis.
     *
     */
    JNIEXPORT virtual double rmsY() const;

    /**
     * Get the RMS of the ICloud3D along the z axis.
     * @return The RMS along the z axis.
     *
     */
    JNIEXPORT virtual double rmsZ() const;

    /**
     * Convert internally the ICloud3D to an IHistogram3D
     * with given number of bins, upper edge and lower edge.
     * @param nBinsX     The number of bins of the x axis.
     * @param lowerEdgeX The lower edge of bins of the x axis.
     * @param upperEdgeX The upper edge of bins of the x axis.
     * @param nBinsY     The number of bins of the y axis.
     * @param lowerEdgeY The lower edge of bins of the y axis.
     * @param upperEdgeY The upper edge of bins of the y axis.
     * @param nBinsZ     The number of bins of the z axis.
     * @param lowerEdgeZ The lower edge of bins of the z axis.
     * @param upperEdgeZ The upper edge of bins of the z axis.
     * @return false If the ICloud3D has already been converted.
     *
     */
    JNIEXPORT virtual bool convert(int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, int nBinsZ, double lowerEdgeZ, double upperEdgeZ);

    /**
     * Convert internally the ICloud3D to an IHistogram3D
     * with given bin edges.
     * @param binEdgesX The bins edges of the x axis.
     * @param binEdgesY The bins edges of the y axis.
     * @param binEdgesZ The bins edges of the z axis.
     * @return false If the ICloud3D has already been converted.
     *
     */
    JNIEXPORT virtual bool convert(const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, const std::vector<double>  & binEdgesZ);

    /**
     * Get the internal IHistogram3D in which the ICloud3D converted to.
     * @return The histogram.
     *                          or because of a convert() method invocation.
     *
     */
    JNIEXPORT virtual const AIDA::IHistogram3D & histogram() const;

    /**
     * Project the ICloud3D on an IHistogram3D.
     * @param hist The IHistogram3D to be filled.
     * @return false If the ICloud3D is already converted.
     *
     */
    JNIEXPORT virtual bool fillHistogram(AIDA::IHistogram3D & hist) const;

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
    JNIEXPORT virtual void * cast(const std::string & className) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JICLOUD3D_H */
