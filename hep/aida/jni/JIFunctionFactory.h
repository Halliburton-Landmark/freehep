// -*- C++ -*-
#ifndef JAIDA_JIFUNCTIONFACTORY_H
#define JAIDA_JIFUNCTIONFACTORY_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/IFunction.h"
#include "AIDA/IFunctionCatalog.h"
#include "AIDA/IFunctionFactory.h"

#include "JProxy.h"

namespace JAIDA {

/** @interface IFunctionFactory
 *
 * Function factory.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 * @stereotype abstractfactory
 */

class JIFunctionFactory: public JProxy, public virtual AIDA::IFunctionFactory {

private:
    jmethodID cloneFunctionOLjava_lang_StringELhep_aida_IFunctionECLhep_aida_IFunctionEMethod;
    jmethodID createFunctionByNameOLjava_lang_StringELjava_lang_StringECLhep_aida_IFunctionEMethod;
    jmethodID createFunctionFromScriptOLjava_lang_StringEILjava_lang_StringELjava_lang_StringELjava_lang_StringELjava_lang_StringECLhep_aida_IFunctionEMethod;
    jmethodID catalogOCLhep_aida_IFunctionCatalogEMethod;

protected:
    inline JIFunctionFactory() { };
    inline JIFunctionFactory(const JIFunctionFactory& r):JProxy(r) { };
    inline JIFunctionFactory& operator=(const JIFunctionFactory&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIFunctionFactory(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIFunctionFactory();

    /**
     * Create function from a name registered in the catalog.
     * This is the easiest way to create simple model functions for fitting.
     * Every AIDA compliant implementation should predefine "G", "E", "Pn"
     * (n is an integer, e.e "P0","P5"). Simple operations are permitted,
     * e.g. "G+P2".
     */
    JNIEXPORT virtual AIDA::IFunction * createFunctionByName(const std::string & name, const std::string & model);

    /**
     * Create function from script. Script conventions:
     * example:  createFunctionFromScript("f1", 2, "a*x[0]*x[0] + b*x[1]", "a,b",
                                          "this is my function", "2*a*x[0],b")
     */
    JNIEXPORT virtual AIDA::IFunction * createFunctionFromScript(const std::string & name, int dim, const std::string & valexpr, const std::string & parameters, const std::string & description, const std::string & gradexpr);

    JNIEXPORT virtual AIDA::IFunction * cloneFunction(const std::string & name, AIDA::IFunction & f);

    /**
     * get access to the function catalog
     */
    JNIEXPORT virtual AIDA::IFunctionCatalog * catalog();

    /** @link association
     * @directed*/
    /*# IFunctionCatalog lnkIFunctionCatalog; */
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIFUNCTIONFACTORY_H */
