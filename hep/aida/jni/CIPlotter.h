/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class hep_aida_jni_CIPlotter */

#ifndef _Included_hep_aida_jni_CIPlotter
#define _Included_hep_aida_jni_CIPlotter
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegion
 * Signature: ()Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_createRegion__
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegion
 * Signature: (D)Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_createRegion__D
  (JNIEnv *, jobject, jdouble);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegion
 * Signature: (DD)Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_createRegion__DD
  (JNIEnv *, jobject, jdouble, jdouble);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegion
 * Signature: (DDD)Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_createRegion__DDD
  (JNIEnv *, jobject, jdouble, jdouble, jdouble);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegion
 * Signature: (DDDD)Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_createRegion__DDDD
  (JNIEnv *, jobject, jdouble, jdouble, jdouble, jdouble);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegions
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_createRegions__
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegions
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_createRegions__I
  (JNIEnv *, jobject, jint);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegions
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_createRegions__II
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegions
 * Signature: (III)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_createRegions__III
  (JNIEnv *, jobject, jint, jint, jint);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    currentRegion
 * Signature: ()Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_currentRegion
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    currentRegionNumber
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIPlotter_currentRegionNumber
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    numberOfRegions
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIPlotter_numberOfRegions
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    setCurrentRegionNumber
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_setCurrentRegionNumber
  (JNIEnv *, jobject, jint);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    next
 * Signature: ()Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_next
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    region
 * Signature: (I)Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_region
  (JNIEnv *, jobject, jint);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    destroyRegions
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_destroyRegions
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    clearRegions
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_clearRegions
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    setParameter
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_setParameter__Ljava_lang_String_2
  (JNIEnv *, jobject, jstring);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    setParameter
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_setParameter__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    parameterValue
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIPlotter_parameterValue
  (JNIEnv *, jobject, jstring);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    availableParameterOptions
 * Signature: (Ljava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIPlotter_availableParameterOptions
  (JNIEnv *, jobject, jstring);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    availableParameters
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIPlotter_availableParameters
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    show
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_show
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    refresh
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_refresh
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    hide
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_hide
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    interact
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_interact
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    writeToFile
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_writeToFile__Ljava_lang_String_2
  (JNIEnv *, jobject, jstring);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    writeToFile
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_writeToFile__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    setTitle
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_setTitle
  (JNIEnv *, jobject, jstring);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    titleStyle
 * Signature: ()Lhep/aida/ITitleStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_titleStyle
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    setTitleStyle
 * Signature: (Lhep/aida/ITitleStyle;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_setTitleStyle
  (JNIEnv *, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif
