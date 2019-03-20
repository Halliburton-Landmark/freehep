// -*- C++ -*-
#ifndef JAIDA_JIFITFACTORY_H
#define JAIDA_JIFITFACTORY_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/IFitData.h"
#include "AIDA/IFitFactory.h"
#include "AIDA/IFitter.h"

#include "JProxy.h"

namespace JAIDA {

/** @interface IFitFactory
 *
 * Factory for fitter and fit data objects.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIFitFactory: public JProxy, public virtual AIDA::IFitFactory {

private:
    jmethodID createFitDataOCLhep_aida_IFitDataEMethod;
    jmethodID createFitterOLjava_lang_StringELjava_lang_StringELjava_lang_StringECLhep_aida_IFitterEMethod;

protected:
    inline JIFitFactory() { };
    inline JIFitFactory(const JIFitFactory& r):JProxy(r) { };
    inline JIFitFactory& operator=(const JIFitFactory&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIFitFactory(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIFitFactory();

    JNIEXPORT virtual AIDA::IFitData * createFitData();

    /**
     * Create a new IFitter.
     * @param fitterType The type of fitter. The supported types are:
     *                    - "CHI2" or "Chi2" or "ChiSquared" for chi squared fitter (this is the default),
     *                    - "ML" or "MaxLikelihood" for maximum likelihood fitter,
     *                    - "LS" or "LeastSquares" for Last Squares fitter.
     * @param engineType The type of optimization engine used by the fitter. The available types depend on the
     *                   specific implementation in use. The default is "" (the implementation specific default).
     * @param options    A string of options. The default is "".
     * @return           The IFitter.
     *
     */
    JNIEXPORT virtual AIDA::IFitter * createFitter(const std::string & fitterType, const std::string & engineType, const std::string & options);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIFITFACTORY_H */
