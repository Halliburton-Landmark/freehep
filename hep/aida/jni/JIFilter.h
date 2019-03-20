// -*- C++ -*-
#ifndef JAIDA_JIFILTER_H
#define JAIDA_JIFILTER_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/IFilter.h"
#include "AIDA/ITuple.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * User's level interface of an IFilter.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIFilter: public JProxy, public virtual AIDA::IFilter {

private:
    jmethodID expressionOCLjava_lang_StringEMethod;
    jmethodID acceptOCZMethod;
    jmethodID initializeOLhep_aida_ITupleECVMethod;
//    mutable std::string expressionString;

protected:
    inline JIFilter() { };
    inline JIFilter(const JIFilter& r):JProxy(r) { };
    inline JIFilter& operator=(const JIFilter&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIFilter(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIFilter();

  /**
   * Initialize the IFilter and associate it to an ITuple.
   * @param tuple The ITuple to which the IFilter is sssociated.
   * @return false If the IFilter and
   *              the ITuple are not compatible.
   *
   */
    JNIEXPORT virtual bool initialize(AIDA::ITuple & tuple);

  /**
   * Check if the IFilter accepts or not the data in the
   * current row of the ITuple it is associated to.
   * @return <code>true</code> if the current data is accepted.
   *
   */
    JNIEXPORT virtual bool accept() const;

   /**
    * Get the expression that defined the IFilter.
    * @return The expression.
    *
    */
    JNIEXPORT virtual std::string expression() const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIFILTER_H */
