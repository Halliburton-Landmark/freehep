
#include "FreeHepTypes.h"

#include "AIDA/IFitParameterSettings.h"

#include "ProxyFactory.h"

#include "CIFitParameterSettings.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIFitParameterSettings
 * Method:    name
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIFitParameterSettings_name
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitParameterSettings* cref = (IFitParameterSettings*)ProxyFactory::getCRef(crefID);

    string result = cref->name();
    jstring jresult = env->NewStringUTF(result.c_str());
    return jresult;
}

/*
 * Class:     hep_aida_jni_CIFitParameterSettings
 * Method:    stepSize
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIFitParameterSettings_stepSize
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitParameterSettings* cref = (IFitParameterSettings*)ProxyFactory::getCRef(crefID);
	
	return cref->stepSize();
}

/*
 * Class:     hep_aida_jni_CIFitParameterSettings
 * Method:    upperBound
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIFitParameterSettings_upperBound
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitParameterSettings* cref = (IFitParameterSettings*)ProxyFactory::getCRef(crefID);
	
	return cref->upperBound();
}

/*
 * Class:     hep_aida_jni_CIFitParameterSettings
 * Method:    lowerBound
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIFitParameterSettings_lowerBound
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitParameterSettings* cref = (IFitParameterSettings*)ProxyFactory::getCRef(crefID);
	
	return cref->lowerBound();
}

/*
 * Class:     hep_aida_jni_CIFitParameterSettings
 * Method:    isBound
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIFitParameterSettings_isBound
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitParameterSettings* cref = (IFitParameterSettings*)ProxyFactory::getCRef(crefID);
	
	return cref->isBound();
}

/*
 * Class:     hep_aida_jni_CIFitParameterSettings
 * Method:    isFixed
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIFitParameterSettings_isFixed
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitParameterSettings* cref = (IFitParameterSettings*)ProxyFactory::getCRef(crefID);
	
	return cref->isFixed();
}

/*
 * Class:     hep_aida_jni_CIFitParameterSettings
 * Method:    setStepSize
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitParameterSettings_setStepSize
  (JNIEnv *env, jobject obj, jdouble step) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitParameterSettings* cref = (IFitParameterSettings*)ProxyFactory::getCRef(crefID);
	
	cref->setStepSize(step);
}

/*
 * Class:     hep_aida_jni_CIFitParameterSettings
 * Method:    setBounds
 * Signature: (DD)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitParameterSettings_setBounds
  (JNIEnv *env, jobject obj, jdouble low, jdouble high) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitParameterSettings* cref = (IFitParameterSettings*)ProxyFactory::getCRef(crefID);
	
	cref->setBounds(low, high);
}

/*
 * Class:     hep_aida_jni_CIFitParameterSettings
 * Method:    removeBounds
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitParameterSettings_removeBounds
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitParameterSettings* cref = (IFitParameterSettings*)ProxyFactory::getCRef(crefID);
	
	cref->removeBounds();
}

/*
 * Class:     hep_aida_jni_CIFitParameterSettings
 * Method:    setFixed
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitParameterSettings_setFixed
  (JNIEnv *env, jobject obj, jboolean fixed) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitParameterSettings* cref = (IFitParameterSettings*)ProxyFactory::getCRef(crefID);

    cref->setFixed(fixed);
}

/*
 * Class:     hep_aida_jni_CIFitParameterSettings
 * Method:    setLowerBound
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitParameterSettings_setLowerBound
  (JNIEnv *env, jobject obj, jdouble val) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitParameterSettings* cref = (IFitParameterSettings*)ProxyFactory::getCRef(crefID);

    cref->setLowerBound(val);
}

/*
 * Class:     hep_aida_jni_CIFitParameterSettings
 * Method:    setUpperBound
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitParameterSettings_setUpperBound
  (JNIEnv *env, jobject obj, jdouble val) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitParameterSettings* cref = (IFitParameterSettings*)ProxyFactory::getCRef(crefID);
	
	cref->setUpperBound(val);
}

/*
 * Class:     hep_aida_jni_CIFitParameterSettings
 * Method:    reset
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitParameterSettings_reset
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitParameterSettings* cref = (IFitParameterSettings*)ProxyFactory::getCRef(crefID);

    cref->reset();
}
