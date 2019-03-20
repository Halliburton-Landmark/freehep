// -*- C++ -*-
#ifndef JAIDA_JITITLESTYLE_H
#define JAIDA_JITITLESTYLE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/ITextStyle.h"
#include "AIDA/ITitleStyle.h"
#include "JIBaseStyle.h"

namespace JAIDA {

/**
 * Style for the "title scene part" of a plotting region or
 * for the global title of a plotting page.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JITitleStyle: public JIBaseStyle, public virtual AIDA::ITitleStyle {

private:
    jmethodID setTextStyleOLhep_aida_ITextStyleECZMethod;
    jmethodID textStyleOCLhep_aida_ITextStyleEMethod;
    AIDA::ITextStyle* iTextStyle;

protected:
    inline JITitleStyle() { };
    inline JITitleStyle(const JITitleStyle& r):JIBaseStyle(r) { };
    inline JITitleStyle& operator=(const JITitleStyle&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JITitleStyle(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JITitleStyle();

    JNIEXPORT virtual AIDA::ITextStyle & textStyle();

    JNIEXPORT virtual bool setTextStyle(const AIDA::ITextStyle & textStyle);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JITITLESTYLE_H */
