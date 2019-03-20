
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AIDA/IAnnotation.h"
#include "JIAnnotation.h"
#include "JIBaseHistogram.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIBaseHistogram::JIBaseHistogram(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory),
        iAnnotation(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    annotationOCLhep_aida_IAnnotationEMethod = env->GetMethodID(cls, "annotation", "()Lhep/aida/IAnnotation;");
    if (annotationOCLhep_aida_IAnnotationEMethod == NULL) {
        std::cerr << "IBaseHistogram" << ": Could not find method: " << "annotation" << "()Lhep/aida/IAnnotation;" << std::endl;
    }

    setTitleOLjava_lang_StringECVMethod = env->GetMethodID(cls, "setTitle", "(Ljava/lang/String;)V");
    if (setTitleOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IBaseHistogram" << ": Could not find method: " << "setTitle" << "(Ljava/lang/String;)V" << std::endl;
    }

    entriesOCIMethod = env->GetMethodID(cls, "entries", "()I");
    if (entriesOCIMethod == NULL) {
        std::cerr << "IBaseHistogram" << ": Could not find method: " << "entries" << "()I" << std::endl;
    }

    titleOCLjava_lang_StringEMethod = env->GetMethodID(cls, "title", "()Ljava/lang/String;");
    if (titleOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IBaseHistogram" << ": Could not find method: " << "title" << "()Ljava/lang/String;" << std::endl;
    }

    dimensionOCIMethod = env->GetMethodID(cls, "dimension", "()I");
    if (dimensionOCIMethod == NULL) {
        std::cerr << "IBaseHistogram" << ": Could not find method: " << "dimension" << "()I" << std::endl;
    }

    resetOCVMethod = env->GetMethodID(cls, "reset", "()V");
    if (resetOCVMethod == NULL) {
        std::cerr << "IBaseHistogram" << ": Could not find method: " << "reset" << "()V" << std::endl;
    }
}

JNIEXPORT JIBaseHistogram::~JIBaseHistogram() {
    delete iAnnotation;
}

JNIEXPORT std::string JIBaseHistogram::title() const {
    // Call to Java
    jstring jtitle = (jstring)env->CallObjectMethod(ref, titleOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(jtitle, &isCopy);
    string titleString = utf;
    if (isCopy) env->ReleaseStringUTFChars(jtitle, utf);
    return titleString;
}

JNIEXPORT bool JIBaseHistogram::setTitle(const std::string & title) {
    jstring jtitle;
    NEWSTRING(jtitle, title)
    env->CallObjectMethod(ref, setTitleOLjava_lang_StringECVMethod, jtitle);
    DELSTRING(jtitle)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT IAnnotation & JIBaseHistogram::annotation() {
    if (iAnnotation == NULL) {
        jobject jannotation = env->CallObjectMethod(ref, annotationOCLhep_aida_IAnnotationEMethod);
        iAnnotation = factory->createIAnnotation(env, jannotation);
    }
    return *iAnnotation;
}

JNIEXPORT const IAnnotation & JIBaseHistogram::annotation() const {
    if (iAnnotation == NULL) {
        jobject jannotation = env->CallObjectMethod(ref, annotationOCLhep_aida_IAnnotationEMethod);
        iAnnotation = factory->createIAnnotation(env, jannotation);
    }
    return *iAnnotation;
}

JNIEXPORT int JIBaseHistogram::dimension() const {
	jint r = env->CallIntMethod(ref, dimensionOCIMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT bool JIBaseHistogram::reset() {
	env->CallVoidMethod(ref, resetOCVMethod);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT int JIBaseHistogram::entries() const {
	jint r = env->CallIntMethod(ref, entriesOCIMethod);
	JNIUtil::checkExceptions(env);
	return r;
}
