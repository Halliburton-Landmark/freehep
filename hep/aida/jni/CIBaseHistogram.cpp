
#include "FreeHepTypes.h"

#include <iostream>

#include "AIDA/IAnnotation.h"
#include "AIDA/IBaseHistogram.h"

#include "ProxyFactory.h"

#include "CIBaseHistogram.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIBaseHistogram_title(JNIEnv *env, jobject obj) {
    jclass cls = env->GetObjectClass(obj);
    jfieldID crefIDField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefIDField);
    IBaseHistogram* cref = (IBaseHistogram*)ProxyFactory::getCRef(crefID);
    string title = cref->title();
    jstring jtitle = env->NewStringUTF(title.c_str());
    return jtitle;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIBaseHistogram_setTitle(JNIEnv *env, jobject obj, jstring jtitle) {
    jboolean isCopy1;
    string title = env->GetStringUTFChars(jtitle, &isCopy1);
    // FIXME 4.0 we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBaseHistogram* cref = (IBaseHistogram*)ProxyFactory::getCRef(crefID);
    cref->setTitle(title);
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIBaseHistogram_annotation(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);

	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBaseHistogram* cref = (IBaseHistogram*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();

    const IAnnotation& annotation = cref->annotation();
    return factory->create(env, annotation);
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIBaseHistogram_dimension(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBaseHistogram* cref = (IBaseHistogram*)ProxyFactory::getCRef(crefID);
    jint r = cref->dimension();
    return r;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIBaseHistogram_reset(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBaseHistogram* cref = (IBaseHistogram*)ProxyFactory::getCRef(crefID);
    cref->reset();
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIBaseHistogram_entries(JNIEnv *env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBaseHistogram* cref = (IBaseHistogram*)ProxyFactory::getCRef(crefID);
    jint r = cref->entries();
    return r;
}
