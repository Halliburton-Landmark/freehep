
#include "FreeHepTypes.h"

#include <vector>

#include "AIDA/IBrushStyle.h"

#include "ProxyFactory.h"

#include "CIBrushStyle.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIBrushStyle
 * Method:    availableColors
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIBrushStyle_availableColors
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBrushStyle* cref = (IBrushStyle*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> names = cref->availableColors();

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
 * Class:     hep_aida_jni_CIBrushStyle
 * Method:    color
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIBrushStyle_color
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBrushStyle* cref = (IBrushStyle*)ProxyFactory::getCRef(crefID);

    string value = cref->color();
    jstring jvalue = env->NewStringUTF(value.c_str());
    return jvalue;
}

/*
 * Class:     hep_aida_jni_CIBrushStyle
 * Method:    opacity
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIBrushStyle_opacity
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBrushStyle* cref = (IBrushStyle*)ProxyFactory::getCRef(crefID);

    return cref->opacity();
}

/*
 * Class:     hep_aida_jni_CIBrushStyle
 * Method:    setColor
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIBrushStyle_setColor
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBrushStyle* cref = (IBrushStyle*)ProxyFactory::getCRef(crefID);

    return cref->setColor(name);
}

/*
 * Class:     hep_aida_jni_CIBrushStyle
 * Method:    setOpacity
 * Signature: (D)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIBrushStyle_setOpacity
  (JNIEnv *env, jobject obj, jdouble jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IBrushStyle* cref = (IBrushStyle*)ProxyFactory::getCRef(crefID);

    return cref->setOpacity(jvalue);
}

