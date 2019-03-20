
#include "FreeHepTypes.h"

#include <vector>

#include "AIDA/ITextStyle.h"

#include "ProxyFactory.h"

#include "CITextStyle.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    availableFonts
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CITextStyle_availableFonts
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> names = cref->availableFonts();

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jnames = (jobjectArray)env->NewObjectArray(names.size(), stringClass, NULL);
    for (unsigned int index=0; index<names.size(); index++) {
	    jobject jtmp = env->NewStringUTF(names[index].c_str());
        env->SetObjectArrayElement(jnames, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jnames;
}

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    fontSize
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CITextStyle_fontSize
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    return cref->fontSize();
}

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    setFontSize
 * Signature: (D)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITextStyle_setFontSize
  (JNIEnv *env, jobject obj, jdouble jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    return cref->setFontSize(jvalue);
}

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    font
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CITextStyle_font
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    string value = cref->font();
    jstring jvalue = env->NewStringUTF(value.c_str());
    return jvalue;
}

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    setFont
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITextStyle_setFont
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    return cref->setFont(name);
}

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    isBold
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITextStyle_isBold
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    return cref->isBold();
}

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    isItalic
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITextStyle_isItalic
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    return cref->isItalic();
}

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    isUnderlined
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITextStyle_isUnderlined
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    return cref->isUnderlined();
}

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    setBold
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITextStyle_setBold__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    return cref->setBold();
}

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    setBold
 * Signature: (Z)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITextStyle_setBold__Z
  (JNIEnv *env, jobject obj, jboolean jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    return cref->setBold(jvalue);
}

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    setItalic
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITextStyle_setItalic__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    return cref->setItalic();
}

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    setItalic
 * Signature: (Z)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITextStyle_setItalic__Z
  (JNIEnv *env, jobject obj, jboolean jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    return cref->setItalic(jvalue);
}

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    setUnderlined
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITextStyle_setUnderlined__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    return cref->setUnderlined();
}

/*
 * Class:     hep_aida_jni_CITextStyle
 * Method:    setUnderlined
 * Signature: (Z)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITextStyle_setUnderlined__Z
  (JNIEnv *env, jobject obj, jboolean jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITextStyle* cref = (ITextStyle*)ProxyFactory::getCRef(crefID);

    return cref->setUnderlined(jvalue);
}

