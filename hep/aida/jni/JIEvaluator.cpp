
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AIDA/ITuple.h"
#include "JIEvaluator.h"
#include "JITuple.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIEvaluator::JIEvaluator(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    expressionOCLjava_lang_StringEMethod = env->GetMethodID(cls, "expression", "()Ljava/lang/String;");
    if (expressionOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IEvaluator" << ": Could not find method: " << "expression" << "()Ljava/lang/String;" << std::endl;
    }

    initializeOLhep_aida_ITupleECVMethod = env->GetMethodID(cls, "initialize", "(Lhep/aida/ITuple;)V");
    if (initializeOLhep_aida_ITupleECVMethod == NULL) {
        std::cerr << "IEvaluator" << ": Could not find method: " << "initialize" << "(Lhep/aida/ITuple;)V" << std::endl;
    }

    evaluateDoubleOCDMethod = env->GetMethodID(cls, "evaluateDouble", "()D");
    if (evaluateDoubleOCDMethod == NULL) {
        std::cerr << "IEvaluator" << ": Could not find method: " << "evaluateDouble" << "()D" << std::endl;
    }

}

JNIEXPORT JIEvaluator::~JIEvaluator() {
}

JNIEXPORT bool JIEvaluator::initialize(ITuple & tuple) {
    jobject jtuple = factory->create(env, tuple);
    env->CallVoidMethod(ref, initializeOLhep_aida_ITupleECVMethod, jtuple);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT double JIEvaluator::evaluateDouble() const {
    jdouble result = env->CallDoubleMethod(ref, evaluateDoubleOCDMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT std::string JIEvaluator::expression() const {
    jstring result = (jstring)env->CallObjectMethod(ref, expressionOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string expressionString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    return expressionString;
}
