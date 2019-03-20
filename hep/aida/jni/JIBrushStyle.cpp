
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "JIBaseStyle.h"
#include "JIBrushStyle.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIBrushStyle::JIBrushStyle(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIBaseStyle(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    setOpacityODCZMethod = env->GetMethodID(cls, "setOpacity", "(D)Z");
    if (setOpacityODCZMethod == NULL) {
        std::cerr << "IBrushStyle" << ": Could not find method: " << "setOpacity" << "(D)Z" << std::endl;
    }

    colorOCLjava_lang_StringEMethod = env->GetMethodID(cls, "color", "()Ljava/lang/String;");
    if (colorOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IBrushStyle" << ": Could not find method: " << "color" << "()Ljava/lang/String;" << std::endl;
    }

    setColorOLjava_lang_StringECZMethod = env->GetMethodID(cls, "setColor", "(Ljava/lang/String;)Z");
    if (setColorOLjava_lang_StringECZMethod == NULL) {
        std::cerr << "IBrushStyle" << ": Could not find method: " << "setColor" << "(Ljava/lang/String;)Z" << std::endl;
    }

    opacityOCDMethod = env->GetMethodID(cls, "opacity", "()D");
    if (opacityOCDMethod == NULL) {
        std::cerr << "IBrushStyle" << ": Could not find method: " << "opacity" << "()D" << std::endl;
    }

    availableColorsOCALjava_lang_StringEMethod = env->GetMethodID(cls, "availableColors", "()[Ljava/lang/String;");
    if (availableColorsOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IBrushStyle" << ": Could not find method: " << "availableColors" << "()[Ljava/lang/String;" << std::endl;
    }

}

JNIEXPORT JIBrushStyle::~JIBrushStyle() {
}

JNIEXPORT std::vector<std::string>  JIBrushStyle::availableColors() const {
    vector<string> result;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, availableColorsOCALjava_lang_StringEMethod);

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

JNIEXPORT std::string JIBrushStyle::color() const {
    jstring result = (jstring)env->CallObjectMethod(ref, colorOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    return resultString;
}

JNIEXPORT double JIBrushStyle::opacity() const {
    jdouble result = env->CallDoubleMethod(ref, opacityOCDMethod);
	JNIUtil::checkExceptions(env);
	return result;
}

JNIEXPORT bool JIBrushStyle::setColor(const std::string & newColor) {
    jstring jnewColor;
    NEWSTRING(jnewColor, newColor)
    jboolean result = env->CallBooleanMethod(ref, setColorOLjava_lang_StringECZMethod, jnewColor);
    DELSTRING(jnewColor)
	JNIUtil::checkExceptions(env);
	return result;
}

JNIEXPORT bool JIBrushStyle::setOpacity(double newOpacity) {
    jboolean result = env->CallBooleanMethod(ref, setOpacityODCZMethod, newOpacity);
	JNIUtil::checkExceptions(env);
	return result;
}
