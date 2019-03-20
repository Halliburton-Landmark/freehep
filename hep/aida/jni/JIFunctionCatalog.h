// -*- C++ -*-
#ifndef JAIDA_JIFUNCTIONCATALOG_H
#define JAIDA_JIFUNCTIONCATALOG_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IFunction.h"
#include "AIDA/IFunctionCatalog.h"

#include "JProxy.h"

namespace JAIDA {

/** @interface
 *
 * Function catalog.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIFunctionCatalog: public JProxy, public virtual AIDA::IFunctionCatalog {

private:
    jmethodID addOLjava_lang_StringELjava_lang_StringECZMethod;
    jmethodID addOLjava_lang_StringELhep_aida_IFunctionECZMethod;
    jmethodID storeAllOLjava_lang_StringECVMethod;
    jmethodID removeOLjava_lang_StringECVMethod;
    jmethodID listOCALjava_lang_StringEMethod;
    jmethodID loadAllOLjava_lang_StringECVMethod;

protected:
    inline JIFunctionCatalog() { };
    inline JIFunctionCatalog(const JIFunctionCatalog& r):JProxy(r) { };
    inline JIFunctionCatalog& operator=(const JIFunctionCatalog&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIFunctionCatalog(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIFunctionCatalog();

    /**
     * Remember persistently definition (code!) of a function under a name.
     * Scripted function created by the user may be automatically available
     * in the subsequent analysis sessions. This is also a way to create
     * new names for combinations of exisiting model functions ("G+G+E+P5").
     * Last but not least, system may be easily extended with model functions
     * developed in the programming language directly.
     * Predefined functions: "G","E","Pn".
     */
    JNIEXPORT virtual bool add(std::string nameId, AIDA::IFunction * f);

    JNIEXPORT virtual bool add(std::string nameId, const std::string & codelet);

    /*
     * Get a list of all available functions.
     */
    JNIEXPORT virtual std::vector<std::string> list();

    /*
     * Remove function from the catalog.
     */
    JNIEXPORT virtual void remove(const std::string & nameId);

    /*
     * Write contents of the catalog to disk.
     * We have to agree on the format here, or define and XML
     * entry for IFunctionCatalog!
     */
    JNIEXPORT virtual bool storeAll(const std::string & nameOnDisk);

    /*
     * Load contents of the catalog from disk
     * We have to agree on the format here, or define and XML
     * entry for IFunctionCatalog!
     */
    JNIEXPORT virtual bool loadAll(const std::string & nameOnDisk);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIFUNCTIONCATALOG_H */
