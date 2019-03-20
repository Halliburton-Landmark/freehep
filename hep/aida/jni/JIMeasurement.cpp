
#include <cstdlib>
#include <iostream>

#include "JIMeasurement.h"
#include "JNIUtil.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JIMeasurement::JIMeasurement(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    setErrorPlusODCVMethod = env->GetMethodID(cls, "setErrorPlus", "(D)V");
    if (setErrorPlusODCVMethod == NULL) {
        std::cerr << "IMeasurement" << ": Could not find method: " << "setErrorPlus" << "(D)V" << std::endl;
    }

    errorPlusOCDMethod = env->GetMethodID(cls, "errorPlus", "()D");
    if (errorPlusOCDMethod == NULL) {
        std::cerr << "IMeasurement" << ": Could not find method: " << "errorPlus" << "()D" << std::endl;
    }

    errorMinusOCDMethod = env->GetMethodID(cls, "errorMinus", "()D");
    if (errorMinusOCDMethod == NULL) {
        std::cerr << "IMeasurement" << ": Could not find method: " << "errorMinus" << "()D" << std::endl;
    }

    valueOCDMethod = env->GetMethodID(cls, "value", "()D");
    if (valueOCDMethod == NULL) {
        std::cerr << "IMeasurement" << ": Could not find method: " << "value" << "()D" << std::endl;
    }

    setErrorMinusODCVMethod = env->GetMethodID(cls, "setErrorMinus", "(D)V");
    if (setErrorMinusODCVMethod == NULL) {
        std::cerr << "IMeasurement" << ": Could not find method: " << "setErrorMinus" << "(D)V" << std::endl;
    }

    setValueODCVMethod = env->GetMethodID(cls, "setValue", "(D)V");
    if (setValueODCVMethod == NULL) {
        std::cerr << "IMeasurement" << ": Could not find method: " << "setValue" << "(D)V" << std::endl;
    }

}

JNIEXPORT JIMeasurement::~JIMeasurement() {
}

JNIEXPORT double JIMeasurement::value() const {
   jdouble r = env->CallDoubleMethod(ref, valueOCDMethod);
   JNIUtil::checkExceptions(env);
   return r;
}

JNIEXPORT double JIMeasurement::errorPlus() const {
   jdouble r = env->CallDoubleMethod(ref, errorPlusOCDMethod);
   JNIUtil::checkExceptions(env);
   return r;
}

JNIEXPORT double JIMeasurement::errorMinus() const {
   jdouble r = env->CallDoubleMethod(ref, errorMinusOCDMethod);
   JNIUtil::checkExceptions(env);
   return r;
}

JNIEXPORT bool JIMeasurement::setValue(double value) {
   env->CallVoidMethod(ref, setValueODCVMethod, value);
   if (JNIUtil::exceptions(env)) return false;
   else return true;
}

JNIEXPORT bool JIMeasurement::setErrorPlus(double errorPlus) {
   env->CallVoidMethod(ref, setErrorPlusODCVMethod, errorPlus);
   if (JNIUtil::exceptions(env)) return false;
   else return true;
}

JNIEXPORT bool JIMeasurement::setErrorMinus(double errorMinus) {
   env->CallVoidMethod(ref, setErrorMinusODCVMethod, errorMinus);
   if (JNIUtil::exceptions(env)) return false;
   else return true;
}
