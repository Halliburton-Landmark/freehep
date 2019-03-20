// -*- C++ -*-
#ifndef JAIDA_JILINESTYLE_H
#define JAIDA_JILINESTYLE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/ILineStyle.h"
#include "JIBrushStyle.h"

namespace JAIDA {

/**
 * Style for all lines (axis lines, legend box outlines, etc.)
 *
 * @author The AIDA team (http://aida.freehep.org/)
 */

class JILineStyle: public JIBrushStyle, public virtual AIDA::ILineStyle {

private:
    jmethodID thicknessOCIMethod;
    jmethodID setLineTypeOLjava_lang_StringECZMethod;
    jmethodID availableLineTypesOCALjava_lang_StringEMethod;
    jmethodID setThicknessOICZMethod;
    jmethodID lineTypeOCLjava_lang_StringEMethod;

protected:
    inline JILineStyle() { };
    inline JILineStyle(const JILineStyle& r):JIBrushStyle(r) { };
    inline JILineStyle& operator=(const JILineStyle&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JILineStyle(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JILineStyle();

  /**
   * Get list of line types supported by this implementation.
   */
    JNIEXPORT virtual std::vector<std::string>  availableLineTypes() const;

  /**
   * Get line type currently in use.
   */
    JNIEXPORT virtual std::string lineType() const;

  /**
   * Get current line thickness.
   */
    JNIEXPORT virtual int thickness() const;

  /**
   * Set current line type e.g. "dotted".
   * @return false if line type not known to this implementation.
   */
    JNIEXPORT virtual bool setLineType(const std::string & newLineType);

  /**
   * Set thickness (exact meaning is implementation-dependent,
   * but <0 means invisible).
   * @return false if value not supported by this implementation.
   */
    JNIEXPORT virtual bool setThickness(int newThickness);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JILINESTYLE_H */
