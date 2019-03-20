/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class hep_aida_jni_CIAnnotation */

#ifndef _Included_hep_aida_jni_CIAnnotation
#define _Included_hep_aida_jni_CIAnnotation
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     hep_aida_jni_CIAnnotation
 * Method:    addItem
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIAnnotation_addItem__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     hep_aida_jni_CIAnnotation
 * Method:    addItem
 * Signature: (Ljava/lang/String;Ljava/lang/String;Z)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIAnnotation_addItem__Ljava_lang_String_2Ljava_lang_String_2Z
  (JNIEnv *, jobject, jstring, jstring, jboolean);

/*
 * Class:     hep_aida_jni_CIAnnotation
 * Method:    removeItem
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIAnnotation_removeItem
  (JNIEnv *, jobject, jstring);

/*
 * Class:     hep_aida_jni_CIAnnotation
 * Method:    value
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIAnnotation_value__Ljava_lang_String_2
  (JNIEnv *, jobject, jstring);

/*
 * Class:     hep_aida_jni_CIAnnotation
 * Method:    setValue
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIAnnotation_setValue
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     hep_aida_jni_CIAnnotation
 * Method:    setSticky
 * Signature: (Ljava/lang/String;Z)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIAnnotation_setSticky
  (JNIEnv *, jobject, jstring, jboolean);

/*
 * Class:     hep_aida_jni_CIAnnotation
 * Method:    size
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIAnnotation_size
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIAnnotation
 * Method:    key
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIAnnotation_key
  (JNIEnv *, jobject, jint);

/*
 * Class:     hep_aida_jni_CIAnnotation
 * Method:    value
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIAnnotation_value__I
  (JNIEnv *, jobject, jint);

/*
 * Class:     hep_aida_jni_CIAnnotation
 * Method:    reset
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIAnnotation_reset
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif