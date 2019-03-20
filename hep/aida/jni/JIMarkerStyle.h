// -*- C++ -*-
#ifndef JAIDA_JIMARKERSTYLE_H
#define JAIDA_JIMARKERSTYLE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IMarkerStyle.h"
#include "JIBrushStyle.h"

namespace JAIDA {

/**
 * Style for all markers (histo representation, legend box etc.)
 *
 * @author The AIDA team (http://aida.freehep.org/)
 */

class JIMarkerStyle: public JIBrushStyle, public virtual AIDA::IMarkerStyle {

private:
    jmethodID setShapeOLjava_lang_StringECZMethod;
    jmethodID shapeOCLjava_lang_StringEMethod;
    jmethodID availableShapesOCALjava_lang_StringEMethod;

protected:
    inline JIMarkerStyle() { };
    inline JIMarkerStyle(const JIMarkerStyle& r):JIBrushStyle(r) { };
    inline JIMarkerStyle& operator=(const JIMarkerStyle&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIMarkerStyle(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIMarkerStyle();

  /**
   * Get list of shapes available in this implementation.
   */
    JNIEXPORT virtual std::vector<std::string>  availableShapes() const;

  /**
   * Get current marker shape.
   */
    JNIEXPORT virtual std::string shape() const;

  /**
   * Set current marker shape, e.g. "openCircle".
   * @return false if shape not available in this implementation.
   */
    JNIEXPORT virtual bool setShape(const std::string & shape);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIMARKERSTYLE_H */
