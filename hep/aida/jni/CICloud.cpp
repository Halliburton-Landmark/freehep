
#include "FreeHepTypes.h"

#include "AIDA/ICloud.h"

#include "ProxyFactory.h"

#include "CICloud.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CICloud_sumOfWeights(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud* cref = (ICloud*)ProxyFactory::getCRef(crefID);;
    jdouble r = cref->sumOfWeights();
    return r;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud_convertToHistogram(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud* cref = (ICloud*)ProxyFactory::getCRef(crefID);;
    cref->convertToHistogram();
}

JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CICloud_isConverted(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud* cref = (ICloud*)ProxyFactory::getCRef(crefID);;
    jboolean r = cref->isConverted();
    return r;
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CICloud_maxEntries(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud* cref = (ICloud*)ProxyFactory::getCRef(crefID);;
    jint r = cref->maxEntries();
    return r;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CICloud_scale(JNIEnv *env, jobject obj, jdouble scale) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ICloud* cref = (ICloud*)ProxyFactory::getCRef(crefID);;
    cref->scale(scale);
}
