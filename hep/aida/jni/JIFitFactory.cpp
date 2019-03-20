
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AIDA/IFitData.h"
#include "AIDA/IFitter.h"
#include "JIFitData.h"
#include "JIFitFactory.h"
#include "JIFitter.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JIFitFactory::JIFitFactory(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    createFitDataOCLhep_aida_IFitDataEMethod = env->GetMethodID(cls, "createFitData", "()Lhep/aida/IFitData;");
    if (createFitDataOCLhep_aida_IFitDataEMethod == NULL) {
        std::cerr << "IFitFactory" << ": Could not find method: " << "createFitData" << "()Lhep/aida/IFitData;" << std::endl;
    }

    createFitterOLjava_lang_StringELjava_lang_StringELjava_lang_StringECLhep_aida_IFitterEMethod = env->GetMethodID(cls, "createFitter", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFitter;");
    if (createFitterOLjava_lang_StringELjava_lang_StringELjava_lang_StringECLhep_aida_IFitterEMethod == NULL) {
        std::cerr << "IFitFactory" << ": Could not find method: " << "createFitter" << "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFitter;" << std::endl;
    }

}

JNIEXPORT JIFitFactory::~JIFitFactory() {
}

JNIEXPORT IFitData * JIFitFactory::createFitData() {
    jobject obj = env->CallObjectMethod(ref, createFitDataOCLhep_aida_IFitDataEMethod);
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIFitData(env, obj);
}

JNIEXPORT IFitter * JIFitFactory::createFitter(const std::string &fitterType, const std::string & engineType, const std::string & options) {
    jstring jfitterType;
    NEWSTRING(jfitterType, fitterType)
    jstring jengineType;
    NEWSTRING(jengineType, engineType)
    jstring joptions;
    NEWSTRING(joptions, options)
    jobject obj = env->CallObjectMethod(ref, createFitterOLjava_lang_StringELjava_lang_StringELjava_lang_StringECLhep_aida_IFitterEMethod,jfitterType,jengineType,joptions);
    DELSTRING(jfitterType)
    DELSTRING(jengineType)
    DELSTRING(joptions)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIFitter(env, obj);
}
