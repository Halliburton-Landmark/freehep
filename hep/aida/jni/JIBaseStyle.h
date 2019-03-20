// -*- C++ -*-
#ifndef JAIDA_JIBASESTYLE_H
#define JAIDA_JIBASESTYLE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IBaseStyle.h"
#include "JProxy.h"

namespace JAIDA {

/**
 * Superclass for all styles in AIDA Plotting package.
 * All styles can be reset to their original values at construction
 * time. In the case of styles which 'contain' other styles (like IStyle
 * or IAxisStyle), reset() calls reset() on the aggregated styles too.
 * All styles are hierarchical, so the plotter's current style is overridden by the
 * region's current style, which is overridden by any 'associated' style
 * which is overwritten by any style passed in explicitly at plotting time.
 * Parameters and options which have been explicitly set to
 * non-default (or default!) values are 'sticky'. For example, if a style
 * has the default 'red' and this has been set explicitly to 'blue' at the
 * Plotter level, then it will override the default 'red' at the Region level.
 * IF the user explicitly sets the region to 'green' (or 'red'!) then it will
 * not be overridden by the 'parent' style.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 */

class JIBaseStyle: public JProxy, public virtual AIDA::IBaseStyle {

private:
    jmethodID availableParameterOptionsOLjava_lang_StringECALjava_lang_StringEMethod;
    jmethodID availableParametersOCALjava_lang_StringEMethod;
    jmethodID parameterValueOLjava_lang_StringECLjava_lang_StringEMethod;
    jmethodID setParameterOLjava_lang_StringELjava_lang_StringECZMethod;
    jmethodID resetOCVMethod;

protected:
    inline JIBaseStyle() { };
    inline JIBaseStyle(const JIBaseStyle& r):JProxy(r) { };
    inline JIBaseStyle& operator=(const JIBaseStyle&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIBaseStyle(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIBaseStyle();

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
    JNIEXPORT virtual bool setParameter(const std::string & paramName, const std::string & options);

  /**
   * Get value of a parameter.
   * @param paramName Name of the parameter.
   * @return the value.
   */
    JNIEXPORT virtual std::string parameterValue(const std::string & parameter) const;

  /**
   * Get list of the available parameters (implementation-dependent)
   */
    JNIEXPORT virtual std::vector<std::string>  availableParameters() const;

  /**
   * Get list of the available options for a given parameter
   * (implementation-dependent).
   */
    JNIEXPORT virtual std::vector<std::string>  availableParameterOptions(const std::string & paramName) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIBASESTYLE_H */
