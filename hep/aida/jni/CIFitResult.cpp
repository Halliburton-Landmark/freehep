
#include "FreeHepTypes.h"

#include "AIDA/IFitResult.h"
#include "AIDA/IFitParameterSettings.h"
#include "AIDA/IFunction.h"

#include "ProxyFactory.h"

#include "CIFitResult.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    isValid
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIFitResult_isValid
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    return cref->isValid();
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    fitStatus
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIFitResult_fitStatus
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    return cref->fitStatus();
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    fittedFunction
 * Signature: ()Lhep/aida/IFunction;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitResult_fittedFunction
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    IFunction& function = cref->fittedFunction();

    ProxyFactory* factory = ProxyFactory::getFactory();
    return factory->create(env, function);
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    quality
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIFitResult_quality
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    return cref->quality();
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    ndf
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIFitResult_ndf
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    return cref->ndf();
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    covMatrixElement
 * Signature: (II)D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIFitResult_covMatrixElement
  (JNIEnv *env, jobject obj, jint i, jint j) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    return cref->covMatrixElement(i, j);
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    fitMethodName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIFitResult_fitMethodName
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    string result = cref->fitMethodName();
    jstring jresult = env->NewStringUTF(result.c_str());
    return jresult;
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    engineName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIFitResult_engineName
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    string result = cref->engineName();
    jstring jresult = env->NewStringUTF(result.c_str());
    return jresult;
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    dataDescription
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIFitResult_dataDescription
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    string result = cref->dataDescription();
    jstring jresult = env->NewStringUTF(result.c_str());
    return jresult;
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    constraints
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIFitResult_constraints
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

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
 * Class:     hep_aida_jni_CIFitResult
 * Method:    fitParameterSettings
 * Signature: (Ljava/lang/String;)Lhep/aida/IFitParameterSettings;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitResult_fitParameterSettings
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    IFitParameterSettings* result = cref->fitParameterSettings(name);

    ProxyFactory* factory = ProxyFactory::getFactory();
	return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    fittedParameters
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL Java_hep_aida_jni_CIFitResult_fittedParameters
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    vector<double> result = cref->fittedParameters();

    jdoubleArray jresult = env->NewDoubleArray(result.size());
    for (unsigned int index=0; index<result.size(); index++) {\
        env->SetDoubleArrayRegion(jresult, index, 1, (jdouble*)(&(result[index])) );
    }

    return jresult;
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    fittedParameterNames
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIFitResult_fittedParameterNames
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> result = cref->fittedParameterNames();

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
 * Class:     hep_aida_jni_CIFitResult
 * Method:    fittedParameter
 * Signature: (Ljava/lang/String;)D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIFitResult_fittedParameter
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    return cref->fittedParameter(name);
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    errors
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL Java_hep_aida_jni_CIFitResult_errors
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    vector<double> result = cref->errors();

    jdoubleArray jresult = env->NewDoubleArray(result.size());
    for (unsigned int index=0; index<result.size(); index++) {\
        env->SetDoubleArrayRegion(jresult, index, 1, (jdouble*)(&(result[index])) );
    }

    return jresult;
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    errorsPlus
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL Java_hep_aida_jni_CIFitResult_errorsPlus
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    vector<double> result = cref->errorsPlus();

    jdoubleArray jresult = env->NewDoubleArray(result.size());
    for (unsigned int index=0; index<result.size(); index++) {\
        env->SetDoubleArrayRegion(jresult, index, 1, (jdouble*)(&(result[index])) );
    }

    return jresult;
}

/*
 * Class:     hep_aida_jni_CIFitResult
 * Method:    errorsMinus
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL Java_hep_aida_jni_CIFitResult_errorsMinus
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitResult* cref = (IFitResult*)ProxyFactory::getCRef(crefID);

    vector<double> result = cref->errorsMinus();

    jdoubleArray jresult = env->NewDoubleArray(result.size());
    for (unsigned int index=0; index<result.size(); index++) {\
        env->SetDoubleArrayRegion(jresult, index, 1, (jdouble*)(&(result[index])) );
    }

    return jresult;
}
