
#include <cstdlib>
#include <iostream>
#include <string>

#include "JIFitParameterSettings.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIFitParameterSettings::JIFitParameterSettings(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    setBoundsODDCVMethod = env->GetMethodID(cls, "setBounds", "(DD)V");
    if (setBoundsODDCVMethod == NULL) {
        std::cerr << "IFitParameterSettings" << ": Could not find method: " << "setBounds" << "(DD)V" << std::endl;
    }

    nameOCLjava_lang_StringEMethod = env->GetMethodID(cls, "name", "()Ljava/lang/String;");
    if (nameOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IFitParameterSettings" << ": Could not find method: " << "name" << "()Ljava/lang/String;" << std::endl;
    }

    setUpperBoundODCVMethod = env->GetMethodID(cls, "setUpperBound", "(D)V");
    if (setUpperBoundODCVMethod == NULL) {
        std::cerr << "IFitParameterSettings" << ": Could not find method: " << "setUpperBound" << "(D)V" << std::endl;
    }

    lowerBoundOCDMethod = env->GetMethodID(cls, "lowerBound", "()D");
    if (lowerBoundOCDMethod == NULL) {
        std::cerr << "IFitParameterSettings" << ": Could not find method: " << "lowerBound" << "()D" << std::endl;
    }

    setStepSizeODCVMethod = env->GetMethodID(cls, "setStepSize", "(D)V");
    if (setStepSizeODCVMethod == NULL) {
        std::cerr << "IFitParameterSettings" << ": Could not find method: " << "setStepSize" << "(D)V" << std::endl;
    }

    isFixedOCZMethod = env->GetMethodID(cls, "isFixed", "()Z");
    if (isFixedOCZMethod == NULL) {
        std::cerr << "IFitParameterSettings" << ": Could not find method: " << "isFixed" << "()Z" << std::endl;
    }

    isBoundOCZMethod = env->GetMethodID(cls, "isBound", "()Z");
    if (isBoundOCZMethod == NULL) {
        std::cerr << "IFitParameterSettings" << ": Could not find method: " << "isBound" << "()Z" << std::endl;
    }

    upperBoundOCDMethod = env->GetMethodID(cls, "upperBound", "()D");
    if (upperBoundOCDMethod == NULL) {
        std::cerr << "IFitParameterSettings" << ": Could not find method: " << "upperBound" << "()D" << std::endl;
    }

    setLowerBoundODCVMethod = env->GetMethodID(cls, "setLowerBound", "(D)V");
    if (setLowerBoundODCVMethod == NULL) {
        std::cerr << "IFitParameterSettings" << ": Could not find method: " << "setLowerBound" << "(D)V" << std::endl;
    }

    removeBoundsOCVMethod = env->GetMethodID(cls, "removeBounds", "()V");
    if (removeBoundsOCVMethod == NULL) {
        std::cerr << "IFitParameterSettings" << ": Could not find method: " << "removeBounds" << "()V" << std::endl;
    }

    setFixedOZCVMethod = env->GetMethodID(cls, "setFixed", "(Z)V");
    if (setFixedOZCVMethod == NULL) {
        std::cerr << "IFitParameterSettings" << ": Could not find method: " << "setFixed" << "(Z)V" << std::endl;
    }

    stepSizeOCDMethod = env->GetMethodID(cls, "stepSize", "()D");
    if (stepSizeOCDMethod == NULL) {
        std::cerr << "IFitParameterSettings" << ": Could not find method: " << "stepSize" << "()D" << std::endl;
    }

    resetOCVMethod = env->GetMethodID(cls, "reset", "()V");
    if (resetOCVMethod == NULL) {
        std::cerr << "IFitParameterSettings" << ": Could not find method: " << "reset" << "()V" << std::endl;
    }

}

JNIEXPORT JIFitParameterSettings::~JIFitParameterSettings() {
}

JNIEXPORT std::string JIFitParameterSettings::name() const {
    jstring result = (jstring)env->CallObjectMethod(ref, nameOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    JNIUtil::checkExceptions(env);
    return resultString;
}

JNIEXPORT double JIFitParameterSettings::stepSize() const {
    jdouble result = env->CallDoubleMethod(ref, stepSizeOCDMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT double JIFitParameterSettings::upperBound() const {
    jdouble result = env->CallDoubleMethod(ref, upperBoundOCDMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT double JIFitParameterSettings::lowerBound() const {
    jdouble result = env->CallDoubleMethod(ref, setLowerBoundODCVMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JIFitParameterSettings::isBound() const {
    jboolean result = env->CallBooleanMethod(ref, isBoundOCZMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JIFitParameterSettings::isFixed() const {
    jboolean result = env->CallBooleanMethod(ref, isFixedOCZMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT void JIFitParameterSettings::setStepSize(double step) {
    env->CallVoidMethod(ref, setStepSizeODCVMethod, step);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIFitParameterSettings::setBounds(double lo, double up) {
    env->CallVoidMethod(ref, setBoundsODDCVMethod, lo, up);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIFitParameterSettings::removeBounds() {
    env->CallVoidMethod(ref, removeBoundsOCVMethod);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIFitParameterSettings::setFixed(bool isFixed) {
    env->CallVoidMethod(ref, setFixedOZCVMethod, isFixed);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIFitParameterSettings::setLowerBound(double lowerBound) {
    env->CallVoidMethod(ref, setLowerBoundODCVMethod, lowerBound);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIFitParameterSettings::setUpperBound(double upperBound) {
    env->CallVoidMethod(ref, setUpperBoundODCVMethod, upperBound);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIFitParameterSettings::reset() {
    env->CallVoidMethod(ref, resetOCVMethod);
    JNIUtil::checkExceptions(env);
}
