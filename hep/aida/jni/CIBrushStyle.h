/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class hep_aida_jni_CIBrushStyle */

#ifndef _Included_hep_aida_jni_CIBrushStyle
#define _Included_hep_aida_jni_CIBrushStyle
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     hep_aida_jni_CIBrushStyle
 * Method:    availableColors
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIBrushStyle_availableColors
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIBrushStyle
 * Method:    color
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIBrushStyle_color
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIBrushStyle
 * Method:    opacity
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIBrushStyle_opacity
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIBrushStyle
 * Method:    setColor
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIBrushStyle_setColor
  (JNIEnv *, jobject, jstring);

/*
 * Class:     hep_aida_jni_CIBrushStyle
 * Method:    setOpacity
 * Signature: (D)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIBrushStyle_setOpacity
  (JNIEnv *, jobject, jdouble);

#ifdef __cplusplus
}
#endif
#endif
