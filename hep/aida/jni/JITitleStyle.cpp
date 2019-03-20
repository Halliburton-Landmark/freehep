
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "AIDA/ITextStyle.h"
#include "JIBaseStyle.h"
#include "JITextStyle.h"
#include "JITitleStyle.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JITitleStyle::JITitleStyle(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIBaseStyle(jnienv, object, factory),
        iTextStyle(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    setTextStyleOLhep_aida_ITextStyleECZMethod = env->GetMethodID(cls, "setTextStyle", "(Lhep/aida/ITextStyle;)Z");
    if (setTextStyleOLhep_aida_ITextStyleECZMethod == NULL) {
        std::cerr << "ITitleStyle" << ": Could not find method: " << "setTextStyle" << "(Lhep/aida/ITextStyle;)Z" << std::endl;
    }

    textStyleOCLhep_aida_ITextStyleEMethod = env->GetMethodID(cls, "textStyle", "()Lhep/aida/ITextStyle;");
    if (textStyleOCLhep_aida_ITextStyleEMethod == NULL) {
        std::cerr << "ITitleStyle" << ": Could not find method: " << "textStyle" << "()Lhep/aida/ITextStyle;" << std::endl;
    }

}

JNIEXPORT JITitleStyle::~JITitleStyle() {
    delete iTextStyle;
}

JNIEXPORT ITextStyle & JITitleStyle::textStyle() {
    jobject obj = env->CallObjectMethod(ref, textStyleOCLhep_aida_ITextStyleEMethod);
    iTextStyle = factory->createITextStyle(env, obj);

    return *iTextStyle;
}

JNIEXPORT bool JITitleStyle::setTextStyle(const ITextStyle & textStyle) {
    jobject jstyle = factory->create(env, textStyle);
    jboolean result = env->CallBooleanMethod(ref, setTextStyleOLhep_aida_ITextStyleECZMethod, jstyle);
    JNIUtil::checkExceptions(env);
    return result;
}
