// -*- C++ -*-
#ifndef JAIDA_JIPLOTTERFACTORY_H
#define JAIDA_JIPLOTTERFACTORY_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/IAxisStyle.h"
#include "AIDA/IDataStyle.h"
#include "AIDA/IFillStyle.h"
#include "AIDA/ILineStyle.h"
#include "AIDA/IMarkerStyle.h"
#include "AIDA/IPlotter.h"
#include "AIDA/IPlotterFactory.h"
#include "AIDA/IPlotterStyle.h"
#include "AIDA/ITextStyle.h"
#include "AIDA/ITitleStyle.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * Factory for plotter and styles.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 */

class JIPlotterFactory: public JProxy, public virtual AIDA::IPlotterFactory {

private:
    jmethodID createDataStyleOCLhep_aida_IDataStyleEMethod;
    jmethodID createOLjava_lang_StringECLhep_aida_IPlotterEMethod;
    jmethodID createAxisStyleOCLhep_aida_IAxisStyleEMethod;
    jmethodID createPlotterStyleOCLhep_aida_IPlotterStyleEMethod;
    jmethodID createTextStyleOCLhep_aida_ITextStyleEMethod;
    jmethodID createLineStyleOCLhep_aida_ILineStyleEMethod;
    jmethodID createMarkerStyleOCLhep_aida_IMarkerStyleEMethod;
    jmethodID createTitleStyleOCLhep_aida_ITitleStyleEMethod;
    jmethodID createFillStyleOCLhep_aida_IFillStyleEMethod;

protected:
    inline JIPlotterFactory() { };
    inline JIPlotterFactory(const JIPlotterFactory& r):JProxy(r) { };
    inline JIPlotterFactory& operator=(const JIPlotterFactory&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIPlotterFactory(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIPlotterFactory();

   /**
     * @param name  A string identifier.
                    A plotter is in general managed by a GUI.
                    The "name" of the plotter could be used as
                    the string identifier for the GUI plotter widget.
                    If "" is passed, some default plotter is used.
    */

    JNIEXPORT virtual AIDA::IPlotter * create(const std::string & name);

   /**
    * Create various basic styles.
    * The returned styles are not managed by the plotter.
    * A user have to delete these objects.
    */
    JNIEXPORT virtual AIDA::IMarkerStyle * createMarkerStyle();

    JNIEXPORT virtual AIDA::ITextStyle * createTextStyle();

    JNIEXPORT virtual AIDA::ILineStyle * createLineStyle();

    JNIEXPORT virtual AIDA::IFillStyle * createFillStyle();

   /**
    * Create various "scene part" styles.
    * The returned styles are not managed by the plotter.
    */
    JNIEXPORT virtual AIDA::IDataStyle * createDataStyle();

    JNIEXPORT virtual AIDA::IAxisStyle * createAxisStyle();

    JNIEXPORT virtual AIDA::ITitleStyle * createTitleStyle();

   /**
    * Create a global plotter style.
    * The returned style is not managed by the plotter.
    */
    JNIEXPORT virtual AIDA::IPlotterStyle * createPlotterStyle();
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIPLOTTERFACTORY_H */
