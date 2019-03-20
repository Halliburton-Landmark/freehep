// -*- C++ -*-
#ifndef JAIDA_JIDATAPOINTSET_H
#define JAIDA_JIDATAPOINTSET_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/IAnnotation.h"
#include "AIDA/IDataPoint.h"
#include "AIDA/IDataPointSet.h"

#include "JProxy.h"

#include "JIManagedObject.h"

namespace JAIDA {

/**
 * Basic user-level interface class for holding and managing
 * a single set of "data points".
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIDataPointSet: public JProxy, public JIManagedObject, public virtual AIDA::IDataPointSet {

private:
    jmethodID annotationOCLhep_aida_IAnnotationEMethod;
    jmethodID upperExtentOICDMethod;
    jmethodID addPointOLhep_aida_IDataPointECVMethod;
    jmethodID setTitleOLjava_lang_StringECVMethod;
    jmethodID scaleODCVMethod;
    jmethodID pointOICLhep_aida_IDataPointEMethod;
    jmethodID removePointOICVMethod;
    jmethodID addPointOCVMethod;
    jmethodID scaleErrorsODCVMethod;
    jmethodID sizeOCIMethod;
    jmethodID titleOCLjava_lang_StringEMethod;
    jmethodID scaleValuesODCVMethod;
    jmethodID dimensionOCIMethod;
    jmethodID lowerExtentOICDMethod;
    jmethodID clearOCVMethod;
    jmethodID setCoordinateOIADADCZMethod;
    jmethodID setCoordinateOIADADADCZMethod;
    mutable AIDA::IAnnotation* iAnnotation;

protected:
    inline JIDataPointSet() { };
    inline JIDataPointSet(const JIDataPointSet& r):JProxy(r), JIManagedObject(r) { };
    inline JIDataPointSet& operator=(const JIDataPointSet&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIDataPointSet(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIDataPointSet();

    /**
     * Get the IAnnotation of the IDataPointSet.
     * @return The IAnnotation.
     *
     */
    JNIEXPORT virtual AIDA::IAnnotation & annotation();

    JNIEXPORT virtual const AIDA::IAnnotation & annotation() const;

    /**
     * Get the title of the IDataPointSet.
     * @return The title.
     *
     */
    JNIEXPORT virtual std::string title() const;

    /**
     * Set the title of the IDataPointSet.
     * @param title The new title.
     * @return false If the title cannot be set.
     *
     */
    JNIEXPORT virtual bool setTitle(const std::string & title);

    /**
     * Get the dimension of the IDataPoints that can be stored in the set.
     * @return The dimension of the IDataPoints storable in the set.
     *
     */
    JNIEXPORT virtual int dimension() const;

    /**
     * Remove all the IDataPoints in the set.
     * After this the IDataPointSet is as just created.
     *
     */
    JNIEXPORT virtual void clear();

    /**
     * Get the current size of the IDataPointSet, i.e. the number
     * of IDataPoints contained in the set.
     * @return The size of the IDataPointSet.
     *
     */
    JNIEXPORT virtual int size() const;

    /**
     * Get the IDataPoint at a give index in the set.
     * @param index The IDataPoint index.
     * @return      The corresponding IDataPoint.
     *
     */
    JNIEXPORT virtual AIDA::IDataPoint * point(int index);

    JNIEXPORT virtual const AIDA::IDataPoint * point(int index) const;

    /**
     * Set the values and errors of a given coordinate all at once.
     * If this method is called on an empty IDataPointSet, a number of points equal
     * to the size of the arrays provided is created; if the IDataPointSet is not empty
     * the dimension of the array must match with the size of the IDataPointSet.
     * @param coord The coordinate's index
     * @param val   The array of the values for the given coordinate
     * @param err   The array with the symmetric errors.
     * @return false if an illegal coordinate is provided or if
     *              there is a mismatch between the size of the array and the size of the IDataPointSet.
     *
     */
    JNIEXPORT virtual bool setCoordinate(int coord, const std::vector<double>  & val, const std::vector<double>  & err);

    /**
     * Set the values and errors of a given coordinate all at once.
     * If this method is called on an empty IDataPointSet, a number of points equal
     * to the size of the arrays provided is created; if the IDataPointSet is not empty
     * the dimension of the array must match with the size of the IDataPointSet.
     * @param coord The coordinate's index
     * @param val   The array of the values for the given coordinate
     * @param errp  The array with the plus errors.
     * @param errm  The array with the minus errors.
     * @return false if an illegal coordinate is provided or if
     *              there is a mismatch between the size of the array and the size of the IDataPointSet.
     *
     */
    JNIEXPORT virtual bool setCoordinate(int coord, const std::vector<double>  & val, const std::vector<double>  & errp, const std::vector<double>  & errm);

    /**
     * Add a new empty IDataPoint at the end of the set.
     * @return false If a new IDataPoint cannot be added to the set.
     *
     */
    JNIEXPORT virtual AIDA::IDataPoint * addPoint();

    /**
     * Add a copy of an IDataPoint at the end of the set.
     * @param point The IDataPoint to be added.
     * @return false If the point has the wrong dimension or
     *                                       if the point cannot be added.
     *
     */
    JNIEXPORT virtual bool addPoint(const AIDA::IDataPoint & point);

    /**
     * Remove the IDataPoint at a given index.
     * @param index The index of the IDataPoint to be removed.
     * @return false If the index is < 0 or >= size().
     *
     */
    JNIEXPORT virtual bool removePoint(int index);

    /**
     * Get the lower value for a give axis.
     * @param coord The coordinate of the axis.
     * @return      The lower edge of the corresponding axis.
     *              If coord < 0 or coord >= dimension(), or if the set is empty NaN is returned.
     *
     */










    JNIEXPORT virtual double lowerExtent(int coord) const;

    /**
     * Get the upper value for a give axis.
     * @param coord The coordinate of the axis.
     * @return      The upper edge of the corresponding axis.
     *              If coord < 0 or coord >= dimension(), or if the set is empty NaN is returned.
     *
     */










    JNIEXPORT virtual double upperExtent(int coord) const;

    /**
     * Scales the values and the errors of all the measurements
     * of each point by a given factor.
     * @param scaleFactor The scale factor.
     * @return false If an illegal scaleFactor is provided.
     *
     */
    JNIEXPORT virtual bool scale(double scaleFactor);

    /**
     * Scales the values of all the measurements
     * of each point by a given factor.
     * @param scaleFactor The scale factor.
     * @return false If an illegal scaleFactor is provided.
     *
     */
    JNIEXPORT virtual bool scaleValues(double scaleFactor);

    /**
     * Scales the errors of all the measurements
     * of each point by a given factor.
     * @param scaleFactor The scale factor.
     * @return false If an illegal scaleFactor is provided.
     *
     */
    JNIEXPORT virtual bool scaleErrors(double scaleFactor);

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
    JNIEXPORT virtual void * cast(const std::string & className) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIDATAPOINTSET_H */
