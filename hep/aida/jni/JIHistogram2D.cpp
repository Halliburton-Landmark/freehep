
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "AIDA/IAxis.h"
#include "AIDA/IHistogram2D.h"
#include "JIAxis.h"
#include "JIHistogram.h"
#include "JIHistogram2D.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JIHistogram2D::JIHistogram2D(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIHistogram(jnienv, object, factory), JIManagedObject(jnienv, object),
        iXaxis(NULL),
        iYaxis(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    binMeanYOIICDMethod = env->GetMethodID(cls, "binMeanY", "(II)D");
    if (binMeanYOIICDMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "binMeanY" << "(II)D" << std::endl;
    }

    binErrorOIICDMethod = env->GetMethodID(cls, "binError", "(II)D");
    if (binErrorOIICDMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "binError" << "(II)D" << std::endl;
    }

    binHeightXOICDMethod = env->GetMethodID(cls, "binHeightX", "(I)D");
    if (binHeightXOICDMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "binHeightX" << "(I)D" << std::endl;
    }

    binHeightYOICDMethod = env->GetMethodID(cls, "binHeightY", "(I)D");
    if (binHeightYOICDMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "binHeightY" << "(I)D" << std::endl;
    }

    binEntriesXOICIMethod = env->GetMethodID(cls, "binEntriesX", "(I)I");
    if (binEntriesXOICIMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "binEntriesX" << "(I)I" << std::endl;
    }

    meanXOCDMethod = env->GetMethodID(cls, "meanX", "()D");
    if (meanXOCDMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "meanX" << "()D" << std::endl;
    }

    fillODDDCVMethod = env->GetMethodID(cls, "fill", "(DDD)V");
    if (fillODDDCVMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "fill" << "(DDD)V" << std::endl;
    }

    binMeanXOIICDMethod = env->GetMethodID(cls, "binMeanX", "(II)D");
    if (binMeanXOIICDMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "binMeanX" << "(II)D" << std::endl;
    }

    meanYOCDMethod = env->GetMethodID(cls, "meanY", "()D");
    if (meanYOCDMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "meanY" << "()D" << std::endl;
    }

    rmsYOCDMethod = env->GetMethodID(cls, "rmsY", "()D");
    if (rmsYOCDMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "rmsY" << "()D" << std::endl;
    }

    addOLhep_aida_IHistogram2DECVMethod = env->GetMethodID(cls, "add", "(Lhep/aida/IHistogram2D;)V");
    if (addOLhep_aida_IHistogram2DECVMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "add" << "(Lhep/aida/IHistogram2D;)V" << std::endl;
    }

    coordToIndexYODCIMethod = env->GetMethodID(cls, "coordToIndexY", "(D)I");
    if (coordToIndexYODCIMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "coordToIndexY" << "(D)I" << std::endl;
    }

    rmsXOCDMethod = env->GetMethodID(cls, "rmsX", "()D");
    if (rmsXOCDMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "rmsX" << "()D" << std::endl;
    }

    binEntriesYOICIMethod = env->GetMethodID(cls, "binEntriesY", "(I)I");
    if (binEntriesYOICIMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "binEntriesY" << "(I)I" << std::endl;
    }

    yAxisOCLhep_aida_IAxisEMethod = env->GetMethodID(cls, "yAxis", "()Lhep/aida/IAxis;");
    if (yAxisOCLhep_aida_IAxisEMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "yAxis" << "()Lhep/aida/IAxis;" << std::endl;
    }

    xAxisOCLhep_aida_IAxisEMethod = env->GetMethodID(cls, "xAxis", "()Lhep/aida/IAxis;");
    if (xAxisOCLhep_aida_IAxisEMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "xAxis" << "()Lhep/aida/IAxis;" << std::endl;
    }

    coordToIndexXODCIMethod = env->GetMethodID(cls, "coordToIndexX", "(D)I");
    if (coordToIndexXODCIMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "coordToIndexX" << "(D)I" << std::endl;
    }

    binEntriesOIICIMethod = env->GetMethodID(cls, "binEntries", "(II)I");
    if (binEntriesOIICIMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "binEntries" << "(II)I" << std::endl;
    }

    binHeightOIICDMethod = env->GetMethodID(cls, "binHeight", "(II)D");
    if (binHeightOIICDMethod == NULL) {
        std::cerr << "IHistogram2D" << ": Could not find method: " << "binHeight" << "(II)D" << std::endl;
    }
}

JNIEXPORT JIHistogram2D::~JIHistogram2D() {
    delete iXaxis;
    delete iYaxis;
}

JNIEXPORT bool JIHistogram2D::fill(double x, double y, double weight) {
	env->CallVoidMethod(ref, fillODDDCVMethod, x, y, weight);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT double JIHistogram2D::binMeanX(int indexX, int indexY) const {
	jdouble r = env->CallDoubleMethod(ref, binMeanXOIICDMethod, indexX, indexY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram2D::binMeanY(int indexX, int indexY) const {
	jdouble r = env->CallDoubleMethod(ref, binMeanYOIICDMethod, indexX, indexY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIHistogram2D::binEntries(int indexX, int indexY) const {
	jint r = env->CallIntMethod(ref, binEntriesOIICIMethod, indexX, indexY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIHistogram2D::binEntriesX(int index) const {
	jint r = env->CallIntMethod(ref, binEntriesXOICIMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIHistogram2D::binEntriesY(int index) const {
	jint r = env->CallIntMethod(ref, binEntriesYOICIMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram2D::binHeight(int indexX, int indexY) const {
	jdouble r = env->CallDoubleMethod(ref, binHeightOIICDMethod, indexX, indexY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram2D::binHeightX(int index) const {
	jdouble r = env->CallDoubleMethod(ref, binHeightXOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram2D::binHeightY(int index) const {
	jdouble r = env->CallDoubleMethod(ref, binHeightYOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram2D::binError(int indexX, int indexY) const {
	jdouble r = env->CallDoubleMethod(ref, binErrorOIICDMethod, indexX, indexY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram2D::meanX() const {
	jdouble r = env->CallDoubleMethod(ref, meanXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram2D::meanY() const {
	jdouble r = env->CallDoubleMethod(ref, meanYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram2D::rmsX() const {
	jdouble r = env->CallDoubleMethod(ref, rmsXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram2D::rmsY() const {
	jdouble r = env->CallDoubleMethod(ref, rmsYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT const IAxis & JIHistogram2D::xAxis() const {
    if (iXaxis == NULL) {
        jobject axis = env->CallObjectMethod(ref, xAxisOCLhep_aida_IAxisEMethod);
        iXaxis = factory->createIAxis(env, axis);
    }
    return *iXaxis;
}

JNIEXPORT const IAxis & JIHistogram2D::yAxis() const {
    if (iYaxis == NULL) {
        jobject axis = env->CallObjectMethod(ref, yAxisOCLhep_aida_IAxisEMethod);
        iYaxis = factory->createIAxis(env, axis);
    }
    return *iYaxis;
}

JNIEXPORT int JIHistogram2D::coordToIndexX(double coord) const {
	jint r = env->CallIntMethod(ref, coordToIndexXODCIMethod, coord);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIHistogram2D::coordToIndexY(double coord) const {
	jint r = env->CallIntMethod(ref, coordToIndexYODCIMethod, coord);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT bool JIHistogram2D::add(const IHistogram2D & hist) {
    jobject jhistogram = factory->create(env, hist);
    env->CallVoidMethod(ref, addOLhep_aida_IHistogram2DECVMethod, jhistogram);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT void * JIHistogram2D::cast(const std::string & className) const {
    return (className == "AIDA::IHistogram2D") ? (void *)this : NULL;
}
