
#include <cstdlib>
#include <iostream>

#include "JIAxis.h"
#include "JNIUtil.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JIAxis::JIAxis(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    upperEdgeOCDMethod = env->GetMethodID(cls, "upperEdge", "()D");
    if (upperEdgeOCDMethod == NULL) {
        std::cerr << "IAxis" << ": Could not find method: " << "upperEdge" << "()D" << std::endl;
    }

    binWidthOICDMethod = env->GetMethodID(cls, "binWidth", "(I)D");
    if (binWidthOICDMethod == NULL) {
        std::cerr << "IAxis" << ": Could not find method: " << "binWidth" << "(I)D" << std::endl;
    }

    coordToIndexODCIMethod = env->GetMethodID(cls, "coordToIndex", "(D)I");
    if (coordToIndexODCIMethod == NULL) {
        std::cerr << "IAxis" << ": Could not find method: " << "coordToIndex" << "(D)I" << std::endl;
    }

    binUpperEdgeOICDMethod = env->GetMethodID(cls, "binUpperEdge", "(I)D");
    if (binUpperEdgeOICDMethod == NULL) {
        std::cerr << "IAxis" << ": Could not find method: " << "binUpperEdge" << "(I)D" << std::endl;
    }

    binsOCIMethod = env->GetMethodID(cls, "bins", "()I");
    if (binsOCIMethod == NULL) {
        std::cerr << "IAxis" << ": Could not find method: " << "bins" << "()I" << std::endl;
    }

    binLowerEdgeOICDMethod = env->GetMethodID(cls, "binLowerEdge", "(I)D");
    if (binLowerEdgeOICDMethod == NULL) {
        std::cerr << "IAxis" << ": Could not find method: " << "binLowerEdge" << "(I)D" << std::endl;
    }

    lowerEdgeOCDMethod = env->GetMethodID(cls, "lowerEdge", "()D");
    if (lowerEdgeOCDMethod == NULL) {
        std::cerr << "IAxis" << ": Could not find method: " << "lowerEdge" << "()D" << std::endl;
    }

    isFixedBinningOCZMethod = env->GetMethodID(cls, "isFixedBinning", "()Z");
    if (isFixedBinningOCZMethod == NULL) {
        std::cerr << "IAxis" << ": Could not find method: " << "isFixedBinning" << "()Z" << std::endl;
    }

}

JNIEXPORT JIAxis::~JIAxis() {
}

JNIEXPORT bool JIAxis::isFixedBinning() const {
  jboolean r = env->CallBooleanMethod(ref, isFixedBinningOCZMethod);
  JNIUtil::checkExceptions(env);
  return r;
}

JNIEXPORT double JIAxis::lowerEdge() const {
  jdouble r = env->CallDoubleMethod(ref, lowerEdgeOCDMethod);
  JNIUtil::checkExceptions(env);
  return r;
}

JNIEXPORT double JIAxis::upperEdge() const {
  jdouble r = env->CallDoubleMethod(ref, upperEdgeOCDMethod);
  JNIUtil::checkExceptions(env);
  return r;
}

JNIEXPORT int JIAxis::bins() const {
  jint r = env->CallIntMethod(ref,binsOCIMethod);
  JNIUtil::checkExceptions(env);
  return r;
}

JNIEXPORT double JIAxis::binLowerEdge(int index) const {
  jdouble r = env->CallDoubleMethod(ref, binLowerEdgeOICDMethod, index);
  JNIUtil::checkExceptions(env);
  return r;
}

JNIEXPORT double JIAxis::binUpperEdge(int index) const {
  jdouble r = env->CallDoubleMethod(ref, binUpperEdgeOICDMethod, index);
  JNIUtil::checkExceptions(env);
  return r;
}

JNIEXPORT double JIAxis::binWidth(int index) const {
  jdouble r = env->CallDoubleMethod(ref, binWidthOICDMethod, index);
  JNIUtil::checkExceptions(env);
  return r;
}

JNIEXPORT int JIAxis::coordToIndex(double coord) const {
  jint r = env->CallIntMethod(ref, coordToIndexODCIMethod,coord);
  JNIUtil::checkExceptions(env);
  return r;
}
