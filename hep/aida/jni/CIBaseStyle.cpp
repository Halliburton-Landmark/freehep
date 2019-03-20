
#include "FreeHepTypes.h"

#include <vector>

#include "AIDA/IBaseStyle.h"

#include "ProxyFactory.h"

#include "CIBaseStyle.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIBaseStyle
 * Method:    reset
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIBaseStyle_reset
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBaseStyle* cref = (IBaseStyle*)ProxyFactory::getCRef(crefID);

    cref->reset();
}

/*
 * Class:     hep_aida_jni_CIBaseStyle
 * Method:    setParameter
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBaseStyle* cref = (IBaseStyle*)ProxyFactory::getCRef(crefID);

    return cref->setParameter(name);
}

/*
 * Class:     hep_aida_jni_CIBaseStyle
 * Method:    setParameter
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname1, jstring jname2) {

    jboolean isCopy1;
    string name1 = env->GetStringUTFChars(jname1, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string name2 = env->GetStringUTFChars(jname2, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBaseStyle* cref = (IBaseStyle*)ProxyFactory::getCRef(crefID);

    return cref->setParameter(name1, name2);
}

/*
 * Class:     hep_aida_jni_CIBaseStyle
 * Method:    parameterValue
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIBaseStyle_parameterValue
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBaseStyle* cref = (IBaseStyle*)ProxyFactory::getCRef(crefID);

    string value = cref->parameterValue(name);
    jstring jvalue = env->NewStringUTF(value.c_str());
    return jvalue;
}

/*
 * Class:     hep_aida_jni_CIBaseStyle
 * Method:    availableParameters
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIBaseStyle_availableParameters
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBaseStyle* cref = (IBaseStyle*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> names = cref->availableParameters();

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
 * Class:     hep_aida_jni_CIBaseStyle
 * Method:    availableParameterOptions
 * Signature: (Ljava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIBaseStyle_availableParameterOptions
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBaseStyle* cref = (IBaseStyle*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> names = cref->availableParameterOptions(name);

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jnames = (jobjectArray)env->NewObjectArray(names.size(), stringClass, NULL);
    for (unsigned int index=0; index<names.size(); index++) {
	    jobject jtmp = env->NewStringUTF(names[index].c_str());
        env->SetObjectArrayElement(jnames, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jnames;
}

