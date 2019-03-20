
#include "FreeHepTypes.h"

#include "AIDA/IFunctionFactory.h"
#include "AIDA/IFunction.h"
#include "AIDA/IFunctionCatalog.h"

#include "ProxyFactory.h"

#include "CIFunctionFactory.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIFunctionFactory
 * Method:    createFunctionByName
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFunction;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFunctionFactory_createFunctionByName
  (JNIEnv *env, jobject obj, jstring jpath, jstring jmodel) {

    jboolean isCopy1;
    string path = env->GetStringUTFChars(jpath, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string model = env->GetStringUTFChars(jmodel, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunctionFactory* cref = (IFunctionFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFunction* result = cref->createFunctionByName(path, model);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFunctionFactory
 * Method:    createFunctionFromScript
 * Signature: (Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFunction;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFunctionFactory_createFunctionFromScript__Ljava_lang_String_2ILjava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jpath, jint dim, jstring jval, jstring jpar, jstring jdesc) {

    jboolean isCopy1;
    string path = env->GetStringUTFChars(jpath, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string val = env->GetStringUTFChars(jval, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy3;
    string par = env->GetStringUTFChars(jpar, &isCopy3);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy4;
    string desc = env->GetStringUTFChars(jdesc, &isCopy4);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunctionFactory* cref = (IFunctionFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFunction* result = cref->createFunctionFromScript(path, dim, val, par, desc);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFunctionFactory
 * Method:    createFunctionFromScript
 * Signature: (Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFunction;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFunctionFactory_createFunctionFromScript__Ljava_lang_String_2ILjava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jpath, jint dim, jstring jval, jstring jpar, jstring jdesc, jstring jgrad) {

    jboolean isCopy1;
    string path = env->GetStringUTFChars(jpath, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string val = env->GetStringUTFChars(jval, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy3;
    string par = env->GetStringUTFChars(jpar, &isCopy3);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy4;
    string desc = env->GetStringUTFChars(jdesc, &isCopy4);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy5;
    string grad = env->GetStringUTFChars(jgrad, &isCopy5);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunctionFactory* cref = (IFunctionFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFunction* result = cref->createFunctionFromScript(path, dim, val, par, desc, grad);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFunctionFactory
 * Method:    cloneFunction
 * Signature: (Ljava/lang/String;Lhep/aida/IFunction;)Lhep/aida/IFunction;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFunctionFactory_cloneFunction
  (JNIEnv *env, jobject obj, jstring jpath, jobject jfunction) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    jboolean isCopy1;
    string path = env->GetStringUTFChars(jpath, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    IFunction* function = factory->createIFunction(env, jfunction);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunctionFactory* cref = (IFunctionFactory*)ProxyFactory::getCRef(crefID);

    IFunction* result = cref->cloneFunction(path, *function);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFunctionFactory
 * Method:    catalog
 * Signature: ()Lhep/aida/IFunctionCatalog;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFunctionFactory_catalog
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunctionFactory* cref = (IFunctionFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();

    IFunctionCatalog* result = cref->catalog();
    return factory->create(env, *result);
}

