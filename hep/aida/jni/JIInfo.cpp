
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AIDA/IFillStyle.h"
#include "AIDA/ILineStyle.h"
#include "AIDA/IMarkerStyle.h"
#include "JIInfo.h"
#include "JIMarkerStyle.h"
#include "JILineStyle.h"
#include "JIFillStyle.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIInfo::JIInfo(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    addLegendOLhep_aida_ILineStyleELjava_lang_StringECVMethod = env->GetMethodID(cls, "addLegend", "(Lhep/aida/ILineStyle;Ljava/lang/String;)V");
    if (addLegendOLhep_aida_ILineStyleELjava_lang_StringECVMethod == NULL) {
        std::cerr << "IInfo" << ": Could not find method: " << "addLegend" << "(Lhep/aida/ILineStyle;Ljava/lang/String;)V" << std::endl;
    }

    addTextOLjava_lang_StringECVMethod = env->GetMethodID(cls, "addText", "(Ljava/lang/String;)V");
    if (addTextOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IInfo" << ": Could not find method: " << "addText" << "(Ljava/lang/String;)V" << std::endl;
    }

    addLegendOLhep_aida_IFillStyleELjava_lang_StringECVMethod = env->GetMethodID(cls, "addLegend", "(Lhep/aida/IFillStyle;Ljava/lang/String;)V");
    if (addLegendOLhep_aida_IFillStyleELjava_lang_StringECVMethod == NULL) {
        std::cerr << "IInfo" << ": Could not find method: " << "addLegend" << "(Lhep/aida/IFillStyle;Ljava/lang/String;)V" << std::endl;
    }

    addLegendOLhep_aida_IMarkerStyleELjava_lang_StringECVMethod = env->GetMethodID(cls, "addLegend", "(Lhep/aida/IMarkerStyle;Ljava/lang/String;)V");
    if (addLegendOLhep_aida_IMarkerStyleELjava_lang_StringECVMethod == NULL) {
        std::cerr << "IInfo" << ": Could not find method: " << "addLegend" << "(Lhep/aida/IMarkerStyle;Ljava/lang/String;)V" << std::endl;
    }

    clearOCVMethod = env->GetMethodID(cls, "clear", "()V");
    if (clearOCVMethod == NULL) {
        std::cerr << "IInfo" << ": Could not find method: " << "clear" << "()V" << std::endl;
    }

}

JNIEXPORT JIInfo::~JIInfo() {
}

JNIEXPORT void JIInfo::clear() {
    env->CallVoidMethod(ref, clearOCVMethod);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIInfo::addText(const std::string & text) {
    jstring jtext;
    NEWSTRING(jtext, text)
    env->CallVoidMethod(ref, addTextOLjava_lang_StringECVMethod, jtext);
    DELSTRING(jtext)
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIInfo::addLegend(const IMarkerStyle & style, const std::string & description) {
    jobject jstyle = factory->create(env, style);
    jstring jdescription;
    NEWSTRING(jdescription, description)
    env->CallVoidMethod(ref, addLegendOLhep_aida_IMarkerStyleELjava_lang_StringECVMethod, jstyle, jdescription);
    DELSTRING(jdescription)
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIInfo::addLegend(const ILineStyle & style, const std::string & description) {
    jobject jstyle = factory->create(env, style);
    jstring jdescription;
    NEWSTRING(jdescription, description)
    env->CallVoidMethod(ref, addLegendOLhep_aida_ILineStyleELjava_lang_StringECVMethod, jstyle, jdescription);
    DELSTRING(jdescription)
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIInfo::addLegend(const IFillStyle & style, const std::string & description) {
    jobject jstyle = factory->create(env, style);
    jstring jdescription;
    NEWSTRING(jdescription, description)
    env->CallVoidMethod(ref, addLegendOLhep_aida_IFillStyleELjava_lang_StringECVMethod, jstyle, jdescription);
    DELSTRING(jdescription)
    JNIUtil::checkExceptions(env);
}
