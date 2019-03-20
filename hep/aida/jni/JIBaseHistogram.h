// -*- C++ -*-
#ifndef JAIDA_JIBASEHISTOGRAM_H
#define JAIDA_JIBASEHISTOGRAM_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/IAnnotation.h"
#include "AIDA/IBaseHistogram.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * User level interface to Histogram.
 * Provides the common functionality of the histogram-like classes.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIBaseHistogram: public JProxy, public virtual AIDA::IBaseHistogram {

private:
    jmethodID annotationOCLhep_aida_IAnnotationEMethod;
    jmethodID entriesOCIMethod;
    jmethodID setTitleOLjava_lang_StringECVMethod;
    jmethodID titleOCLjava_lang_StringEMethod;
    jmethodID dimensionOCIMethod;
    jmethodID resetOCVMethod;
    mutable AIDA::IAnnotation* iAnnotation;

protected:
    inline JIBaseHistogram() { };
    inline JIBaseHistogram(const JIBaseHistogram& r):JProxy(r) { };
    inline JIBaseHistogram& operator=(const JIBaseHistogram&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIBaseHistogram(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIBaseHistogram();

  /**
   * Get the Histogram's title.
   * @return The Histogram's title.
   *
   */
    JNIEXPORT virtual std::string title() const;

  /**
   * Set the histogram title.
   * @param title The title.
   * @return false If title cannot be changed.
   *
   */
    JNIEXPORT virtual bool setTitle(const std::string & title);

  /**
   * Get the IAnnotation associated with the Histogram.
   * @return The IAnnotation.
   *
   */
    JNIEXPORT virtual AIDA::IAnnotation & annotation();

    JNIEXPORT virtual const AIDA::IAnnotation & annotation() const;

  /**
   * Get the Histogram's dimension.
   * @return The Histogram's dimension.
   *
   */
    JNIEXPORT virtual int dimension() const;

  /**
   * Reset the Histogram; as if just created.
   * @return false If something goes wrong.
   *
   */
    JNIEXPORT virtual bool reset();

  /**
   * Get the number of in-range entries in the Histogram.
   * @return The number of in-range entries.
   *
   */
    JNIEXPORT virtual int entries() const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIBASEHISTOGRAM_H */
