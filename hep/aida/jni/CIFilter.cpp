
#include "FreeHepTypes.h"

#include "AIDA/IFilter.h"
#include "AIDA/ITuple.h"

#include "ProxyFactory.h"

#include "CIFilter.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIFilter
 * Method:    initialize
 * Signature: (Lhep/aida/ITuple;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFilter_initialize
  (JNIEnv *env, jobject obj, jobject jtuple) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ITuple* tuple = factory->createITuple(env, jtuple);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFilter* cref = (IFilter*)ProxyFactory::getCRef(crefID);

    cref->initialize(*tuple);
}

/*
 * Class:     hep_aida_jni_CIFilter
 * Method:    accept
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIFilter_accept
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFilter* cref = (IFilter*)ProxyFactory::getCRef(crefID);

    return cref->accept();
}

/*
 * Class:     hep_aida_jni_CIFilter
 * Method:    expression
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIFilter_expression
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFilter* cref = (IFilter*)ProxyFactory::getCRef(crefID);

    string result = cref->expression();
    jstring jresult = env->NewStringUTF(result.c_str());
    return jresult;
}
