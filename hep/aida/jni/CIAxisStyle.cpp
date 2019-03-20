
#include "FreeHepTypes.h"

#include "AIDA/IAxisStyle.h"
#include "AIDA/ILineStyle.h"
#include "AIDA/ITextStyle.h"

#include "ProxyFactory.h"

#include "CIAxisStyle.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIAxisStyle
 * Method:    lineStyle
 * Signature: ()Lhep/aida/ILineStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIAxisStyle_lineStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxisStyle* cref = (IAxisStyle*)ProxyFactory::getCRef(crefID);

    ILineStyle& style = cref->lineStyle();

    ProxyFactory* factory = ProxyFactory::getFactory();

    return factory->create(env, style);
}

/*
 * Class:     hep_aida_jni_CIAxisStyle
 * Method:    tickLabelStyle
 * Signature: ()Lhep/aida/ITextStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIAxisStyle_tickLabelStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxisStyle* cref = (IAxisStyle*)ProxyFactory::getCRef(crefID);

    ITextStyle& style = cref->tickLabelStyle();

    ProxyFactory* factory = ProxyFactory::getFactory();

    return factory->create(env, style);
}

/*
 * Class:     hep_aida_jni_CIAxisStyle
 * Method:    labelStyle
 * Signature: ()Lhep/aida/ITextStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIAxisStyle_labelStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxisStyle* cref = (IAxisStyle*)ProxyFactory::getCRef(crefID);

    ITextStyle& style = cref->labelStyle();

    ProxyFactory* factory = ProxyFactory::getFactory();

    return factory->create(env, style);
}

/*
 * Class:     hep_aida_jni_CIAxisStyle
 * Method:    setlineStyle
 * Signature: (Lhep/aida/ILineStyle;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIAxisStyle_setlineStyle
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ILineStyle* style = factory->createILineStyle(env, jstyle);
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxisStyle* cref = (IAxisStyle*)ProxyFactory::getCRef(crefID);

    return cref->setlineStyle(*style);
}

/*
 * Class:     hep_aida_jni_CIAxisStyle
 * Method:    setTickLabelStyle
 * Signature: (Lhep/aida/ITextStyle;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIAxisStyle_setTickLabelStyle
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ITextStyle* style = factory->createITextStyle(env, jstyle);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxisStyle* cref = (IAxisStyle*)ProxyFactory::getCRef(crefID);

    return cref->setTickLabelStyle(*style);
}

/*
 * Class:     hep_aida_jni_CIAxisStyle
 * Method:    setLabelStyle
 * Signature: (Lhep/aida/ITextStyle;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIAxisStyle_setLabelStyle
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ITextStyle* style = factory->createITextStyle(env, jstyle);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxisStyle* cref = (IAxisStyle*)ProxyFactory::getCRef(crefID);

    return cref->setLabelStyle(*style);
}

/*
 * Class:     hep_aida_jni_CIAxisStyle
 * Method:    setLabel
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIAxisStyle_setLabel
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IAxisStyle* cref = (IAxisStyle*)ProxyFactory::getCRef(crefID);

    cref->setLabel(name);
}

