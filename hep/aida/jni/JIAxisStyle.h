// -*- C++ -*-
#ifndef JAIDA_JIAXISSTYLE_H
#define JAIDA_JIAXISSTYLE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/IAxisStyle.h"
#include "AIDA/ILineStyle.h"
#include "AIDA/ITextStyle.h"
#include "JIBaseStyle.h"

namespace JAIDA {

/**
 * Style for the part of the scene representing the data
 * (then histograms, functions, data point sets).
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIAxisStyle: public JIBaseStyle, public virtual AIDA::IAxisStyle {

private:
    jmethodID setlineStyleOLhep_aida_ILineStyleECZMethod;
    jmethodID tickLabelStyleOCLhep_aida_ITextStyleEMethod;
    jmethodID setLabelOLjava_lang_StringECVMethod;
    jmethodID setTickLabelStyleOLhep_aida_ITextStyleECZMethod;
    jmethodID labelStyleOCLhep_aida_ITextStyleEMethod;
    jmethodID lineStyleOCLhep_aida_ILineStyleEMethod;
    jmethodID setLabelStyleOLhep_aida_ITextStyleECZMethod;
    AIDA::ILineStyle* iLineStyle;
    AIDA::ITextStyle* iTickLabelStyle;
    AIDA::ITextStyle* iLabelStyle;

protected:
    inline JIAxisStyle() { };
    inline JIAxisStyle(const JIAxisStyle& r):JIBaseStyle(r) { };
    inline JIAxisStyle& operator=(const JIAxisStyle&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIAxisStyle(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIAxisStyle();

    JNIEXPORT virtual AIDA::ILineStyle & lineStyle();

    JNIEXPORT virtual AIDA::ITextStyle & tickLabelStyle();

    JNIEXPORT virtual AIDA::ITextStyle & labelStyle();

    JNIEXPORT virtual bool setlineStyle(const AIDA::ILineStyle & lineStyle);

    JNIEXPORT virtual bool setTickLabelStyle(const AIDA::ITextStyle & tickLabelStyle);

    JNIEXPORT virtual bool setLabelStyle(const AIDA::ITextStyle & labelStyle);

    JNIEXPORT virtual void setLabel(const std::string & label);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIAXISSTYLE_H */
