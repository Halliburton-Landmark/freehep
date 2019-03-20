
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "JIPlotterLayout.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIPlotterLayout::JIPlotterLayout(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    availableParametersOCALjava_lang_StringEMethod = env->GetMethodID(cls, "availableParameters", "()[Ljava/lang/String;");
    if (availableParametersOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IPlotterLayout" << ": Could not find method: " << "availableParameters" << "()[Ljava/lang/String;" << std::endl;
    }

    setParameterOLjava_lang_StringEDCZMethod = env->GetMethodID(cls, "setParameter", "(Ljava/lang/String;D)Z");
    if (setParameterOLjava_lang_StringEDCZMethod == NULL) {
        std::cerr << "IPlotterLayout" << ": Could not find method: " << "setParameter" << "(Ljava/lang/String;D)Z" << std::endl;
    }

    parameterValueOLjava_lang_StringECDMethod = env->GetMethodID(cls, "parameterValue", "(Ljava/lang/String;)D");
    if (parameterValueOLjava_lang_StringECDMethod == NULL) {
        std::cerr << "IPlotterLayout" << ": Could not find method: " << "parameterValue" << "(Ljava/lang/String;)D" << std::endl;
    }

    resetOCVMethod = env->GetMethodID(cls, "reset", "()V");
    if (resetOCVMethod == NULL) {
        std::cerr << "IPlotterLayout" << ": Could not find method: " << "reset" << "()V" << std::endl;
    }

}

JNIEXPORT JIPlotterLayout::~JIPlotterLayout() {
}

JNIEXPORT void JIPlotterLayout::reset() {
    env->CallVoidMethod(ref, resetOCVMethod);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT bool JIPlotterLayout::setParameter(const std::string & paramName, double paramValue) {
    jstring jparamName;
    NEWSTRING(jparamName, paramName)
    jboolean result = env->CallBooleanMethod(ref, setParameterOLjava_lang_StringEDCZMethod, jparamName, paramValue);
    DELSTRING(jparamName)
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT double JIPlotterLayout::parameterValue(const std::string & paramName) {
    jstring jparamName;
    NEWSTRING(jparamName, paramName)
    jdouble result = env->CallDoubleMethod(ref, parameterValueOLjava_lang_StringECDMethod, jparamName);
    DELSTRING(jparamName)
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT std::vector<std::string>  JIPlotterLayout::availableParameters() const {
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
