
#include "FreeHepTypes.h"

#include "AIDA/IPlotterLayout.h"

#include "ProxyFactory.h"

#include "CIPlotterLayout.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIPlotterLayout
 * Method:    reset
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIPlotterLayout_reset
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterLayout* cref = (IPlotterLayout*)ProxyFactory::getCRef(crefID);

    cref->reset();
}

/*
 * Class:     hep_aida_jni_CIPlotterLayout
 * Method:    setParameter
 * Signature: (Ljava/lang/String;D)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIPlotterLayout_setParameter
  (JNIEnv *env, jobject obj, jstring jname, jdouble value) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterLayout* cref = (IPlotterLayout*)ProxyFactory::getCRef(crefID);

    return cref->setParameter(name, value);
}

/*
 * Class:     hep_aida_jni_CIPlotterLayout
 * Method:    parameterValue
 * Signature: (Ljava/lang/String;)D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIPlotterLayout_parameterValue
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterLayout* cref = (IPlotterLayout*)ProxyFactory::getCRef(crefID);

    return cref->parameterValue(name);
}

/*
 * Class:     hep_aida_jni_CIPlotterLayout
 * Method:    availableParameters
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIPlotterLayout_availableParameters
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IPlotterLayout* cref = (IPlotterLayout*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> names = cref->availableParameters();

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jnames = env->NewObjectArray(names.size(), stringClass, NULL);
    for (unsigned int index=0; index<names.size(); index++) {
	    jobject jtmp = env->NewStringUTF(names[index].c_str());
        env->SetObjectArrayElement(jnames, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jnames;
}
