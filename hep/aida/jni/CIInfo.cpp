
#include "FreeHepTypes.h"

#include "AIDA/IInfo.h"

#include "ProxyFactory.h"

#include "CIInfo.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIInfo
 * Method:    clear
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIInfo_clear
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IInfo* cref = (IInfo*)ProxyFactory::getCRef(crefID);

    cref->clear();
}

/*
 * Class:     hep_aida_jni_CIInfo
 * Method:    addText
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIInfo_addText
  (JNIEnv *env, jobject obj, jstring jtext) {

    jboolean isCopy1;
    string text = env->GetStringUTFChars(jtext, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IInfo* cref = (IInfo*)ProxyFactory::getCRef(crefID);

	cref->addText(text);
}

/*
 * Class:     hep_aida_jni_CIInfo
 * Method:    addLegend
 * Signature: (Lhep/aida/IMarkerStyle;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIInfo_addLegend__Lhep_aida_IMarkerStyle_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jobject jstyle, jstring jvalue) {

    jboolean isCopy1;
    string value = env->GetStringUTFChars(jvalue, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..
	
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IInfo* cref = (IInfo*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IMarkerStyle* style = factory->createIMarkerStyle(env, jstyle);

    cref->addLegend(*style, value);
}

/*
 * Class:     hep_aida_jni_CIInfo
 * Method:    addLegend
 * Signature: (Lhep/aida/ILineStyle;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIInfo_addLegend__Lhep_aida_ILineStyle_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jobject jstyle, jstring jvalue) {

    jboolean isCopy1;
    string value = env->GetStringUTFChars(jvalue, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..
	
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IInfo* cref = (IInfo*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ILineStyle* style = factory->createILineStyle(env, jstyle);

    cref->addLegend(*style, value);
}

/*
 * Class:     hep_aida_jni_CIInfo
 * Method:    addLegend
 * Signature: (Lhep/aida/IFillStyle;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIInfo_addLegend__Lhep_aida_IFillStyle_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jobject jstyle, jstring jvalue) {

    jboolean isCopy1;
    string value = env->GetStringUTFChars(jvalue, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..
	
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IInfo* cref = (IInfo*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFillStyle* style = factory->createIFillStyle(env, jstyle);

    cref->addLegend(*style, value);
}

