
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AIDA/ILineStyle.h"
#include "AIDA/ITextStyle.h"
#include "JIAxisStyle.h"
#include "JIBaseStyle.h"
#include "JILineStyle.h"
#include "JITextStyle.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIAxisStyle::JIAxisStyle(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIBaseStyle(jnienv, object, factory),
        iLineStyle(NULL),
        iTickLabelStyle(NULL),
        iLabelStyle(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    setlineStyleOLhep_aida_ILineStyleECZMethod = env->GetMethodID(cls, "setlineStyle", "(Lhep/aida/ILineStyle;)Z");
    if (setlineStyleOLhep_aida_ILineStyleECZMethod == NULL) {
        std::cerr << "IAxisStyle" << ": Could not find method: " << "setlineStyle" << "(Lhep/aida/ILineStyle;)Z" << std::endl;
    }

    tickLabelStyleOCLhep_aida_ITextStyleEMethod = env->GetMethodID(cls, "tickLabelStyle", "()Lhep/aida/ITextStyle;");
    if (tickLabelStyleOCLhep_aida_ITextStyleEMethod == NULL) {
        std::cerr << "IAxisStyle" << ": Could not find method: " << "tickLabelStyle" << "()Lhep/aida/ITextStyle;" << std::endl;
    }

    setLabelOLjava_lang_StringECVMethod = env->GetMethodID(cls, "setLabel", "(Ljava/lang/String;)V");
    if (setLabelOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IAxisStyle" << ": Could not find method: " << "setLabel" << "(Ljava/lang/String;)V" << std::endl;
    }

    setTickLabelStyleOLhep_aida_ITextStyleECZMethod = env->GetMethodID(cls, "setTickLabelStyle", "(Lhep/aida/ITextStyle;)Z");
    if (setTickLabelStyleOLhep_aida_ITextStyleECZMethod == NULL) {
        std::cerr << "IAxisStyle" << ": Could not find method: " << "setTickLabelStyle" << "(Lhep/aida/ITextStyle;)Z" << std::endl;
    }

    labelStyleOCLhep_aida_ITextStyleEMethod = env->GetMethodID(cls, "labelStyle", "()Lhep/aida/ITextStyle;");
    if (labelStyleOCLhep_aida_ITextStyleEMethod == NULL) {
        std::cerr << "IAxisStyle" << ": Could not find method: " << "labelStyle" << "()Lhep/aida/ITextStyle;" << std::endl;
    }

    lineStyleOCLhep_aida_ILineStyleEMethod = env->GetMethodID(cls, "lineStyle", "()Lhep/aida/ILineStyle;");
    if (lineStyleOCLhep_aida_ILineStyleEMethod == NULL) {
        std::cerr << "IAxisStyle" << ": Could not find method: " << "lineStyle" << "()Lhep/aida/ILineStyle;" << std::endl;
    }

    setLabelStyleOLhep_aida_ITextStyleECZMethod = env->GetMethodID(cls, "setLabelStyle", "(Lhep/aida/ITextStyle;)Z");
    if (setLabelStyleOLhep_aida_ITextStyleECZMethod == NULL) {
        std::cerr << "IAxisStyle" << ": Could not find method: " << "setLabelStyle" << "(Lhep/aida/ITextStyle;)Z" << std::endl;
    }

}

JNIEXPORT JIAxisStyle::~JIAxisStyle() {
    delete iLineStyle;
    delete iTickLabelStyle;
    delete iLabelStyle;
}

JNIEXPORT ILineStyle & JIAxisStyle::lineStyle() {
    jobject obj = env->CallObjectMethod(ref, lineStyleOCLhep_aida_ILineStyleEMethod);
    iLineStyle = factory->createILineStyle(env, obj);

    return *iLineStyle;
}

JNIEXPORT ITextStyle & JIAxisStyle::tickLabelStyle() {
    jobject obj = env->CallObjectMethod(ref, tickLabelStyleOCLhep_aida_ITextStyleEMethod);
    iTickLabelStyle = factory->createITextStyle(env, obj);

    return *iTickLabelStyle;
}

JNIEXPORT ITextStyle & JIAxisStyle::labelStyle() {
    jobject obj = env->CallObjectMethod(ref, labelStyleOCLhep_aida_ITextStyleEMethod);
    iLabelStyle = factory->createITextStyle(env, obj);

    return *iLabelStyle;
}

// AIDA-45 QUESTION should we correct to setLineStyle ?
JNIEXPORT bool JIAxisStyle::setlineStyle(const ILineStyle & lineStyle) {
    jobject jstyle = factory->create(env, lineStyle);
    jboolean result = env->CallBooleanMethod(ref, setlineStyleOLhep_aida_ILineStyleECZMethod, jstyle);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JIAxisStyle::setTickLabelStyle(const ITextStyle & tickLabelStyle) {
    jobject jstyle = factory->create(env, tickLabelStyle);
    jboolean result = env->CallBooleanMethod(ref, setTickLabelStyleOLhep_aida_ITextStyleECZMethod, jstyle);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JIAxisStyle::setLabelStyle(const ITextStyle & labelStyle) {
    jobject jstyle = factory->create(env, labelStyle);
    jboolean result = env->CallBooleanMethod(ref, setLabelStyleOLhep_aida_ITextStyleECZMethod, jstyle);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT void JIAxisStyle::setLabel(const std::string & label) {
    jstring jlabel;
    NEWSTRING(jlabel, label)
    env->CallVoidMethod(ref, setLabelOLjava_lang_StringECVMethod, jlabel);
    DELSTRING(jlabel)
	JNIUtil::checkExceptions(env);
}
