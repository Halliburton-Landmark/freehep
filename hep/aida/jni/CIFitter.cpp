
#include "FreeHepTypes.h"

#include "AIDA/IFitter.h"
#include "AIDA/IFitData.h"
#include "AIDA/IFitResult.h"
#include "AIDA/IFunction.h"
#include "AIDA/IBaseHistogram.h"
#include "AIDA/IDataPointSet.h"
#include "AIDA/IFitParameterSettings.h"

#include "ProxyFactory.h"

#include "CIFitter.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    fit
 * Signature: (Lhep/aida/IFitData;Lhep/aida/IFunction;)Lhep/aida/IFitResult;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IFitData_2Lhep_aida_IFunction_2
  (JNIEnv *env, jobject obj, jobject jfitData, jobject jfunction) {
    
    ProxyFactory* factory = ProxyFactory::getFactory();
    IFitData* fitData = factory->createIFitData(env, jfitData);
    IFunction* function = factory->createIFunction(env, jfunction);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    IFitResult* result = cref->fit(*fitData, *function);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    fit
 * Signature: (Lhep/aida/IBaseHistogram;Lhep/aida/IFunction;)Lhep/aida/IFitResult;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IBaseHistogram_2Lhep_aida_IFunction_2
  (JNIEnv *env, jobject obj, jobject jh, jobject jfunction) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IBaseHistogram* h = factory->createIBaseHistogram(env, jh);
    IFunction* function = factory->createIFunction(env, jfunction);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    IFitResult* result = cref->fit(*h, *function);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    fit
 * Signature: (Lhep/aida/IBaseHistogram;Ljava/lang/String;)Lhep/aida/IFitResult;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IBaseHistogram_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jobject jh, jstring jmodel) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IBaseHistogram* h = factory->createIBaseHistogram(env, jh);

    jboolean isCopy1;
    string model = env->GetStringUTFChars(jmodel, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    IFitResult* result = cref->fit(*h, model);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    fit
 * Signature: (Lhep/aida/IBaseHistogram;Ljava/lang/String;[D)Lhep/aida/IFitResult;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IBaseHistogram_2Ljava_lang_String_2_3D
  (JNIEnv *env, jobject obj, jobject jh, jstring jmodel, jdoubleArray jinit) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IBaseHistogram* h = factory->createIBaseHistogram(env, jh);

    jboolean isCopy1;
    string model = env->GetStringUTFChars(jmodel, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    vector<double> init;
    unsigned int len = env->GetArrayLength(jinit);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jinit, i, 1, &d);
        init.push_back(d);
    }

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    IFitResult* result = cref->fit(*h, model, init);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    fit
 * Signature: (Lhep/aida/IDataPointSet;Lhep/aida/IFunction;)Lhep/aida/IFitResult;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IDataPointSet_2Lhep_aida_IFunction_2
  (JNIEnv *env, jobject obj, jobject jdp, jobject jfunction) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IDataPointSet* dp = factory->createIDataPointSet(env, jdp);
    IFunction* function = factory->createIFunction(env, jfunction);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    IFitResult* result = cref->fit(*dp, *function);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    fit
 * Signature: (Lhep/aida/IDataPointSet;Ljava/lang/String;)Lhep/aida/IFitResult;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IDataPointSet_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jobject jdp, jstring jmodel) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IDataPointSet* dp = factory->createIDataPointSet(env, jdp);

    jboolean isCopy1;
    string model = env->GetStringUTFChars(jmodel, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    IFitResult* result = cref->fit(*dp, model);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    fit
 * Signature: (Lhep/aida/IDataPointSet;Ljava/lang/String;[D)Lhep/aida/IFitResult;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IDataPointSet_2Ljava_lang_String_2_3D
  (JNIEnv *env, jobject obj, jobject jdp, jstring jmodel, jdoubleArray jinit) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IDataPointSet* dp = factory->createIDataPointSet(env, jdp);

    jboolean isCopy1;
    string model = env->GetStringUTFChars(jmodel, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    vector<double> init;
    unsigned int len = env->GetArrayLength(jinit);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jinit, i, 1, &d);
        init.push_back(d);
    }

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    IFitResult* result = cref->fit(*dp, model, init);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    fit
 * Signature: (Lhep/aida/IFitData;Ljava/lang/String;)Lhep/aida/IFitResult;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IFitData_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jobject jfitData, jstring jmodel) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFitData* fitData = factory->createIFitData(env, jfitData);

    jboolean isCopy1;
    string model = env->GetStringUTFChars(jmodel, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    IFitResult* result = cref->fit(*fitData, model);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    fit
 * Signature: (Lhep/aida/IFitData;Ljava/lang/String;[D)Lhep/aida/IFitResult;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IFitData_2Ljava_lang_String_2_3D
  (JNIEnv *env, jobject obj, jobject jfitData, jstring jmodel, jdoubleArray jinit) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFitData* fitData = factory->createIFitData(env, jfitData);

    jboolean isCopy1;
    string model = env->GetStringUTFChars(jmodel, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    vector<double> init;
    unsigned int len = env->GetArrayLength(jinit);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jinit, i, 1, &d);
        init.push_back(d);
    }

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    IFitResult* result = cref->fit(*fitData, model, init);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    setEngine
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitter_setEngine
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    cref->setEngine(name);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    engineName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIFitter_engineName
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    string result = cref->engineName();
    jstring jresult = env->NewStringUTF(result.c_str());
    return jresult;
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    fitParameterSettings
 * Signature: (Ljava/lang/String;)Lhep/aida/IFitParameterSettings;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitter_fitParameterSettings
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);
	
    ProxyFactory* factory = ProxyFactory::getFactory();
    IFitParameterSettings& result = cref->fitParameterSettings(name);
    
    return factory->create(env, result);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    listParameterSettings
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIFitter_listParameterSettings
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> result = cref->listParameterSettings();

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
 * Class:     hep_aida_jni_CIFitter
 * Method:    resetParameterSettings
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitter_resetParameterSettings
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    cref->resetParameterSettings();
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    setConstraint
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitter_setConstraint
  (JNIEnv *env, jobject obj, jstring jexpression) {

    jboolean isCopy1;
    string expression = env->GetStringUTFChars(jexpression, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    cref->setConstraint(expression);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    constraints
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIFitter_constraints
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> result = cref->constraints();

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
 * Class:     hep_aida_jni_CIFitter
 * Method:    resetConstraints
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitter_resetConstraints
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    cref->resetConstraints();
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    setFitMethod
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitter_setFitMethod
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    cref->setFitMethod(name);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    fitMethodName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIFitter_fitMethodName
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    string result = cref->fitMethodName();
    jstring jresult = env->NewStringUTF(result.c_str());
    return jresult;
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    createScan1D
 * Signature: (Lhep/aida/IFitData;Lhep/aida/IFunction;Ljava/lang/String;IDD)Lhep/aida/IDataPointSet;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitter_createScan1D
  (JNIEnv *env, jobject obj, jobject jfitData, jobject jfunction, jstring jpar, jint npts, jdouble pmin, jdouble pmax) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFitData* fitData = factory->createIFitData(env, jfitData);
    IFunction* function = factory->createIFunction(env, jfunction);

    jboolean isCopy1;
    string par = env->GetStringUTFChars(jpar, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    IDataPointSet* dp = cref->createScan1D(*fitData, *function, par, npts, pmin, pmax);
    return factory->create(env, *dp);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    createContour
 * Signature: (Lhep/aida/IFitData;Lhep/aida/IFitResult;Ljava/lang/String;Ljava/lang/String;ID)Lhep/aida/IDataPointSet;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitter_createContour
  (JNIEnv *env, jobject obj, jobject jfitData, jobject jfitResult, jstring jpar1, jstring jpar2, jint npts, jdouble up) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFitData* fitData = factory->createIFitData(env, jfitData);
    IFitResult* fitResult = factory->createIFitResult(env, jfitResult);

    jboolean isCopy1;
    string par1 = env->GetStringUTFChars(jpar1, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string par2 = env->GetStringUTFChars(jpar2, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    IDataPointSet* dp = cref->createContour(*fitData, *fitResult, par1, par2, npts, up);
    return factory->create(env, *dp);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    setUseFunctionGradient
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitter_setUseFunctionGradient
  (JNIEnv *env, jobject obj, jboolean useGrad) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);
	
	cref->setUseFunctionGradient(useGrad);
}

/*
 * Class:     hep_aida_jni_CIFitter
 * Method:    useFunctionGradient
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIFitter_useFunctionGradient
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitter* cref = (IFitter*)ProxyFactory::getCRef(crefID);

    return cref->useFunctionGradient();
}
