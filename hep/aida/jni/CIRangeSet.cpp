
#include "FreeHepTypes.h"

#include "AIDA/IRangeSet.h"

#include "ProxyFactory.h"

#include "CIRangeSet.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIRangeSet
 * Method:    lowerBounds
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL Java_hep_aida_jni_CIRangeSet_lowerBounds
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IRangeSet* cref = (IRangeSet*)ProxyFactory::getCRef(crefID);

    vector<double> result = cref->lowerBounds();

    jdoubleArray jresult = env->NewDoubleArray(result.size());
    for (unsigned int index=0; index<result.size(); index++) {\
        env->SetDoubleArrayRegion(jresult, index, 1, (jdouble*)(&(result[index])) );
    }

    return jresult;
}

/*
 * Class:     hep_aida_jni_CIRangeSet
 * Method:    upperBounds
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL Java_hep_aida_jni_CIRangeSet_upperBounds
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IRangeSet* cref = (IRangeSet*)ProxyFactory::getCRef(crefID);

    vector<double> result = cref->upperBounds();

    jdoubleArray jresult = env->NewDoubleArray(result.size());
    for (unsigned int index=0; index<result.size(); index++) {\
        env->SetDoubleArrayRegion(jresult, index, 1, (jdouble*)(&(result[index])) );
    }

    return jresult;
}

/*
 * Class:     hep_aida_jni_CIRangeSet
 * Method:    include
 * Signature: (DD)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIRangeSet_include
  (JNIEnv *env, jobject obj, jdouble jvalue1, jdouble jvalue2) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IRangeSet* cref = (IRangeSet*)ProxyFactory::getCRef(crefID);

    cref->include(jvalue1, jvalue2);
}

/*
 * Class:     hep_aida_jni_CIRangeSet
 * Method:    exclude
 * Signature: (DD)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIRangeSet_exclude
  (JNIEnv *env, jobject obj, jdouble jvalue1, jdouble jvalue2) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IRangeSet* cref = (IRangeSet*)ProxyFactory::getCRef(crefID);

    cref->exclude(jvalue1, jvalue2);
}

/*
 * Class:     hep_aida_jni_CIRangeSet
 * Method:    includeAll
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIRangeSet_includeAll
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IRangeSet* cref = (IRangeSet*)ProxyFactory::getCRef(crefID);

    cref->includeAll();
}

/*
 * Class:     hep_aida_jni_CIRangeSet
 * Method:    excludeAll
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIRangeSet_excludeAll
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IRangeSet* cref = (IRangeSet*)ProxyFactory::getCRef(crefID);

    cref->excludeAll();
}

/*
 * Class:     hep_aida_jni_CIRangeSet
 * Method:    isInRange
 * Signature: (D)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIRangeSet_isInRange
  (JNIEnv *env, jobject obj, jdouble jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IRangeSet* cref = (IRangeSet*)ProxyFactory::getCRef(crefID);

    return cref->isInRange(jvalue);
}

/*
 * Class:     hep_aida_jni_CIRangeSet
 * Method:    size
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIRangeSet_size
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IRangeSet* cref = (IRangeSet*)ProxyFactory::getCRef(crefID);

    return cref->size();
}

/*
 * Class:     hep_aida_jni_CIRangeSet
 * Method:    PLUS_INF
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIRangeSet_PLUS_1INF
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IRangeSet* cref = (IRangeSet*)ProxyFactory::getCRef(crefID);

    return cref->PLUS_INF();
}

/*
 * Class:     hep_aida_jni_CIRangeSet
 * Method:    MINUS_INF
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIRangeSet_MINUS_1INF
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IRangeSet* cref = (IRangeSet*)ProxyFactory::getCRef(crefID);

    return cref->MINUS_INF();
}

