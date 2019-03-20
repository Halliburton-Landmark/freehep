
#include "FreeHepTypes.h"

#include "AIDA/IFunction.h"

#include "ProxyFactory.h"

#include "CIFunction.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    title
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIFunction_title
  (JNIEnv *env, jobject obj) {
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    string title = cref->title();
    jstring jtitle = env->NewStringUTF(title.c_str());
    return jtitle;
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    setTitle
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFunction_setTitle
  (JNIEnv *env, jobject obj, jstring jtitle) {

    jboolean isCopy1;
    string title = env->GetStringUTFChars(jtitle, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);
	
	cref->setTitle(title);
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    value
 * Signature: ([D)D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIFunction_value
  (JNIEnv *env, jobject obj, jdoubleArray jvalue) {

    vector<double> value;
    unsigned int len = env->GetArrayLength(jvalue);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jvalue, i, 1, &d);
        value.push_back(d);
    }

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    return cref->value(value);
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    dimension
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIFunction_dimension
  (JNIEnv *env, jobject obj) {
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    return cref->dimension();
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    isEqual
 * Signature: (Lhep/aida/IFunction;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIFunction_isEqual
  (JNIEnv *env, jobject obj, jobject jfunction) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFunction* function = factory->createIFunction(env, jfunction);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    return cref->isEqual(*function);
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    gradient
 * Signature: ([D)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_hep_aida_jni_CIFunction_gradient
  (JNIEnv *env, jobject obj, jdoubleArray jvalue) {

    vector<double> value;
    unsigned int len = env->GetArrayLength(jvalue);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jvalue, i, 1, &d);
        value.push_back(d);
    }

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    vector<double> result = cref->gradient(value);

    jdoubleArray jresult = env->NewDoubleArray(result.size());
    for (unsigned int index=0; index<result.size(); index++) {\
        env->SetDoubleArrayRegion(jresult, index, 1, (jdouble*)(&(result[index])) );
    }

    return jresult;
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    providesGradient
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIFunction_providesGradient
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    return cref->providesGradient();
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    variableName
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIFunction_variableName
  (JNIEnv *env, jobject obj, jint jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    string name = cref->variableName(jvalue);
    jstring jname = env->NewStringUTF(name.c_str());
    return jname;
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    variableNames
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIFunction_variableNames
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> names = cref->variableNames();

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jnames = (jobjectArray)env->NewObjectArray(names.size(), stringClass, NULL);
    for (unsigned int index=0; index<names.size(); index++) {
	    jobject jtmp = env->NewStringUTF(names[index].c_str());
        env->SetObjectArrayElement(jnames, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jnames;
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    setParameters
 * Signature: ([D)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFunction_setParameters
  (JNIEnv *env, jobject obj, jdoubleArray jvalue) {

    vector<double> value;
    unsigned int len = env->GetArrayLength(jvalue);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jvalue, i, 1, &d);
        value.push_back(d);
    }

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    cref->setParameters(value);
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    parameters
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL Java_hep_aida_jni_CIFunction_parameters
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    vector<double> result = cref->parameters();

    jdoubleArray jresult = env->NewDoubleArray(result.size());
    for (unsigned int index=0; index<result.size(); index++) {\
        env->SetDoubleArrayRegion(jresult, index, 1, (jdouble*)(&(result[index])) );
    }

    return jresult;
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    numberOfParameters
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIFunction_numberOfParameters
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    return cref->numberOfParameters();
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    parameterNames
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIFunction_parameterNames
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> names = cref->parameterNames();

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jnames = (jobjectArray)env->NewObjectArray(names.size(), stringClass, NULL);
    for (unsigned int index=0; index<names.size(); index++) {
	    jobject jtmp = env->NewStringUTF(names[index].c_str());
        env->SetObjectArrayElement(jnames, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jnames;
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    setParameter
 * Signature: (Ljava/lang/String;D)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFunction_setParameter
  (JNIEnv *env, jobject obj, jstring jname, jdouble jvalue) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);
	
	cref->setParameter(name, jvalue);
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    parameter
 * Signature: (Ljava/lang/String;)D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIFunction_parameter
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    return cref->parameter(name);	
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    indexOfParameter
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIFunction_indexOfParameter
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    return cref->indexOfParameter(name);	
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    annotation
 * Signature: ()Lhep/aida/IAnnotation;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFunction_annotation
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();

    const IAnnotation& annotation = cref->annotation();
    return factory->create(env, annotation);
}

/*
 * Class:     hep_aida_jni_CIFunction
 * Method:    codeletString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIFunction_codeletString
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunction* cref = (IFunction*)ProxyFactory::getCRef(crefID);

    string codeletString = cref->codeletString();
    jstring jcodeletString = env->NewStringUTF(codeletString.c_str());
    return jcodeletString;
}
