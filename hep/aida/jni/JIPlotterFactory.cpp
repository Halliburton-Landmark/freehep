
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AIDA/IAxisStyle.h"
#include "AIDA/IDataStyle.h"
#include "AIDA/IFillStyle.h"
#include "AIDA/ILineStyle.h"
#include "AIDA/IMarkerStyle.h"
#include "AIDA/IPlotter.h"
#include "AIDA/IPlotterStyle.h"
#include "AIDA/ITextStyle.h"
#include "AIDA/ITitleStyle.h"
#include "JIPlotterFactory.h"
#include "JIPlotter.h"
#include "JIPlotterStyle.h"
#include "JIMarkerStyle.h"
#include "JITitleStyle.h"
#include "JITextStyle.h"
#include "JIDataStyle.h"
#include "JIAxisStyle.h"
#include "JILineStyle.h"
#include "JIFillStyle.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JIPlotterFactory::JIPlotterFactory(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    createDataStyleOCLhep_aida_IDataStyleEMethod = env->GetMethodID(cls, "createDataStyle", "()Lhep/aida/IDataStyle;");
    if (createDataStyleOCLhep_aida_IDataStyleEMethod == NULL) {
        std::cerr << "IPlotterFactory" << ": Could not find method: " << "createDataStyle" << "()Lhep/aida/IDataStyle;" << std::endl;
    }

    createOLjava_lang_StringECLhep_aida_IPlotterEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;)Lhep/aida/IPlotter;");
    if (createOLjava_lang_StringECLhep_aida_IPlotterEMethod == NULL) {
        std::cerr << "IPlotterFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;)Lhep/aida/IPlotter;" << std::endl;
    }

    createAxisStyleOCLhep_aida_IAxisStyleEMethod = env->GetMethodID(cls, "createAxisStyle", "()Lhep/aida/IAxisStyle;");
    if (createAxisStyleOCLhep_aida_IAxisStyleEMethod == NULL) {
        std::cerr << "IPlotterFactory" << ": Could not find method: " << "createAxisStyle" << "()Lhep/aida/IAxisStyle;" << std::endl;
    }

    createPlotterStyleOCLhep_aida_IPlotterStyleEMethod = env->GetMethodID(cls, "createPlotterStyle", "()Lhep/aida/IPlotterStyle;");
    if (createPlotterStyleOCLhep_aida_IPlotterStyleEMethod == NULL) {
        std::cerr << "IPlotterFactory" << ": Could not find method: " << "createPlotterStyle" << "()Lhep/aida/IPlotterStyle;" << std::endl;
    }

    createTextStyleOCLhep_aida_ITextStyleEMethod = env->GetMethodID(cls, "createTextStyle", "()Lhep/aida/ITextStyle;");
    if (createTextStyleOCLhep_aida_ITextStyleEMethod == NULL) {
        std::cerr << "IPlotterFactory" << ": Could not find method: " << "createTextStyle" << "()Lhep/aida/ITextStyle;" << std::endl;
    }

    createLineStyleOCLhep_aida_ILineStyleEMethod = env->GetMethodID(cls, "createLineStyle", "()Lhep/aida/ILineStyle;");
    if (createLineStyleOCLhep_aida_ILineStyleEMethod == NULL) {
        std::cerr << "IPlotterFactory" << ": Could not find method: " << "createLineStyle" << "()Lhep/aida/ILineStyle;" << std::endl;
    }

    createMarkerStyleOCLhep_aida_IMarkerStyleEMethod = env->GetMethodID(cls, "createMarkerStyle", "()Lhep/aida/IMarkerStyle;");
    if (createMarkerStyleOCLhep_aida_IMarkerStyleEMethod == NULL) {
        std::cerr << "IPlotterFactory" << ": Could not find method: " << "createMarkerStyle" << "()Lhep/aida/IMarkerStyle;" << std::endl;
    }

    createTitleStyleOCLhep_aida_ITitleStyleEMethod = env->GetMethodID(cls, "createTitleStyle", "()Lhep/aida/ITitleStyle;");
    if (createTitleStyleOCLhep_aida_ITitleStyleEMethod == NULL) {
        std::cerr << "IPlotterFactory" << ": Could not find method: " << "createTitleStyle" << "()Lhep/aida/ITitleStyle;" << std::endl;
    }

    createFillStyleOCLhep_aida_IFillStyleEMethod = env->GetMethodID(cls, "createFillStyle", "()Lhep/aida/IFillStyle;");
    if (createFillStyleOCLhep_aida_IFillStyleEMethod == NULL) {
        std::cerr << "IPlotterFactory" << ": Could not find method: " << "createFillStyle" << "()Lhep/aida/IFillStyle;" << std::endl;
    }

}

JNIEXPORT JIPlotterFactory::~JIPlotterFactory() {
}

JNIEXPORT IPlotter * JIPlotterFactory::create(const std::string & name) {
    jstring jname;
    NEWSTRING(jname, name)
    jobject r = env->CallObjectMethod(ref, createOLjava_lang_StringECLhep_aida_IPlotterEMethod, jname);
    DELSTRING(jname)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIPlotter(env, r);
}

JNIEXPORT IMarkerStyle * JIPlotterFactory::createMarkerStyle() {
    jobject r = env->CallObjectMethod(ref, createMarkerStyleOCLhep_aida_IMarkerStyleEMethod);
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIMarkerStyle(env, r);
}

JNIEXPORT ITextStyle * JIPlotterFactory::createTextStyle() {
    jobject r = env->CallObjectMethod(ref, createTextStyleOCLhep_aida_ITextStyleEMethod);
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createITextStyle(env, r);
}

JNIEXPORT ILineStyle * JIPlotterFactory::createLineStyle() {
    jobject r = env->CallObjectMethod(ref, createLineStyleOCLhep_aida_ILineStyleEMethod);
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createILineStyle(env, r);
}

JNIEXPORT IFillStyle * JIPlotterFactory::createFillStyle() {
    jobject r = env->CallObjectMethod(ref, createFillStyleOCLhep_aida_IFillStyleEMethod);
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIFillStyle(env, r);
}

JNIEXPORT IDataStyle * JIPlotterFactory::createDataStyle() {
    jobject r = env->CallObjectMethod(ref, createDataStyleOCLhep_aida_IDataStyleEMethod);
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataStyle(env, r);
}

JNIEXPORT IAxisStyle * JIPlotterFactory::createAxisStyle() {
    jobject r = env->CallObjectMethod(ref, createAxisStyleOCLhep_aida_IAxisStyleEMethod);
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIAxisStyle(env, r);
}

JNIEXPORT ITitleStyle * JIPlotterFactory::createTitleStyle() {
    jobject r = env->CallObjectMethod(ref, createTitleStyleOCLhep_aida_ITitleStyleEMethod);
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createITitleStyle(env, r);
}

JNIEXPORT IPlotterStyle * JIPlotterFactory::createPlotterStyle() {
    jobject r = env->CallObjectMethod(ref, createPlotterStyleOCLhep_aida_IPlotterStyleEMethod);
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIPlotterStyle(env, r);
}
