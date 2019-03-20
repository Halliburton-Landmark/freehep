// -*- C++ -*-
#ifndef JPROXY_H
#define JPROXY_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <string>
#include <cstdlib>
#include <cassert>

#include <jni.h>

#include "JAID/JAIDRef.h"

namespace JAIDA {

class ProxyFactory;

/**
 * Base class for Proxies for Java Objects.
 *
 * @author The AIDA team (http://aida.freehep.org/) 
 */

class JProxy: public JAID::JAIDRef {

    protected:
        const ProxyFactory* factory;

        inline JProxy() { };
        inline JProxy(const JProxy& p):JAID::JAIDRef(p) { };
        inline JProxy& operator=(const JProxy&) { return *this; };

    public:
        JProxy(JNIEnv *jenv, jobject obj, const ProxyFactory & proxyFactory) : 
            JAID::JAIDRef(jenv, obj),
            factory(&proxyFactory) {
        }

        ~JProxy() {};
}; // class
} // namespace JAIDA
#endif /* ifndef JPROXY_H */
