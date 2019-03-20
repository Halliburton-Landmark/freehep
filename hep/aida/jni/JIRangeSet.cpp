
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

#include "JIRangeSet.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIRangeSet::JIRangeSet(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    includeAllOCVMethod = env->GetMethodID(cls, "includeAll", "()V");
    if (includeAllOCVMethod == NULL) {
        std::cerr << "IRangeSet" << ": Could not find method: " << "includeAll" << "()V" << std::endl;
    }

    excludeODDCVMethod = env->GetMethodID(cls, "exclude", "(DD)V");
    if (excludeODDCVMethod == NULL) {
        std::cerr << "IRangeSet" << ": Could not find method: " << "exclude" << "(DD)V" << std::endl;
    }

    includeODDCVMethod = env->GetMethodID(cls, "include", "(DD)V");
    if (includeODDCVMethod == NULL) {
        std::cerr << "IRangeSet" << ": Could not find method: " << "include" << "(DD)V" << std::endl;
    }

    upperBoundsOCADMethod = env->GetMethodID(cls, "upperBounds", "()[D");
    if (upperBoundsOCADMethod == NULL) {
        std::cerr << "IRangeSet" << ": Could not find method: " << "upperBounds" << "()[D" << std::endl;
    }

    isInRangeODCZMethod = env->GetMethodID(cls, "isInRange", "(D)Z");
    if (isInRangeODCZMethod == NULL) {
        std::cerr << "IRangeSet" << ": Could not find method: " << "isInRange" << "(D)Z" << std::endl;
    }

    excludeAllOCVMethod = env->GetMethodID(cls, "excludeAll", "()V");
    if (excludeAllOCVMethod == NULL) {
        std::cerr << "IRangeSet" << ": Could not find method: " << "excludeAll" << "()V" << std::endl;
    }

    sizeOCIMethod = env->GetMethodID(cls, "size", "()I");
    if (sizeOCIMethod == NULL) {
        std::cerr << "IRangeSet" << ": Could not find method: " << "size" << "()I" << std::endl;
    }

    lowerBoundsOCADMethod = env->GetMethodID(cls, "lowerBounds", "()[D");
    if (lowerBoundsOCADMethod == NULL) {
        std::cerr << "IRangeSet" << ": Could not find method: " << "lowerBounds" << "()[D" << std::endl;
    }

    plusInfMethod = env->GetMethodID(cls, "PLUS_INF", "()D");
    if (plusInfMethod == NULL) {
        std::cerr << "IRangeSet" << ": Could not find method: " << "PLUS_INF" << "()D" << std::endl;
    }

    minusInfMethod = env->GetMethodID(cls, "MINUS_INF", "()D");
    if (minusInfMethod == NULL) {
        std::cerr << "IRangeSet" << ": Could not find method: " << "MINUS_INF" << "()D" << std::endl;
    }

}

JNIEXPORT JIRangeSet::~JIRangeSet() {
}

JNIEXPORT const std::vector<double>  & JIRangeSet::lowerBounds() {
    lowerBoundsVector.clear();
    // Call to Java
    jdoubleArray jresult = (jdoubleArray)env->CallObjectMethod(ref, lowerBoundsOCADMethod);
    // convert double[] to vector<double>
    unsigned int len = env->GetArrayLength(jresult);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jresult, i, 1, &d);
        lowerBoundsVector.push_back(d);
    }
    JNIUtil::checkExceptions(env);
    return lowerBoundsVector;
}

JNIEXPORT const std::vector<double>  & JIRangeSet::upperBounds() {
    upperBoundsVector.clear();
    // Call to Java
    jdoubleArray jresult = (jdoubleArray)env->CallObjectMethod(ref, upperBoundsOCADMethod);
    // convert double[] to vector<double>
    unsigned int len = env->GetArrayLength(jresult);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jresult, i, 1, &d);
        upperBoundsVector.push_back(d);
    }
    JNIUtil::checkExceptions(env);
    return upperBoundsVector;
}

JNIEXPORT void JIRangeSet::include(double xMin, double xMax) {
    env->CallVoidMethod(ref, includeODDCVMethod, xMin, xMax);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIRangeSet::exclude(double xMin, double xMax) {
    env->CallVoidMethod(ref, excludeODDCVMethod, xMin, xMax);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIRangeSet::includeAll() {
    env->CallVoidMethod(ref, includeAllOCVMethod);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIRangeSet::excludeAll() {
    env->CallVoidMethod(ref, excludeAllOCVMethod);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT bool JIRangeSet::isInRange(double point) {
    jboolean jresult = env->CallBooleanMethod(ref, isInRangeODCZMethod, point);
    JNIUtil::checkExceptions(env);
    return jresult;
}

JNIEXPORT int JIRangeSet::size() {
    jint jresult = env->CallIntMethod(ref, sizeOCIMethod);
    JNIUtil::checkExceptions(env);
    return jresult;
}

JNIEXPORT double JIRangeSet::PLUS_INF() {
    jdouble jresult = env->CallDoubleMethod(ref, plusInfMethod);
    JNIUtil::checkExceptions(env);
    return jresult;
}

JNIEXPORT double JIRangeSet::MINUS_INF() {
    jdouble jresult = env->CallDoubleMethod(ref, minusInfMethod);
    JNIUtil::checkExceptions(env);
    return jresult;
}
