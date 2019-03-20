
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AIDA/ITuple.h"
#include "JIFilter.h"
#include "JITuple.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIFilter::JIFilter(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    expressionOCLjava_lang_StringEMethod = env->GetMethodID(cls, "expression", "()Ljava/lang/String;");
    if (expressionOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IFilter" << ": Could not find method: " << "expression" << "()Ljava/lang/String;" << std::endl;
    }

    acceptOCZMethod = env->GetMethodID(cls, "accept", "()Z");
    if (acceptOCZMethod == NULL) {
        std::cerr << "IFilter" << ": Could not find method: " << "accept" << "()Z" << std::endl;
    }

    initializeOLhep_aida_ITupleECVMethod = env->GetMethodID(cls, "initialize", "(Lhep/aida/ITuple;)V");
    if (initializeOLhep_aida_ITupleECVMethod == NULL) {
        std::cerr << "IFilter" << ": Could not find method: " << "initialize" << "(Lhep/aida/ITuple;)V" << std::endl;
    }

}

JNIEXPORT JIFilter::~JIFilter() {
}

JNIEXPORT bool JIFilter::initialize(ITuple & tuple) {
    jobject jtuple = factory->create(env, tuple);
    env->CallVoidMethod(ref, initializeOLhep_aida_ITupleECVMethod, jtuple);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFilter::accept() const {
    jboolean result = env->CallBooleanMethod(ref, acceptOCZMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT std::string JIFilter::expression() const {
    jstring result = (jstring)env->CallObjectMethod(ref, expressionOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string expressionString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    return expressionString;
}
