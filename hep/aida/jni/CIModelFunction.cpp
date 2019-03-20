
#include "FreeHepTypes.h"

#include "AIDA/IModelFunction.h"

#include "ProxyFactory.h"

#include "CIModelFunction.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIModelFunction
 * Method:    providesNormalization
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIModelFunction_providesNormalization
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IModelFunction* cref = (IModelFunction*)ProxyFactory::getCRef(crefID);

    return cref->providesNormalization();
}

/*
 * Class:     hep_aida_jni_CIModelFunction
 * Method:    normalize
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIModelFunction_normalize
  (JNIEnv *env, jobject obj, jboolean jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IModelFunction* cref = (IModelFunction*)ProxyFactory::getCRef(crefID);

    cref->normalize(jvalue);
}

/*
 * Class:     hep_aida_jni_CIModelFunction
 * Method:    isNormalized
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIModelFunction_isNormalized
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IModelFunction* cref = (IModelFunction*)ProxyFactory::getCRef(crefID);

    return cref->isNormalized();
}

/*
 * Class:     hep_aida_jni_CIModelFunction
 * Method:    parameterGradient
 * Signature: ([D)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_hep_aida_jni_CIModelFunction_parameterGradient
  (JNIEnv *env, jobject obj, jdoubleArray jvalue) {

    vector<double> value;
    unsigned int len = env->GetArrayLength(jvalue);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jvalue, i, 1, &d);
        value.push_back(d);
    }

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IModelFunction* cref = (IModelFunction*)ProxyFactory::getCRef(crefID);

    vector<double> result = cref->parameterGradient(value);

    jdoubleArray jresult = env->NewDoubleArray(result.size());
    for (unsigned int index=0; index<result.size(); index++) {\
        env->SetDoubleArrayRegion(jresult, index, 1, (jdouble*)(&(result[index])) );
    }

    return jresult;
}

/*
 * Class:     hep_aida_jni_CIModelFunction
 * Method:    providesParameterGradient
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIModelFunction_providesParameterGradient
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IModelFunction* cref = (IModelFunction*)ProxyFactory::getCRef(crefID);

    return cref->providesParameterGradient();
}

/*
 * Class:     hep_aida_jni_CIModelFunction
 * Method:    normalizationRange
 * Signature: (I)Lhep/aida/IRangeSet;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIModelFunction_normalizationRange
  (JNIEnv *env, jobject obj, jint jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IModelFunction* cref = (IModelFunction*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();

    const IRangeSet& rangeSet = cref->normalizationRange(jvalue);
    return factory->create(env, rangeSet);
}

/*
 * Class:     hep_aida_jni_CIModelFunction
 * Method:    includeNormalizationAll
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIModelFunction_includeNormalizationAll
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IModelFunction* cref = (IModelFunction*)ProxyFactory::getCRef(crefID);

    cref->includeNormalizationAll();
}

/*
 * Class:     hep_aida_jni_CIModelFunction
 * Method:    excludeNormalizationAll
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIModelFunction_excludeNormalizationAll
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IModelFunction* cref = (IModelFunction*)ProxyFactory::getCRef(crefID);

    cref->excludeNormalizationAll();
}

