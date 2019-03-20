
#include "FreeHepTypes.h"

#include <iostream>

#include "AIDA/IAxis.h"
#include "AIDA/ICloud3D.h"
#include "AIDA/IHistogram3D.h"

#include "ProxyFactory.h"

#include "CICloud3D.h"
#include "JICloud3D.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud3D_fill__DDD(JNIEnv *env, jobject obj, jdouble x, jdouble y, jdouble z){
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x, y, z);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud3D_fill__DDDD(JNIEnv *env, jobject obj, jdouble x, jdouble y, jdouble z, jdouble weight) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x, y, z, weight);
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_lowerEdgeX(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->lowerEdgeX();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_lowerEdgeY(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->lowerEdgeY();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_lowerEdgeZ(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->lowerEdgeZ();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_upperEdgeX(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->upperEdgeX();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_upperEdgeY(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->upperEdgeY();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_upperEdgeZ(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->upperEdgeZ();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_valueX(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->valueX(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_valueY(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->valueY(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_valueZ(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->valueZ(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_weight(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->weight(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_meanX(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->meanX();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_meanY(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->meanY();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_meanZ(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->meanZ();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_rmsX(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->rmsX();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_rmsY(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->rmsY();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud3D_rmsZ(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->rmsZ();
    return r;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud3D_convert__IDDIDDIDD(JNIEnv *env, jobject obj, jint nBinsX, jdouble lowerEdgeX, jdouble upperEdgeX, 
                                                                                                jint nBinsY, jdouble lowerEdgeY, jdouble upperEdgeY,
                                                                                                jint nBinsZ, jdouble lowerEdgeZ, jdouble upperEdgeZ) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;

    cref->convert(nBinsX, lowerEdgeX, upperEdgeX, 
                  nBinsY, lowerEdgeY, upperEdgeY,
                  nBinsZ, lowerEdgeZ, upperEdgeZ);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud3D_convert___3D_3D_3D(JNIEnv *env, jobject obj, jdoubleArray jbinEdgesX, 
                                                                                                jdoubleArray jbinEdgesY, 
                                                                                                jdoubleArray jbinEdgesZ) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;

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
    
    // convert double[] to vector<double>
    vector<double> binEdgesZ;
    unsigned int lenZ = env->GetArrayLength(jbinEdgesZ);
    for (unsigned int iz=0; iz<lenZ; iz++) {
        jdouble d;
        env->GetDoubleArrayRegion(jbinEdgesZ, iz, 1, &d);
        binEdgesZ.push_back(d);
    }
    
    cref->convert(binEdgesX, binEdgesY, binEdgesZ);
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CICloud3D_histogram(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    const IHistogram3D & r = cref->histogram();
    return factory->create(env, r);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud3D_fillHistogram(JNIEnv *env, jobject obj, jobject jhist) {
	jclass cls = env->GetObjectClass(obj);
	
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud3D* cref = (ICloud3D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram3D* hist = factory->createIHistogram3D(env, jhist);
    cref->fillHistogram(*hist);
}
