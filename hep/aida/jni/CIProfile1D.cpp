
#include "FreeHepTypes.h"

#include <iostream>

#include "AIDA/IAxis.h"
#include "AIDA/IProfile1D.h"

#include "ProxyFactory.h"

#include "CIProfile1D.h"
#include "JIProfile1D.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT void JNICALL Java_hep_aida_jni_CIProfile1D_fill__DD(JNIEnv *env, jobject obj, jdouble x, jdouble y){
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile1D* cref = (IProfile1D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x, y);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIProfile1D_fill__DDD(JNIEnv *env, jobject obj, jdouble x, jdouble y, jdouble weight) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile1D* cref = (IProfile1D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x, y, weight);
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile1D_binMean(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile1D* cref = (IProfile1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binMean(index);
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIProfile1D_binEntries(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile1D* cref = (IProfile1D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->binEntries(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile1D_binHeight(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile1D* cref = (IProfile1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binHeight(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile1D_binError(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile1D* cref = (IProfile1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binError(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile1D_binRms(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile1D* cref = (IProfile1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binRms(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile1D_mean(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile1D* cref = (IProfile1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->mean();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile1D_rms(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile1D* cref = (IProfile1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->rms();
    return r;
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIProfile1D_axis(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile1D* cref = (IProfile1D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    const IAxis& axis = cref->axis();
    return factory->create(env, axis);
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIProfile1D_coordToIndex(JNIEnv *env, jobject obj, jdouble coord) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile1D* cref = (IProfile1D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->coordToIndex(coord);
    return r;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIProfile1D_add(JNIEnv *env, jobject obj, jobject jhist) {
	jclass cls = env->GetObjectClass(obj);
	
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile1D* cref = (IProfile1D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    IProfile1D* p = factory->createIProfile1D(env, jhist);
    cref->add(*p);
}
