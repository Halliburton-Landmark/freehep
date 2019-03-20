// -*- C++ -*-
#ifndef JAIDA_JIBRUSHSTYLE_H
#define JAIDA_JIBRUSHSTYLE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IBrushStyle.h"
#include "JIBaseStyle.h"

namespace JAIDA {

/**
 * Superclass for anything which can be drawn in different
 * colours and with (possibly) transparent/opaque/translucent effect.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 */

class JIBrushStyle: public JIBaseStyle, public virtual AIDA::IBrushStyle {

private:
    jmethodID setOpacityODCZMethod;
    jmethodID colorOCLjava_lang_StringEMethod;
    jmethodID setColorOLjava_lang_StringECZMethod;
    jmethodID opacityOCDMethod;
    jmethodID availableColorsOCALjava_lang_StringEMethod;

protected:
    inline JIBrushStyle() { };
    inline JIBrushStyle(const JIBrushStyle& r):JIBaseStyle(r) { };
    inline JIBrushStyle& operator=(const JIBrushStyle&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIBrushStyle(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIBrushStyle();

  /**
   * Get a list of the colours supported by this implementation.
   */
    JNIEXPORT virtual std::vector<std::string>  availableColors() const;

  /**
   * Current colour of this brush style.
   */
    JNIEXPORT virtual std::string color() const;

  /**
   * Current opacity (alpha) of this brush style.
   */
    JNIEXPORT virtual double opacity() const;

  /**
   * Set current colour, e.g. "darkGreen"
   * @return false if colour not recognised by the implementation.
   */
    JNIEXPORT virtual bool setColor(const std::string & newColor);

  /**
   * Set opacity (alpha), e.g. 0 (transparent),
   * 1 (opaque), 0.5 (halfway).
   * @return false if value not supported by the implementation.
   */
    JNIEXPORT virtual bool setOpacity(double newOpacity);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIBRUSHSTYLE_H */
