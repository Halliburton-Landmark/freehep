// -*- C++ -*-
#ifndef JAIDA_JIFITPARAMETERSETTINGS_H
#define JAIDA_JIFITPARAMETERSETTINGS_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/IFitParameterSettings.h"

#include "JProxy.h"

namespace JAIDA {

/** @interface
 *
 * Fitting-specific settings applied to a parameter of the fitted function.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIFitParameterSettings: public JProxy, public virtual AIDA::IFitParameterSettings {

private:
    jmethodID setBoundsODDCVMethod;
    jmethodID nameOCLjava_lang_StringEMethod;
    jmethodID setUpperBoundODCVMethod;
    jmethodID lowerBoundOCDMethod;
    jmethodID setStepSizeODCVMethod;
    jmethodID isFixedOCZMethod;
    jmethodID isBoundOCZMethod;
    jmethodID upperBoundOCDMethod;
    jmethodID setLowerBoundODCVMethod;
    jmethodID removeBoundsOCVMethod;
    jmethodID setFixedOZCVMethod;
    jmethodID stepSizeOCDMethod;
    jmethodID resetOCVMethod;

protected:
    inline JIFitParameterSettings() { };
    inline JIFitParameterSettings(const JIFitParameterSettings& r):JProxy(r) { };
    inline JIFitParameterSettings& operator=(const JIFitParameterSettings&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIFitParameterSettings(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIFitParameterSettings();

  /// Name of the parameter to which settings apply.
    JNIEXPORT virtual std::string name() const;

  /// Step size allows to control the "sensitivity" of the change of the parameter
  /// when fitters looks for the optimal parameter value. Default is 1.0.
    JNIEXPORT virtual double stepSize() const;

  /// Bounds.
    JNIEXPORT virtual double upperBound() const;

    JNIEXPORT virtual double lowerBound() const;

  /// Shortcut for lowerBound() == -INF && upperBound() == +INF.
    JNIEXPORT virtual bool isBound() const;

  /// Value of the parameter cannot change if isFixed() == true.
  /// Parameter can be fixed independently from setting the bounds.
    JNIEXPORT virtual bool isFixed() const;

  /// Set the step size for the fitter.
    JNIEXPORT virtual void setStepSize(double step);

  /// Set bounds. If bounds not set, then default bound is (-INF,+INF).
    JNIEXPORT virtual void setBounds(double lo, double up);

  /// Shortcut for setBounds(-INF,+INF).
    JNIEXPORT virtual void removeBounds();

  /// Fix/unfix parameter.
    JNIEXPORT virtual void setFixed(bool isFixed);

  /**
   * Set the lower bound. When this method is
   * invoked any previous bound is reset. The new bounds
   * are (lowerBound, +INF).
   * @param lowerBound The lower bound.
   *
   */
    JNIEXPORT virtual void setLowerBound(double lowerBound);

  /**
   * Set the upper bound. When this method is
   * invoked any previous bound is reset. The new bounds
   * are (-INF, upperBound).
   * @param upperBound The upper bound.
   *
   */
    JNIEXPORT virtual void setUpperBound(double upperBound);

  /// Reset all settings to the default values (remove bounds, step size = 1.0, no fix).
    JNIEXPORT virtual void reset();
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIFITPARAMETERSETTINGS_H */
