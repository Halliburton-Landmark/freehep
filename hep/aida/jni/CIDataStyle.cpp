
#include "FreeHepTypes.h"

#include "AIDA/IDataStyle.h"
#include "AIDA/IFillStyle.h"
#include "AIDA/ILineStyle.h"
#include "AIDA/IMarkerStyle.h"

#include "ProxyFactory.h"

#include "CIDataStyle.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIDataStyle
 * Method:    lineStyle
 * Signature: ()Lhep/aida/ILineStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIDataStyle_lineStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataStyle* cref = (IDataStyle*)ProxyFactory::getCRef(crefID);

    ILineStyle& style = cref->lineStyle();

    ProxyFactory* factory = ProxyFactory::getFactory();

    return factory->create(env, style);
}

/*
 * Class:     hep_aida_jni_CIDataStyle
 * Method:    markerStyle
 * Signature: ()Lhep/aida/IMarkerStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIDataStyle_markerStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataStyle* cref = (IDataStyle*)ProxyFactory::getCRef(crefID);

    IMarkerStyle& style = cref->markerStyle();

    ProxyFactory* factory = ProxyFactory::getFactory();

    return factory->create(env, style);
}

/*
 * Class:     hep_aida_jni_CIDataStyle
 * Method:    fillStyle
 * Signature: ()Lhep/aida/IFillStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIDataStyle_fillStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataStyle* cref = (IDataStyle*)ProxyFactory::getCRef(crefID);

    IFillStyle& style = cref->fillStyle();

    ProxyFactory* factory = ProxyFactory::getFactory();

    return factory->create(env, style);
}

/*
 * Class:     hep_aida_jni_CIDataStyle
 * Method:    setLineStyle
 * Signature: (Lhep/aida/ILineStyle;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIDataStyle_setLineStyle
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ILineStyle* style = factory->createILineStyle(env, jstyle);
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataStyle* cref = (IDataStyle*)ProxyFactory::getCRef(crefID);

    return cref->setLineStyle(*style);
}

/*
 * Class:     hep_aida_jni_CIDataStyle
 * Method:    setMarkerStyle
 * Signature: (Lhep/aida/IMarkerStyle;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIDataStyle_setMarkerStyle
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IMarkerStyle* style = factory->createIMarkerStyle(env, jstyle);
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataStyle* cref = (IDataStyle*)ProxyFactory::getCRef(crefID);

    return cref->setMarkerStyle(*style);
}

/*
 * Class:     hep_aida_jni_CIDataStyle
 * Method:    setFillStyle
 * Signature: (Lhep/aida/IFillStyle;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIDataStyle_setFillStyle
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IFillStyle* style = factory->createIFillStyle(env, jstyle);
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataStyle* cref = (IDataStyle*)ProxyFactory::getCRef(crefID);

    return cref->setFillStyle(*style);
}

