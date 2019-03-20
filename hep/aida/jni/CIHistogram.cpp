
#include "FreeHepTypes.h"

#include "AIDA/IHistogram.h"

#include "ProxyFactory.h"

#include "CIHistogram.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIHistogram_allEntries(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram* cref = (IHistogram*)ProxyFactory::getCRef(crefID);;
    jint r = cref->allEntries();
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIHistogram_extraEntries(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram* cref = (IHistogram*)ProxyFactory::getCRef(crefID);;
    jint r = cref->extraEntries();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram_equivalentBinEntries(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram* cref = (IHistogram*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->equivalentBinEntries();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram_sumBinHeights(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram* cref = (IHistogram*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->sumBinHeights();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram_sumAllBinHeights(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram* cref = (IHistogram*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->sumAllBinHeights();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram_sumExtraBinHeights(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram* cref = (IHistogram*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->sumExtraBinHeights();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram_minBinHeight(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram* cref = (IHistogram*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->minBinHeight();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram_maxBinHeight(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram* cref = (IHistogram*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->maxBinHeight();
    return r;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIHistogram_scale(JNIEnv *env, jobject obj, jdouble scale) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram* cref = (IHistogram*)ProxyFactory::getCRef(crefID);;
    cref->scale(scale);
}
