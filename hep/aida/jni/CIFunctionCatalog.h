/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class hep_aida_jni_CIFunctionCatalog */

#ifndef _Included_hep_aida_jni_CIFunctionCatalog
#define _Included_hep_aida_jni_CIFunctionCatalog
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     hep_aida_jni_CIFunctionCatalog
 * Method:    add
 * Signature: (Ljava/lang/String;Lhep/aida/IFunction;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIFunctionCatalog_add__Ljava_lang_String_2Lhep_aida_IFunction_2
  (JNIEnv *, jobject, jstring, jobject);

/*
 * Class:     hep_aida_jni_CIFunctionCatalog
 * Method:    add
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIFunctionCatalog_add__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     hep_aida_jni_CIFunctionCatalog
 * Method:    list
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIFunctionCatalog_list
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIFunctionCatalog
 * Method:    remove
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFunctionCatalog_remove
  (JNIEnv *, jobject, jstring);

/*
 * Class:     hep_aida_jni_CIFunctionCatalog
 * Method:    storeAll
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFunctionCatalog_storeAll
  (JNIEnv *, jobject, jstring);

/*
 * Class:     hep_aida_jni_CIFunctionCatalog
 * Method:    loadAll
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFunctionCatalog_loadAll
  (JNIEnv *, jobject, jstring);

#ifdef __cplusplus
}
#endif
#endif