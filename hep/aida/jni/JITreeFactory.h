// -*- C++ -*-
#ifndef JAIDA_JITREEFACTORY_H
#define JAIDA_JITREEFACTORY_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/ITree.h"
#include "AIDA/ITreeFactory.h"
#include "JProxy.h"

namespace JAIDA {

/**
 * The creator of trees.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 */

class JITreeFactory: public JProxy, public virtual AIDA::ITreeFactory {

private:
    jmethodID createOLjava_lang_StringELjava_lang_StringEZZLjava_lang_StringECLhep_aida_ITreeEMethod;
    jmethodID createOCLhep_aida_ITreeEMethod;

protected:
    inline JITreeFactory() { };
    inline JITreeFactory(const JITreeFactory& r):JProxy(r) { };
    inline JITreeFactory& operator=(const JITreeFactory&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JITreeFactory(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JITreeFactory();

    /**
     * Creates a new tree that is not associated with a store.
     */
    JNIEXPORT virtual AIDA::ITree * create();

    /**
     * Creates a new tree and associates it with a store.
     * The store is assumed to be read/write.
     * The store will be created if it does not exist.
     * @param storeName The name of the store, if empty (""), the tree is created
     *                  in memory and therefore will not be associated with a file.
     * @param storeType Implementation specific string, may control store type
     * @param readOnly If true the store is opened readonly, an exception if it does not exist
     * @param createNew If false the file must exist, if true the file will be created
     * @param options Other options, currently are not specified
     *
     */
    JNIEXPORT virtual AIDA::ITree * create(const std::string & storeName, const std::string & storeType, bool readOnly, bool createNew, const std::string & options);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JITREEFACTORY_H */
