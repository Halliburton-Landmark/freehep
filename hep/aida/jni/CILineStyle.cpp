
#include "FreeHepTypes.h"

#include <vector>

#include "AIDA/ILineStyle.h"

#include "ProxyFactory.h"

#include "CUtil.h"
#include "CILineStyle.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CILineStyle
 * Method:    availableLineTypes
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CILineStyle_availableLineTypes
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ILineStyle* cref = (ILineStyle*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> names = cref->availableLineTypes();

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
 * Class:     hep_aida_jni_CILineStyle
 * Method:    lineType
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CILineStyle_lineType
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ILineStyle* cref = (ILineStyle*)ProxyFactory::getCRef(crefID);

    string value = cref->lineType();
    jstring jvalue = env->NewStringUTF(value.c_str());
    return jvalue;
}

/*
 * Class:     hep_aida_jni_CILineStyle
 * Method:    thickness
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CILineStyle_thickness
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ILineStyle* cref = (ILineStyle*)ProxyFactory::getCRef(crefID);

    return cref->thickness();
}

/*
 * Class:     hep_aida_jni_CILineStyle
 * Method:    setLineType
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CILineStyle_setLineType
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ILineStyle* cref = (ILineStyle*)ProxyFactory::getCRef(crefID);

    return cref->setLineType(name);
}

/*
 * Class:     hep_aida_jni_CILineStyle
 * Method:    setThickness
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CILineStyle_setThickness
  (JNIEnv *env, jobject obj, jint jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ILineStyle* cref = (ILineStyle*)ProxyFactory::getCRef(crefID);

    return cref->setThickness(jvalue);
}
