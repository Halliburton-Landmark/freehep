
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "JIBaseHistogram.h"
#include "JIProfile.h"
#include "JNIUtil.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JIProfile::JIProfile(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIBaseHistogram(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    sumExtraBinHeightsOCDMethod = env->GetMethodID(cls, "sumExtraBinHeights", "()D");
    if (sumExtraBinHeightsOCDMethod == NULL) {
        std::cerr << "IProfile" << ": Could not find method: " << "sumExtraBinHeights" << "()D" << std::endl;
    }

    allEntriesOCIMethod = env->GetMethodID(cls, "allEntries", "()I");
    if (allEntriesOCIMethod == NULL) {
        std::cerr << "IProfile" << ": Could not find method: " << "allEntries" << "()I" << std::endl;
    }

    maxBinHeightOCDMethod = env->GetMethodID(cls, "maxBinHeight", "()D");
    if (maxBinHeightOCDMethod == NULL) {
        std::cerr << "IProfile" << ": Could not find method: " << "maxBinHeight" << "()D" << std::endl;
    }

    minBinHeightOCDMethod = env->GetMethodID(cls, "minBinHeight", "()D");
    if (minBinHeightOCDMethod == NULL) {
        std::cerr << "IProfile" << ": Could not find method: " << "minBinHeight" << "()D" << std::endl;
    }

    sumBinHeightsOCDMethod = env->GetMethodID(cls, "sumBinHeights", "()D");
    if (sumBinHeightsOCDMethod == NULL) {
        std::cerr << "IProfile" << ": Could not find method: " << "sumBinHeights" << "()D" << std::endl;
    }

    extraEntriesOCIMethod = env->GetMethodID(cls, "extraEntries", "()I");
    if (extraEntriesOCIMethod == NULL) {
        std::cerr << "IProfile" << ": Could not find method: " << "extraEntries" << "()I" << std::endl;
    }

    sumAllBinHeightsOCDMethod = env->GetMethodID(cls, "sumAllBinHeights", "()D");
    if (sumAllBinHeightsOCDMethod == NULL) {
        std::cerr << "IProfile" << ": Could not find method: " << "sumAllBinHeights" << "()D" << std::endl;
    }

}

JNIEXPORT JIProfile::~JIProfile() {
}

JNIEXPORT int JIProfile::allEntries() const {
	jint r = env->CallIntMethod(ref,allEntriesOCIMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIProfile::extraEntries() const {
	jint r = env->CallIntMethod(ref,extraEntriesOCIMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile::sumBinHeights() const {
	jdouble r = env->CallDoubleMethod(ref, sumBinHeightsOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile::sumAllBinHeights() const {
	jdouble r = env->CallDoubleMethod(ref, sumAllBinHeightsOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile::sumExtraBinHeights() const {
	jdouble r = env->CallDoubleMethod(ref, sumExtraBinHeightsOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile::minBinHeight() const {
	jdouble r = env->CallDoubleMethod(ref, minBinHeightOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile::maxBinHeight() const {
	jdouble r = env->CallDoubleMethod(ref, maxBinHeightOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}
