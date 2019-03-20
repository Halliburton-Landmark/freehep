// -*- C++ -*-
#ifndef JAIDA_JIEVALUATOR_H
#define JAIDA_JIEVALUATOR_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/IEvaluator.h"
#include "AIDA/ITuple.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * User's level interface of an IEvaluator.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIEvaluator: public JProxy, public virtual AIDA::IEvaluator {

private:
    jmethodID expressionOCLjava_lang_StringEMethod;
    jmethodID initializeOLhep_aida_ITupleECVMethod;
    jmethodID evaluateDoubleOCDMethod;

protected:
    inline JIEvaluator() { };
    inline JIEvaluator(const JIEvaluator& r):JProxy(r) { };
    inline JIEvaluator& operator=(const JIEvaluator&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIEvaluator(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIEvaluator();

  /**
   * Initialize the IEvaluator and associate it to an ITuple.
   * @param tuple The ITuple to which the IEvaluator is sssociated.
   * @return false If the IEvaluator and
   *              the ITuple are not compatible.
   *
   */
    JNIEXPORT virtual bool initialize(AIDA::ITuple & tuple);

  /**
   * Evaluate the IEvaluator from the data in the
   * current row of the ITuple it is associated to.
   * @return The current value of the Evaluator.
   *
   */
    JNIEXPORT virtual double evaluateDouble() const;

   /**
    * Get the expression that defined the IEvaluator.
    * @return The expression.
    *
    */
    JNIEXPORT virtual std::string expression() const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIEVALUATOR_H */
