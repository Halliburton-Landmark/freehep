
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <vector>

#include "AIDA/IHistogram3D.h"
#include "JICloud.h"
#include "JICloud3D.h"
#include "JIHistogram3D.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JICloud3D::JICloud3D(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JICloud(jnienv, object, factory), JIManagedObject(jnienv, object)  {
    jclass cls = env->GetObjectClass(getRef());

    rmsZOCDMethod = env->GetMethodID(cls, "rmsZ", "()D");
    if (rmsZOCDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "rmsZ" << "()D" << std::endl;
    }

    upperEdgeZOCDMethod = env->GetMethodID(cls, "upperEdgeZ", "()D");
    if (upperEdgeZOCDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "upperEdgeZ" << "()D" << std::endl;
    }

    histogramOCLhep_aida_IHistogram3DEMethod = env->GetMethodID(cls, "histogram", "()Lhep/aida/IHistogram3D;");
    if (histogramOCLhep_aida_IHistogram3DEMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "histogram" << "()Lhep/aida/IHistogram3D;" << std::endl;
    }

    lowerEdgeYOCDMethod = env->GetMethodID(cls, "lowerEdgeY", "()D");
    if (lowerEdgeYOCDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "lowerEdgeY" << "()D" << std::endl;
    }

    valueZOICDMethod = env->GetMethodID(cls, "valueZ", "(I)D");
    if (valueZOICDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "valueZ" << "(I)D" << std::endl;
    }

    meanXOCDMethod = env->GetMethodID(cls, "meanX", "()D");
    if (meanXOCDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "meanX" << "()D" << std::endl;
    }

    fillHistogramOLhep_aida_IHistogram3DECVMethod = env->GetMethodID(cls, "fillHistogram", "(Lhep/aida/IHistogram3D;)V");
    if (fillHistogramOLhep_aida_IHistogram3DECVMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "fillHistogram" << "(Lhep/aida/IHistogram3D;)V" << std::endl;
    }

    meanYOCDMethod = env->GetMethodID(cls, "meanY", "()D");
    if (meanYOCDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "meanY" << "()D" << std::endl;
    }

    rmsYOCDMethod = env->GetMethodID(cls, "rmsY", "()D");
    if (rmsYOCDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "rmsY" << "()D" << std::endl;
    }

    fillODDDDCVMethod = env->GetMethodID(cls, "fill", "(DDDD)V");
    if (fillODDDDCVMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "fill" << "(DDDD)V" << std::endl;
    }

    meanZOCDMethod = env->GetMethodID(cls, "meanZ", "()D");
    if (meanZOCDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "meanZ" << "()D" << std::endl;
    }

    convertOIDDIDDIDDCVMethod = env->GetMethodID(cls, "convert", "(IDDIDDIDD)V");
    if (convertOIDDIDDIDDCVMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "convert" << "(IDDIDDIDD)V" << std::endl;
    }

    lowerEdgeZOCDMethod = env->GetMethodID(cls, "lowerEdgeZ", "()D");
    if (lowerEdgeZOCDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "lowerEdgeZ" << "()D" << std::endl;
    }

    upperEdgeXOCDMethod = env->GetMethodID(cls, "upperEdgeX", "()D");
    if (upperEdgeXOCDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "upperEdgeX" << "()D" << std::endl;
    }

    rmsXOCDMethod = env->GetMethodID(cls, "rmsX", "()D");
    if (rmsXOCDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "rmsX" << "()D" << std::endl;
    }

    valueXOICDMethod = env->GetMethodID(cls, "valueX", "(I)D");
    if (valueXOICDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "valueX" << "(I)D" << std::endl;
    }

    upperEdgeYOCDMethod = env->GetMethodID(cls, "upperEdgeY", "()D");
    if (upperEdgeYOCDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "upperEdgeY" << "()D" << std::endl;
    }

    valueYOICDMethod = env->GetMethodID(cls, "valueY", "(I)D");
    if (valueYOICDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "valueY" << "(I)D" << std::endl;
    }

    weightOICDMethod = env->GetMethodID(cls, "weight", "(I)D");
    if (weightOICDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "weight" << "(I)D" << std::endl;
    }

    convertOADADADCVMethod = env->GetMethodID(cls, "convert", "([D[D[D)V");
    if (convertOADADADCVMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "convert" << "([D[D[D)V" << std::endl;
    }

    lowerEdgeXOCDMethod = env->GetMethodID(cls, "lowerEdgeX", "()D");
    if (lowerEdgeXOCDMethod == NULL) {
        std::cerr << "ICloud3D" << ": Could not find method: " << "lowerEdgeX" << "()D" << std::endl;
    }

}

JNIEXPORT JICloud3D::~JICloud3D() {
}

JNIEXPORT bool JICloud3D::fill(double x, double y, double z, double weight) {
	env->CallVoidMethod(ref, fillODDDDCVMethod, x, y, z, weight);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT double JICloud3D::lowerEdgeX() const {
	jdouble r = env->CallDoubleMethod(ref, lowerEdgeXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::lowerEdgeY() const {
	jdouble r = env->CallDoubleMethod(ref, lowerEdgeYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::lowerEdgeZ() const {
	jdouble r = env->CallDoubleMethod(ref, lowerEdgeZOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::upperEdgeX() const {
	jdouble r = env->CallDoubleMethod(ref, upperEdgeXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::upperEdgeY() const {
	jdouble r = env->CallDoubleMethod(ref, upperEdgeYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::upperEdgeZ() const {
	jdouble r = env->CallDoubleMethod(ref, upperEdgeZOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::valueX(int index) const {
	jdouble r = env->CallDoubleMethod(ref, valueXOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::valueY(int index) const {
	jdouble r = env->CallDoubleMethod(ref, valueYOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::valueZ(int index) const {
	jdouble r = env->CallDoubleMethod(ref, valueZOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::weight(int index) const {
	jdouble r = env->CallDoubleMethod(ref, weightOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::meanX() const {
	jdouble r = env->CallDoubleMethod(ref, meanXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::meanY() const {
	jdouble r = env->CallDoubleMethod(ref, meanYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::meanZ() const {
	jdouble r = env->CallDoubleMethod(ref, meanZOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::rmsX() const {
	jdouble r = env->CallDoubleMethod(ref, rmsXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::rmsY() const {
	jdouble r = env->CallDoubleMethod(ref, rmsYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud3D::rmsZ() const {
	jdouble r = env->CallDoubleMethod(ref, rmsZOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT bool JICloud3D::convert(int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, int nBinsZ, double lowerEdgeZ, double upperEdgeZ) {
	env->CallVoidMethod(ref, convertOIDDIDDIDDCVMethod, nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY, nBinsZ, lowerEdgeZ, upperEdgeZ);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JICloud3D::convert(const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, const std::vector<double>  & binEdgesZ) {
    jdoubleArray jbinEdgesX, jbinEdgesY,jbinEdgesZ;
    NEWDOUBLEARRAY(jbinEdgesX, binEdgesX)
    NEWDOUBLEARRAY(jbinEdgesY, binEdgesY)
    NEWDOUBLEARRAY(jbinEdgesZ, binEdgesZ)
	env->CallVoidMethod(ref, convertOADADADCVMethod, jbinEdgesX, jbinEdgesY, jbinEdgesZ);
	DELDOUBLEARRAY(jbinEdgesX)
	DELDOUBLEARRAY(jbinEdgesY)
	DELDOUBLEARRAY(jbinEdgesZ)
	return !JNIUtil::exceptions(env);
}

JNIEXPORT const IHistogram3D & JICloud3D::histogram() const {
	jobject r = env->CallObjectMethod(ref, histogramOCLhep_aida_IHistogram3DEMethod);
	JNIUtil::checkExceptions(env);
	IHistogram3D* result = factory->createIHistogram3D(env, r);
	return *result;
}

JNIEXPORT bool JICloud3D::fillHistogram(IHistogram3D & hist) const {
	jobject jhist = factory->create(env, hist);
	env->CallVoidMethod(ref, fillHistogramOLhep_aida_IHistogram3DECVMethod, jhist);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT void * JICloud3D::cast(const std::string & className) const {
    return (className == "AIDA::ICloud3D") ? (void *)this : NULL;
}
