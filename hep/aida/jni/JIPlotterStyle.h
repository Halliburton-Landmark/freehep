// -*- C++ -*-
#ifndef JAIDA_JIPLOTTERSTYLE_H
#define JAIDA_JIPLOTTERSTYLE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/IAxisStyle.h"
#include "AIDA/IDataStyle.h"
#include "AIDA/IInfoStyle.h"
#include "AIDA/IPlotterStyle.h"
#include "AIDA/ITitleStyle.h"
#include "JIBaseStyle.h"

namespace JAIDA {

/**
 * User level interface to plotter style.
 * A plotter style permit to customize various part
 * of the plotting "scene" (axes, titles, data
 * representations, etc...)
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIPlotterStyle: public JIBaseStyle, public virtual AIDA::IPlotterStyle {

private:
    jmethodID infoStyleOCLhep_aida_IInfoStyleEMethod;
    jmethodID setAxisStyleXOLhep_aida_IAxisStyleECZMethod;
    jmethodID setDataStyleOLhep_aida_IDataStyleECZMethod;
    jmethodID dataStyleOCLhep_aida_IDataStyleEMethod;
    jmethodID titleStyleOCLhep_aida_ITitleStyleEMethod;
    jmethodID setInfoStyleOLhep_aida_IInfoStyleECZMethod;
    jmethodID xAxisStyleOCLhep_aida_IAxisStyleEMethod;
    jmethodID setAxisStyleZOLhep_aida_IAxisStyleECZMethod;
    jmethodID yAxisStyleOCLhep_aida_IAxisStyleEMethod;
    jmethodID setTitleStyleOLhep_aida_ITitleStyleECZMethod;
    jmethodID zAxisStyleOCLhep_aida_IAxisStyleEMethod;
    jmethodID setAxisStyleYOLhep_aida_IAxisStyleECZMethod;
    AIDA::IDataStyle* iDataStyle;
    AIDA::IAxisStyle* iXaxisStyle;
    AIDA::IAxisStyle* iYaxisStyle;
    AIDA::IAxisStyle* iZaxisStyle;
    AIDA::ITitleStyle* iTitleStyle;
    AIDA::IInfoStyle* iInfoStyle;

protected:
    inline JIPlotterStyle() { };
    inline JIPlotterStyle(const JIPlotterStyle& r):JIBaseStyle(r) { };
    inline JIPlotterStyle& operator=(const JIPlotterStyle&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIPlotterStyle(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIPlotterStyle();

  /**
   * Get style of various plotting scene parts.
   */
    JNIEXPORT virtual AIDA::IDataStyle & dataStyle();

    JNIEXPORT virtual AIDA::IAxisStyle & xAxisStyle();

    JNIEXPORT virtual AIDA::IAxisStyle & yAxisStyle();

    JNIEXPORT virtual AIDA::IAxisStyle & zAxisStyle();

    JNIEXPORT virtual AIDA::ITitleStyle & titleStyle();

    JNIEXPORT virtual AIDA::IInfoStyle & infoStyle();

  /**
   * Set style of various plotting scene parts.
   */
    JNIEXPORT virtual bool setDataStyle(const AIDA::IDataStyle & dataStyle);

    JNIEXPORT virtual bool setAxisStyleX(const AIDA::IAxisStyle & xAxisStyle);

    JNIEXPORT virtual bool setAxisStyleY(const AIDA::IAxisStyle & yAxisStyle);

    JNIEXPORT virtual bool setAxisStyleZ(const AIDA::IAxisStyle & zAxisStyle);

    JNIEXPORT virtual bool setTitleStyle(const AIDA::ITitleStyle & textStyle);

    JNIEXPORT virtual bool setInfoStyle(const AIDA::IInfoStyle & infoStyle);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIPLOTTERSTYLE_H */
