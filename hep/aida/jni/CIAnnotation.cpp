
#include "FreeHepTypes.h"

#include "AIDA/IAnnotation.h"

#include "ProxyFactory.h"

#include "CIAnnotation.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT void JNICALL Java_hep_aida_jni_CIAnnotation_addItem__Ljava_lang_String_2Ljava_lang_String_2(JNIEnv *env, jobject obj, jstring jkey, jstring jvalue) {
    jboolean isCopy1;
    string key = env->GetStringUTFChars(jkey, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..
    string value = env->GetStringUTFChars(jvalue, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAnnotation* cref = (IAnnotation*)ProxyFactory::getCRef(crefID);;
    cref->addItem(key, value);
}


JNIEXPORT void JNICALL Java_hep_aida_jni_CIAnnotation_addItem__Ljava_lang_String_2Ljava_lang_String_2Z(JNIEnv *env, jobject obj, jstring jkey, jstring jvalue, jboolean sticky){
    jboolean isCopy1;
    string key = env->GetStringUTFChars(jkey, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..
    string value = env->GetStringUTFChars(jvalue, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAnnotation* cref = (IAnnotation*)ProxyFactory::getCRef(crefID);;
    cref->addItem(key, value, sticky);
}


JNIEXPORT void JNICALL Java_hep_aida_jni_CIAnnotation_removeItem(JNIEnv *env, jobject obj, jstring jkey) {
    jboolean isCopy1;
    string key = env->GetStringUTFChars(jkey, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAnnotation* cref = (IAnnotation*)ProxyFactory::getCRef(crefID);;
    cref->removeItem(key);
}


JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIAnnotation_value__Ljava_lang_String_2(JNIEnv *env, jobject obj, jstring jkey) {
    jboolean isCopy1;
    string key = env->GetStringUTFChars(jkey, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAnnotation* cref = (IAnnotation*)ProxyFactory::getCRef(crefID);;
    string value = cref->value(key);
    jstring jvalue = env->NewStringUTF(value.c_str());
    return jvalue;
}


JNIEXPORT void JNICALL Java_hep_aida_jni_CIAnnotation_setValue(JNIEnv *env, jobject obj, jstring jkey, jstring jvalue) {
    jboolean isCopy1;
    string key = env->GetStringUTFChars(jkey, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..
    string value = env->GetStringUTFChars(jvalue, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAnnotation* cref = (IAnnotation*)ProxyFactory::getCRef(crefID);;
    cref->setValue(key, value);
}


JNIEXPORT void JNICALL Java_hep_aida_jni_CIAnnotation_setSticky(JNIEnv *env, jobject obj, jstring jkey, jboolean sticky) {
    jboolean isCopy1;
    string key = env->GetStringUTFChars(jkey, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAnnotation* cref = (IAnnotation*)ProxyFactory::getCRef(crefID);;
    cref->setSticky(key, sticky);
}


JNIEXPORT jint JNICALL Java_hep_aida_jni_CIAnnotation_size(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAnnotation* cref = (IAnnotation*)ProxyFactory::getCRef(crefID);;
    jint r = cref->size();
    return r;
}


JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIAnnotation_key(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAnnotation* cref = (IAnnotation*)ProxyFactory::getCRef(crefID);;
    string key = cref->key(index);
    jstring jkey = env->NewStringUTF(key.c_str());
    return jkey;
}


JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIAnnotation_value__I(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAnnotation* cref = (IAnnotation*)ProxyFactory::getCRef(crefID);;
    string value = cref->value(index);
    jstring jvalue = env->NewStringUTF(value.c_str());
    return jvalue;
}


JNIEXPORT void JNICALL Java_hep_aida_jni_CIAnnotation_reset(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAnnotation* cref = (IAnnotation*)ProxyFactory::getCRef(crefID);;
    cref->reset();
}
