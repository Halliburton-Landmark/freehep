// -*- C++ -*-
#ifndef JAIDA_JIMODELFUNCTION_H
#define JAIDA_JIMODELFUNCTION_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <vector>

#include "AIDA/IModelFunction.h"
#include "AIDA/IRangeSet.h"
#include "JIFunction.h"

namespace JAIDA {

/** @interface IModelFunction
 *
 * Interface of model function for fitting (for advanced users).
 *
 * OPEN QUESTIONS:
 *
 * How to treat normalization at user level? Two possibilities:
 * - we have "Gauss" and "NormalizedGauss", the first one user cannot
 *   use for ML fit
 * - we have only one "Gauss" function, but it's smart and when normalized,
 *   gets rid of one of its parameters
 *
 * Normalization range might be set directly on the function by the user?
 * Now we set it in the data pipe, Victor thinks that it is not very clear
 * and should be on the function ;)
 *
 * @author  The AIDA team (http://aida.freehep.org/)
 *
 */

class JIModelFunction: public JIFunction, public virtual AIDA::IModelFunction {

private:
    jmethodID includeNormalizationAllOCVMethod;
    jmethodID excludeNormalizationAllOCVMethod;
    jmethodID providesParameterGradientOCZMethod;
    jmethodID normalizeOZCVMethod;
    jmethodID parameterGradientOADCADMethod;
    jmethodID normalizationRangeOICLhep_aida_IRangeSetEMethod;
    jmethodID isNormalizedOCZMethod;
    jmethodID providesNormalizationOCZMethod;
    std::vector<double> emptyDoubleVector;
    mutable std::vector<double> parameterGradientVector;
    AIDA::IRangeSet* normalizationRangeSet;

protected:
    inline JIModelFunction() { };
    inline JIModelFunction(const JIModelFunction& r):JIFunction(r) { };
    inline JIModelFunction& operator=(const JIModelFunction&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIModelFunction(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIModelFunction();

  /// Return false if function does not provide the normalization capability.
    JNIEXPORT virtual bool providesNormalization() const;

  /**
   * Normalize by internally adjusting some of the parameters.
   * When normalization is on then integral of the function in
   * the normalization range equals to 1.
   */
    JNIEXPORT virtual void normalize(bool on);

  /**
   * Return true if normalization is currently switched on.
   */
    JNIEXPORT virtual bool isNormalized() const;

  /**
   * Compute gradient with respect to parameters.
   */
    JNIEXPORT virtual const std::vector<double>  & parameterGradient(const std::vector<double>  & x) const;

  /**
   * Return true if provides parameter gradient.
   */
    JNIEXPORT virtual bool providesParameterGradient() const;

  /**
   * Set the normalization range from -inf to +inf in the i-th
   * axis (dimension).
   *
   * Full range is the default if not set otherwise.
   * It is still possible to evaluate function outside of the
   * normalization range.
   *
   * PENDING: no methods to retrieve current range!
   */
    JNIEXPORT virtual AIDA::IRangeSet & normalizationRange(int iAxis);

  /**
   * Set full range in all axes.
   */
    JNIEXPORT virtual void includeNormalizationAll();

  /**
   * Set empty range in all axes.
   */
    JNIEXPORT virtual void excludeNormalizationAll();

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
    JNIEXPORT virtual void * cast(const std::string & className) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIMODELFUNCTION_H */
