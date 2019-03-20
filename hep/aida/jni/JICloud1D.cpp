
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <vector>

#include "AIDA/IHistogram1D.h"
#include "JICloud.h"
#include "JICloud1D.h"
#include "JIHistogram1D.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JICloud1D::JICloud1D(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JICloud(jnienv, object, factory), JIManagedObject(jnienv, object)  {
    jclass cls = env->GetObjectClass(getRef());

    convertOIDDCVMethod = env->GetMethodID(cls, "convert", "(IDD)V");
    if (convertOIDDCVMethod == NULL) {
        std::cerr << "ICloud1D" << ": Could not find method: " << "convert" << "(IDD)V" << std::endl;
    }

    upperEdgeOCDMethod = env->GetMethodID(cls, "upperEdge", "()D");
    if (upperEdgeOCDMethod == NULL) {
        std::cerr << "ICloud1D" << ": Could not find method: " << "upperEdge" << "()D" << std::endl;
    }

    convertOADCVMethod = env->GetMethodID(cls, "convert", "([D)V");
    if (convertOADCVMethod == NULL) {
        std::cerr << "ICloud1D" << ": Could not find method: " << "convert" << "([D)V" << std::endl;
    }

    rmsOCDMethod = env->GetMethodID(cls, "rms", "()D");
    if (rmsOCDMethod == NULL) {
        std::cerr << "ICloud1D" << ": Could not find method: " << "rms" << "()D" << std::endl;
    }

    fillHistogramOLhep_aida_IHistogram1DECVMethod = env->GetMethodID(cls, "fillHistogram", "(Lhep/aida/IHistogram1D;)V");
    if (fillHistogramOLhep_aida_IHistogram1DECVMethod == NULL) {
        std::cerr << "ICloud1D" << ": Could not find method: " << "fillHistogram" << "(Lhep/aida/IHistogram1D;)V" << std::endl;
    }

    meanOCDMethod = env->GetMethodID(cls, "mean", "()D");
    if (meanOCDMethod == NULL) {
        std::cerr << "ICloud1D" << ": Could not find method: " << "mean" << "()D" << std::endl;
    }

    valueOICDMethod = env->GetMethodID(cls, "value", "(I)D");
    if (valueOICDMethod == NULL) {
        std::cerr << "ICloud1D" << ": Could not find method: " << "value" << "(I)D" << std::endl;
    }

    weightOICDMethod = env->GetMethodID(cls, "weight", "(I)D");
    if (weightOICDMethod == NULL) {
        std::cerr << "ICloud1D" << ": Could not find method: " << "weight" << "(I)D" << std::endl;
    }

    histogramOCLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "histogram", "()Lhep/aida/IHistogram1D;");
    if (histogramOCLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "ICloud1D" << ": Could not find method: " << "histogram" << "()Lhep/aida/IHistogram1D;" << std::endl;
    }

    fillODDCVMethod = env->GetMethodID(cls, "fill", "(DD)V");
    if (fillODDCVMethod == NULL) {
        std::cerr << "ICloud1D" << ": Could not find method: " << "fill" << "(DD)V" << std::endl;
    }

    lowerEdgeOCDMethod = env->GetMethodID(cls, "lowerEdge", "()D");
    if (lowerEdgeOCDMethod == NULL) {
        std::cerr << "ICloud1D" << ": Could not find method: " << "lowerEdge" << "()D" << std::endl;
    }

}

JNIEXPORT JICloud1D::~JICloud1D() {
}

JNIEXPORT bool JICloud1D::fill(double x, double weight) {
	env->CallVoidMethod(ref, fillODDCVMethod, x, weight);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT double JICloud1D::lowerEdge() const {
	jdouble r = env->CallDoubleMethod(ref, lowerEdgeOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud1D::upperEdge() const {
	jdouble r = env->CallDoubleMethod(ref, upperEdgeOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud1D::value(int index) const {
	jdouble r = env->CallDoubleMethod(ref, valueOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud1D::weight(int index) const {
	jdouble r = env->CallDoubleMethod(ref, weightOICDMethod, index);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud1D::mean() const {
	jdouble r = env->CallDoubleMethod(ref, meanOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT double JICloud1D::rms() const {
	jdouble r = env->CallDoubleMethod(ref, rmsOCDMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT bool JICloud1D::convert(int nBins, double lowerEdge, double upperEdge) {
	env->CallVoidMethod(ref, convertOIDDCVMethod, nBins, lowerEdge, upperEdge);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JICloud1D::convert(const std::vector<double>  & binEdges) {
    jdoubleArray jbinEdges;
    NEWDOUBLEARRAY(jbinEdges, binEdges)
	env->CallVoidMethod(ref, convertOADCVMethod, jbinEdges);
	DELDOUBLEARRAY(jbinEdges)
	return !JNIUtil::exceptions(env);
}

JNIEXPORT const IHistogram1D & JICloud1D::histogram() const {
	jobject r = env->CallObjectMethod(ref, histogramOCLhep_aida_IHistogram1DEMethod);
	JNIUtil::checkExceptions(env);
	IHistogram1D* result = factory->createIHistogram1D(env, r);
	return *result;
}

JNIEXPORT bool JICloud1D::fillHistogram(IHistogram1D & hist) const {
	jobject jhist = factory->create(env, hist);
	env->CallVoidMethod(ref, fillHistogramOLhep_aida_IHistogram1DECVMethod, jhist);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT void * JICloud1D::cast(const std::string & className) const {
    return (className == "AIDA::ICloud1D") ? (void *)this : NULL;
}
