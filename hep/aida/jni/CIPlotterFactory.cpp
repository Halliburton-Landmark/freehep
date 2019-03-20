
#include "FreeHepTypes.h"

#include "AIDA/IPlotterFactory.h"
#include "AIDA/IPlotter.h"
#include "AIDA/IMarkerStyle.h"
#include "AIDA/ITextStyle.h"
#include "AIDA/ILineStyle.h"
#include "AIDA/IFillStyle.h"
#include "AIDA/IDataStyle.h"
#include "AIDA/IAxisStyle.h"
#include "AIDA/ITitleStyle.h"
#include "AIDA/IPlotterStyle.h"

#include "ProxyFactory.h"

#include "CIPlotterFactory.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIPlotterFactory
 * Method:    create
 * Signature: ()Lhep/aida/IPlotter;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterFactory_create__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterFactory* cref = (IPlotterFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IPlotter* result = cref->create();
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIPlotterFactory
 * Method:    create
 * Signature: (Ljava/lang/String;)Lhep/aida/IPlotter;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterFactory_create__Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterFactory* cref = (IPlotterFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IPlotter* result = cref->create(name);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIPlotterFactory
 * Method:    createMarkerStyle
 * Signature: ()Lhep/aida/IMarkerStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterFactory_createMarkerStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterFactory* cref = (IPlotterFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IMarkerStyle* result = cref->createMarkerStyle();
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIPlotterFactory
 * Method:    createTextStyle
 * Signature: ()Lhep/aida/ITextStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterFactory_createTextStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterFactory* cref = (IPlotterFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITextStyle* result = cref->createTextStyle();
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIPlotterFactory
 * Method:    createLineStyle
 * Signature: ()Lhep/aida/ILineStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterFactory_createLineStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterFactory* cref = (IPlotterFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ILineStyle* result = cref->createLineStyle();
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIPlotterFactory
 * Method:    createFillStyle
 * Signature: ()Lhep/aida/IFillStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterFactory_createFillStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterFactory* cref = (IPlotterFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFillStyle* result = cref->createFillStyle();
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIPlotterFactory
 * Method:    createDataStyle
 * Signature: ()Lhep/aida/IDataStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterFactory_createDataStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterFactory* cref = (IPlotterFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IDataStyle* result = cref->createDataStyle();
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIPlotterFactory
 * Method:    createAxisStyle
 * Signature: ()Lhep/aida/IAxisStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterFactory_createAxisStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterFactory* cref = (IPlotterFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IAxisStyle* result = cref->createAxisStyle();
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIPlotterFactory
 * Method:    createTitleStyle
 * Signature: ()Lhep/aida/ITitleStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterFactory_createTitleStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterFactory* cref = (IPlotterFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITitleStyle* result = cref->createTitleStyle();
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIPlotterFactory
 * Method:    createPlotterStyle
 * Signature: ()Lhep/aida/IPlotterStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterFactory_createPlotterStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterFactory* cref = (IPlotterFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IPlotterStyle* result = cref->createPlotterStyle();
    return factory->create(env, *result);
}
