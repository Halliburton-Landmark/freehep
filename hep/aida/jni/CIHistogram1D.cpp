
#include "FreeHepTypes.h"

#include <iostream>

#include "AIDA/IAxis.h"
#include "AIDA/IHistogram1D.h"

#include "ProxyFactory.h"

#include "CIHistogram1D.h"
#include "JIHistogram1D.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT void JNICALL Java_hep_aida_jni_CIHistogram1D_fill__D(JNIEnv *env, jobject obj, jdouble x){
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram1D* cref = (IHistogram1D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIHistogram1D_fill__DD(JNIEnv *env, jobject obj, jdouble x, jdouble weight) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram1D* cref = (IHistogram1D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x, weight);
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram1D_binMean(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram1D* cref = (IHistogram1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binMean(index);
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIHistogram1D_binEntries(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram1D* cref = (IHistogram1D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->binEntries(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram1D_binHeight(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram1D* cref = (IHistogram1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binHeight(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram1D_binError(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram1D* cref = (IHistogram1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binError(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram1D_mean(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram1D* cref = (IHistogram1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->mean();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram1D_rms(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram1D* cref = (IHistogram1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->rms();
    return r;
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIHistogram1D_axis(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefIDField = env->GetFieldID(cls, "crefID", "J");
	jlong crefID = env->GetLongField(obj, crefIDField);
	IHistogram1D* cref = (IHistogram1D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    const IAxis& axis = cref->axis();
    return factory->create(env, axis);
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIHistogram1D_coordToIndex(JNIEnv *env, jobject obj, jdouble coord) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram1D* cref = (IHistogram1D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->coordToIndex(coord);
    return r;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIHistogram1D_add(JNIEnv *env, jobject obj, jobject jhist) {
	jclass cls = env->GetObjectClass(obj);
	
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram1D* cref = (IHistogram1D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram1D* hist = factory->createIHistogram1D(env, jhist);
    cref->add(*hist);
}
