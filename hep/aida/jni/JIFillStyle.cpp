
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "JIBrushStyle.h"
#include "JIFillStyle.h"
#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIFillStyle::JIFillStyle(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIBrushStyle(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    patternOCLjava_lang_StringEMethod = env->GetMethodID(cls, "pattern", "()Ljava/lang/String;");
    if (patternOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IFillStyle" << ": Could not find method: " << "pattern" << "()Ljava/lang/String;" << std::endl;
    }

    setPatternOLjava_lang_StringECZMethod = env->GetMethodID(cls, "setPattern", "(Ljava/lang/String;)Z");
    if (setPatternOLjava_lang_StringECZMethod == NULL) {
        std::cerr << "IFillStyle" << ": Could not find method: " << "setPattern" << "(Ljava/lang/String;)Z" << std::endl;
    }

    availablePatternsOCALjava_lang_StringEMethod = env->GetMethodID(cls, "availablePatterns", "()[Ljava/lang/String;");
    if (availablePatternsOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IFillStyle" << ": Could not find method: " << "availablePatterns" << "()[Ljava/lang/String;" << std::endl;
    }

}

JNIEXPORT JIFillStyle::~JIFillStyle() {
}

JNIEXPORT std::vector<std::string>  JIFillStyle::availablePatterns() const {
    vector<string> result;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, availablePatternsOCALjava_lang_StringEMethod);

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

JNIEXPORT std::string JIFillStyle::pattern() const {
    jstring result = (jstring)env->CallObjectMethod(ref, patternOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    JNIUtil::checkExceptions(env);
    return resultString;
}

JNIEXPORT bool JIFillStyle::setPattern(const std::string & pattern) {
    jstring jpattern;
    NEWSTRING(jpattern, pattern)
    jboolean result = env->CallBooleanMethod(ref, setPatternOLjava_lang_StringECZMethod, jpattern);
    DELSTRING(jpattern)
    JNIUtil::checkExceptions(env);
    return result;
}
