// -*- C++ -*-
#ifndef JAIDA_JIDATAPOINT_H
#define JAIDA_JIDATAPOINT_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>

#include "AIDA/IDataPoint.h"
#include "AIDA/IMeasurement.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * Basic user-level interface class for holding and managing
 * a single set of "measurements".
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIDataPoint: public JProxy, public virtual AIDA::IDataPoint {

private:
    jmethodID coordinateOICLhep_aida_IMeasurementEMethod;
    jmethodID dimensionOCIMethod;

protected:
    inline JIDataPoint() { };
    inline JIDataPoint(const JIDataPoint& r):JProxy(r) { };
    inline JIDataPoint& operator=(const JIDataPoint&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIDataPoint(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIDataPoint();

    /**
     * Get the dimension of the IDataPoint, i.e. the number
     * of coordinates the point has.
     * @return The dimension.
     *
     */
    JNIEXPORT virtual int dimension() const;

    /**
     * Get the IMeasurement for a given coordinate.
     * @param coord The coordinate.
     * @return      The corresponding IMeasurement.
     *
     */
    JNIEXPORT virtual AIDA::IMeasurement * coordinate(int coord);

    JNIEXPORT virtual const AIDA::IMeasurement * coordinate(int coord) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIDATAPOINT_H */
