
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "JIBaseHistogram.h"
#include "JIHistogram.h"
#include "JNIUtil.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JIHistogram::JIHistogram(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIBaseHistogram(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    equivalentBinEntriesOCDMethod = env->GetMethodID(cls, "equivalentBinEntries", "()D");
    if (equivalentBinEntriesOCDMethod == NULL) {
        std::cerr << "IHistogram" << ": Could not find method: " << "equivalentBinEntries" << "()D" << std::endl;
    }

    sumExtraBinHeightsOCDMethod = env->GetMethodID(cls, "sumExtraBinHeights", "()D");
    if (sumExtraBinHeightsOCDMethod == NULL) {
        std::cerr << "IHistogram" << ": Could not find method: " << "sumExtraBinHeights" << "()D" << std::endl;
    }

    allEntriesOCIMethod = env->GetMethodID(cls, "allEntries", "()I");
    if (allEntriesOCIMethod == NULL) {
        std::cerr << "IHistogram" << ": Could not find method: " << "allEntries" << "()I" << std::endl;
    }

    maxBinHeightOCDMethod = env->GetMethodID(cls, "maxBinHeight", "()D");
    if (maxBinHeightOCDMethod == NULL) {
        std::cerr << "IHistogram" << ": Could not find method: " << "maxBinHeight" << "()D" << std::endl;
    }

    minBinHeightOCDMethod = env->GetMethodID(cls, "minBinHeight", "()D");
    if (minBinHeightOCDMethod == NULL) {
        std::cerr << "IHistogram" << ": Could not find method: " << "minBinHeight" << "()D" << std::endl;
    }

    sumBinHeightsOCDMethod = env->GetMethodID(cls, "sumBinHeights", "()D");
    if (sumBinHeightsOCDMethod == NULL) {
        std::cerr << "IHistogram" << ": Could not find method: " << "sumBinHeights" << "()D" << std::endl;
    }

    extraEntriesOCIMethod = env->GetMethodID(cls, "extraEntries", "()I");
    if (extraEntriesOCIMethod == NULL) {
        std::cerr << "IHistogram" << ": Could not find method: " << "extraEntries" << "()I" << std::endl;
    }

    scaleODCVMethod = env->GetMethodID(cls, "scale", "(D)V");
    if (scaleODCVMethod == NULL) {
        std::cerr << "IHistogram" << ": Could not find method: " << "scale" << "(D)V" << std::endl;
    }

    sumAllBinHeightsOCDMethod = env->GetMethodID(cls, "sumAllBinHeights", "()D");
    if (sumAllBinHeightsOCDMethod == NULL) {
        std::cerr << "IHistogram" << ": Could not find method: " << "sumAllBinHeights" << "()D" << std::endl;
    }

}

JNIEXPORT JIHistogram::~JIHistogram() {
}

JNIEXPORT int JIHistogram::allEntries() const {
	jint r = env->CallIntMethod(ref,allEntriesOCIMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIHistogram::extraEntries() const {
	jint r = env->CallIntMethod(ref,extraEntriesOCIMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram::equivalentBinEntries() const {
	jdouble r = env->CallDoubleMethod(ref,equivalentBinEntriesOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram::sumBinHeights() const {
	jdouble r = env->CallDoubleMethod(ref, sumBinHeightsOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram::sumAllBinHeights() const {
	jdouble r = env->CallDoubleMethod(ref, sumAllBinHeightsOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram::sumExtraBinHeights() const {
	jdouble r = env->CallDoubleMethod(ref, sumExtraBinHeightsOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram::minBinHeight() const {
	jdouble r = env->CallDoubleMethod(ref, minBinHeightOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram::maxBinHeight() const {
	jdouble r = env->CallDoubleMethod(ref, maxBinHeightOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT bool JIHistogram::scale(double scaleFactor) {
	env->CallVoidMethod(ref, scaleODCVMethod, scaleFactor);
	return !JNIUtil::exceptions(env);
}
