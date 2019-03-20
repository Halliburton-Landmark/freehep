// -*- C++ -*-
#ifndef JAIDA_JIINFOSTYLE_H
#define JAIDA_JIINFOSTYLE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/IInfoStyle.h"
#include "AIDA/ITextStyle.h"
#include "JIBaseStyle.h"

namespace JAIDA {

/**
 * Style for the part of the scene representing the info area.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIInfoStyle: public JIBaseStyle, public virtual AIDA::IInfoStyle {

private:
    jmethodID setTextStyleOLhep_aida_ITextStyleECZMethod;
    jmethodID textStyleOCLhep_aida_ITextStyleEMethod;
    AIDA::ITextStyle* iTextStyle;

protected:
    inline JIInfoStyle() { };
    inline JIInfoStyle(const JIInfoStyle& r):JIBaseStyle(r) { };
    inline JIInfoStyle& operator=(const JIInfoStyle&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIInfoStyle(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIInfoStyle();

    JNIEXPORT virtual AIDA::ITextStyle & textStyle();

    JNIEXPORT virtual bool setTextStyle(const AIDA::ITextStyle & textStyle);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIINFOSTYLE_H */
