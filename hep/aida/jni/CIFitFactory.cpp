
#include "FreeHepTypes.h"

#include "AIDA/IFitFactory.h"
#include "AIDA/IFitData.h"
#include "AIDA/IFitter.h"

#include "ProxyFactory.h"

#include "CIFitFactory.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIFitFactory
 * Method:    createFitData
 * Signature: ()Lhep/aida/IFitData;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitFactory_createFitData
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitFactory* cref = (IFitFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFitData* result = cref->createFitData();
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitFactory
 * Method:    createFitter
 * Signature: ()Lhep/aida/IFitter;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitFactory_createFitter__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitFactory* cref = (IFitFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFitter* result = cref->createFitter();
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitFactory
 * Method:    createFitter
 * Signature: (Ljava/lang/String;)Lhep/aida/IFitter;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitFactory_createFitter__Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jtype) {

    jboolean isCopy1;
    string type = env->GetStringUTFChars(jtype, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitFactory* cref = (IFitFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFitter* result = cref->createFitter(type);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitFactory
 * Method:    createFitter
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFitter;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitFactory_createFitter__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jtype, jstring jengine) {

    jboolean isCopy1;
    string type = env->GetStringUTFChars(jtype, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string engine = env->GetStringUTFChars(jengine, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitFactory* cref = (IFitFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFitter* result = cref->createFitter(type, engine);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitFactory
 * Method:    createFitter
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFitter;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitFactory_createFitter__Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jtype, jstring jengine, jstring joptions) {

    jboolean isCopy1;
    string type = env->GetStringUTFChars(jtype, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string engine = env->GetStringUTFChars(jengine, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy3;
    string options = env->GetStringUTFChars(joptions, &isCopy3);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitFactory* cref = (IFitFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFitter* result = cref->createFitter(type, engine, options);
    return factory->create(env, *result);
}
