
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "JIBaseStyle.h"
#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIBaseStyle::JIBaseStyle(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    availableParameterOptionsOLjava_lang_StringECALjava_lang_StringEMethod = env->GetMethodID(cls, "availableParameterOptions", "(Ljava/lang/String;)[Ljava/lang/String;");
    if (availableParameterOptionsOLjava_lang_StringECALjava_lang_StringEMethod == NULL) {
        std::cerr << "IBaseStyle" << ": Could not find method: " << "availableParameterOptions" << "(Ljava/lang/String;)[Ljava/lang/String;" << std::endl;
    }

    availableParametersOCALjava_lang_StringEMethod = env->GetMethodID(cls, "availableParameters", "()[Ljava/lang/String;");
    if (availableParametersOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IBaseStyle" << ": Could not find method: " << "availableParameters" << "()[Ljava/lang/String;" << std::endl;
    }

    parameterValueOLjava_lang_StringECLjava_lang_StringEMethod = env->GetMethodID(cls, "parameterValue", "(Ljava/lang/String;)Ljava/lang/String;");
    if (parameterValueOLjava_lang_StringECLjava_lang_StringEMethod == NULL) {
        std::cerr << "IBaseStyle" << ": Could not find method: " << "parameterValue" << "(Ljava/lang/String;)Ljava/lang/String;" << std::endl;
    }

    setParameterOLjava_lang_StringELjava_lang_StringECZMethod = env->GetMethodID(cls, "setParameter", "(Ljava/lang/String;Ljava/lang/String;)Z");
    if (setParameterOLjava_lang_StringELjava_lang_StringECZMethod == NULL) {
        std::cerr << "IBaseStyle" << ": Could not find method: " << "setParameter" << "(Ljava/lang/String;Ljava/lang/String;)Z" << std::endl;
    }

    resetOCVMethod = env->GetMethodID(cls, "reset", "()V");
    if (resetOCVMethod == NULL) {
        std::cerr << "IBaseStyle" << ": Could not find method: " << "reset" << "()V" << std::endl;
    }

}

JNIEXPORT JIBaseStyle::~JIBaseStyle() {
}

JNIEXPORT void JIBaseStyle::reset() {
    env->CallVoidMethod(ref, resetOCVMethod);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT bool JIBaseStyle::setParameter(const std::string & paramName, const std::string & options) {
    jstring jparamName, joptions;
    NEWSTRING(jparamName, paramName)
    NEWSTRING(joptions, options)
    env->CallVoidMethod(ref, setParameterOLjava_lang_StringELjava_lang_StringECZMethod, jparamName, joptions);
    DELSTRING(jparamName)
    DELSTRING(joptions)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT std::string JIBaseStyle::parameterValue(const std::string & parameter) const {
    jstring jparameter;
    NEWSTRING(jparameter, parameter)
    jstring result = (jstring)env->CallObjectMethod(ref, parameterValueOLjava_lang_StringECLjava_lang_StringEMethod, jparameter);
    DELSTRING(jparameter)
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    JNIUtil::checkExceptions(env);
    return resultString;
}

JNIEXPORT std::vector<std::string>  JIBaseStyle::availableParameters() const {
    vector<string> result;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, availableParametersOCALjava_lang_StringEMethod);

    if (array != NULL) {
        // convert string[] to vector<string>
        unsigned int len = env->GetArrayLength(array);
        for (unsigned int i=0; i<len; i++) {
            jstring jname = (jstring)env->GetObjectArrayElement(array, i);
            jboolean isCopy;
            const char* utf = env->GetStringUTFChars(jname, &isCopy);
            string name = utf;
            if (isCopy) env->ReleaseStringUTFChars(jname, utf);
            result.push_back(name);
        }
    }
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT std::vector<std::string>  JIBaseStyle::availableParameterOptions(const std::string & paramName) const {
    jstring jparamName;
    vector<string> result;
    NEWSTRING(jparamName, paramName)

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, availableParameterOptionsOLjava_lang_StringECALjava_lang_StringEMethod, jparamName);

    DELSTRING(jparamName)
    if (array != NULL) {
        // convert string[] to vector<string>
        unsigned int len = env->GetArrayLength(array);
        for (unsigned int i=0; i<len; i++) {
            jstring jname = (jstring)env->GetObjectArrayElement(array, i);
            jboolean isCopy;
            const char* utf = env->GetStringUTFChars(jname, &isCopy);
            string name = utf;
            if (isCopy) env->ReleaseStringUTFChars(jname, utf);
            result.push_back(name);
        }
    }
    JNIUtil::checkExceptions(env);
    return result;
}
