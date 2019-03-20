
#include "FreeHepTypes.h"

#include "AIDA/IProfile.h"

#include "ProxyFactory.h"

#include "CIProfile.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIProfile_allEntries(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile* cref = (IProfile*)ProxyFactory::getCRef(crefID);;
    jint r = cref->allEntries();
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIProfile_extraEntries(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile* cref = (IProfile*)ProxyFactory::getCRef(crefID);;
    jint r = cref->extraEntries();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile_sumBinHeights(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile* cref = (IProfile*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->sumBinHeights();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile_sumAllBinHeights(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile* cref = (IProfile*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->sumAllBinHeights();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile_sumExtraBinHeights(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile* cref = (IProfile*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->sumExtraBinHeights();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile_minBinHeight(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile* cref = (IProfile*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->minBinHeight();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile_maxBinHeight(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile* cref = (IProfile*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->maxBinHeight();
    return r;
}
