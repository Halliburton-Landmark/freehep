/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class hep_aida_jni_CIDataPointSet */

#ifndef _Included_hep_aida_jni_CIDataPointSet
#define _Included_hep_aida_jni_CIDataPointSet
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    annotation
 * Signature: ()Lhep/aida/IAnnotation;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIDataPointSet_annotation
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    title
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIDataPointSet_title
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    setTitle
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_setTitle
  (JNIEnv *, jobject, jstring);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    dimension
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIDataPointSet_dimension
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    clear
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_clear
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    size
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIDataPointSet_size
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    point
 * Signature: (I)Lhep/aida/IDataPoint;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIDataPointSet_point
  (JNIEnv *, jobject, jint);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    setCoordinate
 * Signature: (I[D[D)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_setCoordinate__I_3D_3D
  (JNIEnv *, jobject, jint, jdoubleArray, jdoubleArray);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    setCoordinate
 * Signature: (I[D[D[D)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_setCoordinate__I_3D_3D_3D
  (JNIEnv *, jobject, jint, jdoubleArray, jdoubleArray, jdoubleArray);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    addPoint
 * Signature: ()Lhep/aida/IDataPoint;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIDataPointSet_addPoint__
  (JNIEnv *, jobject);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    addPoint
 * Signature: (Lhep/aida/IDataPoint;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_addPoint__Lhep_aida_IDataPoint_2
  (JNIEnv *, jobject, jobject);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    removePoint
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_removePoint
  (JNIEnv *, jobject, jint);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    lowerExtent
 * Signature: (I)D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIDataPointSet_lowerExtent
  (JNIEnv *, jobject, jint);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    upperExtent
 * Signature: (I)D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIDataPointSet_upperExtent
  (JNIEnv *, jobject, jint);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    scale
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_scale
  (JNIEnv *, jobject, jdouble);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    scaleValues
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_scaleValues
  (JNIEnv *, jobject, jdouble);

/*
 * Class:     hep_aida_jni_CIDataPointSet
 * Method:    scaleErrors
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_scaleErrors
  (JNIEnv *, jobject, jdouble);

#ifdef __cplusplus
}
#endif
#endif