
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "JIBrushStyle.h"
#include "JILineStyle.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JILineStyle::JILineStyle(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIBrushStyle(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    thicknessOCIMethod = env->GetMethodID(cls, "thickness", "()I");
    if (thicknessOCIMethod == NULL) {
        std::cerr << "ILineStyle" << ": Could not find method: " << "thickness" << "()I" << std::endl;
    }

    setLineTypeOLjava_lang_StringECZMethod = env->GetMethodID(cls, "setLineType", "(Ljava/lang/String;)Z");
    if (setLineTypeOLjava_lang_StringECZMethod == NULL) {
        std::cerr << "ILineStyle" << ": Could not find method: " << "setLineType" << "(Ljava/lang/String;)Z" << std::endl;
    }

    availableLineTypesOCALjava_lang_StringEMethod = env->GetMethodID(cls, "availableLineTypes", "()[Ljava/lang/String;");
    if (availableLineTypesOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "ILineStyle" << ": Could not find method: " << "availableLineTypes" << "()[Ljava/lang/String;" << std::endl;
    }

    setThicknessOICZMethod = env->GetMethodID(cls, "setThickness", "(I)Z");
    if (setThicknessOICZMethod == NULL) {
        std::cerr << "ILineStyle" << ": Could not find method: " << "setThickness" << "(I)Z" << std::endl;
    }

    lineTypeOCLjava_lang_StringEMethod = env->GetMethodID(cls, "lineType", "()Ljava/lang/String;");
    if (lineTypeOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "ILineStyle" << ": Could not find method: " << "lineType" << "()Ljava/lang/String;" << std::endl;
    }

}

JNIEXPORT JILineStyle::~JILineStyle() {
}

JNIEXPORT std::vector<std::string>  JILineStyle::availableLineTypes() const {
    vector<string> result;
    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, availableLineTypesOCALjava_lang_StringEMethod);

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

JNIEXPORT std::string JILineStyle::lineType() const {
    jstring result = (jstring)env->CallObjectMethod(ref, lineTypeOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    return resultString;
}

JNIEXPORT int JILineStyle::thickness() const {
    jint result = env->CallIntMethod(ref, thicknessOCIMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JILineStyle::setLineType(const std::string & newLineType) {
    jstring jnewLineType;
    NEWSTRING(jnewLineType, newLineType)
    jboolean result = env->CallBooleanMethod(ref, setLineTypeOLjava_lang_StringECZMethod, jnewLineType);
    DELSTRING(jnewLineType)
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JILineStyle::setThickness(int newThickness) {
    jboolean result = env->CallBooleanMethod(ref, setThicknessOICZMethod, newThickness);
    JNIUtil::checkExceptions(env);
    return result;
}
