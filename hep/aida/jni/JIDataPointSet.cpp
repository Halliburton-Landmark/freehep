
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AIDA/IAnnotation.h"
#include "AIDA/IDataPoint.h"
#include "JIAnnotation.h"
#include "JIDataPointSet.h"
#include "JIDataPoint.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIDataPointSet::JIDataPointSet(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory), JIManagedObject(jnienv, object),
        iAnnotation(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    annotationOCLhep_aida_IAnnotationEMethod = env->GetMethodID(cls, "annotation", "()Lhep/aida/IAnnotation;");
    if (annotationOCLhep_aida_IAnnotationEMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "annotation" << "()Lhep/aida/IAnnotation;" << std::endl;
    }

    upperExtentOICDMethod = env->GetMethodID(cls, "upperExtent", "(I)D");
    if (upperExtentOICDMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "upperExtent" << "(I)D" << std::endl;
    }

    addPointOLhep_aida_IDataPointECVMethod = env->GetMethodID(cls, "addPoint", "(Lhep/aida/IDataPoint;)V");
    if (addPointOLhep_aida_IDataPointECVMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "addPoint" << "(Lhep/aida/IDataPoint;)V" << std::endl;
    }

    setTitleOLjava_lang_StringECVMethod = env->GetMethodID(cls, "setTitle", "(Ljava/lang/String;)V");
    if (setTitleOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "setTitle" << "(Ljava/lang/String;)V" << std::endl;
    }

    scaleODCVMethod = env->GetMethodID(cls, "scale", "(D)V");
    if (scaleODCVMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "scale" << "(D)V" << std::endl;
    }

    pointOICLhep_aida_IDataPointEMethod = env->GetMethodID(cls, "point", "(I)Lhep/aida/IDataPoint;");
    if (pointOICLhep_aida_IDataPointEMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "point" << "(I)Lhep/aida/IDataPoint;" << std::endl;
    }

    removePointOICVMethod = env->GetMethodID(cls, "removePoint", "(I)V");
    if (removePointOICVMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "removePoint" << "(I)V" << std::endl;
    }

    addPointOCVMethod = env->GetMethodID(cls, "addPoint", "()Lhep/aida/IDataPoint;");
    if (addPointOCVMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "addPoint" << "()Lhep/aida/IDataPoint;" << std::endl;
    }

    scaleErrorsODCVMethod = env->GetMethodID(cls, "scaleErrors", "(D)V");
    if (scaleErrorsODCVMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "scaleErrors" << "(D)V" << std::endl;
    }

    sizeOCIMethod = env->GetMethodID(cls, "size", "()I");
    if (sizeOCIMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "size" << "()I" << std::endl;
    }

    titleOCLjava_lang_StringEMethod = env->GetMethodID(cls, "title", "()Ljava/lang/String;");
    if (titleOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "title" << "()Ljava/lang/String;" << std::endl;
    }

    scaleValuesODCVMethod = env->GetMethodID(cls, "scaleValues", "(D)V");
    if (scaleValuesODCVMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "scaleValues" << "(D)V" << std::endl;
    }

    dimensionOCIMethod = env->GetMethodID(cls, "dimension", "()I");
    if (dimensionOCIMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "dimension" << "()I" << std::endl;
    }

    lowerExtentOICDMethod = env->GetMethodID(cls, "lowerExtent", "(I)D");
    if (lowerExtentOICDMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "lowerExtent" << "(I)D" << std::endl;
    }

    clearOCVMethod = env->GetMethodID(cls, "clear", "()V");
    if (clearOCVMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "clear" << "()V" << std::endl;
    }

    setCoordinateOIADADCZMethod = env->GetMethodID(cls, "setCoordinate", "(I[D[D)V");
    if (setCoordinateOIADADCZMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "setCoordinate" << "(I[D[D)V" << std::endl;
    }

    setCoordinateOIADADADCZMethod = env->GetMethodID(cls, "setCoordinate", "(I[D[D[D)V");
    if (setCoordinateOIADADADCZMethod == NULL) {
        std::cerr << "IDataPointSet" << ": Could not find method: " << "setCoordinate" << "(I[D[D[D)V" << std::endl;
    }
}

JNIEXPORT JIDataPointSet::~JIDataPointSet() {
    delete iAnnotation;
}

JNIEXPORT IAnnotation & JIDataPointSet::annotation() {
    if (iAnnotation == NULL) {
        jobject annotation = env->CallObjectMethod(ref, annotationOCLhep_aida_IAnnotationEMethod);
        iAnnotation = factory->createIAnnotation(env, annotation);
    }
    return *iAnnotation;
}

JNIEXPORT const IAnnotation & JIDataPointSet::annotation() const {
    if (iAnnotation == NULL) {
        jobject annotation = env->CallObjectMethod(ref, annotationOCLhep_aida_IAnnotationEMethod);
        iAnnotation = factory->createIAnnotation(env, annotation);
    }
    return *iAnnotation;
}

JNIEXPORT std::string JIDataPointSet::title() const {
    // Call to Java
    jstring jtitle = (jstring)env->CallObjectMethod(ref, titleOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(jtitle, &isCopy);
    string titleString = utf;
    if (isCopy) env->ReleaseStringUTFChars(jtitle, utf);
    return titleString;
}

JNIEXPORT bool JIDataPointSet::setTitle(const std::string & title) {
    jstring jtitle;
    NEWSTRING(jtitle, title)
    env->CallVoidMethod(ref, setTitleOLjava_lang_StringECVMethod, jtitle);
    DELSTRING(jtitle)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT int JIDataPointSet::dimension() const {
   jint r = env->CallIntMethod(ref, dimensionOCIMethod);
   JNIUtil::checkExceptions(env);
   return r;
}

JNIEXPORT void JIDataPointSet::clear() {
   env->CallVoidMethod(ref, clearOCVMethod);
   JNIUtil::exceptions(env);
}

JNIEXPORT int JIDataPointSet::size() const {
   jint r = env->CallIntMethod(ref, sizeOCIMethod);
   JNIUtil::checkExceptions(env);
   return r;
}

JNIEXPORT IDataPoint * JIDataPointSet::point(int index) {
   jobject obj = env->CallObjectMethod(ref, pointOICLhep_aida_IDataPointEMethod, index);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPoint(env, obj);
}

JNIEXPORT const IDataPoint * JIDataPointSet::point(int index) const {
   jobject obj = env->CallObjectMethod(ref, pointOICLhep_aida_IDataPointEMethod, index);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPoint(env, obj);
}

JNIEXPORT bool JIDataPointSet::setCoordinate(int coord, const std::vector<double> & val, const std::vector<double> & err) {
    jdoubleArray jval, jerr;
    NEWDOUBLEARRAY(jval, val)
    NEWDOUBLEARRAY(jerr, err)
    env->CallVoidMethod(ref, setCoordinateOIADADCZMethod, coord, jval, jerr);
    DELDOUBLEARRAY(jval)
    DELDOUBLEARRAY(jerr)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIDataPointSet::setCoordinate(int coord, const std::vector<double> & val, const std::vector<double> & errp, const std::vector<double> & errm) {
    jdoubleArray jval, jerrp, jerrm;
    NEWDOUBLEARRAY(jval, val)
    NEWDOUBLEARRAY(jerrp, errp)
    NEWDOUBLEARRAY(jerrm, errm)
    env->CallVoidMethod(ref, setCoordinateOIADADADCZMethod, coord, jval, jerrp, jerrm);
    DELDOUBLEARRAY(jval)
    DELDOUBLEARRAY(jerrp)
    DELDOUBLEARRAY(jerrm)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT IDataPoint * JIDataPointSet::addPoint() {
   jobject obj = env->CallObjectMethod(ref, addPointOCVMethod);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPoint(env, obj);
}

JNIEXPORT bool JIDataPointSet::addPoint(const IDataPoint & point) {
   jobject jpoint = factory->create(env, point);
   env->CallVoidMethod(ref, addPointOLhep_aida_IDataPointECVMethod, jpoint);
   if (JNIUtil::exceptions(env)) return false;
   else return true;
}

JNIEXPORT bool JIDataPointSet::removePoint(int index) {
   env->CallVoidMethod(ref, removePointOICVMethod, index);
   if (JNIUtil::exceptions(env)) return false;
   else return true;
}

JNIEXPORT double JIDataPointSet::lowerExtent(int coord) const {
   jdouble r = env->CallDoubleMethod(ref, lowerExtentOICDMethod, coord);
   JNIUtil::exceptions(env);
   return r;
}

JNIEXPORT double JIDataPointSet::upperExtent(int coord) const {
   jdouble r = env->CallDoubleMethod(ref, upperExtentOICDMethod, coord);
   JNIUtil::checkExceptions(env);
   return r;
}

JNIEXPORT bool JIDataPointSet::scale(double scaleFactor) {
   env->CallVoidMethod(ref, scaleODCVMethod, scaleFactor);
   if (JNIUtil::exceptions(env)) return false;
   else return true;
}

JNIEXPORT bool JIDataPointSet::scaleValues(double scaleFactor) {
   env->CallVoidMethod(ref, scaleValuesODCVMethod, scaleFactor);
   if (JNIUtil::exceptions(env)) return false;
   else return true;
}

JNIEXPORT bool JIDataPointSet::scaleErrors(double scaleFactor) {
   env->CallVoidMethod(ref, scaleErrorsODCVMethod, scaleFactor);
   if (JNIUtil::exceptions(env)) return false;
   else return true;
}

JNIEXPORT void * JIDataPointSet::cast(const std::string & className) const {
    return (className == "AIDA::IDataPointSet") ? (void *)this : NULL;
}
