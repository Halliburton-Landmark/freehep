// -*- C++ -*-
#ifndef JAIDA_JIDATASTYLE_H
#define JAIDA_JIDATASTYLE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/IDataStyle.h"
#include "AIDA/IFillStyle.h"
#include "AIDA/ILineStyle.h"
#include "AIDA/IMarkerStyle.h"
#include "JIBaseStyle.h"

namespace JAIDA {

/**
 * Style for the part of the scene representing the data
 * (then histograms, functions, data point sets).
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIDataStyle: public JIBaseStyle, public virtual AIDA::IDataStyle {

private:
    jmethodID markerStyleOCLhep_aida_IMarkerStyleEMethod;
    jmethodID setMarkerStyleOLhep_aida_IMarkerStyleECZMethod;
    jmethodID setLineStyleOLhep_aida_ILineStyleECZMethod;
    jmethodID fillStyleOCLhep_aida_IFillStyleEMethod;
    jmethodID lineStyleOCLhep_aida_ILineStyleEMethod;
    jmethodID setFillStyleOLhep_aida_IFillStyleECZMethod;
    AIDA::ILineStyle* iLineStyle;
    AIDA::IMarkerStyle* iMarkerStyle;
    AIDA::IFillStyle* iFillStyle;

protected:
    inline JIDataStyle() { };
    inline JIDataStyle(const JIDataStyle& r):JIBaseStyle(r) { };
    inline JIDataStyle& operator=(const JIDataStyle&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIDataStyle(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIDataStyle();

  /**
   * Return various styles that may be used to
   * customize the data representation.
   */
    JNIEXPORT virtual AIDA::ILineStyle & lineStyle();

    JNIEXPORT virtual AIDA::IMarkerStyle & markerStyle();

    JNIEXPORT virtual AIDA::IFillStyle & fillStyle();

  /**
   * Set various basic style on the data style.
   */
    JNIEXPORT virtual bool setLineStyle(const AIDA::ILineStyle & lineStyle);

    JNIEXPORT virtual bool setMarkerStyle(const AIDA::IMarkerStyle & markerStyle);

    JNIEXPORT virtual bool setFillStyle(const AIDA::IFillStyle & fillStyle);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIDATASTYLE_H */
