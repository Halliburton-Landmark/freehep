
#include "FreeHepTypes.h"

#include "AIDA/IAxis.h"

#include "ProxyFactory.h"

#include "CIAxis.h"

using namespace AIDA;
using namespace JAIDA;

JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIAxis_isFixedBinning(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxis* cref = (IAxis*)ProxyFactory::getCRef(crefID);;
    jboolean r = cref->isFixedBinning();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIAxis_lowerEdge(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxis* cref = (IAxis*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->lowerEdge();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIAxis_upperEdge(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxis* cref = (IAxis*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->upperEdge();
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIAxis_bins(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxis* cref = (IAxis*)ProxyFactory::getCRef(crefID);;
    jint r = cref->bins();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIAxis_binLowerEdge(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxis* cref = (IAxis*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binLowerEdge(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIAxis_binUpperEdge(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxis* cref = (IAxis*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binUpperEdge(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIAxis_binWidth(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxis* cref = (IAxis*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binWidth(index);
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIAxis_coordToIndex(JNIEnv *env, jobject obj, jdouble coord) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxis* cref = (IAxis*)ProxyFactory::getCRef(crefID);;
    jint r = cref->coordToIndex(coord);
    return r;
}
