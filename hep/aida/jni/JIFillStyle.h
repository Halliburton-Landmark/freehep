// -*- C++ -*-
#ifndef JAIDA_JIFILLSTYLE_H
#define JAIDA_JIFILLSTYLE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IFillStyle.h"
#include "JIBrushStyle.h"

namespace JAIDA {

/**
 * Style for all filled areas (boxes, regions, histograms, etc.)
 *
 * @author The AIDA team (http://aida.freehep.org/)
 */

class JIFillStyle: public JIBrushStyle, public virtual AIDA::IFillStyle {

private:
    jmethodID patternOCLjava_lang_StringEMethod;
    jmethodID setPatternOLjava_lang_StringECZMethod;
    jmethodID availablePatternsOCALjava_lang_StringEMethod;

protected:
    inline JIFillStyle() { };
    inline JIFillStyle(const JIFillStyle& r):JIBrushStyle(r) { };
    inline JIFillStyle& operator=(const JIFillStyle&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIFillStyle(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIFillStyle();

  /**
   * Get a list of patterns available in this implementation.
   */
    JNIEXPORT virtual std::vector<std::string>  availablePatterns() const;

  /**
   * Get name of current pattern.
   */
    JNIEXPORT virtual std::string pattern() const;

  /**
   * Set current pattern, e.g. "crossHatch", "solid".
   * @return false if pattern not known to this implementation.
   */
    JNIEXPORT virtual bool setPattern(const std::string & pattern);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIFILLSTYLE_H */
