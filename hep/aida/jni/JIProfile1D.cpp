
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "AIDA/IAxis.h"
#include "AIDA/IProfile1D.h"
#include "JIAxis.h"
#include "JIProfile.h"
#include "JIProfile1D.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;

JNIEXPORT JIProfile1D::JIProfile1D(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIProfile(jnienv, object, factory), JIManagedObject(jnienv, object),
        iXaxis(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    binHeightOICDMethod = env->GetMethodID(cls, "binHeight", "(I)D");
    if (binHeightOICDMethod == NULL) {
        std::cerr << "IProfile1D" << ": Could not find method: " << "binHeight" << "(I)D" << std::endl;
    }

    coordToIndexODCIMethod = env->GetMethodID(cls, "coordToIndex", "(D)I");
    if (coordToIndexODCIMethod == NULL) {
        std::cerr << "IProfile1D" << ": Could not find method: " << "coordToIndex" << "(D)I" << std::endl;
    }

    rmsOCDMethod = env->GetMethodID(cls, "rms", "()D");
    if (rmsOCDMethod == NULL) {
        std::cerr << "IProfile1D" << ": Could not find method: " << "rms" << "()D" << std::endl;
    }

    binRmsOICDMethod = env->GetMethodID(cls, "binRms", "(I)D");
    if (binRmsOICDMethod == NULL) {
        std::cerr << "IProfile1D" << ": Could not find method: " << "binRms" << "(I)D" << std::endl;
    }

    meanOCDMethod = env->GetMethodID(cls, "mean", "()D");
    if (meanOCDMethod == NULL) {
        std::cerr << "IProfile1D" << ": Could not find method: " << "mean" << "()D" << std::endl;
    }

    axisOCLhep_aida_IAxisEMethod = env->GetMethodID(cls, "axis", "()Lhep/aida/IAxis;");
    if (axisOCLhep_aida_IAxisEMethod == NULL) {
        std::cerr << "IProfile1D" << ": Could not find method: " << "axis" << "()Lhep/aida/IAxis;" << std::endl;
    }

    binErrorOICDMethod = env->GetMethodID(cls, "binError", "(I)D");
    if (binErrorOICDMethod == NULL) {
        std::cerr << "IProfile1D" << ": Could not find method: " << "binError" << "(I)D" << std::endl;
    }

    fillODDDCVMethod = env->GetMethodID(cls, "fill", "(DDD)V");
    if (fillODDDCVMethod == NULL) {
        std::cerr << "IProfile1D" << ": Could not find method: " << "fill" << "(DDD)V" << std::endl;
    }

    addOLhep_aida_IProfile1DECVMethod = env->GetMethodID(cls, "add", "(Lhep/aida/IProfile1D;)V");
    if (addOLhep_aida_IProfile1DECVMethod == NULL) {
        std::cerr << "IProfile1D" << ": Could not find method: " << "add" << "(Lhep/aida/IProfile1D;)V" << std::endl;
    }

    binEntriesOICIMethod = env->GetMethodID(cls, "binEntries", "(I)I");
    if (binEntriesOICIMethod == NULL) {
        std::cerr << "IProfile1D" << ": Could not find method: " << "binEntries" << "(I)I" << std::endl;
    }

    binMeanOICDMethod = env->GetMethodID(cls, "binMean", "(I)D");
    if (binMeanOICDMethod == NULL) {
        std::cerr << "IProfile1D" << ": Could not find method: " << "binMean" << "(I)D" << std::endl;
    }
}

JNIEXPORT JIProfile1D::~JIProfile1D() {
    delete iXaxis;
}

JNIEXPORT bool JIProfile1D::fill(double x, double y, double weight) {
	env->CallVoidMethod(ref, fillODDDCVMethod, x, y, weight);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT double JIProfile1D::binMean(int index) const {
	jdouble r = env->CallDoubleMethod(ref, binMeanOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIProfile1D::binEntries(int index) const {
	jint r = env->CallIntMethod(ref, binEntriesOICIMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile1D::binHeight(int index) const {
	jdouble r = env->CallDoubleMethod(ref, binHeightOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile1D::binError(int index) const {
	jdouble r = env->CallDoubleMethod(ref, binErrorOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile1D::binRms(int index) const {
	jdouble r = env->CallDoubleMethod(ref, binRmsOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile1D::mean() const {
 	jdouble r = env->CallDoubleMethod(ref, meanOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile1D::rms() const {
	jdouble r = env->CallDoubleMethod(ref, rmsOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT const IAxis & JIProfile1D::axis() const {
    if (iXaxis == NULL) {
        jobject axis = env->CallObjectMethod(ref, axisOCLhep_aida_IAxisEMethod);
        iXaxis = factory->createIAxis(env, axis);
    }
    return *iXaxis;
}

JNIEXPORT int JIProfile1D::coordToIndex(double coord) const {
	jint r = env->CallIntMethod(ref, coordToIndexODCIMethod, coord);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT bool JIProfile1D::add(const IProfile1D & profile) {
    jobject jprofile = factory->create(env, profile);
    env->CallVoidMethod(ref, addOLhep_aida_IProfile1DECVMethod, jprofile);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT void * JIProfile1D::cast(const std::string & className) const {
    return (className == "AIDA::IProfile1D") ? (void *)this : NULL;
}
