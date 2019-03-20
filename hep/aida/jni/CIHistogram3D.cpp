
#include "FreeHepTypes.h"

#include <iostream>

#include "AIDA/IAxis.h"
#include "AIDA/IHistogram3D.h"

#include "ProxyFactory.h"

#include "CIHistogram3D.h"
#include "JIHistogram3D.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT void JNICALL Java_hep_aida_jni_CIHistogram3D_fill__DDD(JNIEnv *env, jobject obj, jdouble x, jdouble y, jdouble z){
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x, y, z);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIHistogram3D_fill__DDDD(JNIEnv *env, jobject obj, jdouble x, jdouble y, jdouble z, jdouble weight) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x, y, z, weight);
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_binMeanX(JNIEnv *env, jobject obj, jint xIndex, jint yIndex, jint zIndex) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binMeanX(xIndex, yIndex, zIndex);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_binMeanY(JNIEnv *env, jobject obj, jint xIndex, jint yIndex, jint zIndex) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binMeanY(xIndex, yIndex, zIndex);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_binMeanZ(JNIEnv *env, jobject obj, jint xIndex, jint yIndex, jint zIndex) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binMeanZ(xIndex, yIndex, zIndex);
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIHistogram3D_binEntries(JNIEnv *env, jobject obj, jint xIndex, jint yIndex, jint zIndex) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->binEntries(xIndex, yIndex, zIndex);
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIHistogram3D_binEntriesX(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->binEntriesX(index);
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIHistogram3D_binEntriesY(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->binEntriesY(index);
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIHistogram3D_binEntriesZ(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->binEntriesZ(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_binHeight(JNIEnv *env, jobject obj, jint xIndex, jint yIndex, jint zIndex) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binHeight(xIndex, yIndex, zIndex);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_binHeightX(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binHeightX(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_binHeightY(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binHeightY(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_binHeightZ(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binHeightZ(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_binError(JNIEnv *env, jobject obj, jint xIndex, jint yIndex, jint zIndex) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->binError(xIndex, yIndex, zIndex);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_meanX(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->meanX();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_meanY(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->meanY();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_meanZ(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->meanZ();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_rmsX(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->rmsX();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_rmsY(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->rmsY();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIHistogram3D_rmsZ(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->rmsZ();
    return r;
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIHistogram3D_xAxis(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    const IAxis& axis = cref->xAxis();
    return factory->create(env, axis);
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIHistogram3D_yAxis(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    const IAxis& axis = cref->yAxis();
    return factory->create(env, axis);
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIHistogram3D_zAxis(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    const IAxis& axis = cref->zAxis();
    return factory->create(env, axis);
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIHistogram3D_coordToIndexX(JNIEnv *env, jobject obj, jdouble coord) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->coordToIndexX(coord);
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIHistogram3D_coordToIndexY(JNIEnv *env, jobject obj, jdouble coord) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->coordToIndexY(coord);
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIHistogram3D_coordToIndexZ(JNIEnv *env, jobject obj, jdouble coord) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;
    jint r = cref->coordToIndexZ(coord);
    return r;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIHistogram3D_add(JNIEnv *env, jobject obj, jobject jhist) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IHistogram3D* cref = (IHistogram3D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram3D* hist = factory->createIHistogram3D(env, jhist);
    cref->add(*hist);
}
