
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "AIDA/IAxis.h"
#include "AIDA/IHistogram1D.h"
#include "JIAxis.h"
#include "JIHistogram.h"
#include "JIHistogram1D.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIHistogram1D::JIHistogram1D(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIHistogram(jnienv, object, factory), JIManagedObject(jnienv, object),
        iXaxis(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    binHeightOICDMethod = env->GetMethodID(cls, "binHeight", "(I)D");
    if (binHeightOICDMethod == NULL) {
        std::cerr << "IHistogram1D" << ": Could not find method: " << "binHeight" << "(I)D" << std::endl;
    }

    coordToIndexODCIMethod = env->GetMethodID(cls, "coordToIndex", "(D)I");
    if (coordToIndexODCIMethod == NULL) {
        std::cerr << "IHistogram1D" << ": Could not find method: " << "coordToIndex" << "(D)I" << std::endl;
    }

    rmsOCDMethod = env->GetMethodID(cls, "rms", "()D");
    if (rmsOCDMethod == NULL) {
        std::cerr << "IHistogram1D" << ": Could not find method: " << "rms" << "()D" << std::endl;
    }

    meanOCDMethod = env->GetMethodID(cls, "mean", "()D");
    if (meanOCDMethod == NULL) {
        std::cerr << "IHistogram1D" << ": Could not find method: " << "mean" << "()D" << std::endl;
    }

    axisOCLhep_aida_IAxisEMethod = env->GetMethodID(cls, "axis", "()Lhep/aida/IAxis;");
    if (axisOCLhep_aida_IAxisEMethod == NULL) {
        std::cerr << "IHistogram1D" << ": Could not find method: " << "axis" << "()Lhep/aida/IAxis;" << std::endl;
    }

    binErrorOICDMethod = env->GetMethodID(cls, "binError", "(I)D");
    if (binErrorOICDMethod == NULL) {
        std::cerr << "IHistogram1D" << ": Could not find method: " << "binError" << "(I)D" << std::endl;
    }

    binEntriesOICIMethod = env->GetMethodID(cls, "binEntries", "(I)I");
    if (binEntriesOICIMethod == NULL) {
        std::cerr << "IHistogram1D" << ": Could not find method: " << "binEntries" << "(I)I" << std::endl;
    }

    binMeanOICDMethod = env->GetMethodID(cls, "binMean", "(I)D");
    if (binMeanOICDMethod == NULL) {
        std::cerr << "IHistogram1D" << ": Could not find method: " << "binMean" << "(I)D" << std::endl;
    }

    addOLhep_aida_IHistogram1DECVMethod = env->GetMethodID(cls, "add", "(Lhep/aida/IHistogram1D;)V");
    if (addOLhep_aida_IHistogram1DECVMethod == NULL) {
        std::cerr << "IHistogram1D" << ": Could not find method: " << "add" << "(Lhep/aida/IHistogram1D;)V" << std::endl;
    }

    fillODDCVMethod = env->GetMethodID(cls, "fill", "(DD)V");
    if (fillODDCVMethod == NULL) {
        std::cerr << "IHistogram1D" << ": Could not find method: " << "fill" << "(DD)V" << std::endl;
    }
}

JNIEXPORT JIHistogram1D::~JIHistogram1D() {
   delete iXaxis;
}

JNIEXPORT bool JIHistogram1D::fill(double x, double weight) {
	env->CallVoidMethod(ref, fillODDCVMethod, x, weight);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT double JIHistogram1D::binMean(int index) const {
	jdouble r = env->CallDoubleMethod(ref, binMeanOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIHistogram1D::binEntries(int index) const {
	jint r = env->CallIntMethod(ref, binEntriesOICIMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram1D::binHeight(int index) const {
	jdouble r = env->CallDoubleMethod(ref, binHeightOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram1D::binError(int index) const {
	jdouble r = env->CallDoubleMethod(ref, binErrorOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram1D::mean() const {
	jdouble r = env->CallDoubleMethod(ref, meanOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram1D::rms() const {
	jdouble r = env->CallDoubleMethod(ref, rmsOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT const IAxis & JIHistogram1D::axis() const {
    if (iXaxis == NULL) {
        jobject axis = env->CallObjectMethod(ref, axisOCLhep_aida_IAxisEMethod);
        iXaxis = factory->createIAxis(env, axis);
    }
    return *iXaxis;
}

JNIEXPORT int JIHistogram1D::coordToIndex(double coord) const {
	jint r = env->CallIntMethod(ref, coordToIndexODCIMethod, coord);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT bool JIHistogram1D::add(const IHistogram1D & hist) {
    jobject jhistogram = factory->create(env, hist);
    if (jhistogram == NULL) return true;
    
    env->CallVoidMethod(ref, addOLhep_aida_IHistogram1DECVMethod, jhistogram);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT void * JIHistogram1D::cast(const std::string & className) const {
    return (className == "AIDA::IHistogram1D") ? (void *)this : NULL;
}
