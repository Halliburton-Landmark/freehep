
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "JIBrushStyle.h"
#include "JITextStyle.h"
#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JITextStyle::JITextStyle(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIBrushStyle(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    fontOCLjava_lang_StringEMethod = env->GetMethodID(cls, "font", "()Ljava/lang/String;");
    if (fontOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "ITextStyle" << ": Could not find method: " << "font" << "()Ljava/lang/String;" << std::endl;
    }

    isItalicOCZMethod = env->GetMethodID(cls, "isItalic", "()Z");
    if (isItalicOCZMethod == NULL) {
        std::cerr << "ITextStyle" << ": Could not find method: " << "isItalic" << "()Z" << std::endl;
    }

    setFontSizeODCZMethod = env->GetMethodID(cls, "setFontSize", "(D)Z");
    if (setFontSizeODCZMethod == NULL) {
        std::cerr << "ITextStyle" << ": Could not find method: " << "setFontSize" << "(D)Z" << std::endl;
    }

    fontSizeOCDMethod = env->GetMethodID(cls, "fontSize", "()D");
    if (fontSizeOCDMethod == NULL) {
        std::cerr << "ITextStyle" << ": Could not find method: " << "fontSize" << "()D" << std::endl;
    }

    setItalicOZCZMethod = env->GetMethodID(cls, "setItalic", "(Z)Z");
    if (setItalicOZCZMethod == NULL) {
        std::cerr << "ITextStyle" << ": Could not find method: " << "setItalic" << "(Z)Z" << std::endl;
    }

    setUnderlinedOZCZMethod = env->GetMethodID(cls, "setUnderlined", "(Z)Z");
    if (setUnderlinedOZCZMethod == NULL) {
        std::cerr << "ITextStyle" << ": Could not find method: " << "setUnderlined" << "(Z)Z" << std::endl;
    }

    setBoldOZCZMethod = env->GetMethodID(cls, "setBold", "(Z)Z");
    if (setBoldOZCZMethod == NULL) {
        std::cerr << "ITextStyle" << ": Could not find method: " << "setBold" << "(Z)Z" << std::endl;
    }

    isBoldOCZMethod = env->GetMethodID(cls, "isBold", "()Z");
    if (isBoldOCZMethod == NULL) {
        std::cerr << "ITextStyle" << ": Could not find method: " << "isBold" << "()Z" << std::endl;
    }

    availableFontsOCALjava_lang_StringEMethod = env->GetMethodID(cls, "availableFonts", "()[Ljava/lang/String;");
    if (availableFontsOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "ITextStyle" << ": Could not find method: " << "availableFonts" << "()[Ljava/lang/String;" << std::endl;
    }

    isUnderlinedOCZMethod = env->GetMethodID(cls, "isUnderlined", "()Z");
    if (isUnderlinedOCZMethod == NULL) {
        std::cerr << "ITextStyle" << ": Could not find method: " << "isUnderlined" << "()Z" << std::endl;
    }

    setFontOLjava_lang_StringECZMethod = env->GetMethodID(cls, "setFont", "(Ljava/lang/String;)Z");
    if (setFontOLjava_lang_StringECZMethod == NULL) {
        std::cerr << "ITextStyle" << ": Could not find method: " << "setFont" << "(Ljava/lang/String;)Z" << std::endl;
    }

}

JNIEXPORT JITextStyle::~JITextStyle() {
}

JNIEXPORT std::vector<std::string>  JITextStyle::availableFonts() const {
    vector<string> result;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, availableFontsOCALjava_lang_StringEMethod);

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

JNIEXPORT double JITextStyle::fontSize() const {
    jdouble result = env->CallDoubleMethod(ref, fontSizeOCDMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JITextStyle::setFontSize(double size) {
    jboolean result = env->CallBooleanMethod(ref, setFontSizeODCZMethod, size);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT std::string JITextStyle::font() const {
    jstring result = (jstring)env->CallObjectMethod(ref, fontOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    JNIUtil::checkExceptions(env);
    return resultString;
}

JNIEXPORT bool JITextStyle::setFont(const std::string & font) {
    jstring jfont;
    NEWSTRING(jfont, font)
    jboolean result = env->CallBooleanMethod(ref, setFontOLjava_lang_StringECZMethod, jfont);
    DELSTRING(jfont)
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JITextStyle::isBold() const {
    jboolean result = env->CallBooleanMethod(ref, isBoldOCZMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JITextStyle::isItalic() const {
    jboolean result = env->CallBooleanMethod(ref, isItalicOCZMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JITextStyle::isUnderlined() const {
    jboolean result = env->CallBooleanMethod(ref, isUnderlinedOCZMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JITextStyle::setBold(bool bold) {
    jboolean result = env->CallBooleanMethod(ref, setBoldOZCZMethod, bold);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JITextStyle::setItalic(bool italic) {
    jboolean result = env->CallBooleanMethod(ref, setItalicOZCZMethod, italic);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JITextStyle::setUnderlined(bool underlined) {
    jboolean result = env->CallBooleanMethod(ref, setUnderlinedOZCZMethod, underlined);
    JNIUtil::checkExceptions(env);
    return result;
}
