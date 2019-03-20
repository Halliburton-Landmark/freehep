
#include "FreeHepTypes.h"

#include <vector>

#include "AIDA/IAxisStyle.h"
#include "AIDA/IDataStyle.h"
#include "AIDA/IInfoStyle.h"
#include "AIDA/IPlotterStyle.h"
#include "AIDA/ITitleStyle.h"

#include "ProxyFactory.h"

#include "CUtil.h"
#include "CIPlotterStyle.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIPlotterStyle
 * Method:    dataStyle
 * Signature: ()Lhep/aida/IDataStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterStyle_dataStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterStyle* cref = (IPlotterStyle*)ProxyFactory::getCRef(crefID);

    IDataStyle& style = cref->dataStyle();

    ProxyFactory* factory = ProxyFactory::getFactory();
 
    return factory->create(env, style);   
}

/*
 * Class:     hep_aida_jni_CIPlotterStyle
 * Method:    xAxisStyle
 * Signature: ()Lhep/aida/IAxisStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterStyle_xAxisStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterStyle* cref = (IPlotterStyle*)ProxyFactory::getCRef(crefID);

    IAxisStyle& style = cref->xAxisStyle();

    ProxyFactory* factory = ProxyFactory::getFactory();
 
    return factory->create(env, style);   
}

/*
 * Class:     hep_aida_jni_CIPlotterStyle
 * Method:    yAxisStyle
 * Signature: ()Lhep/aida/IAxisStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterStyle_yAxisStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterStyle* cref = (IPlotterStyle*)ProxyFactory::getCRef(crefID);

    IAxisStyle& style = cref->yAxisStyle();

    ProxyFactory* factory = ProxyFactory::getFactory();
 
    return factory->create(env, style);   
}

/*
 * Class:     hep_aida_jni_CIPlotterStyle
 * Method:    zAxisStyle
 * Signature: ()Lhep/aida/IAxisStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterStyle_zAxisStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterStyle* cref = (IPlotterStyle*)ProxyFactory::getCRef(crefID);

    IAxisStyle& style = cref->zAxisStyle();

    ProxyFactory* factory = ProxyFactory::getFactory();
 
    return factory->create(env, style);   
}

/*
 * Class:     hep_aida_jni_CIPlotterStyle
 * Method:    titleStyle
 * Signature: ()Lhep/aida/ITitleStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterStyle_titleStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterStyle* cref = (IPlotterStyle*)ProxyFactory::getCRef(crefID);

    ITitleStyle& style = cref->titleStyle();

    ProxyFactory* factory = ProxyFactory::getFactory();
 
    return factory->create(env, style);   
}

/*
 * Class:     hep_aida_jni_CIPlotterStyle
 * Method:    infoStyle
 * Signature: ()Lhep/aida/IInfoStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterStyle_infoStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterStyle* cref = (IPlotterStyle*)ProxyFactory::getCRef(crefID);

    IInfoStyle& style = cref->infoStyle();

    ProxyFactory* factory = ProxyFactory::getFactory();
 
    return factory->create(env, style);   
}

/*
 * Class:     hep_aida_jni_CIPlotterStyle
 * Method:    setDataStyle
 * Signature: (Lhep/aida/IDataStyle;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIPlotterStyle_setDataStyle
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IDataStyle* style = factory->createIDataStyle(env, jstyle);
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterStyle* cref = (IPlotterStyle*)ProxyFactory::getCRef(crefID);

    return cref->setDataStyle(*style);
}

/*
 * Class:     hep_aida_jni_CIPlotterStyle
 * Method:    setAxisStyleX
 * Signature: (Lhep/aida/IAxisStyle;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIPlotterStyle_setAxisStyleX
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IAxisStyle* style = factory->createIAxisStyle(env, jstyle);
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterStyle* cref = (IPlotterStyle*)ProxyFactory::getCRef(crefID);

    return cref->setAxisStyleX(*style);
}

/*
 * Class:     hep_aida_jni_CIPlotterStyle
 * Method:    setAxisStyleY
 * Signature: (Lhep/aida/IAxisStyle;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIPlotterStyle_setAxisStyleY
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IAxisStyle* style = factory->createIAxisStyle(env, jstyle);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterStyle* cref = (IPlotterStyle*)ProxyFactory::getCRef(crefID);

    return cref->setAxisStyleY(*style);
}

/*
 * Class:     hep_aida_jni_CIPlotterStyle
 * Method:    setAxisStyleZ
 * Signature: (Lhep/aida/IAxisStyle;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIPlotterStyle_setAxisStyleZ
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IAxisStyle* style = factory->createIAxisStyle(env, jstyle);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterStyle* cref = (IPlotterStyle*)ProxyFactory::getCRef(crefID);

    return cref->setAxisStyleZ(*style);
}

/*
 * Class:     hep_aida_jni_CIPlotterStyle
 * Method:    setTitleStyle
 * Signature: (Lhep/aida/ITitleStyle;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIPlotterStyle_setTitleStyle
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ITitleStyle* style = factory->createITitleStyle(env, jstyle);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterStyle* cref = (IPlotterStyle*)ProxyFactory::getCRef(crefID);

    return cref->setTitleStyle(*style);
}

/*
 * Class:     hep_aida_jni_CIPlotterStyle
 * Method:    setInfoStyle
 * Signature: (Lhep/aida/IInfoStyle;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIPlotterStyle_setInfoStyle
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IInfoStyle* style = factory->createIInfoStyle(env, jstyle);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterStyle* cref = (IPlotterStyle*)ProxyFactory::getCRef(crefID);

    return cref->setInfoStyle(*style);
}
