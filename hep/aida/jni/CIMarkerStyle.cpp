
#include "FreeHepTypes.h"

#include <vector>

#include "AIDA/IMarkerStyle.h"

#include "ProxyFactory.h"

#include "CIMarkerStyle.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIMarkerStyle
 * Method:    availableShapes
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIMarkerStyle_availableShapes
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IMarkerStyle* cref = (IMarkerStyle*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> names = cref->availableShapes();

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
 * Class:     hep_aida_jni_CIMarkerStyle
 * Method:    shape
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIMarkerStyle_shape
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IMarkerStyle* cref = (IMarkerStyle*)ProxyFactory::getCRef(crefID);

    string value = cref->shape();
    jstring jvalue = env->NewStringUTF(value.c_str());
    return jvalue;
}

/*
 * Class:     hep_aida_jni_CIMarkerStyle
 * Method:    setShape
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIMarkerStyle_setShape
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IMarkerStyle* cref = (IMarkerStyle*)ProxyFactory::getCRef(crefID);

    return cref->setShape(name);
}

