/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class hep_aida_jni_CIEvaluator */

#ifndef _Included_hep_aida_jni_CIEvaluator
#define _Included_hep_aida_jni_CIEvaluator
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     hep_aida_jni_CIEvaluator
 * Method:    initialize
 * Signature: (Lhep/aida/ITuple;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIEvaluator_initialize
  (JNIEnv *, jobject, jobject);

/*
 * Class:     hep_aida_jni_CIEvaluator
 * Method:    evaluateDouble
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIEvaluator_evaluateDouble
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIEvaluator
 * Method:    expression
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIEvaluator_expression
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
