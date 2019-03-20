
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "AIDA/IAxis.h"
#include "AIDA/IProfile2D.h"
#include "JIAxis.h"
#include "JIProfile.h"
#include "JIProfile2D.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;

JNIEXPORT JIProfile2D::JIProfile2D(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIProfile(jnienv, object, factory), JIManagedObject(jnienv, object),
        iXaxis(NULL),
        iYaxis(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    binMeanYOIICDMethod = env->GetMethodID(cls, "binMeanY", "(II)D");
    if (binMeanYOIICDMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "binMeanY" << "(II)D" << std::endl;
    }

    binErrorOIICDMethod = env->GetMethodID(cls, "binError", "(II)D");
    if (binErrorOIICDMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "binError" << "(II)D" << std::endl;
    }

    binHeightXOICDMethod = env->GetMethodID(cls, "binHeightX", "(I)D");
    if (binHeightXOICDMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "binHeightX" << "(I)D" << std::endl;
    }

    binHeightYOICDMethod = env->GetMethodID(cls, "binHeightY", "(I)D");
    if (binHeightYOICDMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "binHeightY" << "(I)D" << std::endl;
    }

    binEntriesXOICIMethod = env->GetMethodID(cls, "binEntriesX", "(I)I");
    if (binEntriesXOICIMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "binEntriesX" << "(I)I" << std::endl;
    }

    meanXOCDMethod = env->GetMethodID(cls, "meanX", "()D");
    if (meanXOCDMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "meanX" << "()D" << std::endl;
    }

    binMeanXOIICDMethod = env->GetMethodID(cls, "binMeanX", "(II)D");
    if (binMeanXOIICDMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "binMeanX" << "(II)D" << std::endl;
    }

    binRmsOIICDMethod = env->GetMethodID(cls, "binRms", "(II)D");
    if (binRmsOIICDMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "binRms" << "(II)D" << std::endl;
    }

    meanYOCDMethod = env->GetMethodID(cls, "meanY", "()D");
    if (meanYOCDMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "meanY" << "()D" << std::endl;
    }

    rmsYOCDMethod = env->GetMethodID(cls, "rmsY", "()D");
    if (rmsYOCDMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "rmsY" << "()D" << std::endl;
    }

    fillODDDDCVMethod = env->GetMethodID(cls, "fill", "(DDDD)V");
    if (fillODDDDCVMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "fill" << "(DDDD)V" << std::endl;
    }

    coordToIndexYODCIMethod = env->GetMethodID(cls, "coordToIndexY", "(D)I");
    if (coordToIndexYODCIMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "coordToIndexY" << "(D)I" << std::endl;
    }

    rmsXOCDMethod = env->GetMethodID(cls, "rmsX", "()D");
    if (rmsXOCDMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "rmsX" << "()D" << std::endl;
    }

    binEntriesYOICIMethod = env->GetMethodID(cls, "binEntriesY", "(I)I");
    if (binEntriesYOICIMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "binEntriesY" << "(I)I" << std::endl;
    }

    addOLhep_aida_IProfile2DECVMethod = env->GetMethodID(cls, "add", "(Lhep/aida/IProfile2D;)V");
    if (addOLhep_aida_IProfile2DECVMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "add" << "(Lhep/aida/IProfile2D;)V" << std::endl;
    }

    yAxisOCLhep_aida_IAxisEMethod = env->GetMethodID(cls, "yAxis", "()Lhep/aida/IAxis;");
    if (yAxisOCLhep_aida_IAxisEMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "yAxis" << "()Lhep/aida/IAxis;" << std::endl;
    }

    coordToIndexXODCIMethod = env->GetMethodID(cls, "coordToIndexX", "(D)I");
    if (coordToIndexXODCIMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "coordToIndexX" << "(D)I" << std::endl;
    }

    xAxisOCLhep_aida_IAxisEMethod = env->GetMethodID(cls, "xAxis", "()Lhep/aida/IAxis;");
    if (xAxisOCLhep_aida_IAxisEMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "xAxis" << "()Lhep/aida/IAxis;" << std::endl;
    }

    binEntriesOIICIMethod = env->GetMethodID(cls, "binEntries", "(II)I");
    if (binEntriesOIICIMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "binEntries" << "(II)I" << std::endl;
    }

    binHeightOIICDMethod = env->GetMethodID(cls, "binHeight", "(II)D");
    if (binHeightOIICDMethod == NULL) {
        std::cerr << "IProfile2D" << ": Could not find method: " << "binHeight" << "(II)D" << std::endl;
    }

}

JNIEXPORT JIProfile2D::~JIProfile2D() {
    delete iXaxis;
    delete iYaxis;
}

JNIEXPORT bool JIProfile2D::fill(double x, double y, double z, double weight) {
	env->CallVoidMethod(ref, fillODDDDCVMethod, x, y, z, weight);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT double JIProfile2D::binMeanX(int indexX, int indexY) const {
	jdouble r = env->CallDoubleMethod(ref, binMeanXOIICDMethod, indexX, indexY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile2D::binMeanY(int indexX, int indexY) const {
	jdouble r = env->CallDoubleMethod(ref, binMeanYOIICDMethod, indexX, indexY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIProfile2D::binEntries(int indexX, int indexY) const {
	jint r = env->CallIntMethod(ref, binEntriesOIICIMethod, indexX, indexY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIProfile2D::binEntriesX(int indexX) const {
	jint r = env->CallIntMethod(ref, binEntriesXOICIMethod, indexX);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIProfile2D::binEntriesY(int indexY) const {
 	jint r = env->CallIntMethod(ref, binEntriesYOICIMethod, indexY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile2D::binHeight(int indexX, int indexY) const {
	jdouble r = env->CallDoubleMethod(ref, binHeightOIICDMethod, indexX, indexY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile2D::binHeightX(int indexX) const {
	jdouble r = env->CallDoubleMethod(ref, binHeightXOICDMethod, indexX);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile2D::binHeightY(int indexY) const {
	jdouble r = env->CallDoubleMethod(ref, binHeightYOICDMethod, indexY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile2D::binError(int indexX, int indexY) const {
	jdouble r = env->CallDoubleMethod(ref, binErrorOIICDMethod, indexX, indexY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile2D::binRms(int indexX, int indexY) const {
	jdouble r = env->CallDoubleMethod(ref, binRmsOIICDMethod, indexX, indexY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile2D::meanX() const {
 	jdouble r = env->CallDoubleMethod(ref, meanXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile2D::meanY() const {
 	jdouble r = env->CallDoubleMethod(ref, meanYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile2D::rmsX() const {
	jdouble r = env->CallDoubleMethod(ref, rmsXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JIProfile2D::rmsY() const {
	jdouble r = env->CallDoubleMethod(ref, rmsYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT const IAxis & JIProfile2D::xAxis() const {
    if (iXaxis == NULL) {
        jobject axis = env->CallObjectMethod(ref, xAxisOCLhep_aida_IAxisEMethod);
        iXaxis = factory->createIAxis(env, axis);
    }
    return *iXaxis;
}

JNIEXPORT const IAxis & JIProfile2D::yAxis() const {
    if (iYaxis == NULL) {
        jobject axis = env->CallObjectMethod(ref, yAxisOCLhep_aida_IAxisEMethod);
        iYaxis = factory->createIAxis(env, axis);
    }
    return *iYaxis;
}

JNIEXPORT int JIProfile2D::coordToIndexX(double coordX) const {
	jint r = env->CallIntMethod(ref, coordToIndexXODCIMethod, coordX);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT int JIProfile2D::coordToIndexY(double coordY) const {
	jint r = env->CallIntMethod(ref, coordToIndexYODCIMethod, coordY);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT bool JIProfile2D::add(const IProfile2D & profile) {
    jobject jprofile = factory->create(env, profile);
    env->CallVoidMethod(ref, addOLhep_aida_IProfile2DECVMethod, jprofile);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT void * JIProfile2D::cast(const std::string & className) const {
    return (className == "AIDA::IProfile2D") ? (void *)this : NULL;
}
