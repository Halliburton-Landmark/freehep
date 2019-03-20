
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <vector>

#include "AIDA/IRangeSet.h"
#include "JIFunction.h"
#include "JIModelFunction.h"
#include "JIRangeSet.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;

JNIEXPORT JIModelFunction::JIModelFunction(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIFunction(jnienv, object, factory),
        normalizationRangeSet(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    includeNormalizationAllOCVMethod = env->GetMethodID(cls, "includeNormalizationAll", "()V");
    if (includeNormalizationAllOCVMethod == NULL) {
        std::cerr << "IModelFunction" << ": Could not find method: " << "includeNormalizationAll" << "()V" << std::endl;
    }

    excludeNormalizationAllOCVMethod = env->GetMethodID(cls, "excludeNormalizationAll", "()V");
    if (excludeNormalizationAllOCVMethod == NULL) {
        std::cerr << "IModelFunction" << ": Could not find method: " << "excludeNormalizationAll" << "()V" << std::endl;
    }

    providesParameterGradientOCZMethod = env->GetMethodID(cls, "providesParameterGradient", "()Z");
    if (providesParameterGradientOCZMethod == NULL) {
        std::cerr << "IModelFunction" << ": Could not find method: " << "providesParameterGradient" << "()Z" << std::endl;
    }

    normalizeOZCVMethod = env->GetMethodID(cls, "normalize", "(Z)V");
    if (normalizeOZCVMethod == NULL) {
        std::cerr << "IModelFunction" << ": Could not find method: " << "normalize" << "(Z)V" << std::endl;
    }

    parameterGradientOADCADMethod = env->GetMethodID(cls, "parameterGradient", "([D)[D");
    if (parameterGradientOADCADMethod == NULL) {
        std::cerr << "IModelFunction" << ": Could not find method: " << "parameterGradient" << "([D)[D" << std::endl;
    }

    normalizationRangeOICLhep_aida_IRangeSetEMethod = env->GetMethodID(cls, "normalizationRange", "(I)Lhep/aida/IRangeSet;");
    if (normalizationRangeOICLhep_aida_IRangeSetEMethod == NULL) {
        std::cerr << "IModelFunction" << ": Could not find method: " << "normalizationRange" << "(I)Lhep/aida/IRangeSet;" << std::endl;
    }

    isNormalizedOCZMethod = env->GetMethodID(cls, "isNormalized", "()Z");
    if (isNormalizedOCZMethod == NULL) {
        std::cerr << "IModelFunction" << ": Could not find method: " << "isNormalized" << "()Z" << std::endl;
    }

    providesNormalizationOCZMethod = env->GetMethodID(cls, "providesNormalization", "()Z");
    if (providesNormalizationOCZMethod == NULL) {
        std::cerr << "IModelFunction" << ": Could not find method: " << "providesNormalization" << "()Z" << std::endl;
    }

}

JNIEXPORT JIModelFunction::~JIModelFunction() {
}

JNIEXPORT bool JIModelFunction::providesNormalization() const {
    jboolean result = env->CallBooleanMethod(ref, providesNormalizationOCZMethod);
	JNIUtil::checkExceptions(env);
	return result;
}

JNIEXPORT void JIModelFunction::normalize(bool on) {
    env->CallVoidMethod(ref, normalizeOZCVMethod, on);
	JNIUtil::checkExceptions(env);
}

JNIEXPORT bool JIModelFunction::isNormalized() const {
    jboolean result = env->CallBooleanMethod(ref, isNormalizedOCZMethod);
	JNIUtil::checkExceptions(env);
	return result;
}

JNIEXPORT const std::vector<double>  & JIModelFunction::parameterGradient(const std::vector<double>  & x) const {
    jdoubleArray jx;
    NEWDOUBLEARRAY(jx, x)
    parameterGradientVector.clear();
    // Call to Java
    jdoubleArray jresult = (jdoubleArray)env->CallObjectMethod(ref, parameterGradientOADCADMethod, jx);
    // convert double[] to vector<double>
    unsigned int len = env->GetArrayLength(jresult);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jresult, i, 1, &d);
        parameterGradientVector.push_back(d);
    }
    DELDOUBLEARRAY(jx)
    JNIUtil::checkExceptions(env);
    return parameterGradientVector;
}

JNIEXPORT bool JIModelFunction::providesParameterGradient() const {
    jboolean result = env->CallBooleanMethod(ref, providesParameterGradientOCZMethod);
	JNIUtil::checkExceptions(env);
	return result;
}

JNIEXPORT IRangeSet & JIModelFunction::normalizationRange(int iAxis) {
    jobject obj = env->CallObjectMethod(ref, normalizationRangeOICLhep_aida_IRangeSetEMethod, iAxis);
    JNIUtil::checkExceptions(env);
    normalizationRangeSet = factory->createIRangeSet(env, obj);
    return *normalizationRangeSet;
}

JNIEXPORT void JIModelFunction::includeNormalizationAll() {
    env->CallVoidMethod(ref, includeNormalizationAllOCVMethod);
	JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIModelFunction::excludeNormalizationAll() {
    env->CallVoidMethod(ref, excludeNormalizationAllOCVMethod);
	JNIUtil::checkExceptions(env);
}

JNIEXPORT void * JIModelFunction::cast(const std::string & className) const {
    return (className == "AIDA::IModelFunction") ? (void *)this : NULL;
}
