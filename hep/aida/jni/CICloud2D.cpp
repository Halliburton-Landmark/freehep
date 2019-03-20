
#include "FreeHepTypes.h"

#include <iostream>

#include "AIDA/IAxis.h"
#include "AIDA/ICloud2D.h"
#include "AIDA/IHistogram2D.h"

#include "ProxyFactory.h"

#include "CICloud2D.h"
#include "JICloud2D.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud2D_fill__DD(JNIEnv *env, jobject obj, jdouble x, jdouble y){
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x, y);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud2D_fill__DDD(JNIEnv *env, jobject obj, jdouble x, jdouble y, jdouble weight) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x, y, weight);
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud2D_lowerEdgeX(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->lowerEdgeX();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud2D_lowerEdgeY(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->lowerEdgeY();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud2D_upperEdgeX(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->upperEdgeX();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud2D_upperEdgeY(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->upperEdgeY();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud2D_valueX(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->valueX(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud2D_valueY(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->valueY(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud2D_weight(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->weight(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud2D_meanX(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->meanX();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud2D_meanY(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->meanY();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud2D_rmsX(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->rmsX();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud2D_rmsY(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->rmsY();
    return r;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud2D_convert__IDDIDD(JNIEnv *env, jobject obj, jint nBinsX, jdouble lowerEdgeX, jdouble upperEdgeX, jint nBinsY, jdouble lowerEdgeY, jdouble upperEdgeY) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;

    cref->convert(nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud2D_convert___3D_3D(JNIEnv *env, jobject obj, jdoubleArray jbinEdgesX, jdoubleArray jbinEdgesY) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;

    // convert double[] to vector<double>
    vector<double> binEdgesX;
    unsigned int lenX = env->GetArrayLength(jbinEdgesX);
    for (unsigned int ix=0; ix<lenX; ix++) {
        jdouble d;
        env->GetDoubleArrayRegion(jbinEdgesX, ix, 1, &d);
        binEdgesX.push_back(d);
    }

    // convert double[] to vector<double>
    vector<double> binEdgesY;
    unsigned int lenY = env->GetArrayLength(jbinEdgesY);
    for (unsigned int iy=0; iy<lenY; iy++) {
        jdouble d;
        env->GetDoubleArrayRegion(jbinEdgesY, iy, 1, &d);
        binEdgesY.push_back(d);
    }
    
    cref->convert(binEdgesX, binEdgesY);
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CICloud2D_histogram(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    const IHistogram2D & r = cref->histogram();
    return factory->create(env, r);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud2D_fillHistogram(JNIEnv *env, jobject obj, jobject jhist) {
	jclass cls = env->GetObjectClass(obj);
	
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud2D* cref = (ICloud2D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram2D* hist = factory->createIHistogram2D(env, jhist);
    cref->fillHistogram(*hist);
}
