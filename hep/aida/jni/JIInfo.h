// -*- C++ -*-
#ifndef JAIDA_JIINFO_H
#define JAIDA_JIINFO_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/IFillStyle.h"
#include "AIDA/IInfo.h"
#include "AIDA/ILineStyle.h"
#include "AIDA/IMarkerStyle.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * The info class permits to access the info area of a region.
 * Through it legends, statistics, text could be displayed.
 * A legend is an association of a graphical marker and a text.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIInfo: public JProxy, public virtual AIDA::IInfo {

private:
    jmethodID addLegendOLhep_aida_ILineStyleELjava_lang_StringECVMethod;
    jmethodID addTextOLjava_lang_StringECVMethod;
    jmethodID addLegendOLhep_aida_IFillStyleELjava_lang_StringECVMethod;
    jmethodID addLegendOLhep_aida_IMarkerStyleELjava_lang_StringECVMethod;
    jmethodID clearOCVMethod;

protected:
    inline JIInfo() { };
    inline JIInfo(const JIInfo& r):JProxy(r) { };
    inline JIInfo& operator=(const JIInfo&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIInfo(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIInfo();

  /**
   * Clear the info area.
   */
    JNIEXPORT virtual void clear();

  /**
   * Add a text. The text is appended to existing info elements.
   */
    JNIEXPORT virtual void addText(const std::string & text);

  /**
   * Add a marker, line or fill area legend.
   * The legend is appended to existing elements.
   */
    JNIEXPORT virtual void addLegend(const AIDA::IMarkerStyle & style, const std::string & description);

    JNIEXPORT virtual void addLegend(const AIDA::ILineStyle & style, const std::string & description);

    JNIEXPORT virtual void addLegend(const AIDA::IFillStyle & style, const std::string & description);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIINFO_H */
