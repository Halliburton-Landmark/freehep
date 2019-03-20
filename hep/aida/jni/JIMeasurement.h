// -*- C++ -*-
#ifndef JAIDA_JIMEASUREMENT_H
#define JAIDA_JIMEASUREMENT_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/IMeasurement.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * Basic user-level interface class for holding a single "measurement"
 * with positive and negative errors (to allow for asymmetric errors).
 * "IMeasurement" = "value" + "errorPlus" - "errorMinus"
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIMeasurement: public JProxy, public virtual AIDA::IMeasurement {

private:
    jmethodID setErrorPlusODCVMethod;
    jmethodID errorPlusOCDMethod;
    jmethodID errorMinusOCDMethod;
    jmethodID valueOCDMethod;
    jmethodID setErrorMinusODCVMethod;
    jmethodID setValueODCVMethod;

protected:
    inline JIMeasurement() { };
    inline JIMeasurement(const JIMeasurement& r):JProxy(r) { };
    inline JIMeasurement& operator=(const JIMeasurement&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIMeasurement(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIMeasurement();

    /**
     * Get the value of the IMeasurement.
     * @return The value of the IMeasurement.
     *
     */
    JNIEXPORT virtual double value() const;

    /**
     * Get the plus error of the IMeasurement.
     * @return The plus error.
     *
     */
    JNIEXPORT virtual double errorPlus() const;

    /**
     * Get the minus error of the IMeasurement.
     * @return The minus error.
     *
     */
    JNIEXPORT virtual double errorMinus() const;

    /**
     * Set the value of the IMeasurement.
     * @param value The new value of the IMeasurement.
     * @return false If the value cannot be set.
     *
     */
    JNIEXPORT virtual bool setValue(double value);

    /**
     * Set the plus error of the IMeasurement.
     * @param value The new plus error of the IMeasurement.
     * @return false If the error cannot be set or it is negative.
     *
     */
    JNIEXPORT virtual bool setErrorPlus(double errorPlus);

    /**
     * Set the minus error of the IMeasurement.
     * @param value The new minus error of the IMeasurement.
     * @return false If the error cannot be set or it is negative.
     *
     */
    JNIEXPORT virtual bool setErrorMinus(double errorMinus);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIMEASUREMENT_H */
