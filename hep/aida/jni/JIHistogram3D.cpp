
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "AIDA/IAxis.h"
#include "AIDA/IHistogram3D.h"
#include "JIAxis.h"
#include "JIHistogram.h"
#include "JIHistogram3D.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JIHistogram3D::JIHistogram3D(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIHistogram(jnienv, object, factory), JIManagedObject(jnienv, object),
        iXaxis(NULL),
        iYaxis(NULL),
        iZaxis(NULL)  {

    jclass cls = env->GetObjectClass(getRef());

    rmsZOCDMethod = env->GetMethodID(cls, "rmsZ", "()D");
    if (rmsZOCDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "rmsZ" << "()D" << std::endl;
    }

    binHeightYOICDMethod = env->GetMethodID(cls, "binHeightY", "(I)D");
    if (binHeightYOICDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "binHeightY" << "(I)D" << std::endl;
    }

    meanXOCDMethod = env->GetMethodID(cls, "meanX", "()D");
    if (meanXOCDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "meanX" << "()D" << std::endl;
    }

    binHeightOIIICDMethod = env->GetMethodID(cls, "binHeight", "(III)D");
    if (binHeightOIIICDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "binHeight" << "(III)D" << std::endl;
    }

    meanYOCDMethod = env->GetMethodID(cls, "meanY", "()D");
    if (meanYOCDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "meanY" << "()D" << std::endl;
    }

    fillODDDDCVMethod = env->GetMethodID(cls, "fill", "(DDDD)V");
    if (fillODDDDCVMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "fill" << "(DDDD)V" << std::endl;
    }

    binEntriesOIIICIMethod = env->GetMethodID(cls, "binEntries", "(III)I");
    if (binEntriesOIIICIMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "binEntries" << "(III)I" << std::endl;
    }

    addOLhep_aida_IHistogram3DECVMethod = env->GetMethodID(cls, "add", "(Lhep/aida/IHistogram3D;)V");
    if (addOLhep_aida_IHistogram3DECVMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "add" << "(Lhep/aida/IHistogram3D;)V" << std::endl;
    }

    rmsXOCDMethod = env->GetMethodID(cls, "rmsX", "()D");
    if (rmsXOCDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "rmsX" << "()D" << std::endl;
    }

    zAxisOCLhep_aida_IAxisEMethod = env->GetMethodID(cls, "zAxis", "()Lhep/aida/IAxis;");
    if (zAxisOCLhep_aida_IAxisEMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "zAxis" << "()Lhep/aida/IAxis;" << std::endl;
    }

    binHeightZOICDMethod = env->GetMethodID(cls, "binHeightZ", "(I)D");
    if (binHeightZOICDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "binHeightZ" << "(I)D" << std::endl;
    }

    yAxisOCLhep_aida_IAxisEMethod = env->GetMethodID(cls, "yAxis", "()Lhep/aida/IAxis;");
    if (yAxisOCLhep_aida_IAxisEMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "yAxis" << "()Lhep/aida/IAxis;" << std::endl;
    }

    binEntriesZOICIMethod = env->GetMethodID(cls, "binEntriesZ", "(I)I");
    if (binEntriesZOICIMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "binEntriesZ" << "(I)I" << std::endl;
    }

    xAxisOCLhep_aida_IAxisEMethod = env->GetMethodID(cls, "xAxis", "()Lhep/aida/IAxis;");
    if (xAxisOCLhep_aida_IAxisEMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "xAxis" << "()Lhep/aida/IAxis;" << std::endl;
    }

    binErrorOIIICDMethod = env->GetMethodID(cls, "binError", "(III)D");
    if (binErrorOIIICDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "binError" << "(III)D" << std::endl;
    }

    binHeightXOICDMethod = env->GetMethodID(cls, "binHeightX", "(I)D");
    if (binHeightXOICDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "binHeightX" << "(I)D" << std::endl;
    }

    binEntriesXOICIMethod = env->GetMethodID(cls, "binEntriesX", "(I)I");
    if (binEntriesXOICIMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "binEntriesX" << "(I)I" << std::endl;
    }

    rmsYOCDMethod = env->GetMethodID(cls, "rmsY", "()D");
    if (rmsYOCDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "rmsY" << "()D" << std::endl;
    }

    binMeanZOIIICDMethod = env->GetMethodID(cls, "binMeanZ", "(III)D");
    if (binMeanZOIIICDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "binMeanZ" << "(III)D" << std::endl;
    }

    coordToIndexYODCIMethod = env->GetMethodID(cls, "coordToIndexY", "(D)I");
    if (coordToIndexYODCIMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "coordToIndexY" << "(D)I" << std::endl;
    }

    coordToIndexZODCIMethod = env->GetMethodID(cls, "coordToIndexZ", "(D)I");
    if (coordToIndexZODCIMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "coordToIndexZ" << "(D)I" << std::endl;
    }

    meanZOCDMethod = env->GetMethodID(cls, "meanZ", "()D");
    if (meanZOCDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "meanZ" << "()D" << std::endl;
    }

    binEntriesYOICIMethod = env->GetMethodID(cls, "binEntriesY", "(I)I");
    if (binEntriesYOICIMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "binEntriesY" << "(I)I" << std::endl;
    }

    binMeanXOIIICDMethod = env->GetMethodID(cls, "binMeanX", "(III)D");
    if (binMeanXOIIICDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "binMeanX" << "(III)D" << std::endl;
    }

    coordToIndexXODCIMethod = env->GetMethodID(cls, "coordToIndexX", "(D)I");
    if (coordToIndexXODCIMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "coordToIndexX" << "(D)I" << std::endl;
    }

    binMeanYOIIICDMethod = env->GetMethodID(cls, "binMeanY", "(III)D");
    if (binMeanYOIIICDMethod == NULL) {
        std::cerr << "IHistogram3D" << ": Could not find method: " << "binMeanY" << "(III)D" << std::endl;
    }
}

JNIEXPORT JIHistogram3D::~JIHistogram3D() {
    delete iXaxis;
    delete iYaxis;
    delete iZaxis;
}

JNIEXPORT bool JIHistogram3D::fill(double x, double y, double z, double weight) {
	env->CallVoidMethod(ref, fillODDDDCVMethod, x, y, z, weight);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT double JIHistogram3D::binMeanX(int indexX, int indexY, int indexZ) const {
	jdouble r = env->CallDoubleMethod(ref, binMeanXOIIICDMethod, indexX, indexY, indexZ);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram3D::binMeanY(int indexX, int indexY, int indexZ) const {
	jdouble r = env->CallDoubleMethod(ref, binMeanYOIIICDMethod, indexX, indexY, indexZ);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram3D::binMeanZ(int indexX, int indexY, int indexZ) const {
	jint r = env->CallIntMethod(ref, binEntriesOIIICIMethod, indexX, indexY, indexZ);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIHistogram3D::binEntries(int indexX, int indexY, int indexZ) const {
	jint r = env->CallIntMethod(ref, binEntriesOIIICIMethod, indexX, indexY, indexZ);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIHistogram3D::binEntriesX(int index) const {
	jint r = env->CallIntMethod(ref, binEntriesXOICIMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIHistogram3D::binEntriesY(int index) const {
	jint r = env->CallIntMethod(ref, binEntriesYOICIMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIHistogram3D::binEntriesZ(int index) const {
	jint r = env->CallIntMethod(ref, binEntriesZOICIMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram3D::binHeight(int indexX, int indexY, int indexZ) const {
	jdouble r = env->CallDoubleMethod(ref, binHeightOIIICDMethod, indexX, indexY, indexZ);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram3D::binHeightX(int index) const {
	jdouble r = env->CallDoubleMethod(ref, binHeightXOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram3D::binHeightY(int index) const {
	jdouble r = env->CallDoubleMethod(ref, binHeightYOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram3D::binHeightZ(int index) const {
	jdouble r = env->CallDoubleMethod(ref, binHeightZOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram3D::binError(int indexX, int indexY, int indexZ) const {
	jdouble r = env->CallDoubleMethod(ref, binErrorOIIICDMethod, indexX, indexY, indexZ);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram3D::meanX() const {
	jdouble r = env->CallDoubleMethod(ref, meanXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram3D::meanY() const {
	jdouble r = env->CallDoubleMethod(ref, meanYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram3D::meanZ() const {
	jdouble r = env->CallDoubleMethod(ref, meanZOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram3D::rmsX() const {
	jdouble r = env->CallDoubleMethod(ref, rmsXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram3D::rmsY() const {
	jdouble r = env->CallDoubleMethod(ref, rmsYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIHistogram3D::rmsZ() const {
	jdouble r = env->CallDoubleMethod(ref, rmsZOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT const IAxis & JIHistogram3D::xAxis() const {
    if (iXaxis == NULL) {
        jobject axis = env->CallObjectMethod(ref, xAxisOCLhep_aida_IAxisEMethod);
        iXaxis = factory->createIAxis(env, axis);
    }
    return *iXaxis;
}

JNIEXPORT const IAxis & JIHistogram3D::yAxis() const {
    if (iYaxis == NULL) {
        jobject axis = env->CallObjectMethod(ref, yAxisOCLhep_aida_IAxisEMethod);
        iYaxis = factory->createIAxis(env, axis);
    }
    return *iYaxis;
}

JNIEXPORT const IAxis & JIHistogram3D::zAxis() const {
    if (iZaxis == NULL) {
        jobject axis = env->CallObjectMethod(ref, zAxisOCLhep_aida_IAxisEMethod);
        iZaxis = factory->createIAxis(env, axis);
    }
    return *iZaxis;
}

JNIEXPORT int JIHistogram3D::coordToIndexX(double coord) const {
	jint r = env->CallIntMethod(ref, coordToIndexXODCIMethod, coord);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIHistogram3D::coordToIndexY(double coord) const {
	jint r = env->CallIntMethod(ref, coordToIndexYODCIMethod, coord);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIHistogram3D::coordToIndexZ(double coord) const {
	jint r = env->CallIntMethod(ref, coordToIndexZODCIMethod, coord);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT bool JIHistogram3D::add(const IHistogram3D & hist) {
    jobject jhistogram = factory->create(env, hist);
    env->CallVoidMethod(ref, addOLhep_aida_IHistogram3DECVMethod, jhistogram);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT void * JIHistogram3D::cast(const std::string & className) const {
    return (className == "AIDA::IHistogram3D") ? (void *)this : NULL;
}
