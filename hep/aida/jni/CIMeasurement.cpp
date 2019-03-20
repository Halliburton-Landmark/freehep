#include "FreeHepTypes.h"

#include "AIDA/IMeasurement.h"

#include "ProxyFactory.h"

#include "CIMeasurement.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIMeasurement_value
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IMeasurement* cref = (IMeasurement*)ProxyFactory::getCRef(crefID);
 
    return cref->value();
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIMeasurement_errorPlus
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IMeasurement* cref = (IMeasurement*)ProxyFactory::getCRef(crefID);
 
    return cref->errorPlus();
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIMeasurement_errorMinus
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IMeasurement* cref = (IMeasurement*)ProxyFactory::getCRef(crefID);
 
    return cref->errorMinus();
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIMeasurement_setValue
  (JNIEnv *env, jobject obj, jdouble jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IMeasurement* cref = (IMeasurement*)ProxyFactory::getCRef(crefID);
 
    cref->setValue(jvalue);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIMeasurement_setErrorPlus
  (JNIEnv *env, jobject obj, jdouble jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IMeasurement* cref = (IMeasurement*)ProxyFactory::getCRef(crefID);
 
    cref->setErrorPlus(jvalue);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIMeasurement_setErrorMinus
  (JNIEnv *env, jobject obj, jdouble jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IMeasurement* cref = (IMeasurement*)ProxyFactory::getCRef(crefID);
 
    cref->setErrorMinus(jvalue);
}
