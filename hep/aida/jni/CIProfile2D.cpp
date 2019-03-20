
#include "FreeHepTypes.h"

#include <iostream>

#include "AIDA/IAxis.h"
#include "AIDA/IProfile2D.h"

#include "ProxyFactory.h"

#include "CIProfile2D.h"
#include "JIProfile2D.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT void JNICALL Java_hep_aida_jni_CIProfile2D_fill__DDD(JNIEnv *env, jobject obj, jdouble x, jdouble y, jdouble z){
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x, y, z);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIProfile2D_fill__DDDD(JNIEnv *env, jobject obj, jdouble x, jdouble y, jdouble z, jdouble weight) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x, y, z, weight);
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile2D_binMeanX(JNIEnv *env, jobject obj, jint xIndex, jint yIndex) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binMeanX(xIndex, yIndex);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile2D_binMeanY(JNIEnv *env, jobject obj, jint xIndex, jint yIndex) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binMeanY(xIndex, yIndex);
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIProfile2D_binEntries(JNIEnv *env, jobject obj, jint xIndex, jint yIndex) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->binEntries(xIndex, yIndex);
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIProfile2D_binEntriesX(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->binEntriesX(index);
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIProfile2D_binEntriesY(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->binEntriesY(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile2D_binHeight(JNIEnv *env, jobject obj, jint xIndex, jint yIndex) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binHeight(xIndex, yIndex);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile2D_binHeightX(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binHeightX(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile2D_binHeightY(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binHeightY(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile2D_binError(JNIEnv *env, jobject obj, jint xIndex, jint yIndex) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binError(xIndex, yIndex);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile2D_binRms(JNIEnv *env, jobject obj, jint xIndex, jint yIndex) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binRms(xIndex, yIndex);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile2D_meanX(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->meanX();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile2D_meanY(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->meanY();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile2D_rmsX(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->rmsX();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIProfile2D_rmsY(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->rmsY();
    return r;
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIProfile2D_xAxis(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    const IAxis& axis = cref->xAxis();
    return factory->create(env, axis);
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIProfile2D_yAxis(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    const IAxis& axis = cref->yAxis();
    return factory->create(env, axis);
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIProfile2D_coordToIndexX(JNIEnv *env, jobject obj, jdouble coord) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->coordToIndexX(coord);
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIProfile2D_coordToIndexY(JNIEnv *env, jobject obj, jdouble coord) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->coordToIndexY(coord);
    return r;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIProfile2D_add(JNIEnv *env, jobject obj, jobject jhist) {
	jclass cls = env->GetObjectClass(obj);
	
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IProfile2D* cref = (IProfile2D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    IProfile2D* p = factory->createIProfile2D(env, jhist);
    cref->add(*p);
}
