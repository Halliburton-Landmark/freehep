
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <vector>

#include "AIDA/IHistogram2D.h"
#include "JICloud.h"
#include "JICloud2D.h"
#include "JIHistogram2D.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JICloud2D::JICloud2D(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JICloud(jnienv, object, factory), JIManagedObject(jnienv, object)  {
    jclass cls = env->GetObjectClass(getRef());

    convertOADADCVMethod = env->GetMethodID(cls, "convert", "([D[D)V");
    if (convertOADADCVMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "convert" << "([D[D)V" << std::endl;
    }

    lowerEdgeYOCDMethod = env->GetMethodID(cls, "lowerEdgeY", "()D");
    if (lowerEdgeYOCDMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "lowerEdgeY" << "()D" << std::endl;
    }

    rmsXOCDMethod = env->GetMethodID(cls, "rmsX", "()D");
    if (rmsXOCDMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "rmsX" << "()D" << std::endl;
    }

    upperEdgeXOCDMethod = env->GetMethodID(cls, "upperEdgeX", "()D");
    if (upperEdgeXOCDMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "upperEdgeX" << "()D" << std::endl;
    }

    histogramOCLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "histogram", "()Lhep/aida/IHistogram2D;");
    if (histogramOCLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "histogram" << "()Lhep/aida/IHistogram2D;" << std::endl;
    }

    meanXOCDMethod = env->GetMethodID(cls, "meanX", "()D");
    if (meanXOCDMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "meanX" << "()D" << std::endl;
    }

    convertOIDDIDDCVMethod = env->GetMethodID(cls, "convert", "(IDDIDD)V");
    if (convertOIDDIDDCVMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "convert" << "(IDDIDD)V" << std::endl;
    }

    fillODDDCVMethod = env->GetMethodID(cls, "fill", "(DDD)V");
    if (fillODDDCVMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "fill" << "(DDD)V" << std::endl;
    }

    valueXOICDMethod = env->GetMethodID(cls, "valueX", "(I)D");
    if (valueXOICDMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "valueX" << "(I)D" << std::endl;
    }

    rmsYOCDMethod = env->GetMethodID(cls, "rmsY", "()D");
    if (rmsYOCDMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "rmsY" << "()D" << std::endl;
    }

    meanYOCDMethod = env->GetMethodID(cls, "meanY", "()D");
    if (meanYOCDMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "meanY" << "()D" << std::endl;
    }

    weightOICDMethod = env->GetMethodID(cls, "weight", "(I)D");
    if (weightOICDMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "weight" << "(I)D" << std::endl;
    }

    valueYOICDMethod = env->GetMethodID(cls, "valueY", "(I)D");
    if (valueYOICDMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "valueY" << "(I)D" << std::endl;
    }

    upperEdgeYOCDMethod = env->GetMethodID(cls, "upperEdgeY", "()D");
    if (upperEdgeYOCDMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "upperEdgeY" << "()D" << std::endl;
    }

    lowerEdgeXOCDMethod = env->GetMethodID(cls, "lowerEdgeX", "()D");
    if (lowerEdgeXOCDMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "lowerEdgeX" << "()D" << std::endl;
    }

    fillHistogramOLhep_aida_IHistogram2DECVMethod = env->GetMethodID(cls, "fillHistogram", "(Lhep/aida/IHistogram2D;)V");
    if (fillHistogramOLhep_aida_IHistogram2DECVMethod == NULL) {
        std::cerr << "ICloud2D" << ": Could not find method: " << "fillHistogram" << "(Lhep/aida/IHistogram2D;)V" << std::endl;
    }

}

JNIEXPORT JICloud2D::~JICloud2D() {
}

JNIEXPORT bool JICloud2D::fill(double x, double y, double weight) {
	env->CallVoidMethod(ref, fillODDDCVMethod, x, y, weight);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT double JICloud2D::lowerEdgeX() const {
	jdouble r = env->CallDoubleMethod(ref, lowerEdgeXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud2D::lowerEdgeY() const {
	jdouble r = env->CallDoubleMethod(ref, lowerEdgeYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud2D::upperEdgeX() const {
	jdouble r = env->CallDoubleMethod(ref, upperEdgeXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud2D::upperEdgeY() const {
	jdouble r = env->CallDoubleMethod(ref, upperEdgeYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud2D::valueX(int index) const {
	jdouble r = env->CallDoubleMethod(ref, valueXOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud2D::valueY(int index) const {
	jdouble r = env->CallDoubleMethod(ref, valueYOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud2D::weight(int index) const {
	jdouble r = env->CallDoubleMethod(ref, weightOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud2D::meanX() const {
	jdouble r = env->CallDoubleMethod(ref, meanXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud2D::meanY() const {
	jdouble r = env->CallDoubleMethod(ref, meanYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud2D::rmsX() const {
	jdouble r = env->CallDoubleMethod(ref, rmsXOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud2D::rmsY() const {
	jdouble r = env->CallDoubleMethod(ref, rmsYOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT bool JICloud2D::convert(int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY) {
	env->CallVoidMethod(ref, convertOIDDIDDCVMethod, nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JICloud2D::convert(const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY) {
    jdoubleArray jbinEdgesX, jbinEdgesY;
    NEWDOUBLEARRAY(jbinEdgesX, binEdgesX)
    NEWDOUBLEARRAY(jbinEdgesY, binEdgesY)
	env->CallVoidMethod(ref, convertOADADCVMethod, jbinEdgesX, jbinEdgesY);
	DELDOUBLEARRAY(jbinEdgesX)
	DELDOUBLEARRAY(jbinEdgesY)
	return !JNIUtil::exceptions(env);
}

JNIEXPORT const IHistogram2D & JICloud2D::histogram() const {
	jobject r = env->CallObjectMethod(ref, histogramOCLhep_aida_IHistogram2DEMethod);
	JNIUtil::checkExceptions(env);
	IHistogram2D* result = factory->createIHistogram2D(env, r);
	return *result;
}

JNIEXPORT bool JICloud2D::fillHistogram(IHistogram2D & hist) const {
	jobject jhist = factory->create(env, hist);
	env->CallVoidMethod(ref, fillHistogramOLhep_aida_IHistogram2DECVMethod, jhist);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT void * JICloud2D::cast(const std::string & className) const {
    return (className == "AIDA::ICloud2D") ? (void *)this : NULL;
}
