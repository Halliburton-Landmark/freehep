
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "JIAnnotation.h"
#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;

JNIEXPORT JIAnnotation::JIAnnotation(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    keyOICLjava_lang_StringEMethod = env->GetMethodID(cls, "key", "(I)Ljava/lang/String;");
    if (keyOICLjava_lang_StringEMethod == NULL) {
        std::cerr << "IAnnotation" << ": Could not find method: " << "key" << "(I)Ljava/lang/String;" << std::endl;
    }

    valueOICLjava_lang_StringEMethod = env->GetMethodID(cls, "value", "(I)Ljava/lang/String;");
    if (valueOICLjava_lang_StringEMethod == NULL) {
        std::cerr << "IAnnotation" << ": Could not find method: " << "value" << "(I)Ljava/lang/String;" << std::endl;
    }

    valueOLjava_lang_StringECLjava_lang_StringEMethod = env->GetMethodID(cls, "value", "(Ljava/lang/String;)Ljava/lang/String;");
    if (valueOLjava_lang_StringECLjava_lang_StringEMethod == NULL) {
        std::cerr << "IAnnotation" << ": Could not find method: " << "value" << "(Ljava/lang/String;)Ljava/lang/String;" << std::endl;
    }

    setValueOLjava_lang_StringELjava_lang_StringECVMethod = env->GetMethodID(cls, "setValue", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (setValueOLjava_lang_StringELjava_lang_StringECVMethod == NULL) {
        std::cerr << "IAnnotation" << ": Could not find method: " << "setValue" << "(Ljava/lang/String;Ljava/lang/String;)V" << std::endl;
    }

    removeItemOLjava_lang_StringECVMethod = env->GetMethodID(cls, "removeItem", "(Ljava/lang/String;)V");
    if (removeItemOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IAnnotation" << ": Could not find method: " << "removeItem" << "(Ljava/lang/String;)V" << std::endl;
    }

    sizeOCIMethod = env->GetMethodID(cls, "size", "()I");
    if (sizeOCIMethod == NULL) {
        std::cerr << "IAnnotation" << ": Could not find method: " << "size" << "()I" << std::endl;
    }

    addItemOLjava_lang_StringELjava_lang_StringEZCVMethod = env->GetMethodID(cls, "addItem", "(Ljava/lang/String;Ljava/lang/String;Z)V");
    if (addItemOLjava_lang_StringELjava_lang_StringEZCVMethod == NULL) {
        std::cerr << "IAnnotation" << ": Could not find method: " << "addItem" << "(Ljava/lang/String;Ljava/lang/String;Z)V" << std::endl;
    }

    resetOCVMethod = env->GetMethodID(cls, "reset", "()V");
    if (resetOCVMethod == NULL) {
        std::cerr << "IAnnotation" << ": Could not find method: " << "reset" << "()V" << std::endl;
    }

    setStickyOLjava_lang_StringEZCVMethod = env->GetMethodID(cls, "setSticky", "(Ljava/lang/String;Z)V");
    if (setStickyOLjava_lang_StringEZCVMethod == NULL) {
        std::cerr << "IAnnotation" << ": Could not find method: " << "setSticky" << "(Ljava/lang/String;Z)V" << std::endl;
    }

}

JNIEXPORT JIAnnotation::~JIAnnotation() {
}

JNIEXPORT bool JIAnnotation::addItem(const std::string & key, const std::string & value, bool sticky) {
   jstring jkey, jvalue;
   NEWSTRING(jkey, key)
   NEWSTRING(jvalue, value)
   jboolean obj = env->CallBooleanMethod(ref, addItemOLjava_lang_StringELjava_lang_StringEZCVMethod, jkey, jvalue, sticky);
   DELSTRING(jkey);
   DELSTRING(jvalue);
   return obj || !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIAnnotation::removeItem(const std::string & key) {
   jstring jkey;
   NEWSTRING(jkey, key)
   env->CallVoidMethod(ref, removeItemOLjava_lang_StringECVMethod, jkey);
   DELSTRING(jkey);
   return !JNIUtil::exceptions(env);
}

JNIEXPORT std::string JIAnnotation::value(const std::string & key) const {
    jstring jkey;
    NEWSTRING(jkey, key)
    jstring jvalue = (jstring)env->CallObjectMethod(ref, valueOLjava_lang_StringECLjava_lang_StringEMethod, jkey);
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(jvalue, &isCopy);
    string valueString = utf;
    if (isCopy) env->ReleaseStringUTFChars(jvalue, utf);
    DELSTRING(jkey)
    return valueString;
}

JNIEXPORT void JIAnnotation::setValue(const std::string & key, const std::string & value) {
    jstring jkey, jvalue;
    NEWSTRING(jkey, key)
    NEWSTRING(jvalue, value)
    env->CallVoidMethod(ref, setValueOLjava_lang_StringELjava_lang_StringECVMethod, jkey, jvalue);
    DELSTRING(jkey);
    DELSTRING(jvalue);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIAnnotation::setSticky(const std::string & key, bool sticky) {
    jstring jkey;
    NEWSTRING(jkey, key)
    env->CallVoidMethod(ref, setStickyOLjava_lang_StringEZCVMethod, jkey, sticky);
    DELSTRING(jkey);
	JNIUtil::checkExceptions(env);
}

JNIEXPORT int JIAnnotation::size() const {
	jint r = env->CallIntMethod(ref, sizeOCIMethod);
	JNIUtil::checkExceptions(env);
	return r;
}

JNIEXPORT std::string JIAnnotation::key(int index) const {
    jstring jvalue = (jstring)env->CallObjectMethod(ref, keyOICLjava_lang_StringEMethod, index);
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(jvalue, &isCopy);
    string keyString = utf;
    if (isCopy) env->ReleaseStringUTFChars(jvalue, utf);
    return keyString;
}

JNIEXPORT std::string JIAnnotation::value(int index) const {
    jstring jvalue = (jstring)env->CallObjectMethod(ref, valueOICLjava_lang_StringEMethod, index);
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(jvalue, &isCopy);
    string valuesString = utf;
    if (isCopy) env->ReleaseStringUTFChars(jvalue, utf);
    return valuesString;
}

JNIEXPORT void JIAnnotation::reset() {
   env->CallVoidMethod(ref, resetOCVMethod);
   JNIUtil::checkExceptions(env);
}
