// -*- C++ -*-
#ifndef JAIDA_JIMANAGEDOBJECT_H
#define JAIDA_JIMANAGEDOBJECT_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/IManagedObject.h"
#include "JAID/JAIDRef.h"

namespace JAIDA {

/**
 * An object which can be stored in a tree.
 * @see ITree
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */
// NOTE we do not inherit from JAIDRef to avoid the famous diamond inheritence.
// Histograms, Clouds and others inherit from their Base classes and thus from JAIDRef
// and from ManagedObject. The latter should thus create its own reference and env
// management.
class JIManagedObject: public virtual AIDA::IManagedObject {

private:
    JNIEnv* moEnv;
    jobject moRef;
    jmethodID nameOCLjava_lang_StringEMethod;

protected:

    inline JIManagedObject() { };
    inline JIManagedObject(const JIManagedObject& r) { };
    inline JIManagedObject& operator=(const JIManagedObject&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIManagedObject(JNIEnv *jnienv, jobject object);

    /// Destructor.
    JNIEXPORT virtual ~JIManagedObject();

    /**
     * Get the name of an IManagedObject.
     * Names can only be changed using the ITree.mv().
     * @return The name of the IManagedObject.
     *
     */
    JNIEXPORT virtual std::string name() const;

}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIMANAGEDOBJECT_H */
