
#include "FreeHepTypes.h"

#include <iostream>

#include "AIDA/IAxis.h"
#include "AIDA/ICloud1D.h"
#include "AIDA/IHistogram1D.h"

#include "ProxyFactory.h"

#include "CICloud1D.h"
#include "JICloud1D.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud1D_fill__D(JNIEnv *env, jobject obj, jdouble x){
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud1D* cref = (ICloud1D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud1D_fill__DD(JNIEnv *env, jobject obj, jdouble x, jdouble weight) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud1D* cref = (ICloud1D*)ProxyFactory::getCRef(crefID);;
    cref->fill(x, weight);
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud1D_lowerEdge(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud1D* cref = (ICloud1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->lowerEdge();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud1D_upperEdge(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud1D* cref = (ICloud1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->upperEdge();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud1D_value(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud1D* cref = (ICloud1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->value(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud1D_weight(JNIEnv *env, jobject obj, jint index) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud1D* cref = (ICloud1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->weight(index);
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud1D_mean(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud1D* cref = (ICloud1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->mean();
    return r;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud1D_rms(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud1D* cref = (ICloud1D*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->rms();
    return r;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud1D_convert__IDD(JNIEnv *env, jobject obj, jint nBins, jdouble lowerEdge, jdouble upperEdge) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud1D* cref = (ICloud1D*)ProxyFactory::getCRef(crefID);;

    cref->convert(nBins, lowerEdge, upperEdge);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud1D_convert___3D(JNIEnv *env, jobject obj, jdoubleArray jbinEdges) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud1D* cref = (ICloud1D*)ProxyFactory::getCRef(crefID);;

    // convert double[] to vector<double>
    vector<double> binEdges;
    unsigned int len = env->GetArrayLength(jbinEdges);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jbinEdges, i, 1, &d);
        binEdges.push_back(d);
    }
    
    cref->convert(binEdges);
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CICloud1D_histogram(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud1D* cref = (ICloud1D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    const IHistogram1D & r = cref->histogram();
    return factory->create(env, r);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud1D_fillHistogram(JNIEnv *env, jobject obj, jobject jhist) {
	jclass cls = env->GetObjectClass(obj);
	
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud1D* cref = (ICloud1D*)ProxyFactory::getCRef(crefID);;

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram1D* hist = factory->createIHistogram1D(env, jhist);
    cref->fillHistogram(*hist);
}
