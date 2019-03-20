
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "AIDA/IFillStyle.h"
#include "AIDA/ILineStyle.h"
#include "AIDA/IMarkerStyle.h"
#include "JIBaseStyle.h"
#include "JIDataStyle.h"
#include "JILineStyle.h"
#include "JIFillStyle.h"
#include "JIMarkerStyle.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIDataStyle::JIDataStyle(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIBaseStyle(jnienv, object, factory),
        iLineStyle(NULL),
        iMarkerStyle(NULL),
        iFillStyle(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    markerStyleOCLhep_aida_IMarkerStyleEMethod = env->GetMethodID(cls, "markerStyle", "()Lhep/aida/IMarkerStyle;");
    if (markerStyleOCLhep_aida_IMarkerStyleEMethod == NULL) {
        std::cerr << "IDataStyle" << ": Could not find method: " << "markerStyle" << "()Lhep/aida/IMarkerStyle;" << std::endl;
    }

    setMarkerStyleOLhep_aida_IMarkerStyleECZMethod = env->GetMethodID(cls, "setMarkerStyle", "(Lhep/aida/IMarkerStyle;)Z");
    if (setMarkerStyleOLhep_aida_IMarkerStyleECZMethod == NULL) {
        std::cerr << "IDataStyle" << ": Could not find method: " << "setMarkerStyle" << "(Lhep/aida/IMarkerStyle;)Z" << std::endl;
    }

    setLineStyleOLhep_aida_ILineStyleECZMethod = env->GetMethodID(cls, "setLineStyle", "(Lhep/aida/ILineStyle;)Z");
    if (setLineStyleOLhep_aida_ILineStyleECZMethod == NULL) {
        std::cerr << "IDataStyle" << ": Could not find method: " << "setLineStyle" << "(Lhep/aida/ILineStyle;)Z" << std::endl;
    }

    fillStyleOCLhep_aida_IFillStyleEMethod = env->GetMethodID(cls, "fillStyle", "()Lhep/aida/IFillStyle;");
    if (fillStyleOCLhep_aida_IFillStyleEMethod == NULL) {
        std::cerr << "IDataStyle" << ": Could not find method: " << "fillStyle" << "()Lhep/aida/IFillStyle;" << std::endl;
    }

    lineStyleOCLhep_aida_ILineStyleEMethod = env->GetMethodID(cls, "lineStyle", "()Lhep/aida/ILineStyle;");
    if (lineStyleOCLhep_aida_ILineStyleEMethod == NULL) {
        std::cerr << "IDataStyle" << ": Could not find method: " << "lineStyle" << "()Lhep/aida/ILineStyle;" << std::endl;
    }

    setFillStyleOLhep_aida_IFillStyleECZMethod = env->GetMethodID(cls, "setFillStyle", "(Lhep/aida/IFillStyle;)Z");
    if (setFillStyleOLhep_aida_IFillStyleECZMethod == NULL) {
        std::cerr << "IDataStyle" << ": Could not find method: " << "setFillStyle" << "(Lhep/aida/IFillStyle;)Z" << std::endl;
    }

}

JNIEXPORT JIDataStyle::~JIDataStyle() {
    delete iLineStyle;
    delete iMarkerStyle;
    delete iFillStyle;
}

JNIEXPORT ILineStyle & JIDataStyle::lineStyle() {
    jobject obj = env->CallObjectMethod(ref, lineStyleOCLhep_aida_ILineStyleEMethod);
    iLineStyle = factory->createILineStyle(env, obj);

    return *iLineStyle;
}

JNIEXPORT IMarkerStyle & JIDataStyle::markerStyle() {
    jobject obj = env->CallObjectMethod(ref, markerStyleOCLhep_aida_IMarkerStyleEMethod);
    iMarkerStyle = factory->createIMarkerStyle(env, obj);

    return *iMarkerStyle;
}

JNIEXPORT IFillStyle & JIDataStyle::fillStyle() {
    jobject obj = env->CallObjectMethod(ref, fillStyleOCLhep_aida_IFillStyleEMethod);
    iFillStyle = factory->createIFillStyle(env, obj);

    return *iFillStyle;
}

JNIEXPORT bool JIDataStyle::setLineStyle(const ILineStyle & lineStyle) {
    jobject jstyle = factory->create(env, lineStyle);
    jboolean result = env->CallBooleanMethod(ref, setLineStyleOLhep_aida_ILineStyleECZMethod, jstyle);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JIDataStyle::setMarkerStyle(const IMarkerStyle & markerStyle) {
    jobject jstyle = factory->create(env, markerStyle);
    jboolean result = env->CallBooleanMethod(ref, setMarkerStyleOLhep_aida_IMarkerStyleECZMethod, jstyle);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JIDataStyle::setFillStyle(const IFillStyle & fillStyle) {
    jobject jstyle = factory->create(env, fillStyle);
    jboolean result = env->CallBooleanMethod(ref, setFillStyleOLhep_aida_IFillStyleECZMethod, jstyle);
    JNIUtil::checkExceptions(env);
    return result;
}
