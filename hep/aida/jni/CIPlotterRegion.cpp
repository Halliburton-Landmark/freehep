
#include "FreeHepTypes.h"

#include "AIDA/IPlotterRegion.h"
#include "AIDA/IBaseHistogram.h"
#include "AIDA/IFunction.h"
#include "AIDA/IDataPointSet.h"
#include "AIDA/IPlotterStyle.h"
#include "AIDA/IPlotterLayout.h"
#include "AIDA/IInfo.h"

#include "ProxyFactory.h"

#include "CIPlotterRegion.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    plot
 * Signature: (Lhep/aida/IBaseHistogram;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IBaseHistogram_2
  (JNIEnv *env, jobject obj, jobject jh) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IBaseHistogram* h = factory->createIBaseHistogram(env, jh);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->plot(*h);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    plot
 * Signature: (Lhep/aida/IBaseHistogram;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IBaseHistogram_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jobject jh, jstring joptions) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IBaseHistogram* h = factory->createIBaseHistogram(env, jh);

    jboolean isCopy1;
    string options = env->GetStringUTFChars(joptions, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->plot(*h, options);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    plot
 * Signature: (Lhep/aida/IBaseHistogram;Lhep/aida/IPlotterStyle;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IBaseHistogram_2Lhep_aida_IPlotterStyle_2
  (JNIEnv *env, jobject obj, jobject jh, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IBaseHistogram* h = factory->createIBaseHistogram(env, jh);
    IPlotterStyle* style = factory->createIPlotterStyle(env, jstyle);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->plot(*h, *style);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    plot
 * Signature: (Lhep/aida/IBaseHistogram;Lhep/aida/IPlotterStyle;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IBaseHistogram_2Lhep_aida_IPlotterStyle_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jobject jh, jobject jstyle, jstring joptions) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IBaseHistogram* h = factory->createIBaseHistogram(env, jh);
    IPlotterStyle* style = factory->createIPlotterStyle(env, jstyle);

    jboolean isCopy1;
    string options = env->GetStringUTFChars(joptions, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->plot(*h, *style, options);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    plot
 * Signature: (Lhep/aida/IFunction;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IFunction_2
  (JNIEnv *env, jobject obj, jobject jfunction) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFunction* function = factory->createIFunction(env, jfunction);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->plot(*function);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    plot
 * Signature: (Lhep/aida/IFunction;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IFunction_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jobject jfunction, jstring joptions) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFunction* function = factory->createIFunction(env, jfunction);

    jboolean isCopy1;
    string options = env->GetStringUTFChars(joptions, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->plot(*function, options);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    plot
 * Signature: (Lhep/aida/IFunction;Lhep/aida/IPlotterStyle;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IFunction_2Lhep_aida_IPlotterStyle_2
  (JNIEnv *env, jobject obj, jobject jfunction, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFunction* function = factory->createIFunction(env, jfunction);
    IPlotterStyle* style = factory->createIPlotterStyle(env, jstyle);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->plot(*function, *style);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    plot
 * Signature: (Lhep/aida/IFunction;Lhep/aida/IPlotterStyle;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IFunction_2Lhep_aida_IPlotterStyle_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jobject jfunction, jobject jstyle, jstring joptions) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFunction* function = factory->createIFunction(env, jfunction);
    IPlotterStyle* style = factory->createIPlotterStyle(env, jstyle);

    jboolean isCopy1;
    string options = env->GetStringUTFChars(joptions, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->plot(*function, *style, options);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    plot
 * Signature: (Lhep/aida/IDataPointSet;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IDataPointSet_2
  (JNIEnv *env, jobject obj, jobject jdp) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IDataPointSet* dp = factory->createIDataPointSet(env, jdp);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->plot(*dp);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    plot
 * Signature: (Lhep/aida/IDataPointSet;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IDataPointSet_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jobject jdp, jstring joptions) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IDataPointSet* dp = factory->createIDataPointSet(env, jdp);

    jboolean isCopy1;
    string options = env->GetStringUTFChars(joptions, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->plot(*dp, options);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    plot
 * Signature: (Lhep/aida/IDataPointSet;Lhep/aida/IPlotterStyle;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IDataPointSet_2Lhep_aida_IPlotterStyle_2
  (JNIEnv *env, jobject obj, jobject jdp, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IDataPointSet* dp = factory->createIDataPointSet(env, jdp);
    IPlotterStyle* style = factory->createIPlotterStyle(env, jstyle);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->plot(*dp, *style);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    plot
 * Signature: (Lhep/aida/IDataPointSet;Lhep/aida/IPlotterStyle;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IDataPointSet_2Lhep_aida_IPlotterStyle_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jobject jdp, jobject jstyle, jstring joptions) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IDataPointSet* dp = factory->createIDataPointSet(env, jdp);
    IPlotterStyle* style = factory->createIPlotterStyle(env, jstyle);

    jboolean isCopy1;
    string options = env->GetStringUTFChars(joptions, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->plot(*dp, *style, options);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    remove
 * Signature: (Lhep/aida/IBaseHistogram;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_remove__Lhep_aida_IBaseHistogram_2
  (JNIEnv *env, jobject obj, jobject jh) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IBaseHistogram* h = factory->createIBaseHistogram(env, jh);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->remove(*h);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    remove
 * Signature: (Lhep/aida/IFunction;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_remove__Lhep_aida_IFunction_2
  (JNIEnv *env, jobject obj, jobject jfunction) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFunction* function = factory->createIFunction(env, jfunction);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->remove(*function);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    remove
 * Signature: (Lhep/aida/IDataPointSet;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_remove__Lhep_aida_IDataPointSet_2
  (JNIEnv *env, jobject obj, jobject jdp) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IDataPointSet* dp = factory->createIDataPointSet(env, jdp);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->remove(*dp);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    clear
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_clear
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->clear();
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setParameter
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setParameter__Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setParameter(name);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setParameter
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setParameter__Ljava_lang_String_2Ljava_lang_String_2
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
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setParameter(name, options);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    parameterValue
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIPlotterRegion_parameterValue
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    string result = cref->parameterValue(name);
    jstring jresult = env->NewStringUTF(result.c_str());
    return jresult;
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    availableParameterOptions
 * Signature: (Ljava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIPlotterRegion_availableParameterOptions
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

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
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    availableParameters
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIPlotterRegion_availableParameters
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

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
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    style
 * Signature: ()Lhep/aida/IPlotterStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterRegion_style
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IPlotterStyle& style = cref->style();
    return factory->create(env, style);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setStyle
 * Signature: (Lhep/aida/IPlotterStyle;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setStyle
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IPlotterStyle* style = factory->createIPlotterStyle(env, jstyle);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setStyle(*style);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    applyStyle
 * Signature: (Lhep/aida/IPlotterStyle;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_applyStyle
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IPlotterStyle* style = factory->createIPlotterStyle(env, jstyle);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->applyStyle(*style);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setTitle
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setTitle
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setTitle(name);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setXLimits
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setXLimits__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setXLimits();
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setXLimits
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setXLimits__D
  (JNIEnv *env, jobject obj, jdouble min) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setXLimits(min);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setXLimits
 * Signature: (DD)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setXLimits__DD
  (JNIEnv *env, jobject obj, jdouble min, jdouble max) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setXLimits(min, max);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setYLimits
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setYLimits__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setYLimits();
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setYLimits
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setYLimits__D
  (JNIEnv *env, jobject obj, jdouble min) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setYLimits(min);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setYLimits
 * Signature: (DD)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setYLimits__DD
  (JNIEnv *env, jobject obj, jdouble min, jdouble max) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setYLimits(min, max);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setZLimits
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setZLimits__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setZLimits();
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setZLimits
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setZLimits__D
  (JNIEnv *env, jobject obj, jdouble min) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setZLimits(min);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setZLimits
 * Signature: (DD)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setZLimits__DD
  (JNIEnv *env, jobject obj, jdouble min, jdouble max) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setZLimits(min, max);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    layout
 * Signature: ()Lhep/aida/IPlotterLayout;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterRegion_layout
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IPlotterLayout& layout = cref->layout();
    return factory->create(env, layout);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    setLayout
 * Signature: (Lhep/aida/IPlotterLayout;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterRegion_setLayout
  (JNIEnv *env, jobject obj, jobject jlayout) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IPlotterLayout* layout = factory->createIPlotterLayout(env, jlayout);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    cref->setLayout(*layout);
}

/*
 * Class:     hep_aida_jni_CIPlotterRegion
 * Method:    info
 * Signature: ()Lhep/aida/IInfo;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIPlotterRegion_info
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterRegion* cref = (IPlotterRegion*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IInfo& info = cref->info();
    return factory->create(env, info);
}
