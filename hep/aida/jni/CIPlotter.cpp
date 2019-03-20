
#include "FreeHepTypes.h"

#include "AIDA/IPlotter.h"
#include "AIDA/IPlotterRegion.h"
#include "AIDA/ITitleStyle.h"

#include "ProxyFactory.h"

#include "CIPlotter.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegion
 * Signature: ()Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_createRegion__
  (JNIEnv *env, jobject obj) {
    
    ProxyFactory* factory = ProxyFactory::getFactory();
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    IPlotterRegion* region = cref->createRegion();
    return factory->create(env, *region);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegion
 * Signature: (D)Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_createRegion__D
  (JNIEnv *env, jobject obj, jdouble x) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    IPlotterRegion* region = cref->createRegion(x);
    return factory->create(env, *region);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegion
 * Signature: (DD)Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_createRegion__DD
  (JNIEnv *env, jobject obj, jdouble x, jdouble y) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    IPlotterRegion* region = cref->createRegion(x, y);
    return factory->create(env, *region);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegion
 * Signature: (DDD)Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_createRegion__DDD
  (JNIEnv *env, jobject obj, jdouble x, jdouble y, jdouble w) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    IPlotterRegion* region = cref->createRegion(x, y, w);
    return factory->create(env, *region);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegion
 * Signature: (DDDD)Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_createRegion__DDDD
  (JNIEnv *env, jobject obj, jdouble x, jdouble y, jdouble w, jdouble h) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    IPlotterRegion* region = cref->createRegion(x, y, w, h);
    return factory->create(env, *region);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegions
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_createRegions__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->createRegions();
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegions
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_createRegions__I
  (JNIEnv *env, jobject obj, jint c) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->createRegions(c);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegions
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_createRegions__II
  (JNIEnv *env, jobject obj, jint c, jint r) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->createRegions(c, r);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    createRegions
 * Signature: (III)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_createRegions__III
  (JNIEnv *env, jobject obj, jint c, jint r, jint i) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->createRegions(c, r, i);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    currentRegion
 * Signature: ()Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_currentRegion
  (JNIEnv *env, jobject obj) {

    ProxyFactory* factory = ProxyFactory::getFactory();

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    IPlotterRegion& region = cref->currentRegion();
    return factory->create(env, region);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    currentRegionNumber
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIPlotter_currentRegionNumber
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    return cref->currentRegionNumber();
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    numberOfRegions
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIPlotter_numberOfRegions
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    return cref->numberOfRegions();
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    setCurrentRegionNumber
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_setCurrentRegionNumber
  (JNIEnv *env, jobject obj, jint i) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->setCurrentRegionNumber(i);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    next
 * Signature: ()Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_next
  (JNIEnv *env, jobject obj) {

    ProxyFactory* factory = ProxyFactory::getFactory();

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    IPlotterRegion& region = cref->next();
    return factory->create(env, region);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    region
 * Signature: (I)Lhep/aida/IPlotterRegion;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_region
  (JNIEnv *env, jobject obj, jint i) {

    ProxyFactory* factory = ProxyFactory::getFactory();

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    IPlotterRegion* region = cref->region(i);
    return factory->create(env, *region);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    destroyRegions
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_destroyRegions
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->destroyRegions();
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    clearRegions
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_clearRegions
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->clearRegions();
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    setParameter
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_setParameter__Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->setParameter(name);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    setParameter
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_setParameter__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname, jstring joptions) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string options = env->GetStringUTFChars(joptions, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->setParameter(name, options);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    parameterValue
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIPlotter_parameterValue
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    string result = cref->parameterValue(name);
    jstring jresult = env->NewStringUTF(result.c_str());
    return jresult;
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    availableParameterOptions
 * Signature: (Ljava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIPlotter_availableParameterOptions
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> result = cref->availableParameterOptions(name);

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jresult = env->NewObjectArray(result.size(), stringClass, NULL);
    for (unsigned int index=0; index<result.size(); index++) {
	    jobject jtmp = env->NewStringUTF(result[index].c_str());
        env->SetObjectArrayElement(jresult, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jresult;
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    availableParameters
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIPlotter_availableParameters
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> result = cref->availableParameters();

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jresult = env->NewObjectArray(result.size(), stringClass, NULL);
    for (unsigned int index=0; index<result.size(); index++) {
	    jobject jtmp = env->NewStringUTF(result[index].c_str());
        env->SetObjectArrayElement(jresult, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jresult;
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    show
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_show
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->show();
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    refresh
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_refresh
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->refresh();
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    hide
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_hide
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->hide();
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    interact
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_interact
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->interact();
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    writeToFile
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_writeToFile__Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->writeToFile(name);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    writeToFile
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_writeToFile__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname, jstring jtype) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string type = env->GetStringUTFChars(jtype, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->writeToFile(name, type);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    setTitle
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_setTitle
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->setTitle(name);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    titleStyle
 * Signature: ()Lhep/aida/ITitleStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotter_titleStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITitleStyle& style = cref->titleStyle();
    return factory->create(env, style);
}

/*
 * Class:     hep_aida_jni_CIPlotter
 * Method:    setTitleStyle
 * Signature: (Lhep/aida/ITitleStyle;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotter_setTitleStyle
  (JNIEnv *env, jobject obj, jobject jstyle) {
    
    ProxyFactory* factory = ProxyFactory::getFactory();
    ITitleStyle* style = factory->createITitleStyle(env, jstyle);
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotter* cref = (IPlotter*)ProxyFactory::getCRef(crefID);

    cref->setTitleStyle(*style);
}

