// -*- C++ -*-
#ifndef JAIDA_REGISTRY_H
#define JAIDA_REGISTRY_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include "FreeHepTypes.h"

#include <iostream>
#include <map>

#include <jni.h>

namespace JAIDA {

/**
 * Registry to keep track of the Java -> C++ connections.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 */

class Registry {

private:
    static bool debug;    
    static std::map<const void*, jobject> jref;
    static std::map<const void*, jclass> jrefClass;
    static std::map<jlong, const void*> cref;
    static Registry* registry;
    
public:

    JNIEXPORT inline Registry() {
        debug = (getenv("AIDAJNI_DEBUG") != NULL);
    }
    
    JNIEXPORT virtual inline ~Registry() {
    }
    
    JNIEXPORT static inline Registry* getRegistry() {
        if (registry == NULL) registry = new Registry();
        return registry;
    }

    JNIEXPORT static inline void add(jlong ID, const void* cobj, jobject jobj, jclass jcls) {
        if (debug) std::cout << "Registry::add(" << ID << ", C=" << cobj << ", J=" << jobj << ", JCLS=" << jcls << ");" << std::endl;
        cref[ID] = cobj;
        jref[cobj] = jobj; 
        jrefClass[cobj] = jcls;
    }

    JNIEXPORT static inline void remove(jlong ID) {
        if (debug) std::cout << "Registry::remove(" << ID << ");" << std::endl;
        const void* cobj = lookup(ID);
        cref.erase(ID);
        jref.erase(cobj);
        jrefClass.erase(cobj);
    }

    JNIEXPORT static inline const void* lookup(jlong ID) {
        if (debug) std::cout << "Registry::lookup(" << ID << ");";
        std::map<jlong, const void*>::iterator i = cref.find(ID);
        const void* result = (i == cref.end()) ? NULL : i->second;
        if (debug) {
            std::cout << " ===> C=";
            if (result == NULL) {
                std::cout << "NULL";
            } else { 
                std::cout << result;
            }
            std::cout << ";" << std::endl;
        }
        return result;
    }
    
    JNIEXPORT static inline jobject lookup(const void* cobj) {
        if (debug) std::cout << "Registry::lookup(C=" << cobj << ");";
        std::map<const void*, jobject>::iterator i = jref.find(cobj);
        jobject result = (i == jref.end()) ? NULL : i->second;
        if (debug) {
            std::cout << " ===> J=";
            if (result == NULL) {
                std::cout << "NULL";
            } else { 
                std::cout << result;
            }
            std::cout << ";" << std::endl;   
        }     
        return result;
    }
    
    JNIEXPORT static inline jclass lookupClass(const void* cobj) {
        if (debug) std::cout << "Registry::lookup(C=" << cobj << ");";
        std::map<const void*, jclass>::iterator i = jrefClass.find(cobj);
        jclass result = (i == jrefClass.end()) ? NULL : i->second;
        if (debug) {
            std::cout << " ===> JCLS=";
            if (result == NULL) {
                std::cout << "NULL";
            } else { 
                std::cout << result;
            }
            std::cout << ";" << std::endl;   
        }     
        return result;
    }
    
}; // class
} // namespace JAIDA

#endif /* ifndef JAIDA_REGISTRY_H */

