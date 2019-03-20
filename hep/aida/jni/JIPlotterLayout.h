// -*- C++ -*-
#ifndef JAIDA_JIPLOTTERLAYOUT_H
#define JAIDA_JIPLOTTERLAYOUT_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IPlotterLayout.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * Interface to permit customization of the layout
 * of scene objects.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIPlotterLayout: public JProxy, public virtual AIDA::IPlotterLayout {

private:
    jmethodID availableParametersOCALjava_lang_StringEMethod;
    jmethodID setParameterOLjava_lang_StringEDCZMethod;
    jmethodID parameterValueOLjava_lang_StringECDMethod;
    jmethodID resetOCVMethod;

protected:
    inline JIPlotterLayout() { };
    inline JIPlotterLayout(const JIPlotterLayout& r):JProxy(r) { };
    inline JIPlotterLayout& operator=(const JIPlotterLayout&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIPlotterLayout(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIPlotterLayout();

  /**
   * Return to original (construction time) state. Explicitly
   * set parameters will be set to defaults and may be overridden
   */
    JNIEXPORT virtual void reset();

  /**
   * Set a parameter.
   * @param paramName Name of the parameter.
   * @param options String of options.
   * @return false if parameter (or its options) unknown or invalid.
   */
    JNIEXPORT virtual bool setParameter(const std::string & paramName, double paramValue);

  /**
   * Get parameter value.
   */
    JNIEXPORT virtual double parameterValue(const std::string & paramName);

  /**
   * Get list of the available parameters (implementation-dependent)
   */
    JNIEXPORT virtual std::vector<std::string>  availableParameters() const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIPLOTTERLAYOUT_H */
