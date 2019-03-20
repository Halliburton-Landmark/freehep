// -*- C++ -*-
#ifndef JAIDA_JITEXTSTYLE_H
#define JAIDA_JITEXTSTYLE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/ITextStyle.h"
#include "JIBrushStyle.h"

namespace JAIDA {

/**
 * Style for all text (e.g. axis labels, legend box text etc.)
 *
 * @author The AIDA team (http://aida.freehep.org/)
 */

class JITextStyle: public JIBrushStyle, public virtual AIDA::ITextStyle {

private:
    jmethodID fontOCLjava_lang_StringEMethod;
    jmethodID isItalicOCZMethod;
    jmethodID setFontSizeODCZMethod;
    jmethodID fontSizeOCDMethod;
    jmethodID setItalicOZCZMethod;
    jmethodID setUnderlinedOZCZMethod;
    jmethodID setBoldOZCZMethod;
    jmethodID isBoldOCZMethod;
    jmethodID availableFontsOCALjava_lang_StringEMethod;
    jmethodID isUnderlinedOCZMethod;
    jmethodID setFontOLjava_lang_StringECZMethod;

protected:
    inline JITextStyle() { };
    inline JITextStyle(const JITextStyle& r):JIBrushStyle(r) { };
    inline JITextStyle& operator=(const JITextStyle&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JITextStyle(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JITextStyle();

  /**
   * Get list of fonts available in this implementation.
   */
    JNIEXPORT virtual std::vector<std::string>  availableFonts() const;

  /**
   * Get current font size.
   */
    JNIEXPORT virtual double fontSize() const;

  /**
   * Set current font size.
   * @return false if size not supported by this implementation.
   */
    JNIEXPORT virtual bool setFontSize(double size);

  /**
   * Get name of current font.
   */
    JNIEXPORT virtual std::string font() const;

  /**
   * Set current font, e.g. "timesNewRoman" or "courier".
   * @return false if font not supported by this implementation.
   */
    JNIEXPORT virtual bool setFont(const std::string & font);

    JNIEXPORT virtual bool isBold() const;

    JNIEXPORT virtual bool isItalic() const;

    JNIEXPORT virtual bool isUnderlined() const;

    JNIEXPORT virtual bool setBold(bool bold);

    JNIEXPORT virtual bool setItalic(bool italic);

    JNIEXPORT virtual bool setUnderlined(bool underlined);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JITEXTSTYLE_H */
