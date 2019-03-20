
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "JIBaseHistogram.h"
#include "JICloud.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JICloud::JICloud(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIBaseHistogram(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    sumOfWeightsOCDMethod = env->GetMethodID(cls, "sumOfWeights", "()D");
    if (sumOfWeightsOCDMethod == NULL) {
        std::cerr << "ICloud" << ": Could not find method: " << "sumOfWeights" << "()D" << std::endl;
    }

    scaleODCVMethod = env->GetMethodID(cls, "scale", "(D)V");
    if (scaleODCVMethod == NULL) {
        std::cerr << "ICloud" << ": Could not find method: " << "scale" << "(D)V" << std::endl;
    }

    isConvertedOCZMethod = env->GetMethodID(cls, "isConverted", "()Z");
    if (isConvertedOCZMethod == NULL) {
        std::cerr << "ICloud" << ": Could not find method: " << "isConverted" << "()Z" << std::endl;
    }

    maxEntriesOCIMethod = env->GetMethodID(cls, "maxEntries", "()I");
    if (maxEntriesOCIMethod == NULL) {
        std::cerr << "ICloud" << ": Could not find method: " << "maxEntries" << "()I" << std::endl;
    }

    convertToHistogramOCVMethod = env->GetMethodID(cls, "convertToHistogram", "()V");
    if (convertToHistogramOCVMethod == NULL) {
        std::cerr << "ICloud" << ": Could not find method: " << "convertToHistogram" << "()V" << std::endl;
    }

}

JNIEXPORT JICloud::~JICloud() {
}

JNIEXPORT double JICloud::sumOfWeights() const {
    jdouble r = env->CallDoubleMethod(ref, sumOfWeightsOCDMethod);
    JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT bool JICloud::convertToHistogram() {
    env->CallVoidMethod(ref, convertToHistogramOCVMethod);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JICloud::isConverted() const {
    jboolean r = env->CallBooleanMethod(ref, isConvertedOCZMethod);
    JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT int JICloud::maxEntries() const {
    jint r = env->CallIntMethod(ref, maxEntriesOCIMethod);
    JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT bool JICloud::scale(double scaleFactor) {
    env->CallVoidMethod(ref, scaleODCVMethod, scaleFactor);
    return !JNIUtil::exceptions(env);
}
